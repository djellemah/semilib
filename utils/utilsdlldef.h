#ifndef utilsdlldef_h
#define utilsdlldef_h

#if defined ( _WIN32 ) && !defined ( _WIN32_WINNT )
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

#ifdef _WIN32
	#ifdef LOGGER_NO_USE_DLL
		#define LOGGER_DLL_API
	#else	
		#ifdef LOGGER_BUILD_DLL
			#define LOGGER_DLL_API __declspec ( dllexport )
		#else
			#if _MSC_VER >= 1200
				#define LOGGER_DLL_API
			#else
				#define LOGGER_DLL_API __declspec ( dllimport )
			#endif
		#endif
	#endif
#else
	#define LOGGER_DLL_API
#endif

#endif

