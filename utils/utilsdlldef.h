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

#ifndef utilsdlldef_h
#define utilsdlldef_h

#if defined ( UTILS_NO_USE_DLL ) || !defined ( WIN32 )
	#define UTILS_DLL_API
	#pragma message ( "UTILS - Not building for DLL" )
#else
	#ifdef BUILD_UTILS_DLL
		#define UTILS_DLL_API __declspec ( dllexport )
		#pragma message ( "UTILS - Building DLL" )
	#else
		#define UTILS_DLL_API __declspec ( dllimport )
		#pragma message ( "UTILS - Including DLL" )
	#endif
#endif

/*
	Make this always a DLL
*/

#ifdef PERSISTENCE_BUILD_DLL
	#define PERSISTENCE_DLL_API __declspec ( dllexport )
	#pragma message ( "PERSISTENCE - Building DLL" )
#else
	#define PERSISTENCE_DLL_API __declspec ( dllimport )
	#pragma message ( "PERSISTENCE - Including DLL" )
#endif


// disable warnings about requiring DLL interface
//#pragma warning(disable:4251)

#endif
