#ifndef utils_h
#define utils_h

#include "utilsdlldef.h"

#include <string>
#include <sstream>

/**
	Define the path separator character. \ for win32, / for unix
*/
extern const char * pathsep;

UTILS_DLL_API void stripCr ( std::string & s );

/**
	Convert a number into a string. Instantiates an ostringstream
	each time, for thread safety, so it's not extremely lightweight.
	OTOH this is the Stroustrup recommended way.
*/
template<class T>
std::string numberToString ( T num )
{
	std::ostringstream os;
	os << num;
	return os.str();
}

/**
	Fetch a struct tm value containing the current time.
*/
UTILS_DLL_API struct tm brokentime();

/**
	Fetch the current time in the format 01-jun-02
*/
UTILS_DLL_API std::string today();

/**
	Full timestamp, including seconds and milliseconds
*/
UTILS_DLL_API std::string timestamp();

/**
	Fetch the current time in the format 6 JUN 2002 10:40
*/
UTILS_DLL_API std::string now();

/**
	trim whitespace from the beginning and end of the string

	This could probably be done better with find_first_not_of
	but the app is nearly live and I don't want to mess with things

	\todo implement with algorithms
*/
UTILS_DLL_API std::string trim ( const std::string & );

/**
	Do something like perl's join
*/
template<class Collection, class Joiner>
UTILS_DLL_API std::string join ( const Collection & collection, const Joiner & joiner )
{
	using namespace std;
	ostringstream os;

	typename Collection::const_iterator begin = collection.begin();
	typename Collection::const_iterator cur = collection.begin();
	for ( ; cur != collection.end(); ++cur )
	{
		if ( cur != begin )
		{
			os << joiner;
		}
		os << *cur;
	}
	return os.str();
}

#endif

// Of course, MSVC 6 can't compile these.
#ifndef _MSC_VER
/**
	Helper template for for_each_delete
*/
template<class T>
void deleteObject ( T obj )
{
	delete obj;
}

/**
	Call delete on all elements in the given range
*/
template<class I>
void for_each_delete ( I begin, I end )
{
	for_each ( begin, end, deleteObject<typename I::value_type> );
}

/**
	Call delete for the entire collection
*/
template<class C>
void for_each_delete ( C & collection )
{
	for_each_delete ( collection.begin(), collection.end() );
}
#else
template<class C>
void for_each_delete ( C & collection )
{
	C::iterator cur = collection.begin();
	for( ; cur != collection.end(); ++cur )
	{
		delete *cur;
	}
}
#endif
