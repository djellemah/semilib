#ifndef fuzzydlldef_h
#define fuzzydlldef_h

#ifdef FUZZY_NO_USE_DLL
	#define FUZZY_DLL_API
#endif

#ifdef FUZZY_BUILD_DLL
	#define FUZZY_DLL_API __declspec ( dllexport )
#else
	#define FUZZY_DLL_API __declspec ( dllimport )
#endif

// disable warnings about requiring DLL interface
#pragma warning(disable:4251)

#endif
