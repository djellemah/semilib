#ifndef _WIN32
#include <unistd.h>
#else
#include "minwin.h"
#endif

#include "utils.h"

#include <iostream>
#include <vector>

using namespace std;

int main ( int argc, char * argv[] )
{
	// 5 minutes, 23 seconds
	
	int millis;
	if ( argc == 3 )
	{
		millis = atoi ( argv[1] ) * 60 * 1000 + atoi ( argv[2] ) * 1000;
	}
	else
	{
		millis = 5 * 60 * 1000 + 23 * 1000;
	}
	
	cout << "5:32 " << strftime ( millis / 1000, "%M:%S" ) << endl;
	
	return 0;
}
