#include "Logger.h"

using namespace std;

Logger::Logger()
: _filter ( all )
, _end ( *this )
, _locks ( 0 )
{
}

void Logger::log ( const std::string & msg, LogLevel level )
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
	return _os;
}

EndLog & Logger::end( LogLevel level )
{
	Logger::instance()._end.level ( level );
	return Logger::instance()._end;
}

void Logger::endMessage( LogLevel level )
{
	log ( _os.str(), level );
	
	// end of message, so someone else can have a go now
	// the mutex is recursively acquired in os()
	while ( _locks > 0 )
	{
		// do this before the release, so we don't get a race
		 --_locks;
		_lock.release ();
	}
}

/**
	The default logger just sends to stdout
*/
class CoutLogger : public Logger
{
public:
	void doLog ( const string & msg, LogLevel level )
	{
		cout << level << ": " << msg << endl;
	}
};

Logger * newInstance ( Logger * )
{
	return new CoutLogger;
}

ostream & Logger::os()
{
	// this is quite tricky, because this might be
	// called several times before endMessage is called
	// so we need a count
	instance()._lock.acquire ( _mutex );
	// for debugging only
	int locks = instance()._locks;
	++instance()._locks;
	return Logger::instance().los();
}
