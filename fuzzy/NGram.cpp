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

#include "NGram.h"

#include <algorithm>

using namespace std;

#include "SoundexCharLookup.h"

bool soundexMatch ( char a, char b )
{
	return Soundex::lookup[a] == Soundex::lookup[b];
}

pair<int,int> NGram::doMatch ( const string & b, const string & a )
{
	int	count = 0;
	int MaxMatch = 0;
	string::const_iterator beginNgram = a.begin();
	string::const_iterator endNgram = beginNgram + length;

	// Make n-grams from search string and look for these in target
	for(; endNgram <= a.end(); ++beginNgram, ++endNgram )
	{
		string temp ( beginNgram, endNgram );
//		MaxMatch += length;
		// number of potential matches should be incremented
		// once per iteration
		++MaxMatch;

		// search for the ngram in the string, using iterators
//		if ( b.end() != search ( b.begin(), b.end(), beginNgram, endNgram, soundexMatch ) )
		if ( b.end() != search ( b.begin(), b.end(), beginNgram, endNgram ) )
			count++;
	}
	// weight according to n-Gram length
	// ie number of n-grams actually matched * n-gram length
	// and the total number of possible n-gram matches in the string
//	return make_pair ( count * length, MaxMatch );
	return make_pair ( count, MaxMatch );
}
