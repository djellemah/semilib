#include "Ranking.h"

#include <iomanip>

FUZZY_DLL_API ostream & operator << ( ostream & os, const pair<double,string> & r )
{
	os << setw ( 8 ) << setprecision ( 4 ) << fixed << showpoint;
	os << r.first * 100.0;
	os << "%";
	os << " " << r.second;
	return os;
}

bool Ranking::operator < ( const Ranking & other ) const
{
	if ( first == other.first )
		return second < other.second;
	else
		return first < other.first;
}

