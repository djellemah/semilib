#ifndef _WIN32
#include <unistd.h>
#else
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include "utils.h"
#include "Timer.h"

#include <iostream>
#include <vector>

using namespace std;

int main ( int argc, char * argv[] )
{
	Timer timer;
#ifndef _WIN32
	sleep ( 5 );
#else
	Sleep ( 5000 );
#endif
	cout << "elapsed: " << timer.elapsed() << endl;
	cout << "stop: " << timer.stop() << endl;
}
