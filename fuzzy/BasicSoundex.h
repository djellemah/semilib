#ifndef BasicSoundex_h
#define BasicSoundex_h

#include <string>

#include "fuzzydlldef.h"

namespace JLeffler
{

using namespace std;

// arbitrary Soundex. Makes a soundex of n characters
FUZZY_DLL_API string nsoundex ( const string & str, unsigned int n );

// normal Soundex. Makes a soundex of 4 characters
FUZZY_DLL_API string soundex(const string & str);

}
#endif
