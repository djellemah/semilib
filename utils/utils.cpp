#include "utils.h"

#include <time.h>
#include "Lock.h"
#include <sstream>

using namespace std;

#ifdef _WIN32
	UTILS_DLL_API const char * pathsep = "\\";
#else
	const char * pathsep = "/";
#endif

#ifdef _MSC_VER
#include <tchar.h>
#endif

#include <time.h>

/**
	Strip all carriage returns.
*/
UTILS_DLL_API void stripCr ( string & s )
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

UTILS_DLL_API struct tm brokentime()
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

UTILS_DLL_API string today()
{
	struct tm btime = brokentime();
		
	// convert to a string
	const size_t maxbufsize = 40;
	char buf[maxbufsize+1];
	size_t result = strftime (buf, maxbufsize, "%d-%b-%y" , &btime );
	return string ( buf );
}

UTILS_DLL_API string now()
{
	struct tm btime = brokentime();

	// convert to a string
	const size_t maxbufsize = 60;
	char buf[maxbufsize+1];
	size_t result = strftime (buf, maxbufsize, "%d %b %Y %H:%M" , &btime );
	return string ( buf );
}

UTILS_DLL_API string timestamp()
{
	struct tm btime = brokentime();

	// convert to a string
	const size_t maxbufsize = 60;
	char buf[maxbufsize+1];
	size_t result = strftime (buf, maxbufsize, "%d %b %Y %H:%M:%S" , &btime );
	return string ( buf );
}

UTILS_DLL_API string trim ( const string & s )
{
	if ( s.empty() )
	{
		return string();
	}
	
	// strip spaces from beginning of string
	string::const_iterator begin = s.begin();
	
	while ( *begin == ' ' && begin != s.end() )
	{
		++begin;
	}
	
	if ( begin == s.end() )
	{
		return string();
	}

	// strip spaces from end of string
	string::const_iterator end = s.end() - 1;
	while ( *end == ' ' )
	{
		--end;
	}
	
	return string ( begin, end + 1 );
}

UTILS_DLL_API string strftime ( const time_t & t, const string & format )
{
	const int maxbuf = 256;
	struct tm tm_time;
	Lock lock ( mutex );
	tm_time = *::localtime ( & t );
	char temp[maxbuf];
#ifdef _MSC_VER
	::_tcsftime ( temp, maxbuf-1, format.c_str(), &tm_time );
#else
	::strftime ( temp, maxbuf-1, format.c_str(), &tm_time );
#endif
	return string ( temp );
}
