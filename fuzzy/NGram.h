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

#ifndef NGram_h
#define NGram_h

#include <utility>
#include <string>

using namespace std;

#include "fuzzydlldef.h"

class FUZZY_DLL_API NGram
{
public:
	// construct this with a particular length, then call match
	// longer length means the words must correspond more closely
	NGram ( int defaultLength = 3 )
		: length ( defaultLength )
	{
	}

	/*
		pair.first contains the ngram match value for this string
		pair.second contains the largest possible ngram value match for this string
	*/
	pair<int,int> match ( const string & a, const string & b )
	{
		if ( a.length() < b.length() )
			return doMatch ( a,b );
		else
			return doMatch ( b,a );
	}

	bool operator < ( const NGram & other ) const
	{
		return length < other.length;
	}

	bool operator == ( const NGram & other ) const
	{
		return length == other.length;
	}

protected:
	// find a percentage match of a in b
	// length of b should be less than length of a

	/**
		pair.first contains the ngram match value for this string
		pair.second contains the largest possible ngram value match for this string
	*/
	pair<int,int> doMatch ( const string & b, const string & a );

private:
	int length;
};


#endif
