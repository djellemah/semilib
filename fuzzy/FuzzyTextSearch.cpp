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

#include "MatchFunction.h"
#include "Soundex.h"
#include "Ranking.h"

ostream & operator << ( ostream & os, const pair<float,string> & p )
{
		os << "(" << p.first << "," << p.second << ")";
}

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
// for outputting an element of the results array
/*
bool match_compare ( Results::key_type a, Results::key_type b )
{
    return a.first > b.first;
}

struct SortByMatch
{
	void operator ()( const pair<float,string> & value )
	{
		if ( value.first > _threshold )
			_os << value << endl;
	}

private:
	ostream & _os;
	double _threshold;
};
*/

void help( char * argv[] )
{
	cout << "test file word percent" << endl;
	exit ( 0 );
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

		// input collection
		ifstream is ( inputs );

		// output collection
		Results results;

		// create a collection of results from the input
		// collection, which happens in this case to be an iostream
		// Line is a descendant of string that reads one line
		// with it's >> operator, rather than the next token
		transform (
			istream_iterator<Line>(is)
			, istream_iterator<Line>()
			, insert_iterator<Results> ( results, results.begin() )
			, MatchFunction ( word )
// an alternative to MatchFunction			
//			, Soundex ( word )
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
	return 0;
}
