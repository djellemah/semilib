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

#pragma warning(disable: 4786)
#include "Persistence.h"

#ifdef _WIN32
	PersistenceRegistry * registryInstance = 0;
#else
	PersistenceRegistry persistenceRegistryInstance;
	PersistenceRegistry * registryInstance = &persistenceRegistryInstance;
#endif

long registryRefcount = 0;

PersistenceRegistry::PersistenceRegistry()
{
	_persistentObjects = new AbstractConstructor::PersistentObjects();
}

PersistenceRegistry::~PersistenceRegistry()
{
	// remove all the contained objects
	AbstractConstructor::PersistentObjects::iterator current = _persistentObjects->begin();
	AbstractConstructor::PersistentObjects::iterator end = _persistentObjects->end();

	for ( ; current != end; ++current )
	{
		AbstractConstructor * temp = current->second;
		delete current->second;
	}

	delete _persistentObjects;
}


/*
	These aren't really necessary with PersistenceRegistry. But
	left them here in case things turn out differently.
*/
AbstractConstructor::AbstractConstructor()
{
}

AbstractConstructor::~AbstractConstructor()
{
}

AbstractConstructor::PersistentObjects & AbstractConstructor::getPersistentObjects()
{
	return registryInstance->persistentObjects();
}

/*
	All processes share a reference-counted registry
*/
#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <windows.h>

BOOL APIENTRY DllMain( HANDLE handle,  DWORD reason_for_call, LPVOID lpReserved )
{
	switch ( reason_for_call )
	{
	case DLL_PROCESS_ATTACH:
		if ( registryRefcount++ == 0 )
			registryInstance = new PersistenceRegistry();
		break;
	case DLL_PROCESS_DETACH:
		if ( --registryRefcount == 0 )
			delete registryInstance;
		break;

	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	default:
		break;
	}

	// initialise the registry for persistence objects
    return TRUE;
}

#else

/*
	These don't work. For some reason.
void _init ( void )
{
	if ( registryRefcount++ == 0 )
	{
		registryInstance = new PersistenceRegistry();
	}
}

void _fini ( void )
{
	if ( --registryRefcount == 0 )
		delete registryInstance;
}
*/

#endif

