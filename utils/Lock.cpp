#include "Lock.h"

/**
	create the Lock object
*/
Lock()
{
#ifdef _WIN32
	::InitializeCriticalSection ( &criticalSection );
#endif
}

/**
	lock the Lockhronisation object
*/
void lock()
{
#ifdef _WIN32
	::EnterCriticalSection ( &criticalSection );
#endif
}

/**
	release the Lockhronisation object
*/
void release()
{
#ifdef _WIN32
	::LeaveCriticalSection ( &criticalSection );
#endif
}

/**
	delete the Lockhronisation object
*/
virtual ~Lock()
{
#ifdef _WIN32
	::DeleteCriticalSection ( &criticalSection );
#endif
}
