#ifndef TempFile_h
#define TempFile_h

#include <string>

#include "utilsdlldef.h"

namespace Utils
{
	using namespace std;

/**
	Creates a temporary file with the specified prefix
	and takes care of deleting the file when the object
	goes out of scope.
*/
class UTILS_DLL_API TempFile
{
public:
	TempFile ( const char * prefix = 0 );
	~TempFile();

	operator const string & () const
	{
		return filename;
	}

	operator const char * () const
	{
		return filename.c_str();
	}

private:
	string filename;
};

}

#endif

