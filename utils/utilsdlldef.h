#ifndef utilsdlldef_h
#define utilsdlldef_h

#ifdef UTILS_NO_USE_DLL
	#define UTILS_DLL_API
#else
	#ifdef BUILD_UTILS_DLL
		#define UTILS_DLL_API __declspec ( dllexport )
	#else
		#define UTILS_DLL_API __declspec ( dllimport )
	#endif
#endif

// disable warnings about requiring DLL interface
#pragma warning(disable:4251)

#endif
