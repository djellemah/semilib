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

#pragma warning(disable: 4786)

#include "Singleton.h"
#include "Lock.h"
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/**
	This keeps the order in which singletons were constructed
	so that we can destroy them in reverse order
*/
typedef vector<string> InstanceOrder;
InstanceOrder instanceOrder;


/**
	This is a global set of all singleton instances. DO NOT
	declare this as DLL exportable, or allow it to escape
	from it's DLL.
*/
Mutex instancesMutex;

Mutex & getMutex()
{
	return instancesMutex;
}

/**
	This is a managed container to ensure that the
	singleton instances are deleted on shutdown.
*/
class Instances : public map<string, SingletonBase*>
{
public:
	Instances()
	{
	}

	void cleanup()
	{
		Lock lock ( instancesMutex );
		while ( instanceOrder.size() > 0 )
		{
			string name = instanceOrder.back();
			instanceOrder.pop_back();
			iterator it = find ( name );
			if ( it != end() )
			{
				SingletonBase * base = it->second;
				delete base;
				erase ( it );
			}
		}
	}

	/**
		Clean up singletons in reverse order of construction
	*/
	~Instances()
	{
		cleanup();
	}
};

/**
	This is a global set of all singleton instances. DO NOT
	declare this as DLL exportable, or allow it to escape
	from its DLL.
*/
Instances instances;

bool haveInstance ( const string & name )
{
	return instances.find ( name ) != instances.end();
}

void keepInstance ( const std::string & name, SingletonBase * instance )
{
	instanceOrder.push_back ( name );
	instances[name] = instance;
}

SingletonBase * getInstance ( const std::string & name )
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

void deleteSingletons()
{
	instances.cleanup();
}
