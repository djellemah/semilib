#ifndef regexdlldef_h
#define regexdlldef_h

#ifdef REGEX_NO_USE_DLL
	#define REGEX_DLL_API
#else
	#ifdef BUILD_REGEX_DLL
		#define REGEX_DLL_API __declspec ( dllexport )
	#else
		#define REGEX_DLL_API __declspec ( dllimport )
	#endif
#endif

// disable warnings about requiring DLL interface
#pragma warning(disable:4251)

#endif
