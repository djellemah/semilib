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
#ifndef NGramFunctor_h
#define NGramFunctor_h


#include <vector>
#include <map>

using namespace std;

#include "fuzzydlldef.h"

#include "NGram.h"
#include "Ranking.h"

// disable non dll-interface warnings
#pragma warning(disable: 4275)

/**
	This is a predicate to be used with the STL sum function.
	\ingroup match
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

/**
	Calculate (a2/b2) + (a2/b2) + (an/bn).
	\ingroup match
*/
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

#ifdef _MSVC
	DividedSum ( const pair<int,int> & aPair )
	{
		_sum = (T)(aPair.first) / (T)(aPair.second);
	}
#else
	template<class N>
	DividedSum ( const pair<N,N> & aPair )
	{
		_sum = (T)aPair.first / (T)aPair.second;
	}
#endif
	
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
		, NGramFunctor ( argv[2] )
	);

	output should be a collection of Ranking objects

	It would be a good idea to templatise this class so that
	Ranking and string are parameters
	\ingroup match
*/
class FUZZY_DLL_API NGramFunctor
{
public:
	NGramFunctor ( const string & toMatch );

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
