#include "utilsdlldef.h"
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
