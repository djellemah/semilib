#ifndef utils_h
#define utils_h

#include <string>
#include <sstream>

/**
	Define the path separator character. \ for win32, / for unix
*/
extern const char * pathsep;

void stripCr ( std::string & s );

/**
	Convert a number into a string. Instantiates an ostringstream
	each time, for thread safety, so it's not extremely lightweight.
	OTOH this is the Stroustrup recommended way.
	
	\todo it might be better to have this mutex protected, and
	use the static. Since there probably won't be much contention
	for this function.
*/
template<class T>
std::string numberToString ( T num )
{
	std::ostringstream os;
	os << num;
	return os.str();
}

#endif

