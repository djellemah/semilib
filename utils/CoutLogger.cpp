#include "CoutLogger.h"
#include "utils.h"
#include <cstdlib>

using namespace std;
namespace semilib
{

void CoutLogger::doLog ( const string & msg, Level::LogLevel level )
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

Logger * newInstance ( Logger * )
{
	return new semilib::CoutLogger;
}

}
