/*
Copyright (C) 1998, John Anderson

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

#ifndef Change_h
#define Change_h

#include <stdexcept>

using std::runtime_error;

template <class T>
class Change
{
public:
	Change()
		: _recalculate ( true )
	{
	}

	Change( const T & other )
	{
		operator = ( other );
	}

	Change<T> &	operator = ( const T & other )
	{
		_recalculate = false;
		_data = other;
		return *this;
	}

	Change<T> &	operator = ( const Change<T> & other )
	{
		_recalculate = other._recalculate;
		_data = other._data;
	}

	const bool recalculate() const
	{
		return _recalculate;
	}

	Change<T> & recalculate ( const bool other )
	{
		_recalculate = other;
		return *this;
	}

	operator const T & ()
	{
		return data();
	}

protected:
	const T & data()
	{
		if ( recalculate() )
		{
			throw runtime_error ( "Don't forget to recalculate..." );
		}
		return _data;
	}

private:
	bool _recalculate;
	T _data;
};

#endif
