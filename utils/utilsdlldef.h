#ifndef utilsdlldef_h
#define utilsdlldef_h

#ifdef _WIN32
	#ifdef UTILS_NO_USE_DLL
		#define UTILS_DLL_API
	#else	
		#ifdef UTILS_BUILD_DLL
			#define UTILS_DLL_API __declspec ( dllexport )
		#else
			#define UTILS_DLL_API __declspec ( dllimport )
		#endif
	#endif
#else
	#define UTILS_DLL_API
#endif

#endif

