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

#ifdef _WIN32
	#include "minwin.h"
#endif

/**
	A way to lock and release a Sync object easily.
*/
class Lock
{
public:

	// Default Constructor
	Lock()
		: _sync ( 0 )
	{
	}

	Lock ( Sync & aSync )
		: _sync ( &aSync )
	{
		sync().lock();
	}

	void acquire ( Sync & aSync )
	{
		sync ( aSync );
		sync().lock();
	}

	void release ()
	{
		sync().release();
	}

	// Destructor
	virtual ~Lock()
	{
		sync().release();
	}

	Sync & sync()
	{
		assert ( _sync == 0 );
		return *_sync;
	}

	Lock & sync ( Sync & aSync )
	{
		_sync = &aSync;
		return *this;
	}

private:
	Sync * _sync;
};

#endif
