#ifndef regexlib_h
#define regexlib_h

// use c++ regex library
#define jmlib

// use rx-1.5, or rx-1.9
// #define rx

// use gnu regex library
// Doesn't treat 0-th subexpression as the whole match
// #define regex

/*
#ifndef __BCPLUSPLUS__
	#define RXSPACE rxSpace::
#else
	#define RXSPACE
#endif


#ifndef __BCPLUSPLUS__
namespace rxSpace
{
#endif
#ifndef __BCPLUSPLUS__
}
#endif
*/

#ifdef rx

extern "C"
{
	// make sure we have enough regex cache space
	/*
	RX_DEFAULT_DFA_CACHE_SIZE
	rx_default_cache->bytes_allowed = 1<<20
	*/

	/*
	RX_DEFAULT_NFA_DELAY
	rx_basic_unfaniverse_delay

	#define RX_DEFAULT_NFA_DELAY 1024

	*/

	// for the rx-1.5 version
	/*
	#include"rx-1.5/rxposix.h"
	*/

	// for the rx-1.9 version, which has some bugs in it. 1.9a might fix them, dunno yet.
	/*
	#include "rx-1.9/posix.h"
	#include "rx-1.9/errnorx.h"
	#include "rx-1.9/match-regexp.h"
	*/

		#define __USING_CNAME__
		using namespace std;
		// make sure the rx stuff compiles properly
		// and be friendly to other folx who've define __STDC__
		#ifndef __STDC__
			#define __STDC__
//			#include"rx-1.5/rxposix.h"
			#include "regex-0.12/regex.h"
			#undef __STDC__
		#else
//		#include"rx-1.5/rxposix.h"
		#include "regex-0.12/regex.h"
		#endif
} // end of extern "C"
#endif

#ifdef jmlib
	#define RE_POSIX_COMPAT
	#include "Regexpp/jregex.h"
	#define RXSPACE
#endif

#endif
