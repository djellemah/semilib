#pragma warning ( disable : 4275 )

#include "Logger.h"
#include "Mutex.h"
#include "Singleton.h"

#include <iomanip>
#include <map>

using namespace std;
using namespace semilib;

Logger & semilib::logger = Singleton<Logger,Mutex,Lock>::instance();

Logger * newInstance ( Logger * );

Logger & Logger::instance()
{
	return Singleton<Logger,Mutex,Lock>::instance();
}

#ifndef _WIN32
void logger_init(void) __attribute__((constructor));

void logger_init(void)
{
/*
	cout << "before " << &logger << endl;
	Logger * tmp = &logger;
	(void*)tmp = (void*)&Logger::instance();
	cout << "after " << &logger << endl;
*/
}
#endif

#pragma warning( disable : 4355 )
Logger::Logger()
: _filter ( Level::all )
, _end ( *this )
, _locks ( 0 )
{
//	cout << "Initialising Logger" << endl;
}
#pragma warning( default : 4355 )

Mutex & Logger::mutex()
{
	return Singleton<Logger,Mutex,Lock>::mutex();
}

void Logger::log ( const std::string & msg, Level::LogLevel level )
{
	_lock.acquire ( mutex() );
	// only log the message if the level is set above it
	if( level <= _filter )
	{
		ostringstream os;
		os << setw(8) << left << levelToString ( level ) << ": " << msg;
		doLog (  os.str(), level );
	}

	// reset the buffer for the next message
	_os.str ( string() );
	_lock.release();
}

std::ostream & semilib::operator<< ( std::ostream & os, const EndLog & el )
{
	// signal to the Logger that this is the end of a message
	el._logger.endMessage( el._level );

	return os;
}

void Logger::endMessage( Level::LogLevel level )
{
	// prevent other threads getting in here
	// between the last --_locks and the _locks > 0 test
	_lock.acquire ( mutex() );
	log ( _os.str(), level );

	// end of message, so someone else can have a go now
	// the mutex can be acquired several times in os()
	// so it needs to be released several times here
	while ( _locks > 0 )
	{
		 --_locks;
		_lock.release ();
	}
	_lock.release();
}

ostream & Logger::os()
{
	// this is quite tricky, because this might be
	// called several times before endMessage is called
	// so we need a count
	_lock.acquire ( mutex() );
	++_locks;
	return _os;
}

EndLog & Logger::end( Level::LogLevel level )
{
	// acquire the lock
	Logger::instance()._lock.acquire ( Logger::instance().mutex() );

	// increment usage count, cos we're not releasing the lock in this method
	++Logger::instance()._locks;

	// set the current level
	Logger::instance()._end.level ( level );

	// return the end object
	return Logger::instance()._end;
}

void Logger::filter ( Level::LogLevel level )
{
	// can't just return _filter, gcc
	// then insists on creating two separate
	// instances
	Logger::instance()._filter = level;
}

Level::LogLevel Logger::filter() const
{
	return Logger::instance()._filter;
	//return _filter;
}


string Logger::levelToString ( Level::LogLevel level )
{
	using namespace Level;

	string retval;
	switch ( level )
	{
		case none:
			retval = "none";
			break;
		case critical:
			retval = "critical";
			break;
		case error:
			retval = "error";
			break;
		case warning:
			retval = "warning";
			break;
		case message:
			retval = "message";
			break;
		case info:
			retval = "info";
			break;
		case debug:
			retval = "debug";
			break;
		default:
			retval = "unknown";
			break;
	};
	return retval;
}

Level::LogLevel Logger::stringToLevel ( std::string stringLevel )
{
	using namespace Level;
	std::map<std::string,Level::LogLevel> levels;
	levels["none"] = none;
	levels["critical"] = critical;
	levels["error"] = error;
	levels["warning"] = warning;
	levels["message"] = message;
	levels["info"] = info;
	levels["debug"] = debug;
	levels["all"] = all;

	if ( levels.find ( stringLevel ) != levels.end() )
	{
		return levels[stringLevel];
	}
	else
	{
		ostringstream os;
		os << "Level " << stringLevel << " not found in Logger::stringToLevel";
		throw runtime_error ( os.str() );
	}
}

int Logger::pid() const
{
#ifndef _WIN32
	return getpid();
#else
	return ::GetCurrentProcessId();
#endif
}

int Logger::thread() const
{
#ifndef _WIN32
	return 0;
#else
	return ::GetCurrentThreadId();
#endif
}


ostream & semilib::elog ( std::ostream & os )
{
	os << Logger::end();
	return os;
}

void semilib::elog ( Logger & logger )
{
	logger << Logger::end();
}


EndLog & semilib::elog ( Level::LogLevel level )
{
	return Logger::end ( level );
}

LogChainer::LogChainer ( Logger & l, Level::LogLevel level )
: _logger ( l )
, _level ( level )
, _copied ( false )
{
}

LogChainer::LogChainer ( const LogChainer & other )
: _logger ( other._logger )
, _level ( other._level )
, _copied ( false )
{
	other._copied = true;
}

LogChainer::~LogChainer()
{
	// only send the elog if this copy is the last
	// in the chain.
	if ( !_copied )
	{
		_logger << elog(_level);
	}
}

LogChainer semilib::loch ( Level::LogLevel level )
{
	return LogChainer ( Logger::instance(), level );
}
