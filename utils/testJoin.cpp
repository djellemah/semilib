#include "utils.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace semilib;

int main ( int argc, char * argv[] )
{
	vector<string> values;
	values.push_back ( "20030510" );
	values.push_back ( "20030510" );
/*
	values.push_back ( "one" );
	values.push_back ( "two" );
	values.push_back ( "three" );
	values.push_back ( "three" );
	values.push_back ( "three" );
	values.push_back ( "three" );
	values.push_back ( "three" );
	values.push_back ( "three" );
*/

	cout << join ( values, "," ) << endl;
	
	return 0;
}
