/*
Copyright (C) 1998, 1999, 2000 John Anderson

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU Library General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef FlagsMapper_h
#define FlagsMapper_h

#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

#include "utilsdlldef.h"

/**
	This class turns bitmap-type options fields into strings.
	Useful for debugging and persistence.

	The format of the string that gets read in is as follows:
	<pre>
	&lt;flag name&gt;&lt;whitespace&gt;&lt;integer&gt;
	</pre>
	for example:
	<pre>
	REG_EXTENDED 1
	REG_ICASE 2
	REG_NEWLINE 4
	REG_NOSUB 8
	</pre>
*/
class UTILS_DLL_API FlagsMapper
{
public:
	FlagsMapper()
	{
		sum = 0;
	}

	/**
		read the flags in from the specified string
	*/
	FlagsMapper( const string & aString )
	{
		istringstream is ( aString );
		read ( is );
	}

	/// read the flags in from the specified stream
	FlagsMapper( istream & is )
	{
		read ( is );
	}

	/// Provides a string representation of the integer for the defined flags
	string stringForFlags ( unsigned int flag ) const;

	/// provides the integer representation of a series of flags
	unsigned int flagForStrings ( const string & aString ) const;

	/// provides the string representation for one flag
	string operator [] ( unsigned int index ) const
	{
		return stringForFlags ( index );
	}

	/// provides the integer representation for one flag
	unsigned int operator [] ( const string & aString ) const
	{
		return flagForStrings ( aString );
	}

protected:
	void read ( istream & is );
	unsigned int flagForOneString ( const string & aString ) const;
	const string & stringForOneFlag ( unsigned int flag ) const;
	void stripSpaces ( string & aString ) const;

private:	
	typedef map<unsigned int,string> FlagsToStrings;
	typedef	map<string,unsigned int> StringsToFlags;

	FlagsToStrings flagsToStrings;
	StringsToFlags stringsToFlags;

	unsigned int sum;

	/**
		for summing the values in an STL collection. I'm sure this
		must be predefined somewhere...
	*/
	class SumPredicate;
};

#endif
