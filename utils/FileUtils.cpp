/*
Copyright (C) 1998, 1999, 2000 John Anderson

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU Library General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

// "debug info trancated" warning
#pragma warning(disable: 4786)

#include <sstream>
#include <iostream>

#ifdef WIN32
	#include <direct.h>
#else
	#include <sys/stat.h>
	#include <asm/errno.h>
	#include <fcntl.h>
	#include <errno.h>
	#include <unistd.h>
	
	#define _O_RDONLY O_RDONLY
	#define _open open
	#define _close close
#endif

#include "FileUtils.h"
#include "utils.h"

// "exception specfication ignored" warning
#pragma warning(disable: 4290)

namespace Utils
{

#ifdef _WIN32
	UTILS_DLL_API const char * directorySeparator = "\\";
#else
	const char * directorySeparator = "/";
#endif

using namespace std;

FileUtils::ErrorMessages * FileUtils::_errorMessages = 0;
bool FileUtils::_initialised;

FileUtils::ErrorMessages & FileUtils::errorMessages()
{
	if ( _errorMessages == 0 )
	{
		_errorMessages = new ErrorMessages();
	}
	return *_errorMessages;
}

void FileUtils::init()
{
	if ( !_initialised )
	{
		errorMessages()[EACCES] = ""
			"Tried to open read-only file for writing, "
			"or file's sharing mode does not allow specified operations, "
			"or given path is directory.";
		errorMessages()[EEXIST] = "Filename already exists.";
		errorMessages()[EINVAL] = "Invalid oflag or pmode argument.";
		errorMessages()[EMFILE] = "No more file handles available (too many open files).";
		errorMessages()[ENOENT] = "File or path not found.";

		_initialised = true;
	}
}

/*
	Should probably use the _stat function to do the work with,
	instead of _open and _close.
	But I'm not sure if it's portable.
*/
bool FileUtils::exists () const throw ( exception )
{
	if ( _filename.empty() )
		throw runtime_error ( "No filename specified" );

	int result = _open( _filename.c_str(), _O_RDONLY );

	if ( result != -1 )
	{
		_close ( result );
		_reason = 0;
		return true;
	}
	else
	{
		_reason = errno;

		// return true if we get a EACCESS, false otherwise
		// because the file exists, but either it's a directory
		// or we don't have access permissions
		return _reason == EACCES;

		// but it doesn't work
		// return false;
	}
}

const string FileUtils::reason() const
{
	if ( _reason == 0 )
		return "No Error for file \"" + _filename + "\".";

	string retval = "Error for file \"" + _filename + "\". ";
	if ( errorMessages()[_reason] == "" )
	{
		return retval + "Error unknown.";
	}
	else
		return retval + errorMessages()[_reason];
}

bool fileExists ( const string & filename ) throw ( exception )
{
	FileUtils fu ( filename );
	return fu.exists();
}

/**
	Split a path into segments given a particular split char.
	Has some special case handling for win32 paths
*/
vector<string> splitPath( const string & dirname, char splitOn )
{
	istringstream is ( dirname );
	vector<string> retval;
	while ( is.good() )
	{
		string temp;
		getline ( is, temp, splitOn );
		
		// not interested in empty sections
		if ( temp.empty() ) continue;

#ifdef _WIN32
		// special case for fully-qualified windows paths
		if ( temp.length() == 2 && temp[1] == ':' )
		{
			string rest;
			getline ( is, rest, splitOn );
			temp += splitOn + rest;
		}
#endif
		
		retval.push_back ( temp );
	}
	return retval;
}

void mkdir( const string & dirname ) throw ( runtime_error )
{
	vector<string> dirs = splitPath ( dirname );

	vector<string>::iterator current = dirs.begin();
	vector<string>::iterator end = dirs.end();
#ifdef _WIN32
	string path;
#else
	// make it an absolute path if the first char is a /
	string path ( dirname[0] == '/' ? "/" : "" );
#endif

	for (; current != end; ++current )
	{
		path += *current;
		if ( !FileUtils::exists (path) )
		{
#ifdef _WIN32
			int result = ::_mkdir ( path.c_str() );
#else
			// with rwxr-xr-x permissions
			int result = ::mkdir ( path.c_str(), S_IRWXU | S_IRGRP | S_IXGRP |S_IROTH | S_IXOTH );
#endif
			// only throw an error if it's something other than
			// the directory already exists
			if ( result == -1 && errno != EEXIST )
			{
				throw runtime_error ( "Error for path " + dirname + ". " + path + " could not be created. " + FileUtils::errorMessages()[errno] );
			}
		}
		path += directorySeparator;
	}
}

UTILS_DLL_API string executableDirectory( const std::string & envvar )
{
	string directory;
	// directory can be cached because it will only be set
	// on startup
	char * env_home = 0;
	if ( !envvar.empty() )
	{
		env_home = getenv ( envvar.c_str() );
	}
	
	if ( env_home != 0 )
	{
		directory = env_home;
	}
	else
	{
#ifdef _WIN32
		// try to figure out the path from the name
		// of the executable
		vector<string> bits;
		if ( __argv != 0 )
		{
			bits = Utils::splitPath ( string ( __argv[0] ) );
		}
#else
		vector<string> bits;
#endif
		if ( bits.size() >= 2 )
		{
			// remove last element
			bits.erase ( bits.end() - 1 );
			directory = join ( bits, directorySeparator );
		}
		else
		{
			// AAaAaaaaargh. Just put it wherever.
			directory = ".";
		}
	}
	directory += Utils::directorySeparator;
	return directory;
}

} // end of namespace Utils

#pragma warning(default: 4290)
