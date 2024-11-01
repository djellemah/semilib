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

#include "utilsdlldef.h"

#pragma warning ( disable:4251 )

namespace semilib
{

/**
	This class turns bitmap-type options fields into strings.
	Useful for debugging and persistence.

	The format of the string that gets read in is as follows:
	\verbatim
	<flag name><whitespace><integer>
	\endverbatim
	for example:
	\code
	REG_EXTENDED 1
	REG_ICASE 2
	REG_NEWLINE 4
	REG_NOSUB 8
	\endcode
	
	\todo handle both bitmap and value flags
	\ingroup utils
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
	FlagsMapper( const std::string & rhs )
	{
		std::istringstream is ( rhs );
		read ( is );
	}

	/// read the flags in from the specified stream
	FlagsMapper( std::istream & is )
	{
		read ( is );
	}

	/// Provides a string representation of the integer for the defined flags
	std::string stringForFlags ( unsigned long flag ) const;

	/// provides the integer representation of a series of flags
	unsigned long flagForStrings ( const std::string & aString ) const;

	/// provides the string representation for one flag
	std::string operator [] ( unsigned long index ) const
	{
		return stringForOneFlag ( index );
	}

	/// provides the integer representation for one flag
	unsigned long operator [] ( const std::string & rhs ) const
	{
		return flagForOneString ( rhs );
	}

protected:
	void read ( std::istream & is );
	unsigned long flagForOneString ( const std::string & rhs ) const;
	const std::string & stringForOneFlag ( unsigned long flag ) const;
	void stripSpaces ( std::string & rhs ) const;

private:	
	typedef std::map<unsigned long,std::string> FlagsToStrings;
	typedef	std::map<std::string,unsigned long> StringsToFlags;

	FlagsToStrings flagsToStrings;
	StringsToFlags stringsToFlags;

	unsigned long sum;

	/**
		for summing the values in an STL collection. I'm sure this
		must be predefined somewhere...
	*/
	class SumPredicate;
};

}

#pragma warning ( default:4251 )

#endif
