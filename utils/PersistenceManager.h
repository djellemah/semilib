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

#ifndef PersistenceManager_h
#define PersistenceManager_h

#include "SmartPointer.h"
#include "Persistence.h"

#include <typeinfo>
#include <iostream>
#include <string>

namespace semilib
{

/**
	\defgroup persistence Lightweight Persistence

	Minimally instrusive, very lightweight, generic polymorphous
	persistence manager.
	Allows objects to be streamed out and read in. Uses the typeid operator
	to write out a name that can be used to construct an instance
	so it can be read in. Relies on the object having a default
	constructor and overloaded operators >> and <<. It's mainly so
	you can read in a bunch of descendant objects from a stream and
	have them come back polymorphously.

	It also relies on each class that needs to be persistent having the
	following definitions anywhere in the linkage of the program:
	\code
	namespace
	{
		Constructor<Object> instance;
	}
	\endcode
	where Object is the name of the class to be made persistent. The namespace
	is just to ensure that 'instance' doesn't clash with any other names. You
	can actually call it anything you like: x, i, n, a, b, c, someVeryLongIdentifier.

	Top persist the class you have to have something like
	\code
	pfn ( ostream & os )
	{
		PersistenceManager<Object> pm;
		Object o;
		pm.persist ( os, o );
	}
	\endcode
	and to restore it, something like
	\code
	rfn( istream & is )
	{
		PersistenceManager<Object> pm;
		SmartPointer<Object> optr = pm.restore ( is );
	}
	\endcode
*/

/**
	This needs to be define whenever you need to read from or write to
	a persistence stream.
	\ingroup persistence
*/
template <class Persistent>
class PERSISTENCE_DLL_API PersistenceManager
{
public:
	PersistenceManager()
	{
	}

	/// persist an object on the given stream.
	virtual void persist ( std::ostream & os, const Persistent & object ) const;

	/**
		restores an object from the given stream. You get back a pointer
		because you might be getting a descendant of the object this
		persistence manager can deal with.
	*/
	virtual SmartPointer<Persistent> restore ( std::istream & is ) const;

	/// For debugging. Write a list of all objects that this persistence manager deals with
	void writePersistentObjectNames ( std::ostream & os ) const;

protected:

	/**
		makes a new object depending on the type information coming
		from the stream.
	*/
	virtual Persistent * makeNewObject( const std::string & line ) const;
};

}

// have to do this cos MSVC 6.0 doesn't support
// the 'export' keyword for templates.
#include "PersistenceManager.cpp"

#endif
