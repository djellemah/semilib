#include <string>
#include <algorithm>

#include <ctype.h>

using namespace std;

#include "Soundex.h"
#include "BasicSoundex.h"
#include "functions.h"
#include "matchfunctions.h"

Soundex::Soundex ( const string & toMatch )
	: _toMatch ( PrepareTheString ( toMatch ) )
	, _theString ( toMatch )
{
}

Ranking Soundex::operator () ( const string & element )
{
	// strip out punctuation and accented characters
	string soundex = PrepareTheString ( element );

	// return percentage match and original string 
	float percent = (( soundex == _toMatch ) ? 1.0 : 0.0 );
	return Ranking ( percent, element );
}

string Soundex::PrepareTheString(const string & OriginStr)
{
	string retval;

	// change all punctuation things to spaces
	transform (
		OriginStr.begin()
		, OriginStr.end()
		, insert_iterator<string> ( retval, retval.begin() )
		, stripThings
	);

	// remove digits (oops)
	remove_if ( retval.begin(), retval.end(), isDigit );

	// strip all spaces
	remove ( retval.begin(), retval.end(), ' ' );

	return JLeffler::nsoundex ( retval.c_str(), 6 );
}
