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

#ifndef istring_h
#define istring_h

#include <string>
#include <locale>
#include <iostream>

using std::char_traits;
using std::basic_string;
using std::string;
using std::locale;
using std::ostream;

#include "Change.h"
#include "utilsdlldef.h"

template<class E=char>
struct UTILS_DLL_API IgnoreCaseTraits : public char_traits<char>
{
	static bool eq(const E & x, const E & y)
	{
		return std::tolower ( x, l ) == std::tolower ( y, l );
	}

	static bool lt(const E & x, const E & y)
	{
		return std::tolower ( x, l ) < std::tolower ( y, l );
	}

	static int compare(const E *x, const E *y, size_t n)
	{
		return strnicmp ( x, y, n );
	}

	static const E *find(const E *x, size_t n, const E& y)
	{
		E temp = std::tolower ( y, l );
		for ( size_t i = 0; i < n; ++i )
		{
			if ( std::tolower ( x[i], l ) == temp )
				return x + i;
		}
		return 0;
	}

private:
	UTILS_DLL_API static locale l;
};

//typedef basic_string<char, IgnoreCaseTraits<char> > istring;
// warning about base class not a dll interface. Which it is.
#pragma warning(disable:4275)
class UTILS_DLL_API istring : public basic_string<char, IgnoreCaseTraits<char> >
{
public:
	istring()
		: basic_string<char, IgnoreCaseTraits<char> > ()
	{
	}

	istring( const char * chstr )
		: basic_string<char, IgnoreCaseTraits<char> > ( chstr )
	{
	}

	istring( const string & astr )
		: basic_string<char, IgnoreCaseTraits<char> > ( astr.c_str() )
	{
		stringCache.recalculate ( true );
	}

	istring & operator = ( const istring & other )
	{
		basic_string<char, IgnoreCaseTraits<char> >::operator = ( other );
		stringCache.recalculate ( true );

		return *this;
	}

	operator const string & () const
	{
		return asString();
	}

	const string & asString() const
	{
		if ( stringCache.recalculate() )
		{
			stringCache = string ( c_str() );
		}
		return stringCache;
	}

private:
	mutable Change<string> stringCache;
};
#pragma warning(default:4275)

UTILS_DLL_API ostream & operator<< ( ostream & os, const istring & val );

#endif
