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
	a quick hack.
*/
class UTILS_DLL_API Lock
{
public:

	// Default Constructor
	Lock()
		: _mutex ( 0 )
	{
	}

	Lock ( Mutex & aMutex )
		: _mutex ( &aMutex )
	{
		mutex().lock();
	}

	void acquire ( Mutex & aMutex )
	{
		mutex ( aMutex );
		mutex().lock();
	}

	void release ()
	{
		mutex().release();
	}

	// Destructor
	virtual ~Lock()
	{
		mutex().release();
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

private:
	Mutex * _mutex;
};

#endif
