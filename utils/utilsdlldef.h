#ifndef utilsdlldef_h
#define utilsdlldef_h

#ifdef _WIN32
	#define _WIN32_WINNT 0x0400
#endif

#ifdef _WIN32
	#ifdef UTILS_NO_USE_DLL
		#define UTILS_DLL_API
	#else	
		#ifdef UTILS_BUILD_DLL
			#define UTILS_DLL_API __declspec ( dllexport )
		#else
			#if _MSC_VER >= 1200
				#define UTILS_DLL_API
			#else
				#define UTILS_DLL_API __declspec ( dllimport )
			#endif
		#endif
	#endif
#else
	#define UTILS_DLL_API
#endif

#ifdef _WIN32
	#ifdef PERSISTENCE_NO_USE_DLL
		#define PERSISTENCE_DLL_API
	#else	
		#ifdef PERSISTENCE_BUILD_DLL
			#define PERSISTENCE_DLL_API __declspec ( dllexport )
		#else
			#if _MSC_VER >= 1200
				#define PERSISTENCE_DLL_API
			#else
				#define PERSISTENCE_DLL_API __declspec ( dllimport )
			#endif
		#endif
	#endif
#else
	#define PERSISTENCE_DLL_API
#endif

#endif

