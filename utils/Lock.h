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
#include "minwin.h"
#include "utilsdlldef.h"
#endif

namespace semilib
{

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
	Lock();

	Lock ( Mutex & aMutex );

	void acquire ( Mutex & aMutex );

	void release ();

	/**
		A blocking lock has always acquired the lock
		if this can be called.
	*/
	virtual bool acquired() const
	{
		return true;
	}
	
	/**
		Only release the mutex if _owned
		is true, ie this instance was constructed
		with a mutex.
	*/
	virtual ~Lock();

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
	virtual bool acquire();
	
	// whether or not we should release the lock
	bool _owned;

	/// Only release the lock when count gets back down to 0
	int _count;

private:
	Mutex * _mutex;
};

}

#endif
