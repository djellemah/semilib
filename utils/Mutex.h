#ifndef Mutex_h
#define Mutex_h

#ifdef _WIN32
#error need thread include here
#else
	#include <pthread.h>
#endif

/**
	Mutexhronisation class. Create on of these whenever a critical section is
	necessary. Then, on entering the critical section do:
	<pre>
		Mutex aMutex ( mutex );
	</pre>
	the Mutex will be released when aMutex goes out of scope.

	The Mutex object should be in a scope outside that of aMutex. A good
	way to do it is to make Mutex class member, and then for each
	method that needs to control access, have the above line as the
	first line in the method implementation.

	\todo this is a _WIN32 specific class, but the functionality it uses
	should be available in any thread implementation. So, implement it, already!
*/
class Mutex
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
		release the Mutexhronisation object
	*/
	void release();

	/**
		delete the Mutexhronisation object
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
