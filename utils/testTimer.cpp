#ifndef _WIN32
#include <unistd.h>
#else
#include "minwin.h"
#endif

#include "utils.h"
#include "Timer.h"

#include <iostream>
#include <vector>

using namespace std;
using namespace semilib;

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
