#include "Singleton.h"

Instances instances;
Mutex instancesMutex;

using namespace std;

bool haveInstance ( const string & name )
{
	return instances.find ( name ) != instances.end();
}

void keepInstance ( const std::string & name, void * instance )
{
	instances[name] = instance;
}
void * getInstance ( const std::string & name )
{
	return instances[name];
}

void acquireLock()
{
	instancesMutex.lock();
}

void releaseLock()
{
	instancesMutex.release();
}
