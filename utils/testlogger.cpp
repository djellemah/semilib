#include "Mutex.h"
#include "Lock.h"

int main()
{
	Mutex mutex;
	
	Lock lock ( mutex );
}
