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

/**
	a reference count pointer object. More overhead than
	a SmartPointer, but safer in certain situations. Like
	multithreading, in fact it uses thread synchronisation
	objects Lock and Sync.
<p>
	Acts like SmartPointer in many ways in that an instance of RefCount
	is almost completely interchangeable for the pointer it's reference
	counting. See SmartPointer documentation for more details.
*/
template <class T>
class RefCount
{
public:
	typedef map<T*,unsigned int> References;

	// Default Constructor
	RefCount ( T * _ptr = 0 )
		: _ptr ( _ptr )
	{
		++refcount;
		increment();
	}

	// Copy Constructor
	RefCount ( const RefCount & other )
		: _ptr ( 0 )
	{
		++refcount;
		operator = ( other );
	}

	// Destructor
	virtual ~RefCount()
	{
		// lock from here because we want to changed _references
		// as well. If Lock isn't re-entrant, we have a problem
		// because decrement() also puts a lock on _sync.

		Lock aLock ( _sync );
		decrement();

		if ( --refcount == 0 )
		{
			delete _references;

			// in case someone else wants to use it
			_references = 0;
		}
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
		Lock aLock ( _sync );
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
		Lock aLock ( _sync );
		if ( _references == 0 )
			_references = new References;
		return *_references;
	}

	References & references() const
	{
		Lock aLock ( _sync );
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
		Lock aLock ( _sync );
		if ( _ptr == 0 ) return;

		if ( --references()[_ptr] == 0 )
		{
			references().erase ( _ptr );
			delete _ptr;
			_ptr = 0;
		}
	}

	/**
		increment the reference count for the _ptr held by this
		instance.
	*/
	void increment()
	{
		Lock aLock ( _sync );
		if ( _ptr == 0 ) return;

		if ( references().find ( _ptr ) != references().end() )
			++references()[_ptr];
		else
			references()[_ptr] = 1;
	}

private:
	T * _ptr;

	/**
		synchronize accesses to class members for multi-threaded situations,
		since that's the most likely place a RefCount object will be used.
	*/
	Sync _sync;

	/**
		the list of references, which obviously must exist beyond the
		lifetime of any particular RefCount instance. It would be neater
		not to use a pointer here, but then we run into trouble with
		the order in which static objects are constructed.
	*/
	static References * _references;

	/**
		the reference count for _references. Provided that there is
		at least one instance of RefCount, _references will not be deleted
	*/
	static unsigned long refcount;
};

template <class T>
RefCount<T>::References * RefCount<T>::_references;

template <class T>
unsigned long RefCount<T>::refcount;

// insertion operator
template <class T>
ostream & operator << ( ostream & os, const RefCount<T> & aRefCount )
{
	aRefCount.write ( os );
	return os;
}

// extraction operator
template <class T>
istream & operator >> ( istream & is, RefCount<T> & aRefCount );

#endif
