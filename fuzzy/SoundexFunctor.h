#ifndef Soundex_h
#define Soundex_h

#include <vector>

using namespace std;

#include "fuzzydlldef.h"
#include "fuzzy.h"

/**
	This is to be used via the transform algorithm
*/
class FUZZY_DLL_API Soundex
{
public:
	Soundex ( const string & toMatch );

	Ranking operator () ( const string & element );

protected:
	// remove all punctuation and accents. Then remove
	// all spaces. Then append _ to the beginning and end
	// of the string
	string PrepareTheString ( const string & OriginStr );

private:
	string _toMatch;
	string _theString;
};

#endif
