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

class UTILS_DLL_API Timer
{
public:
	Timer( bool shouldStart = true )
	{
		if ( shouldStart )
			start();
	}

	unsigned start()
	{
		_start = ::GetTickCount();
		running = true;
		return _start;
	}

	// returns the number of seconds since start
	// also stops the timer running
	unsigned int stop()
	{
		_stop = ::GetTickCount();
		running = false;
		return elapsed();
	}

	// returns the number of milliseconds since start
	unsigned int elapsed()
	{
		if ( running )
		{
			DWORD current = ::GetTickCount();
			return current - _start;
		}
		else
		{
			return _stop - _start;
		}
	}

private:
	unsigned int _start;
	unsigned int _stop;
	bool running;
};


#endif