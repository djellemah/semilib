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

#include <typeinfo>
#include <iostream>
#include <string>

// local include files
#include "SmartPointer.h"
#include "Persistence.h"

#pragma hdrstop

using namespace std;

/**
	generic polymorphous (perverse?) persistence manager. Allows
	objects to be streamed out and read in. Uses the typeid operator
	to write out a name that can be used to construct an instance
	so it can be read in. Relies on the object having a default
	constructor and overloaded operators >> and <<. It's mainly so
	you can read in a bunch of descendant objects from a stream and
	have them come back polymorphously.
<p>
	It also relies on each class that needs to be persistent having the
	following definitions anywhere in the linkage of the program:
	<pre>
	namespace
	{
		Constructor&lt;Object&gt; instance;
	}
	</pre>
	where Object is the name of the class to be made persistent. The namespace
	is just to ensure that 'instance' doesn't clash with any other names. You
	can actually call it anything you like: x, i, n, a, b, c, someVeryLongIdentifier.
<p>
	Top persist the class you have to have something like
	<pre>
	pfn ( ostream & os )
	{
		PersistenceManager&lt;Object&gt; pm;
		Object o;
		pm.persist ( os, o );
	}
	</pre>
	and to restore it, something like
	<pre>
	rfn( istream & is )
	{
		PersistenceManager&lt;Object&gt; pm;
		SmartPointer&lt;Object&gt; optr = pm.restore ( is );
	}
	</pre>
*/
template <class Persistent>
class PersistenceManager
{
public:
	PersistenceManager()
	{
	}

	/// persist an object on the given stream.
	virtual void persist ( ostream & os, const Persistent & object ) const;

	/**
		restores an object from the given stream. You get back a pointer
		because you might be getting a descendant of the object this
		persistence manager can deal with.
	*/
	virtual SmartPointer<Persistent> restore ( istream & is ) const;

	/// For debuggin. Write a list of all objects that this persistence manager deals with
	void writePersistentObjectNames ( ostream & os ) const;

protected:

	/**
		makes a new object depending on the type information coming
		from the stream.
	*/
	virtual Persistent * makeNewObject( const string & line ) const;
};

// have to do this cos MSVC 5.0 doesn't support
// the 'export' keyword for templates.
#include "PersistenceManager.cpp"

#endif
