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
#pragma warning(disable: 4290)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

#include "FileUtils.h"
#include "Line.h"

using namespace Utils;

#include "NGramFunctor.h"
#include "SoundexFunctor.h"
#include "Ranking.h"

/**
	Various string matching techniques that can be applied
	to find the best match for a string in a collection of
	strings.
	
	\code
	vector<string> strings;
	vector<Ranking> results;
	string word;
	
	transform (
		strings.begin()
		, strings.end()
		, insert_iterator<vector<Ranking> > ( results, results.begin() )
		, NGramFunctor(word)
	);
	\endcode
	
	will result in a set of rankings <code>pair<float,string></code>,
	each of which contains
	a string and a percentage match for that string against
	<code>word</code>
	
	NGram matching is at least O(N), so you could use Soundex to reduce the number
	of strings for NGram to match, and use NGram to come up with a best match
	when compared to the others in the set. In other words Soundex allows for
	index-type searching, whereas NGram requries exhaustive searching. Although
	NGram does a better job of matching strings where there are spelling mistakes
	and typos.

	\defgroup match
*/

// for outputting an element of the results array
struct Out
{
	Out ( ostream & os, double threshold = 0.0 )
		: _os ( os )
		, _threshold ( threshold )
	{
	}

	void operator ()( const pair<float,string> & value )
	{
		if ( value.first > _threshold )
			_os << value << endl;
	}

private:
	ostream & _os;
	double _threshold;
};

typedef vector <Ranking> Results;

void help( char * argv[] )
{
	cout << "test <file> <word>" << endl;
	exit ( 0 );
}

template<class Iterator, class Functor>
void printBestMatches ( Iterator begin, Iterator end, Functor match )
{
	// output collection
	Results results;

	// create a collection of results from the input
	transform (
		begin
		, end
		, insert_iterator<Results> ( results, results.begin() )
		, match
	);

	// sort results into match order, from worst to best
	sort ( results.begin() , results.end() );
	
	// output best 10 (or number of elements in list) results to stdout
	copy (
		results.rbegin()
#ifdef WIN32
// min was a define in windows.h or something. Fucken.
		, results.rbegin() + _MIN ( results.size(), (size_t)10 )
#else
		, results.rbegin() + min ( results.size(), (size_t)10 )
#endif
		, ostream_iterator<Results::value_type> ( cout, "\n" )
	);
}

int main( int argc, char * argv[] )
{
	if ( argc < 3 || argc > 4 )
	{
		help( argv );
	}
	else
	{
		const char * inputs = argv[1];
		const char * word = argv[2];
		const char * percent = argc == 4 ? argv[3] : "0.0";

		if ( !FileUtils::exists ( inputs ) )
		{
			cout << "Couldn't find file " << inputs << endl;
			return 1;
		}
		
		// input stream (collection, see next comment)
		ifstream is ( inputs );
		
		/*
			Line is a descendant of string that reads one line
			with it's >> operator, rather than the next token.
			so when used with istream_iterator<Line>, the
			input file is a collection of strings.
		*/
		
		cout << "Doing ngram matching for " << word << endl;
		// print ngram matches
		printBestMatches (
			istream_iterator<Line>(is)
			, istream_iterator<Line>()
			, NGramFunctor ( word )
		);
		cout << "-------------------------------" << endl;
		
		// for some reason, we can't reuse is from above
		ifstream sis ( inputs );

		cout << "Doing soundex matching for " << word << endl;
		// print soundex matches
		printBestMatches (
			istream_iterator<Line>(sis)
			, istream_iterator<Line>()
			, SoundexFunctor ( word )
		);
		
		cout << "all tests OK" << endl;
	}
	return 0;
}
