#include "istring.h"

UTILS_DLL_API locale IgnoreCaseTraits<char>::l ( locale::empty() );

UTILS_DLL_API ostream & operator<< ( ostream & os, const istring & val )
{
	os << val.asString();
	return os;
}
