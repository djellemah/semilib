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

#ifndef functions_h
#define functions_h

#include <string>
#include <sstream>

#include "utilsdlldef.h"

namespace semilib
{

/**
	\defgroup string String Handling

	Various string handling convenience functions.
	
	\@{
*/
/// removes the eol characters from a line, whether they're there or not, just like Perl.
UTILS_DLL_API void chomp ( std::string & line );

/// returns a time stamp of the format "Tue Oct 13 12:44:26 1998".
UTILS_DLL_API std::string longtimestamp();
/// returns a short date as a string (dd/mmm/yy).
UTILS_DLL_API std::string shortDateAsString();

/// overloads because the standard 'convenience' functions are not very convenient.
UTILS_DLL_API bool isDigit ( char d );
/// overloads because the standard 'convenience' functions are not very convenient.
UTILS_DLL_API char toUpper ( char a );
/// overloads because the standard 'convenience' functions are not very convenient.
UTILS_DLL_API std::string toUpper ( const std::string & );
/// overloads because the standard 'convenience' functions are not very convenient.
UTILS_DLL_API std::string toUpper ( const char * );

/// like sprintf, but returns a string.
UTILS_DLL_API std::string ssprintf ( const char * fmt, ... );

/// return a string representation of a uuid.
UTILS_DLL_API std::string uuidAsString();

/**
	(win32) Convert from a Unicode string to a multibyte string.
	This functions assumes that actually multibyte
	strings can be treated as char strings.
*/
#ifdef WIN32
template <class charType>
std::string fromUnicode ( charType * ustring )
{
	const int wstrlen = wcslen ( (wchar_t*)ustring );
	SmartPointer<char> buffer = new char[wstrlen + 1];
	
	int result = ::wcstombs( buffer, (wchar_t*)ustring, wstrlen );

	// terminate string, cos WideCharToMultiByte doesn't
	return std::string ( buffer, wstrlen );
}
#endif

/**
\@}
*/

}

#endif
