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
		cout << timestamp() << ": " << msg << endl;
	}
};

Logger * newInstance ( Logger * )
{
	return new CoutLogger;
}

