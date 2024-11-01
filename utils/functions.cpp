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
#include "functions.h"
#include "SmartPointer.h"

#ifdef _WIN32
	#pragma comment(lib, "rpcrt4.lib")
	#include <rpc.h>
#else
	#include <uuid/uuid.h>
#endif

#include <locale>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdarg>
#include <cstring>

#include <time.h>

using namespace std;

namespace semilib
{

std::locale loc;

UTILS_DLL_API bool isDigit ( char d )
{
	return std::isdigit ( d, loc );
}

UTILS_DLL_API char toUpper ( char a )
{
	return std::toupper ( a, loc );
}

UTILS_DLL_API void chomp ( string & line )
{
	if ( !line.empty() )
	{
		string::iterator last = line.end() - 1;
		if ( *last == '\n' || *last == '\r' || *last == ' ' )
		{
			line.erase ( last );
		}
	}
}

UTILS_DLL_API string longtimestamp()
{
	time_t ltime;
	time( &ltime );
	string retval ( ctime( &ltime ) );
	chomp ( retval );
	return retval;
}

UTILS_DLL_API string shortDateAsString()
{
	// get time in milliseconds
	time_t long_time;
	time( &long_time );

	// convert to local time
    struct tm * newtime = localtime( &long_time );

	// format in dd/mm/yyyy format
	ostringstream os;
	os << newtime->tm_mday << "/" << newtime->tm_mon + 1 << "/" << newtime->tm_year + 1900;
	return os.str();
}

UTILS_DLL_API string toUpper ( const char * other )
{
	return toUpper ( string ( other ) );
}

UTILS_DLL_API string toUpper ( const string & other )
{
	SmartPointer<char> buf = new char[other.length() + 1];
	::strcpy ( buf, other.c_str() );
	for ( unsigned int i = 0; i < other.length(); ++i )
	{
		buf[i] = toupper ( buf[i] );
	}

	return string ( buf );
}

#ifdef _WIN32
UTILS_DLL_API string ssprintf ( const char * fmt, ... )
{
	// 32 bytes should be enough for now...
	unsigned long length = 0x20;
	SmartPointer<char> buf = new char[length];

	// get the argument list
	va_list list;
	va_start( list, fmt );

	// _vsnprintf returns -1 if it couldn't fit all the
	// characters in, so loop until it returns a positive number
	while ( ::_vsnprintf ( buf, length, fmt, list ) < 0 )
	{
		length <<= 1;
		buf = new char[length];
	}
	
	// the new! string
	return string ( buf );
}
#endif

/*
	RpcStringFree screws things up because it needs an extra level
	of indirection to delete the string
*/
class RpcDeallocate
{
public:
	void operator() ( unsigned char * p )
	{
#ifdef _WIN32
		::RpcStringFree ( & p );
#endif
		}
};

/**
	Generate a string representation of a uuid
*/
UTILS_DLL_API string uuidAsString()
{
#ifndef _WIN32
	uuid_t uuid;
	::uuid_generate ( uuid );
	char buffer[40];
	::uuid_unparse ( uuid, buffer );
	return string ( buffer );
#else
	// create a Universally Unique Identifier
	// based on date, time and ethernet address or something
	// see MSVC documentation under the RPC subsystem

	//NOTE uuid generation is not supported by Windows 95

	//NB remember to link in RPC libraries.

	UUID uuid;

	// make the new id
	if ( ::UuidCreate ( &uuid ) != RPC_S_OK )
		throw runtime_error ( "Couldn't create uuid" );

	// make the buffer
	SmartPointer<unsigned char, RpcDeallocate> buf;

	// get a string representation of the uuid
	if ( ::UuidToString ( &uuid, &buf ) != RPC_S_OK )
		throw runtime_error ( "Couldn't convert uuid to string representation" );

	// make the string representation palatable
	string sReturnValue ( (char*)(unsigned char *)buf );

	return sReturnValue;
#endif
}

}
