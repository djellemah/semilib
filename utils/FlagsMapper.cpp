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

#pragma warning(disable: 4786)

#include <numeric>
using namespace std;

#include "FlagsMapper.h"

string FlagsMapper::stringForFlags ( unsigned long flag ) const
{
	if ( flag == 0 )
		return "";

	if ( flag > sum )
		throw runtime_error ("There aren't that many possibilities" );

	string temp;
	// iterate through the map adding each string

	map<unsigned long,string>::const_iterator current = flagsToStrings.begin();
	map<unsigned long,string>::const_iterator end = flagsToStrings.end();
	for (; current != end; ++current )
	{
		if ( ( (*current).first & flag ) != 0 )
			temp += (*current).second + " | ";
	}

	// remove the last " | "
	return temp.substr ( 0, temp.length() - 3 );
}

unsigned long FlagsMapper::flagForStrings ( const string & aString ) const
{
	unsigned long flags = 0;
	istringstream is ( aString );
	string temp;
	while ( !is.eof() )
	{
		getline ( is, temp, '|' );
		stripSpaces ( temp );
		flags += flagForOneString ( temp );
	}

	return flags;
}

class FlagsMapper::SumPredicate
{
public:
	SumPredicate()
	{
		thesum = 0;
	}

	void operator () ( StringsToFlags::value_type & element )
	{
		thesum += element.second;
	}

	operator long ()
	{
		return thesum;
	}

private:
	unsigned long thesum;
};

void FlagsMapper::read ( istream & is )
{
	string flagString;
	unsigned long flag;
	while ( ws (is), is.good() )
	{
		is >> flagString >> hex >> flag;
		if ( is.fail() )
			throw runtime_error ( "FlagsMapper encountered an error while parsing input" );
		flagsToStrings[flag] = flagString;
		stringsToFlags[flagString] = flag;
	}

	// no, you can't use accumulate() here
	SumPredicate thesum;
	sum = for_each ( stringsToFlags.begin(), stringsToFlags.end(), thesum );
}

unsigned long FlagsMapper::flagForOneString ( const string & aString ) const
{
	if ( stringsToFlags.find ( aString ) == stringsToFlags.end() )
	{
		ostringstream os;
		os << "No flag for string " << aString;
		throw runtime_error ( os.str() );
	}

	//return stringsToFlags[aString];
	return const_cast<FlagsMapper*>(this)->stringsToFlags[aString];
}

const string & FlagsMapper::stringForOneFlag ( unsigned long flag ) const
{
	if ( flagsToStrings.find ( flag ) == flagsToStrings.end() )
	{
		ostringstream os;
		os << "No string for flag " << flag;
		throw runtime_error ( os.str() );
	}

	return const_cast<FlagsMapper*>(this)->flagsToStrings[flag];
}

void FlagsMapper::stripSpaces ( string & aString ) const
{
	istringstream is ( aString );
	ostringstream os;
	unsigned long next = char_traits<char>::eof();
	while ( next = is.get(), !is.eof())
	{
		if ( !isspace ( next ) )
			os << char_traits<char>::to_char_type ( next );
	}
	aString = os.str();
}
