#ifndef winutils_h
#define winutils_h

#include <comdef.h>
#include <iostream>

std::ostream & operator << ( std::ostream &, const _com_error & e );

#endif

