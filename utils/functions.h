/*
Copyright (C) 1998, John Anderson

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

#ifndef functions_h
#define functions_h

#include <string>
#include <sstream>

using namespace std;

#include "utilsdlldef.h"

/// removes the eol characters from a line, whether they're there or not
UTILS_DLL_API void chomp ( string & line );

/// returns a time stamp of the format "Tue Oct 13 12:44:26 1998"
UTILS_DLL_API string timestamp();
UTILS_DLL_API string shortDateAsString();

// overloads because the goddam 'convenience' functions are not very convenient
UTILS_DLL_API bool isDigit ( char d );
UTILS_DLL_API char toUpper ( char a );
UTILS_DLL_API string toUpper ( const string & );
UTILS_DLL_API string toUpper ( const char * );

// convenience

// convert a long to a string
template<class T>
UTILS_DLL_API string numberToString ( T number )
{
	ostringstream os;
	os << number;
	return os.str();
}

// like sprintf, but returns a string
UTILS_DLL_API string ssprintf ( const char * fmt, ... );

#endif
