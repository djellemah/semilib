#include "Logger.h"

using namespace std;

#pragma warning( disable : 4355 ) 
Logger::Logger()
: _filter ( Level::all )
, _end ( *this )
, _locks ( 0 )
{
}
#pragma warning( default : 4355 ) 

void Logger::log ( const std::string & msg, Level::LogLevel level )
{
	Lock lock ( _mutex );
	// only log the message if the level is set above it
	if( level <= _filter )
	{
		doLog ( msg, level );
	}
	
	// reset the buffer for the next message
	_os.str ( string() );
}

std::ostream & operator<< ( std::ostream & os, EndLog & el )
{
	// signal to the Logger that this is the end of a message
	el._logger.endMessage( el._level );
	
	return os;
}

ostream & Logger::los()
{
	// this is quite tricky, because this might be
	// called several times before endMessage is called
	// so we need a count
	_lock.acquire ( _mutex );
	++_locks;
	return _os;
}

void Logger::endMessage( Level::LogLevel level )
{
	log ( _os.str(), level );
	
	// end of message, so someone else can have a go now
	// the mutex is recursively acquired in os()
	
	// prevent other threads getting in here
	// between the last --_locks and the _locks > 0 test
	_lock.acquire ( _mutex );
	while ( _locks > 0 )
	{
		// do this before the release, so we don't get a race
		 --_locks;
		_lock.release ();
	}
	_lock.release();
}

ostream & Logger::os()
{
	return instance().los();
}

EndLog & Logger::end( Level::LogLevel level )
{
	Logger::instance()._end.level ( level );
	return Logger::instance()._end;
}


string Logger::levelToString ( Level::LogLevel level )
{
	using namespace Level;
	
	string retval;
	switch ( level )
	{
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
			retval = "unknown level";
			break;
	};
	return retval;
}
