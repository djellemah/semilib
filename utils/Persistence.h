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

#ifndef Persistence_h
#define Persistence_h

#include <typeinfo>
#include <string>
#include <map>
#include <functional>

using namespace std;

#include "utilsdlldef.h"
#include "SmartPointer.h"

/**
	This is used to create an instance of an object whose name is
	the key in a map of name to an object which can create an instance
	of the named class.
*/
class PERSISTENCE_DLL_API AbstractConstructor
{
public:
	/**
		the third template parameter shouldn't really be necessary
		but gcc doesn't seem to support default initialisers for templates.
	*/
	typedef map<string, AbstractConstructor*, less<string> > PersistentObjects;

	AbstractConstructor();
	virtual ~AbstractConstructor();

	/**
		the Constructor template object overrides this to
		instantiate a class. Because of this method, AbstractConstructor
		and Constructor are what are know as function objects.
	*/
	virtual void * operator ()()
	{
		throw runtime_error ( "No instance of the constructor object" );
		return NULL;
	}

	/**
		get a reference to the map of names to classes.
	*/
	static PersistentObjects & getPersistentObjects();

protected:
	static SmartPointer<PersistentObjects> persistentObjects;
	static long refcount;
};

/**
	A template class that add itself to the map
	of constructor classes in AbstractConstructor, and which
	is able to create an instance of the Persistent class.
*/
template <class Persistent>
class PERSISTENCE_DLL_API Constructor : public AbstractConstructor
{
public:
	/// create a new instance of Persistent.
	virtual void * operator ()()
	{
		return new Persistent;
	}

	/**
		only because I'm too lazy to go and
		change an earlier hack so g++ will cope
		_name is a dummy parameter that doesn't actually get used
	*/
	Constructor( const char * _name )
	{
		string temp = typeid ( Persistent ).name();
		getPersistentObjects()[temp] = this;

		// add this so that older files work properly
		// should be able to remove it at some point
		getPersistentObjects()["class " + temp] = this;
	}

	/**
		At least one call must be made to this constructor in order that
		a PersistenceManager can restore instances of class Persistent.
	*/
	Constructor()
	{
		string temp = typeid ( Persistent ).name();
		getPersistentObjects()[temp] = this;

		// add this so that older files work properly
		// should be able to remove it at some point
		getPersistentObjects()["class " + temp] = this;
	}
};

#endif
