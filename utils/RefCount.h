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

#ifndef RefCount_h
#define RefCount_h

#include <iostream>
#include <string>
#include <map>

using namespace std;

#include "Lock.h"
#include "Mutex.h"
#include "SmartPointer.h"

// disable 'multiple assignment operator' warning
#pragma warning(disable: 4522)

namespace semilib
{

/**
	a reference count pointer object. More overhead than
	a SmartPointer, but safer in certain situations. Like
	multithreading, in fact it uses thread synchronisation
	objects Lock and Sync.
<p>
	Acts like SmartPointer in many ways in that an instance of RefCount
	is almost completely interchangeable for the pointer it's reference
	counting. See SmartPointer documentation for more details.
	\ingroup smartpointer
*/
template <class T, class Deallocator = NormalDelete<T> >
class RefCount
{
public:
	typedef map<T*,unsigned int> References;

	// Default Constructor
	RefCount ( T * _ptr = 0 )
		: _ptr ( _ptr )
	{
		increment();
	}

	// Copy Constructor
	RefCount ( const RefCount & other )
		: _ptr ( 0 )
	{
		operator = ( other );
	}

	// Destructor
	virtual ~RefCount()
	{
		// lock from here because we want to changed _references
		// as well. If Lock isn't re-entrant, we have a problem
		// because decrement() also puts a lock on _sync.

		Lock aLock ( mutex() );
		decrement();
	}

	/**
		to avoid problems with the combination of a non-explicit
		constructor and a conversion operator. See SmartPointer
		for details.
	*/
	const RefCount & operator = ( RefCount & other )
	{
		return operator = ( const_cast<const RefCount &>(other) );
	}

	// assignment operator
	const RefCount & operator = ( const RefCount & other )
	{
		Lock aLock ( mutex() );
		if ( _ptr != other._ptr )
		{
			decrement();
			_ptr = other._ptr;
		}
		increment();
	
		return *this;
	}

	/// need this for storing instances in STL containers
	bool operator < ( const RefCount & other ) const
	{
		return _ptr < other._ptr;
	}

	/// need this for storing instances in STL containers
	bool operator == ( const RefCount & other ) const
	{
		return _ptr == other._ptr;
	}

	// for comparing to things being pointed to
	bool operator == ( const T * other ) const
	{
		return _ptr == other;
	}

	/**
		member access operator. Obviously
		won't work with T as a non-class object
	*/
	T * operator -> () const
	{
		return _ptr;
	}

	/// a dereference operator
	T & operator * ()
	{
		return *_ptr;
	}

	/// another dereference operator
	const T & operator * () const
	{
		return *_ptr;
	}

	/**
		conversion operator. Use an instance
		of this object wherever a T * is expected
	*/
	operator T * () const
	{
		return _ptr;
	}

	T * data () const
	{
		return _ptr;
	}

	References & references()
	{
		Lock aLock ( mutex() );
		if ( _references == 0 )
			_references = new References;
		return *_references;
	}

	References & references() const
	{
		Lock aLock ( mutex() );
		if ( _references == 0 )
			_references = new References;
		return *_references;
	}

	/**
		mostly for debugging the class. Prints the addresse
		being pointed to and the refcounts for the address.
	*/
	void write ( ostream & os ) const
	{
		os << hex << _ptr << ": " << references()[_ptr];
	}

protected:
	/**
		decrement the reference count for the _ptr held by this
		instance.
	*/
	void decrement()
	{
		Lock aLock ( mutex() );
		if ( _ptr == 0 ) return;

		if ( --references()[_ptr] == 0 )
		{
			references().erase ( _ptr );
			deallocator() ( _ptr );
			_ptr = 0;
		}
	}

	/**
		increment the reference count for the _ptr held by this
		instance.
	*/
	void increment()
	{
		Lock aLock ( mutex() );
		if ( _ptr == 0 ) return;

		if ( references().find ( _ptr ) != references().end() )
			++references()[_ptr];
		else
			references()[_ptr] = 1;
	}

	Deallocator & deallocator()
	{
		return _deallocator;
	}
	
private:
	T * _ptr;

	/**
		synchronize accesses to class members for multi-threaded situations,
		since that's the most likely place a RefCount object will be used.
	*/
	static Mutex * _mutex;

	static Mutex & mutex()
	{
		if ( _mutex == 0 )
		{
			_mutex = new Mutex;
		}
		return *_mutex;
	}

	/**
		the list of references, which obviously must exist beyond the
		lifetime of any particular RefCount instance. It would be neater
		not to use a pointer here, but then we run into trouble with
		the order in which static objects are constructed.
	*/
	static References * _references;
	
	/**
		So that we can assign custom deallocators
	*/
	Deallocator _deallocator;
};

/**
\ingroup smartpointer
*/
template <class T, class D>
typename RefCount<T,D>::References *
RefCount<T,D>::_references;

/**
\ingroup smartpointer
*/
template <class T, class D>
Mutex *
RefCount<T,D>::_mutex;

/**
	insertion operator
	\ingroup smartpointer
*/
template <class T, class D>
ostream & operator << ( ostream & os, const RefCount<T,D> & aRefCount )
{
	aRefCount.write ( os );
	return os;
}

/**
	extraction operator
	\ingroup smartpointer
*/
template <class T, class D>
istream & operator >> ( istream & is, RefCount<T,D> & aRefCount );

}

#endif
