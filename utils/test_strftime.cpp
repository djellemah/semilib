#ifndef _WIN32
#include <unistd.h>
#else
#include "minwin.h"
#endif

#include "utils.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace semilib;

int main ( int argc, char * argv[] )
{
	// 5 minutes, 23 seconds
	
	int millis;
	if ( argc == 3 )
	{
		millis = atoi ( argv[1] ) * 60 * 1000 + atoi ( argv[2] ) * 1000;
		cout << argv[1] <<":" << argv[2];
		cout << " ";
		cout << strftime ( millis / 1000, "%M:%S" );
		cout << endl;
	}
	else
	{
		millis = 5 * 60 * 1000 + 23 * 1000;
		cout << "5:32 ";
		cout << " ";
		cout << strftime ( millis / 1000, "%M:%S" );
		cout << endl;
	}
	
	
	return 0;
}
