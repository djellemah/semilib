/*
Copyright (C) 1998, 1999, 2000 John Anderson

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU Library General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef Lock_h
#define Lock_h

#include <cassert>
#include "Mutex.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRA_LEAN
#include <windows.h>
#include "utilsdlldef.h"
#endif

/**
	A way to lock and release a Mutex object easily. Very ungeneral and mostly
	a quick hack. There are two ways to use it: either constructed with a
	mutex, so that the mutex is release when the instance goes out of scope;
	or using the acquire/release pair of methods when there isn't a clear scope,
	ie in Logger.
*/
class UTILS_DLL_API Lock
{
public:

	/**
		Doesn't attempt to release the mutex in
		the destructor call
	*/
	Lock()
		: _mutex ( 0 )
		, _owned ( false )
	{
	}

	Lock ( Mutex & aMutex )
		: _mutex ( &aMutex )
		, _owned ( true )
	{
		_owned = acquire();
	}

	void acquire ( Mutex & aMutex )
	{
		mutex ( aMutex );
		_owned = acquire();
	}

	void release ()
	{
		if ( _owned )
		{
			mutex().release();
			_owned = false;
		}
	}

	bool acquired() const
	{
		return _owned;
	}
	
	/**
		Only release the mutex if _owned
		is true, ie this instance was constructed
		with a mutex.
	*/
	virtual ~Lock()
	{
		release();
	}

	Mutex & mutex()
	{
		assert ( _mutex != 0 );
		return *_mutex;
	}

	Lock & mutex ( Mutex & aMutex )
	{
		_mutex = &aMutex;
		return *this;
	}

protected:
	
	/**
		Assume that the mutex instance has already been set.
		Return true if the mutex was successfully locked, false
		otherwise.
	*/
	virtual bool acquire()
	{
		mutex().lock();
		return true;
	}
	
	bool _owned;

private:
	Mutex * _mutex;
};

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
	{
	}

	TryLock ( Mutex & aMutex )
	: Lock ( aMutex )
	{
	}

	virtual bool acquire()
	{
		return mutex().trylock();
	}
};

#endif
