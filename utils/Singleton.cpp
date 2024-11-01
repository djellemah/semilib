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

#ifdef _MSC_VER

#pragma warning(disable: 4786)

#include "Singleton.h"
#include "Lock.h"
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

#include "utils.h"

using namespace std;
using namespace semilib;

/**
	This is a global set of all singleton instances. DO NOT
	declare this as DLL exportable, or allow it to escape
	from it's DLL.
*/
Mutex * _instancesMutex = 0;

Mutex & semilib::getMutex()
{
	if ( _instancesMutex == 0 )
	{
		_instancesMutex = new Mutex();
	}
	return *_instancesMutex;
}

/**
	This is a managed container to ensure that the
	singleton instances are deleted on shutdown.
*/
class Instances : public map<string, void*>
{
	/**
		This keeps the order in which singletons were constructed
		so that we can destroy them in reverse order
	*/
	typedef vector<string> InstanceOrder;
	InstanceOrder instanceOrder;

public:
	Instances()
	{
	}

	void remove ( const std::string & name )
	{
		Lock lock ( getMutex() );

		// remove the instance order entry
		InstanceOrder::iterator orderit = std::find ( instanceOrder.begin(), instanceOrder.end(), name );
		if ( orderit != instanceOrder.end() )
		{
			instanceOrder.erase ( orderit );
			iterator it = find ( name );
			if ( it != end() )
			{
				void * base = it->second;
				erase ( it );
			}
		}
	}

	
	void add ( const std::string & name, void * instance )
	{
		instanceOrder.push_back ( name );
		operator[] ( name ) = instance;
	}

	/**
		Clean up singletons in reverse order of construction
	*/
	void cleanup()
	{
		Lock lock ( getMutex() );
		while ( instanceOrder.size() > 0 )
		{
			string name = instanceOrder.back();
			instanceOrder.pop_back();
			iterator it = find ( name );
			if ( it != end() )
			{
				void * base = it->second;
				erase ( it );
				delete base;
			}
		}
	}

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
Instances * _instances = 0;

Instances & getInstances()
{
	if ( _instances == 0 )
	{
		_instances = new Instances();
	}
	return *_instances;
}

bool semilib::haveInstance ( const string & name )
{
	Lock lock ( getMutex() );
	return getInstances().find ( name ) != getInstances().end();
}

void semilib::keepInstance ( const std::string & name, void * instance )
{
	getInstances().add ( name, instance );
}

void semilib::removeInstance ( const string & name )
{
	getInstances().remove ( name );
}

void * semilib::getInstance ( const std::string & name )
{
	Lock lock ( getMutex() );
	return getInstances()[name];
}

void semilib::acquireLock()
{
	getMutex().lock();
}

void semilib::releaseLock()
{
	getMutex().release();
}

void semilib::deleteSingletons()
{
	getInstances().cleanup();
}

class SingletonInit
{
public:
	SingletonInit()
	{
		if ( _instancesMutex == 0 )
		{
			_instancesMutex = new Mutex();
		}
		if ( _instances == 0 )
		{
			_instances = new Instances();
		}
	}

	~SingletonInit()
	{
		// reverse order of construction
		delete _instances;
		delete _instancesMutex;
	}
};

namespace {
	SingletonInit init;
}

#if 0

#ifdef _WIN32
#include "minwin.h"
BOOL APIENTRY DllMain(
	HANDLE hModule
	, DWORD  ul_reason_for_call
	, LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
//			cout << "Loading semilib dll" << endl;
			break;
		case DLL_THREAD_ATTACH:
//			cout << "attach thread semilib dll" << endl;
			break;
		case DLL_THREAD_DETACH:
//			cout << "detach thread semilib dll" << endl;
			break;
		case DLL_PROCESS_DETACH:
//			cout << "Unloading semilib dll" << endl;
			break;
	}
	return TRUE;
}
#endif // _WIN32

#endif // if 0

#endif
