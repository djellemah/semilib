#include "utils.h"

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

