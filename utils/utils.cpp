#include "utils.h"

#include <time.h>
#include "Lock.h"

#include <sstream>

using namespace std;

#ifdef _WIN32
	const char * pathsep = "\\";
#else
	const char * pathsep = "/";
#endif

/**
	Strip all carriage returns.
*/
void stripCr ( string & s )
{
	ostringstream os;
	istringstream is ( s );
	for ( char next = is.get(); is.good(); next = is.get() )
	{
		if ( next != '\r' )
			os << next;
	}
	
	s = os.str();
}

using namespace std;

Mutex mutex;

struct tm brokentime()
{
	// fetch the current time
	time_t thetime;
	time ( &thetime );
	
	// convert to a broken time value
	struct tm btime;
		
	// make a copy now to avoid the system pointer
	// getting overriden with a different value
	Lock lock ( mutex );
	btime = *localtime (&thetime);
	
	return btime;
}

string today()
{
	struct tm btime = brokentime();
		
	// convert to a string
	const size_t maxbufsize = 40;
	char buf[maxbufsize];
	size_t result = strftime (buf, maxbufsize, "%0d-%b-%y" , &btime );
	return string ( buf );
}

string now()
{
	struct tm btime = brokentime();

	// convert to a string
	const size_t maxbufsize = 40;
	char buf[maxbufsize];
	size_t result = strftime (buf, maxbufsize, "%d %b %Y %H:%M" , &btime );
	return string ( buf );
}

