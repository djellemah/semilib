#ifndef MatchFunction_h
#define MatchFunction_h

#include <vector>
#include <map>

using namespace std;

#include "fuzzydlldef.h"

#include "NGram.h"

typedef FUZZY_DLL_API pair<float,string> Ranking;

/*
	This is a predicate to be used with the STL sum function
*/
struct OneResult : public pair<int,int> 
{
	OneResult ( int a = 0, int b = 0 )
		: pair<int,int> ( a, b )
	{
	}

	OneResult ( pair<int,int> aPair )
		: pair<int,int> ( aPair )
	{
	}

	OneResult operator + ( const OneResult & other )
	{
		OneResult retval ( *this );
		retval += other;
		return retval;
	}

	const OneResult & operator += ( const OneResult & other )
	{
		first += other.first;
		second += other.second;

		return *this;
	}
};

template<class T>
struct DividedSum
{
	DividedSum ()
		: _sum ( 0 )
	{
	}

	DividedSum ( const DividedSum & other )
		: _sum ( other._sum )
	{
	}

	DividedSum ( const T & a, const T & b )
		: _sum ( a / b )
	{
	}

/*
	DividedSum ( const pair<T,T> & aPair )
	{
		_sum = aPair.first / aPair.second;
	}
*/

	// should turn this into a template member
	// as soon as I have a compiler that supports it
	DividedSum ( const pair<int,int> & aPair )
	{
		_sum = (T)(aPair.first) / (T)(aPair.second);
	}

	DividedSum operator + ( const DividedSum & other )
	{
		DividedSum retval ( *this );
		retval += other;

		return retval;
	}

	const DividedSum & operator += ( const DividedSum & other )
	{
		_sum += other._sum;

		return *this;
	}

	DividedSum & operator = ( const DividedSum & other )
	{
		_sum = other._sum;
		return *this;
	}

	operator const T & ()
	{
		return _sum;
	}
private:
	T _sum;
};

/**
	This is to be used via the transform algorithm.
	For example:

	transform (
		begin_input
		, end_input
		, begin_output
		, MatchFunction ( argv[2] )
	);

	output should be a map with the key as the string
	being matched against toMatch, and the value
	as the percentage match
*/
class FUZZY_DLL_API MatchFunction
{
public:
	MatchFunction ( const string & toMatch );

	Ranking operator () ( const string & element );

protected:
	// remove all punctuation and accents. Then remove
	// all spaces. Then append _ to the beginning and end
	// of the string
	string PrepareTheString ( const string & OriginStr );

private:
	string _toMatch;

	// list of results
	vector<pair<int,int> > results;
	static map<int, NGram> grams;
};

#endif
