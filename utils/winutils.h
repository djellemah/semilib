#ifndef winutils_h
#define winutils_h

#include <comdef.h>
#include <iostream>

#include "utilsdlldef.h"

namespace semilib
{

UTILS_DLL_API std::ostream & operator << ( std::ostream &, const _com_error & e );

}

#endif

