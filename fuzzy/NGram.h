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

/**
	NGrams are a way of calculating a percentage match
	between two strings. There are some documents Out There
	on the details. This is a fairly simple implementation.
	
	Each ngram is constructed to have a certain length, say n. One string
	is searched for all possible substrings of length n from the other string.
	
	\todo use soundex-type letter proximity and keyboard
	proximity to handle phonetic misspellings and typos.
	
	\todo use proximity of each ngram between the two string to
	alter its goodness-of-fit value.
	
	\todo decide whether to cache ngrams of length n, using the
	Flyweight pattern.
	
	\ingroup match
*/
class FUZZY_DLL_API NGram
{
public:
	/**
		Construct an NGram matcher with length defaultLength
	*/
	NGram ( int defaultLength = 3 )
		: length ( defaultLength )
	{
	}

	/**
		match a against b to given a percentage indication of
		how closely they match.
		@return
		pair.first contains the number of ngrams matched for this string
		pair.second contains the largest possible ngram value match for this string
		pair.first / pair.second will therefore give the percentage match.
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

	/**
		Match a against b, where
		length(b) < length(a).

		@see match
	*/
	pair<int,int> doMatch ( const string & b, const string & a );

private:
	int length;
};

#endif
