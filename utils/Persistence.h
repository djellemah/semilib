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

#include "utilsdlldef.h"
#include "SmartPointer.h"

#ifdef _WIN32
#include "minwin.h"
#endif

#include <typeinfo>
#include <string>
#include <map>
#include <functional>
#include <algorithm>

namespace semilib
{

class PersistenceRegistry;

/**
	This is used to create an instance of an object whose name is
	the key in a map of name to an object which can create an instance
	of the named class.

	@see PersistenceManager
	\ingroup persistence
*/
class PERSISTENCE_DLL_API AbstractConstructor
{
public:
	/**
		the third template parameter shouldn't really be necessary
		but gcc doesn't seem to support default initialisers for templates.

		Don't want a smart pointer here, unless it's a refcount...
	*/
	typedef std::map<std::string, AbstractConstructor*, std::less<std::string> > PersistentObjects;

	AbstractConstructor();
	virtual ~AbstractConstructor();

	/**
		the Constructor template object overrides this to
		instantiate a class. Because of this method, AbstractConstructor
		and Constructor are what are know as function objects.
	*/
	virtual void * operator ()()
	{
		throw std::runtime_error ( "No instance of the constructor object" );
		return 0;
	}

	static PersistentObjects & getPersistentObjects();

private:
	static PersistenceRegistry * persistenceRegistry;
#ifdef _WIN32
	/**
		Ugly hack time. Windoes DLLs have their own memory space, so allow
		DLL entry and exit to work with only one copy of the registry.
	*/
	friend BOOL APIENTRY DllMain( HANDLE,  DWORD, LPVOID );
#endif
};

/**
	This class keeps track of the list (map, actually) of registered
	objects that can be persisted and restored.

	There can only be one such list, obviously, so we can't rely on
	static declarations to do this properly because of kak with DLLs.
	\ingroup persistence
*/
class PERSISTENCE_DLL_API PersistenceRegistry
{
public:
	PersistenceRegistry();
	~PersistenceRegistry();

	AbstractConstructor::PersistentObjects & persistentObjects()
	{
		return *_persistentObjects;
	}

protected:
	AbstractConstructor::PersistentObjects * _persistentObjects;
};

/**
	A template class that add itself to the map
	of constructor classes in AbstractConstructor, and which
	is able to create an instance of the Persistent class.

	Each persistent class (Foo, say) should have a statement like this somewhere

	namespace
	{
		Constructor<Foo> somedummyname;
	}

	Which will call the constructor of Constructor, which will add Foo to
	the list of registered objects.
	\ingroup persistence
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
		MSVC complains that it can't resolve this symbol unless you
		explicitly define it. Duh.
	*/
	Constructor ( const Constructor & )
	{
	}

	/**
		At least one call must be made to this constructor in order that
		a PersistenceManager can restore instances of class Persistent.
	*/
	Constructor()
	{
		std::string temp = typeid ( Persistent ).name();

		// only insert the object if it doesn't already exist
		if ( getPersistentObjects().find ( temp ) == getPersistentObjects().end() )
		{
			// make sure a copy of this is stored, in case this is deleted later
			getPersistentObjects()[temp] = new Constructor<Persistent>(*this);
		}
	}
};

}

#endif
