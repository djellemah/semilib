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

#ifndef StaticInit_h
#define StaticInit_h

#include <memory>

using namespace std;

#include "utilsdlldef.h"

/**
	This provices a once-off initialisation of something
	when static members can't be relied upon and optimised access
	to the data. This is done using a function
	pointer which points to different functions for the first
	call when all the initialisation is done, and for subsequent
	calls when all it has to do is return the object that has
	already been constructed.
	\ingroup utils
*/
template <class Object, class Allocator = allocator<Object> >
class UTILS_DLL_API StaticInit
{
public:
	StaticInit()
	{
	}

	~StaticInit()
	{
	}
	/**
		This uses one function for the first call
		and then the other function for all subsequent calls.
		This avoids the overhead of having to check for
		_item == 0 on every call to getFreeList
	*/
	static Object & getStaticItem()
	{
		return whichTime();
	}
	
	Object & operator () ()
	{
		return getStaticItem();
	}

private:
	
	/// The instance is stored here
	static Object * _item;

	/// pointer to which function to use
	static Object & (*whichTime)();

	/// the function called on subseqent times
	static Object & subsequentTime()
	{
		return *_item;
	}

	/// the function called the first time
	static Object & firstTime()
	{
		Allocator a;

		// don't use a.allocate because we then run into an endless loop
		// if smartnew.cpp is being used.
		_item = a.allocate ( sizeof ( Object ), 0 );
		//_item = static_cast<Object*>( calloc ( 1, sizeof ( Object ) ) );
		a.construct ( _item, Object() );
		
		// make sure we don't get null here
		assert(_item != 0);

		// otherwise make sure we go to the other function next time
		whichTime = subsequentTime;

		return *_item;
	}
};

template <class Object, class Allocator>
Object * StaticInit<Object, Allocator>::_item;

template <class Object, class Allocator>
Object & (*StaticInit<Object, Allocator>::whichTime)() = StaticInit<Object, Allocator>::firstTime;

#endif
