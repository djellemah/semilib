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

#ifndef SoundexFunctor_h
#define SoundexFunctor_h

#include <vector>

using namespace std;

#include "fuzzydlldef.h"
#include "Ranking.h"

/**
	arbitrary Soundex. Makes a soundex of n characters
	\ingroup match
*/
FUZZY_DLL_API string nsoundex ( const string & str, unsigned int n );

/**
	normal Soundex. Makes a soundex of 4 characters
	\ingroup match
*/
FUZZY_DLL_API string soundex(const string & str);

/**
	Soundex match functor, to be used via the transform algorithm.
	\ingroup match
*/
class FUZZY_DLL_API SoundexFunctor
{
public:
	SoundexFunctor ( const string & toMatch );

	Ranking operator () ( const string & element );

protected:
	/**
		remove all punctuation and accents. Then remove
		all spaces. Then append _ to the beginning and end
		of the string
	*/
	string PrepareTheString ( const string & OriginStr );

private:
	string _toMatch;
	string _theString;
};

#endif
