#include <unistd.h>

#include "utils.h"
#include "Timer.h"

#include <iostream>
#include <vector>

using namespace std;

int main ( int argc, char * argv[] )
{
	Timer timer;
	sleep ( 5 );
	cout << "elapsed: " << timer.elapsed() << endl;
	cout << "stop: " << timer.stop() << endl;
}
