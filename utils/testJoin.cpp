#include "utils.h"

#include <iostream>
#include <vector>

using namespace std;

int main ( int argc, char * argv[] )
{
	vector<string> values;
	values.push_back ( "one" );
	values.push_back ( "two" );
	values.push_back ( "three" );
	
	cout << join ( values, argc ) << endl;
	
	return 0;
}
