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

#ifndef Ranking_h
#define Ranking_h

#include <utility>
#include <string>
#include <iostream>

using namespace std;

#include "fuzzydlldef.h"

// disable non dll-interface warnings
#pragma warning(disable: 4275)

/**
	This class stores the results of a matching run
*/
class FUZZY_DLL_API Ranking : public pair<double,string>
{
public:
	Ranking ( const double & f, const string & s )
		: pair<double,string> ( f, s )
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
		return first == other.first && second == other.second;
	}
	
	bool operator < ( const Ranking & other ) const;
};

FUZZY_DLL_API ostream & operator << ( ostream &, const pair<double,string> & );

#endif
