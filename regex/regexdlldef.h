#ifndef regexdlldef_h
#define regexdlldef_h

#if defined( REGEX_NO_USE_DLL ) || !defined ( _WIN32 )
	#define REGEX_DLL_API
#else
	#ifdef BUILD_REGEX_DLL
		#define REGEX_DLL_API __declspec ( dllexport )
	#else
		#if _MSC_VER >= 1200
			#define REGEX_DLL_API
		#else
			#define REGEX_DLL_API __declspec ( dllimport )
		#endif
	#endif
#endif

// disable warnings about requiring DLL interface
#pragma warning(disable:4251)

#endif
