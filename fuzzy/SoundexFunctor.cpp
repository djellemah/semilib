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

#include <string>
#include <algorithm>

#include <ctype.h>

using namespace std;

#include "Soundex.h"
#include "BasicSoundex.h"
#include "functions.h"
#include "matchfunctions.h"

SoundexFunctor::SoundexFunctor ( const string & toMatch )
	: _toMatch ( PrepareTheString ( toMatch ) )
	, _theString ( toMatch )
{
}

Ranking SoundexFunctor::operator () ( const string & element )
{
	// strip out punctuation and accented characters
	string soundex = PrepareTheString ( element );

	// return percentage match and original string
	double percent = (( soundex == _toMatch ) ? 1.0 : 0.0 );
	return Ranking ( percent, element );
}

string SoundexFunctor::PrepareTheString(const string & original)
{
	string retval;

	// change all punctuation things to spaces
	transform (
		original.begin()
		, original.end()
		, insert_iterator<string> ( retval, retval.begin() )
		, stripThings
	);

	// remove digits (oops)
	remove_if ( retval.begin(), retval.end(), isDigit );

	// strip all spaces
	remove ( retval.begin(), retval.end(), ' ' );

	return nsoundex ( retval.c_str(), 6 );
}
