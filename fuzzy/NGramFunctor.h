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

#ifndef MatchFunction_h
#define MatchFunction_h

#include <vector>
#include <map>

using namespace std;

#include "fuzzydlldef.h"

#include "NGram.h"

class FUZZY_DLL_API Ranking : public pair<float,string>
{
public:
	Ranking ( const float & f, const string & s )
		: pair<float,string> ( f, s )
	{
	}
	
	Ranking & operator = ( const Ranking & other )
	{
		first = other.first;
		second = other.second;
		return *this;
	}
	
	bool operator == ( const Ranking & other ) const
	{
		return first == other.first;
	}
	
	bool operator < ( const Ranking & other ) const;
};

ostream & operator << ( ostream &, const Ranking & );

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
