#ifndef Mutex_h
#define Mutex_h

#ifdef _WIN32
	#define WIN32_LEAN_AND_MEAN
	#define VC_EXTRA_LEAN
	#include <windows.h>
#else
	#include <pthread.h>
#endif

#include "utilsdlldef.h"

/**
	Mutex class. Create on of these whenever a critical section is
	necessary. Then, on entering the critical section do:
	\code
		Lock lock ( mutex );
	\endcode
	the Mutex will be released when lock goes out of scope.

	The Mutex object should be in a scope outside that of lock. A good
	way to do it is to make Mutex class member, and then for each
	method that needs to control access, have the above line as the
	first line in the method implementation.
	
	For win32, this uses a CriticalSection object. For pthreads, it
	uses a mutex object.
*/
class UTILS_DLL_API Mutex
{
public:

	/**
		create the Mutex object
	*/
	Mutex();

	/**
		Mutex the Mutex object
	*/
	void lock();

	/**
		release the Mutex object
	*/
	void release();

	/**
		Do an async lock on the Mutex object. Return true
		if the lock attempt succeeded, false otherwise.
	*/
	bool trylock();

	/**
		delete the Mutex object
	*/
	~Mutex();

private:
	/// where the OS-level Mutex object is stored
#ifdef _WIN32
	CRITICAL_SECTION criticalSection;
#else
	pthread_mutex_t _mutex;
#endif
};

#endif
