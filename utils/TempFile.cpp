#include "TempFile.h"

#include <stdexcept>
#include <string>

#ifndef _WIN32
	#include <unistd.h>
#else
#endif

#include "FileUtils.h"

namespace Utils
{

#ifndef _WIN32
	#define _tempnam tempnam
	#define _unlink unlink
#endif

std::string getTempDir()
{
	const char * env = getenv ( "TMP" );
	if ( env == 0 )
	{
		env = getenv ( "TEMP" );
	}
	
	if ( env == 0 )
	{
#ifdef _WIN32
		return std::string ( "." ) + directorySeparator;
#else
		return "/tmp";
#endif
	}

	return env;
}
	
TempFile::TempFile ( const char * prefix, const char * dir )
{
	if ( prefix == 0 )
	{
		prefix = "tmp";
	}
	
	string tempdir;
	if ( dir == 0 )
	{
		tempdir = getTempDir();
	}
	
	// make a temp file with the document header in it.
	// OK, Ok, so it's a bit of a hack.
	filename = _tempnam( tempdir.c_str(), prefix );
	if ( filename.empty() )
	{
		throw std::runtime_error ( "Can't create a temporary file." );
	}
}

TempFile::~TempFile()
{
	// delete temporary file
	_unlink ( filename.c_str() );
}

}
	
