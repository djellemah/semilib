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

#ifndef Timer_h
#define Timer_h

#ifdef _MSVC
#include "minwin.h"
#else
#include <sys/time.h>
#endif

/**
	millisecond timer class. Works OK in windows, not so good with
	glibc-2.2.5 and linux-2.4.18.
	
	\todo fix GNU timings
*/
class Timer
{
public:
	
	/**
		start the timer running if true, or just create the
		object if false.
	*/
	Timer( bool shouldStart = true )
	{
		if ( shouldStart )
			start();
	}

	/**
		Start the timer running.
	*/
	unsigned start()
	{
#ifdef _MSVC
		_start = ::GetTickCount();
#else
		gettimeofday ( &_start, 0 );
#endif
		running = true;
		return _start.tv_sec * 1000000 + _start.tv_usec;
	}

	/**
		returns the number of milliseconds since start
		also stops the timer running
	*/
	unsigned int stop()
	{
#ifdef _MSVC
		_stop = ::GetTickCount();
#else
		gettimeofday ( &_stop, 0 );
#endif
		running = false;
		return elapsed();
	}

	/**
		returns the number of milliseconds since start
	*/
	unsigned int elapsed()
	{
		if ( running )
		{
#ifdef _MSVC
			DWORD current = ::GetTickCount();
			return current - _start;
#else
			struct timeval current;
			gettimeofday ( &current, 0 );
			return ( current.tv_sec * 1000000 + current.tv_usec ) - ( _start.tv_sec * 1000000 + _start.tv_usec );
#endif
		}
		else
		{
#ifdef _MSVC
			return _stop - _start;
#else
			return ( _stop.tv_sec * 1000000 + _stop.tv_usec ) - ( _start.tv_sec * 1000000 + _start.tv_usec );
#endif
		}
	}

private:
	struct timeval _start;
	struct timeval _stop;
	bool running;
};

#endif
