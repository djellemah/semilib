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

#ifndef MarkStream_h
#define MarkStream_h

#include <iostream>

using namespace std;
/**
	This is a stream marker which acquires a position in an istream
	on construction, and restores that position on destruction. Obviously
	this relies on seekg to be possible with that stream.
*/
class MarkStream
{
public:
	MarkStream ( istream & _is, bool _active = true )
		: is ( _is )
		, active ( _active )
	{
		pos = is.tellg();
	}

	/// restore the stream to the constructed position
	void restore ()
	{
		is.seekg ( pos );
	}

	/// set a new mark
	void set ()
	{
		pos = is.tellg();
	}
	
	/// make sure we don't go back to the mark on destruction
	void release()
	{
		active = false;
	}

	~MarkStream ()
	{
		if ( active )
			restore ();
	}

private:
	long pos;
	istream & is;
	bool active;
};


#endif
