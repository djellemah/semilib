#include "Mutex.h"

#ifdef _WIN32
#include "minwin.h"
#else
#include <errno.h>
#endif

/**
	create the Mutex object
*/
Mutex::Mutex()
{
#ifdef _WIN32
	::InitializeCriticalSection ( &criticalSection );
#else
	pthread_mutexattr_t attr;
	pthread_mutexattr_init ( &attr );
	pthread_mutexattr_settype ( &attr, PTHREAD_MUTEX_RECURSIVE );
	
	pthread_mutex_init ( &_mutex, &attr );
	
	pthread_mutexattr_destroy ( &attr );
#endif
}

/**
	Lock the Mutex object
*/
void Mutex::lock()
{
#ifdef _WIN32
	::EnterCriticalSection ( &criticalSection );
#else
	pthread_mutex_lock ( &_mutex );
#endif
}

bool Mutex::trylock()
{
	bool retval = false;
#ifdef _MSC_VER
	BOOL result = ::TryEnterCriticalSection ( &criticalSection );
	return result != 0;
#else
	int result = pthread_mutex_trylock ( &_mutex );
	return result != EBUSY;
#endif
}

/**
	release the Mutex object
*/
void Mutex::release()
{
#ifdef _WIN32
	::LeaveCriticalSection ( &criticalSection );
#else
	pthread_mutex_unlock ( &_mutex );
#endif
}

/**
	delete the Mutexhronisation object
*/
Mutex::~Mutex()
{
#ifdef _WIN32
	::DeleteCriticalSection ( &criticalSection );
#else
	pthread_mutex_destroy ( &_mutex );
#endif
}
