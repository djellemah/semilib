#pragma warning(disable: 4786)

#include "MatchFunction.h"
#include "matchfunctions.h"

#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>

using namespace std;

map<int, NGram> MatchFunction::grams;

MatchFunction::MatchFunction ( const string & toMatch )
	: _toMatch ( PrepareTheString ( toMatch ) )
{
	if ( grams.empty() )
	{
		for ( int i = 2; i <= 10; ++i )
		{
			// pre-create ngram matchers
			grams[i] = NGram ( i );
		}
	}
}

Ranking MatchFunction::operator () ( const string & element )
{
	// strip out punctuation and accented characters
	string line = PrepareTheString ( element );
#ifdef WIN32
	switch ( _MIN ( line.length(), _toMatch.length() ) )
#else
	switch ( min ( line.length(), _toMatch.length() ) )
#endif
	{
	case 0:
	case 1:
	case 2:
	case 3:
		return Ranking ( 0.0f, element );

	case 4:
	case 5:
	case 6:
		if ( abs ( line.length() - _toMatch.length() ) > 2 )
			return Ranking ( 0.0f, element );

	default:
		if ( abs ( line.length() - _toMatch.length() ) > 3 )
			return Ranking ( 0.0f, element );
	}

	// do all n-grams from 2 through 7 or the smallest length, whatever is first
/*
	for ( int i = 2; i <= 7 && i <= _cpp_min ( line.length(), _toMatch.length() ); ++i )
	{
		results.push_back ( grams[i].match( line, _toMatch ) );
	}
*/
	// In the original algorithm
/*
	results.push_back ( grams[3].match( line, _toMatch ) );
	results.push_back ( grams[_toMatch.length() < 7 ? 2 : 5].match( line, _toMatch ) );
*/
	// clear out previous results
	results.clear();

	// - 2 to igmore the _ and the _ on either side
	switch ( _toMatch.length() - 2 )
	{
		// these should have already been dealt with
		// in the previous switch. But leave them here anyway
		case 0:
		case 1:
		case 2:
			return Ranking ( 0.0, element );

		case 3:
		case 4:
		case 5:
			results.push_back ( grams[2].match( line, _toMatch ) );
			break;
		case 6:
		case 7:
			results.push_back ( grams[2].match( line, _toMatch ) );
			results.push_back ( grams[3].match( line, _toMatch ) );
			break;
		case 8:
		case 9:
			results.push_back ( grams[2].match( line, _toMatch ) );
			results.push_back ( grams[4].match( line, _toMatch ) );
			break;
		case 10:
		case 11:
		case 12:
			results.push_back ( grams[2].match( line, _toMatch ) );
			results.push_back ( grams[5].match( line, _toMatch ) );
			break;
		default:
			results.push_back ( grams[2].match( line, _toMatch ) );
			results.push_back ( grams[_toMatch.length()/2].match( line, _toMatch ) );
			break;
	}

	// calculate match totals
/*
	OneResult total;
	total = accumulate ( results.begin(), results.end(), total );
	// need cast to float to make sure the division is done properly
	float similarity = (float)total.first / total.second;
*/
	// This section calculates the similarity as a float
	// for each ngram (DividedSum), then calculates the average.
	DividedSum<float> total;

	total = accumulate ( results.begin(), results.end(), total );

	// calculate average match
	float similarity = total / results.size();

	// return percentage match and original string
	return Ranking ( similarity, element );
}

string MatchFunction::PrepareTheString(const string & OriginStr)
{
	string retval;

	// change all punctuation things to spaces
	transform (
		OriginStr.begin()
		, OriginStr.end()
		, insert_iterator<string> ( retval, retval.begin() )
		, stripThings
	);

	// remove spaces
	// retval = string ( retval.begin(), remove ( retval.begin(), retval.end(), ' ' ) );

	// append and prepend an _
	return "_" + retval + "_";
}
