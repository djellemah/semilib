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

#ifndef fuzzydlldef_h
#define fuzzydlldef_h

#ifdef _WIN32
	#ifdef FUZZY_NO_USE_DLL
		#define FUZZY_DLL_API
	#endif
	
	#ifdef FUZZY_BUILD_DLL
		#define FUZZY_DLL_API __declspec ( dllexport )
	#else
		#define FUZZY_DLL_API __declspec ( dllimport )
	#endif
#else
	#define FUZZY_DLL_API
#endif

// disable warnings about requiring DLL interface
#pragma warning(disable:4251)

#endif
