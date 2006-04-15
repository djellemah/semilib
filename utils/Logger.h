#ifndef Logger_h
#define Logger_h

/**
	\defgroup logger Logging

	The main class here is Logger, accessed via loch.
	\code
	loch(Level::info) << "This is a message: " << someMessage;
	\endcode

	Old style interface would be
	\code
	logger << "This is a message: " << someMessage << elog(Level::info);
	\endcode

	CoutLogger and FileLogger output to stdout and a file, respectively.

	\note Don't use slow functions inside the operator << calls to the
	logger. Use this pattern instead:
	\code
	ostringstream os;
	os << "This" << endl;
	os << " is " << endl;
	os << " a message" << endl;
	loch ( Level::info ) << os.str();
	\endcode
*/

#include "Lock.h"

#include <iostream>
#include <sstream>
#include <string>

//#include "utilsdlldef.h"
#define LOGGER_DLL_API

namespace semilib
{

class Logger;

LOGGER_DLL_API Logger * newInstance ( Logger * dummy );

namespace Level
{
	enum LogLevel { none, critical, error, warning, message, info, debug, all };
}

/**
	Used as an iostream manipulator to signal the end of a message
	\ingroup logger
*/
class LOGGER_DLL_API EndLog
{
public:
	EndLog ( Logger & logger )
	: _logger ( logger )
	{
	}

	void level ( Level::LogLevel l )
	{
		_level = l;
	}

private:
	Logger & _logger;
	Level::LogLevel _level;

	friend LOGGER_DLL_API std::ostream & operator<< ( std::ostream & os, const EndLog & el );
};

/**
	Defined to allow Logger::end() as a stream manipulator
*/
LOGGER_DLL_API std::ostream & operator<< ( std::ostream & os, const EndLog & el );

/**
	This object does logging that can be used either from a
	stream-type interface, or via a method interface. For example:
	\code
	Logger::instance().log( "This is a message" );
	logger << "This is another message" << elog;
	logger << "This is a message" << endl;
	logger << "That comes on two lines" << endl;
	logger << elog;
	\endcode

	\warning elog is VERY IMPORTANT. Without it you might
	deadlock the logger. loch is better.

	The class can be easily subclassed to log to a system logging
	facility, or to a database, or whatever. It's also necessary to
	provide an subclass implementing doLog, and an implementation of
	newInstance to return the new instance of the class, if you want it
	hook into the Singleton logger instance. Otherwise you can just
	instantiate logger instances as you need them.

	\note The mutex used for this class *must* be recursive.

	\todo use TLS to store elog marker, and only lock for the write. Would
	prevent things like socket DNS reverse-resolution locking up
	all the other threads. Also, makes forgetting elog less dangerous.
	\todo use an observer pattern for outputs, so we don't have link
	weirdness, and we can set a default output.

	\see LogChainer

	\todo remove logger and replace with logger()

	\todo rename loch(...) to logger(...)

	\ingroup logger
*/
class LOGGER_DLL_API Logger
{
public:
	Logger();

	/// Defined as virtual for subclasses
	virtual ~Logger() {};

	/**
		Tell the logger implementation to flush any caches
		it might have. Does nothing by default.
	*/
	virtual void flush() {}

	/**
		This can either be called as is, or used via the stream
		interface. This version is slightly safer in that the programmer
		doesn't need to remember to call elog.
	*/
	void log ( const std::string & msg, Level::LogLevel level = Level::message );

	/**
		Call this with the highest level of message to be
		actually logged. Default is to log everything.
	*/
	virtual void filter ( Level::LogLevel level );

	/**
		Return the current filter level
	*/
	virtual Level::LogLevel filter() const;

	/**
		It's *necessary* to call this after using the
		stream interface, otherwise the lock never gets released:
		\code
		logger << "Some message" << Logger::end( critical );
		\endcode

		For an easier way, \see loch
	*/
	static EndLog & end ( Level::LogLevel level = Level::message );

	/**
		Translate the log level to a string
	*/
	static std::string levelToString ( Level::LogLevel level );

	/**
		Translate a string to the log level
	*/
	static Level::LogLevel Logger::stringToLevel ( std::string stringLevel );

	/**
		Access the stream for the logger.
		\internal Use operator << ( Logger &, T & ) instead.
	*/
	std::ostream & os();

	/**
		Return the logger instance. It shouldn't be necessary
		to use this, use the "logger" global variable instead.
	*/
	static Logger & instance();

protected:
	friend LOGGER_DLL_API std::ostream & operator<< ( std::ostream & os, const EndLog & el );
	friend LOGGER_DLL_API Logger * newInstance ( Logger * );

	/// De-construct this overload
	Logger ( const Logger & );

	/**
		Subclasses should override this to actually log the message.

		\warning this is mutex-protected, so don't block in here
		for too long, whatever's using the logger will slow down
		quite a bit.
	*/
	virtual void doLog ( const std::string & message, Level::LogLevel level ) = 0;

	void endMessage( Level::LogLevel level );

	/**
		fetch the current process id
	*/
	int Logger::pid() const;

	/**
		fetch the current thread id
	*/
	int Logger::thread() const;

protected:
	/**
		Return the mutex for the logger. Since the instance of
		logger is normally a Singleton, this will return a
		global mutex. Override this method if you don't want
		this behaviour.
	*/
	virtual Mutex & mutex();

	/// The underlying stream.
	std::ostringstream _os;

	/// the current log level
	Level::LogLevel _filter;

	/// The endlog object.
	EndLog _end;

	/**
		This is used to ensure that multiple clients don't interleave
		their output.
	*/
	Lock _lock;

	/// The mutex that gets locked on
	Mutex _mutex;

	/**
		A count to make sure that the locks acquired by os()
		are unlocked the correct number of times by endMessage().
	*/
	int _locks;
};

/**
	Convenience function that returns Logger::EndLog

	\deprecated in favour of loch
	\ingroup logger
*/
LOGGER_DLL_API extern std::ostream& elog ( std::ostream & );

#ifndef _MSC_VER
/**
	to allow logger << elog;
	\todo fix this
	\ingroup logger
*/
extern void elog ( Logger & logger );
#endif

LOGGER_DLL_API extern EndLog & elog ( Level::LogLevel level = Level::message );

/**
	A definition of this must be linked to provide
	the instance which actually does the logging.
	\ingroup logger
*/
LOGGER_DLL_API Logger * newInstance ( Logger * );

/**
	allow << directly to a logger

	\deprecated in favour of loch
	\ingroup logger
*/
template<class T>
std::ostream & operator<< ( Logger &, const T & type )
{
	// I'm sure there was a good reason, other than
	// just convenience, to have the reference...
	std::ostream & os = Logger::instance().os();
	os << type;
	return os;
}

/**
	The logger instance
	\deprecated in favour of loch
	\ingroup logger
*/
LOGGER_DLL_API extern Logger & logger;

/**
	This is a wrapper for the logger that simplifies usage.

	\see loch

	This is a Sentry pattern with
	a twist - the _copied flag is set by each recipient of a
	copy, and the last uncopied instance in the chain will send elog
	and unlock the logger instance.
	\ingroup logger
*/
class LogChainer
{
public:
	LogChainer ( Logger &, Level::LogLevel );
	LogChainer ( const LogChainer & );
	virtual ~LogChainer();

	/// calls Logger's flush
	void flush();

	/// calls Logger's filter
	void filter ( Level::LogLevel level );

	/// calls Logger's filter
	Level::LogLevel filter() const;

	/**
		\internal

		Used by the << operator
	*/
	template<class T>
	void log ( const T & rhs)
	{
		// only send data to the stream if the filter
		// allows it. Otherwise don't waste the CPU
		if ( _level <= _logger.filter() )
		{
			_logger.os() << rhs;
		}
	}

private:
	mutable bool _copied;
	Level::LogLevel _level;
	Logger & _logger;
};

/**
	allow << directly to a LogChainer. The parameters and
	return values are pass-by-value because it allows LogChainer
	to use its copy constructor to keep track of when to send the
	elog.

	\warning The logger lock will still be started by the first
	call to the stream, so slow evaluations inside the chain
	will then slow down the logging system because of the global lock.

	\ingroup logger
*/
template<class T>
LogChainer operator<< ( LogChainer ld, const T & type )
{
	ld.log ( type );
	return ld;
}

/**
	This is the preferred interface. It allows you to do things like this:
	\code
	loch ( Level::debug ) << "Oh My god, " << evilPerson << killed Kenny!";
	\endcode

	and the chained instance will auto-magically send elog for you and
	unlock the logger instance so that
	you don't have to remember to. It will also make sure
	that the << operators use as little CPU as possible
	if the current log level is less than the filter level.

	\ingroup logger
*/
LogChainer loch ( Level::LogLevel level );

/**
	The verbose version in case you want to use a specific
	logger instance rather than the global one.

	\ingroup logger
*/
LogChainer loch ( Logger &, Level::LogLevel );

}

#endif
