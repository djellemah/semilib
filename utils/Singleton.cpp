/**
	\file
	
	This file implements the necessary hackery to allow
	the Singleton to work properly across win32 dlls. Without
	this hackery, the linker decides that each DLL and executable
	making use of the include file gets it's own instance of the
	static data members, fucking things up royally. So this allows
	there to be only one singleton per process, the way things should
	be, rather than one singleton per link target.
	
	If you know a better way to do this, please let me know.
*/
#include "Singleton.h"
#include <map>
#include <algorithm>

using namespace std;

typedef map<string, void*> Instances;
/**
	This is a global set of all singleton instances. DO NOT
	declare this as DLL exportable, or allow it to escape
	from it's DLL.
*/
Instances instances;

/**
	This is a global set of all singleton instances. DO NOT
	declare this as DLL exportable, or allow it to escape
	from it's DLL.
*/
Mutex instancesMutex;

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
