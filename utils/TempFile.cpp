#include "TempFile.h"

#include <stdexcept>

#ifndef _WIN32
	#include <unistd.h>
#else
#endif

namespace Utils
{

#ifndef _WIN32
	#define _tempnam tempnam
	#define _unlink unlink
#endif

TempFile::TempFile ( const char * prefix )
{
	if ( prefix == 0 )
	{
#ifdef _WIN32
#else
		prefix = "/tmp";
#endif
	}
	// make a temp file with the document header in it.
	// OK, Ok, so it's a bit of a hack.
	filename = _tempnam( ".", prefix );
	if ( filename.empty() )
	{
		throw runtime_error ( "Can't create a temporary file." );
	}
}

TempFile::~TempFile()
{
	// delete temporary file
	_unlink ( filename.c_str() );
}

}
	
