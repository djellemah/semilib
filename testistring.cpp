#pragma warning(disable: 4786)

#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <locale>

using namespace std;

#include "istring.h"
#include "functions.h"

void main()
{
	string query( "select count (*) from pcodes;" );

	cout << query.find ( "count" ) << endl;
	cout << query.find ( "COUNT" ) << endl;
	cout << query.find ( "Count" ) << endl;
}