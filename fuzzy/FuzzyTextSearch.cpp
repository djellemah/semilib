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
#include <map>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

#include <FileUtils.h>
#include <Line.h>

#include "MatchFunction.h"
#include "Soundex.h"


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

typedef multimap<float,string> Results;

// for outputting an element of the results array
bool match_compare ( Results::key_type a, Results::key_type b )
{
    //return a.first > b.first;
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

void help( char * argv[] )
{
	cout << argv[0] << endl;
	exit ( 0 );
}

void test()
{
	typedef map<int,float> TestMap;
	TestMap testmap;
	sort<TestMap::reverse_iterator> (
		testmap.begin()
		, testmap.end()
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
//			, Soundex ( argv[2] )
		);

		// output the first two results
/*
		cout << *(results.rbegin()) << endl;
		cout << *(++results.rbegin()) << endl;
*/		
		
		// sort results into match order, from best to worst

/*
		sort<Results::reverse_iterator> (
			results.rbegin()
			, results.rend()
//			, match_compare
		);
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
