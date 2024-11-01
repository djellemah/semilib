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

#include "utilsdlldef.h"
#ifdef WIN32
#include "minwin.h"

#ifdef BUILD_UTILS_DLL

void fn()
{
}

// this functions gets called on DLL startup
// look for DllEntryPoint in the help files
BOOL APIENTRY DllMain(HANDLE hModule,
                      DWORD  ul_reason_for_call,
                      LPVOID lpReserved)
{
    switch( ul_reason_for_call )
	{
    case DLL_PROCESS_ATTACH:
		fn();
		break;
    case DLL_THREAD_ATTACH:
		fn();
		break;
    case DLL_THREAD_DETACH:
		fn();
		break;
    case DLL_PROCESS_DETACH:
		fn();
		break;
    }

	// initialisation succeeded
    return TRUE;
}

#endif

#endif // WIN32
