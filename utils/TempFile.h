#ifndef TempFile_h
#define TempFile_h

#include <string>

#include "utilsdlldef.h"

namespace semilib
{

/**
	Creates a temporary filename with the specified prefix
	and takes care of deleting the file when the object
	goes out of scope.

	NOTE: the file itself is NOT created. This is to allow
	TempFile to be used with ofstream ( char * )
	
	\ingroup file
*/
class UTILS_DLL_API TempFile
{
public:
	TempFile ( const char * prefix = 0, const char * dir = 0 );
	~TempFile();

	operator const std::string & () const
	{
		return asString();
	}

	operator const char * () const
	{
		return asString().c_str();
	}

	const std::string & asString() const
	{
		return filename;
	}

private:
	std::string filename;
};

}

#endif
