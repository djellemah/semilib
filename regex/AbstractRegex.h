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

#ifndef AbstractRegex_h
#define AbstractRegex_h

#include <iostream>
#include <string>

using namespace std;

#include "utilsdlldef.h"

/**
	A base class for regex that defines match, just in case some other
	algorithm (say prefix matching) needs to be used instead of the full regular
	expression library. I originally used it for some performance tuning, but
	it ended up not making much of a difference, especially if you use the ^ and $
	regular expression operators to mark the beginning and the end of a string.
	
	In fact it may slow down Regex slightly due to the virtual match method
	\ingroup Regex
*/
class /*UTILS_DLL_API*/ AbstractRegex
{
public:
	virtual bool match ( const string & s, unsigned long pos = 0 ) const = 0;
};

#endif
