/*
**	  SOUNDEX CODING
**
**	  Rules:
**	  1.	  Retain the first letter; ignore non-alphabetic characters.
**	  2.	  Replace second and subsequent characters by a group code.
**			  Group   Letters
**			  1			   BFPV
**			  2			   CGJKSXZ
**			  3			   DT
**			  4			   L
**			  5			   MN
**			  6			   R
**	  3.	  Do not repeat digits
**	  4.	  Truncate or ser-pad to 4-character result.
**
**	  Originally formatted with tabstops set at 4 spaces -- you were warned!
**
**	  Code by: Jonathan Leffler (john@sphinx.co.uk)
**	  This code is shareware -- I wrote it; you can have it for free
**	  if you supply it to anyone else who wants it for free.**
**	  BUGS: Assumes ASCII

Slightly modified by John Anderson (panic@semiosix.com) circa 2000 to be c++ and use STL stuff
*/

#include <string>
#include <iterator>

#include "BasicSoundex.h"
#include "functions.h"

#include "SoundexCharLookup.h"

using Soundex::lookup;

namespace JLeffler
{

using namespace std;


/**
	Soundex for arbitrary number of characters of information
*/
string nsoundex ( const string & str, unsigned int n )
{
	string retval;
	string::const_iterator s = str.begin();
	insert_iterator<string> t ( retval, retval.end() );

	// this assumes that we're only dealing with alphanumeric characters
	char last = ' ';
	while ( retval.length() < n )
	{
		// pad with 0's
		if ( s == str.end() )
		{
			*t++ = '0';
		}
		else
		{
			char c = *s;
			if ( s == str.begin() )
			{
#ifdef WIN32
				*t++ = toupper ( (int)c );
#else
				*t++ = std::toupper ( (int)c );
#endif
			}
			else
			{
				// the cast is to make sure characters > 127
				// still work..
				c = lookup[(unsigned char)c];

				// ignore irrelevant characters and duplicates
				if (c != '0' && c != last )
					*t++ = c;
			}
			last = c;
			++s;
		}
	}

	return retval;
}

/* Normal external interface */
string soundex ( const string & str)
{
	return ( nsoundex ( str, 4 ) );
}

} // end of JLeffler namespace

