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

#ifndef PersistenceManager_cpp
#define PersistenceManager_cpp

#include "PersistenceManager.h"
#include "posException.h"
#include "functions.h"

using namespace std;

namespace semilib
{

template <class Persistent>
void
PersistenceManager<Persistent>::
persist ( std::ostream & os, const Persistent & object ) const
{
	os << endl;
	os << typeid ( object ).name() << endl;
	os << "{" << endl;
	os << object << endl;
	os << "}" << endl;
}

template <class Persistent>
Persistent *
PersistenceManager<Persistent>::
makeNewObject( const std::string & line ) const
{
	if (
		AbstractConstructor::getPersistentObjects().find(line)
		==
		AbstractConstructor::getPersistentObjects().end()
	)
	{
		std::ostringstream os;
		os << "Couldn't find Constructor instance for " << line << ".\n\n";
		os << "Existing Constructor instances are: " << endl;
		writePersistentObjectNames ( os );		
		throw runtime_error ( os.str() );
	}

	AbstractConstructor * constructor = AbstractConstructor::getPersistentObjects()[line];

	return reinterpret_cast<Persistent*>( (*constructor)() );
}

template <class Persistent>
SmartPointer<Persistent>
PersistenceManager<Persistent>::
restore ( std::istream & is ) const // throw ( runtime_error )
{
	// for debugging. Allow setting of conditional breakpoints
	// long pos = is.tellg();

	std::string line;

	// ignore empty lines
	while ( getline ( is, line ), chomp ( line ), line.empty() )
	{
		if ( is.eof() ) throw posException ( is.tellg(), " Unexpected eof" );
	}

	Persistent * newObject = makeNewObject( line );

	while ( getline ( is, line ), chomp ( line ), line.empty() );
	// Parser::chomp ( line );
	if ( line != "{" )
		throw posException ( is.tellg(), "Expecting {, found " + line );

	is >> *newObject;

	while ( getline ( is, line ), chomp ( line ), line.empty() )
	{
		if ( is.eof() ) throw posException ( is.tellg(), " Unexpected eof" );
	}

	if ( line != "}" )
		throw posException ( is.tellg(), ("Expecting }, found " + line).c_str() );

	// force eof if it's here...
	is.peek();

	return SmartPointer<Persistent>(newObject);
}

template <class Persistent>
void
PersistenceManager<Persistent>::
writePersistentObjectNames ( std::ostream & os ) const
{
	AbstractConstructor::PersistentObjects::const_iterator current = AbstractConstructor::getPersistentObjects().begin();
	AbstractConstructor::PersistentObjects::const_iterator end = AbstractConstructor::getPersistentObjects().end();

	for ( ; current != end; current++ )
	{
		os << current->first << endl;
	}
}

}

#endif
