#include "Logger.h"
#include "utils.h"

using namespace std;

/**
	The default logger just sends to stderr
*/
class CoutLogger : public Logger
{
public:
	void doLog ( const string & msg, Level::LogLevel level )
	{
		char * env_level = getenv ( "SEMILIB_LOGGER_LEVEL" );
		Level::LogLevel filterLevel = Level::none;
		if ( env_level != 0 )
		{
			filterLevel = stringToLevel ( env_level );
		}
		else
		{
			filterLevel = Level::all;
		}
		if ( level < filterLevel )
		{
			cout << timestamp() << ": " << msg << endl;
		}
	}
};

Logger * newInstance ( Logger * )
{
	return new CoutLogger;
}

