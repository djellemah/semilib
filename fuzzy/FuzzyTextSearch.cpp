#pragma warning(disable: 4786)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

#include "MatchFunction.h"
#include "Soundex.h"
#include "FileUtils.h"

#include "Line.h"

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

void help( char * argv[] )
{
	cout << argv[0] << endl;
	exit ( 0 );
}

int main( int argc, char * argv[] )
{
	if ( argc != 4 )
	{
		help( argv );
	}
	else
	{
		const char * inputs = argv[1];
		const char * word = argv[2];
		const char * percent = argv[3];

		if ( !FileUtils::exists ( inputs ) )
		{
			cout << "Couldn't find file " << inputs << endl;
		}

		// input collection
		ifstream is ( inputs );

		// output collection
		typedef multimap<float,string> Results;
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
//			, Soundex ( argv[2] )
		);

/*
		// output the first two results
		cout << *(results.rbegin()) << endl;
		cout << *(++results.rbegin()) << endl;
*/
		// output all results
		for_each (
			results.begin()
			, results.end()
			, Out( cout, atof ( percent ) )
		);
/*
		// This should work, but it complains about not finding
		// the appropriate overloaded >> operator. Which is weird
		// and I can't figure it out.
		copy (
			results.begin()
			, results.end()
			, ostream_iterator<Results::value_type> ( cout, "\n" )
		);
*/
	}
	return 0;
}
