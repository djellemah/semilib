#ifndef Logger_h
#define Logger_h

#include "Singleton.h"
#include "Mutex.h"
#include "Lock.h"

#include <iostream>
#include <sstream>
#include <string>

class Logger;

enum LogLevel { critical, error, warning, message, info, debug, all };

/**
	Used as an iostream maninpulator to signal the end of a message
*/
class EndLog
{
public:
	EndLog ( Logger & logger )
	: _logger ( logger )
	{
	}
	
	void level ( LogLevel l )
	{
		_level = l;
	}
	
private:
	Logger & _logger;
	LogLevel _level;
	
	friend std::ostream & operator<< ( std::ostream & os, EndLog & el );
};

/**
	Defined to allow Logger::end() as a stream manipulator
*/
std::ostream & operator<< ( std::ostream & os, EndLog & el );

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
	facility, or to a database, or whatever.

	\warning The mutex used for this class *must* be recursive.
	\todo remove debugging commented-out cout
*/
class Logger : public Singleton<Logger, Mutex, Lock>
{
public:
	/// Defined as virtual for subclasses
	virtual ~Logger() {};
		
	/**
		This can either be called as is, or used via the stream
		interface.
	*/
	void log ( const std::string & msg, LogLevel level = message );

	/**
		Provide a logging stream.
	*/
	std::ostream & los();
		
	/**
		To be used in conjunction with los() to signal the
		end of one message. Used either directly or via
		the EndLog manipulator.
	*/
	void endMessage( LogLevel level );
		
	/**
		Call this with the highest level of message to be
		actually logged. Default is to log everything.
	*/
	void filter ( LogLevel level )
	{
		_filter = level;
	}

	/**
		Return the current filter level
	*/
	LogLevel filter() const
	{
		return _filter;
	}
	
	/**
		Use this to get access to the stream interface, like this:
		\code
		Logger::log() << This is a message << Logger::end();
		\endcode
	*/
	static std::ostream & os();
	
	/**
		Call this to get a manipulator, like this:
		\code
		Logger::instance().los() << "Some message" << Logger::end( critical );
		\endcode
	*/
	static EndLog & end ( LogLevel level = message );

protected:
	Logger();
	
	/**
		Subclasses should override this to actually log the message.

		\warning this is mutext-protected, so don't block in here
		for too long, whatever's using the logger will slow down
		quite a bit.
	*/
	virtual void doLog ( const std::string & message, LogLevel level ) = 0;
	
	friend Logger * newInstance ( Logger * );

	std::ostringstream _os;
	LogLevel _filter;
	
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

Logger * newInstance ( Logger * );

#endif
