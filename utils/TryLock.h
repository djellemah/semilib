#ifndef TryLock_h
#define TryLock_h

#include "Lock.h"
#include "utilsdlldef.h"

/**
	A try lock. This will never block on a locked mutex,
	but will instead return true from acquired() if the
	mutex was locked, false if another thread has already locked it.
*/
class UTILS_DLL_API TryLock : public Lock
{
public:

	/**
		Doesn't attempt to release the mutex in
		the destructor call
	*/
	TryLock()
	: Lock()
	, _acquired ( false )
	{
	}

	TryLock ( Mutex & aMutex )
	: Lock ()
	, _acquired ( false )
	{
		mutex ( aMutex );
		_owned = acquire();
	}

	virtual bool acquired() const
	{
		return _acquired;
	}

	virtual bool acquire()
	{
		_acquired = mutex().trylock();
		return _acquired;
	}

	virtual ~TryLock()
	{
	}

private:
	// whether or not the lock was acquired
	bool _acquired;
};

#endif

