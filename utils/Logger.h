#ifndef Logger_h
#define Logger_h

#include "Singleton.h"
#include "Mutex.h"
#include "Lock.h"

#include <iostream>
#include <sstream>
#include <string>

//#include "utilsdlldef.h"
#define LOGGER_DLL_API

class Logger;

namespace Level
{
	enum LogLevel { none, critical, error, warning, message, info, debug, all };
}

/**
	Used as an iostream maninpulator to signal the end of a message
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
	
	friend LOGGER_DLL_API std::ostream & operator<< ( std::ostream & os, EndLog & el );
};

/**
	Defined to allow Logger::end() as a stream manipulator
*/
LOGGER_DLL_API std::ostream & operator<< ( std::ostream & os, EndLog & el );

/**
	This object does logging that can be used either from a
	stream-type interface, or via a method interface. For example:
	\code
	Logger::instance().log( "This is a message" );
	Logger::os() << "This is another message" << Logger::end();
	Logger::instance().los() << "This is a message" << endl;
	Logger::instance().los() << "That comes on two lines" << endl;
	Logger::os() << Logger::end();
	\endcode

	The class can be easily subclassed to log to a system logging
	facility, or to a database, or whatever. It's also necessary to
	provide an subclass implementing doLog, and an implementation of
	newInstance to return the new instance of the class.

	\warning The mutex used for this class *must* be recursive.
	
	\todo make the interface a bit neater
	\todo allow for minimal overhead when there's no logging. Null iobuf
	or something like that.
*/
class LOGGER_DLL_API Logger : public Singleton<Logger, Mutex, Lock>
{
public:
	/// Defined as virtual for subclasses
	virtual ~Logger() {};
		
	/**
		Tell the logger to flush any caches it might have.
		Does nothing by default.
	*/
	virtual void flush()
	{
	}

	/**
		This can either be called as is, or used via the stream
		interface.
	*/
	void log ( const std::string & msg, Level::LogLevel level = Level::message );

	/**
		Provide a logging stream.
		This acquires a lock that's release on a call Logger::end()
	*/
	std::ostream & los();
		
	/**
		To be used in conjunction with los() to signal the
		end of one message. Used either directly or via
		the EndLog manipulator.
	*/
	void endMessage( Level::LogLevel level );
		
	/**
		Call this with the highest level of message to be
		actually logged. Default is to log everything.
	*/
	void filter ( Level::LogLevel level )
	{
		_filter = level;
	}

	/**
		Return the current filter level
	*/
	Level::LogLevel filter() const
	{
		return _filter;
	}
	
	/**
		Use this to get access to the stream interface, like this:
		\code
		Logger::log() << This is a message << Logger::end();
		\endcode
		This acquires a lock that's release on a call Logger::end()
	*/
	static std::ostream & os();
	
	/**
		Call this to get a manipulator, like this:
		\code
		Logger::instance().los() << "Some message" << Logger::end( critical );
		\endcode
		In fact, it's *necessary* to call this after using the
		stream interface, otherwise the lock never gets released.
	*/
	static EndLog & end ( Level::LogLevel level = Level::message );
	
	/**
		Translate the log level to a string
	*/
	static std::string levelToString ( Level::LogLevel level );

protected:
	Logger();
	Logger ( const Logger & );
	
	/**
		Subclasses should override this to actually log the message.

		\warning this is mutex-protected, so don't block in here
		for too long, whatever's using the logger will slow down
		quite a bit.
	*/
	virtual void doLog ( const std::string & message, Level::LogLevel level ) = 0;
	
	friend LOGGER_DLL_API Logger * newInstance ( Logger * );

	std::ostringstream _os;
	Level::LogLevel _filter;
	
	EndLog _end;

	/**
		This is used to ensure that multiple clients don't interleave
		their output.
	*/
	Lock _lock;

	/**
		A count to make sure that the locks acquired by os()
		are unlocked the correct number of times by endMessage().
	*/
	int _locks;
};

LOGGER_DLL_API Logger * newInstance ( Logger * );

#endif
