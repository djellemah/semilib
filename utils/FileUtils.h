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

#ifndef FileUtils_h
#define FileUtils_h

/**
	\defgroup file File and Directory
	
	Various file and directory handling routines.
*/

#include <string>
#include <map>
#include <stdexcept>
#include <vector>

#ifdef WIN32
	#include <io.h>
#endif
#include <fcntl.h>

#include "utilsdlldef.h"

#pragma warning(disable:4290)

namespace semilib
{
	using namespace std;
#ifdef _WIN32
	UTILS_DLL_API extern const char * directorySeparator;
#else
	extern const char * directorySeparator;
#endif

/**
This is the central place for file utilities.
Currently it:
	- tests for the existence of a file
	- creates a directory, even when it means creating several subdirectories.
	
	\todo split off some of the methods into pure functions, where they
	don't need an object.
	
	\ingroup file
*/
class UTILS_DLL_API FileUtils
{
	typedef map<int, string> ErrorMessages;
	static ErrorMessages * _errorMessages;
public:

	/// Default Constructor
	FileUtils()
	{
		init();
	}

	/// Copy Constructor
	FileUtils ( const FileUtils & other )
	{
		operator = ( other );
	}

	/// create a FileUtils instance for operations on a given filename
	FileUtils ( const string & filename )
		: _filename ( filename )
	{
		init();
	}

	/// Destructor
	virtual ~FileUtils()
	{
	}

	/// assignment operator
	const FileUtils & operator = ( const FileUtils & )
	{
		throw runtime_error ( "FileUtils::operator = not implemented" );
		return *this;
	}

	/// in case of usage in an STL container
	bool operator < ( const FileUtils & other ) const
	{
		return _filename < other._filename;
	}

	/// in case of usage in an STL container
	bool operator == ( const FileUtils & other ) const
	{
		return _filename == other._filename;
	}

	/**
		find out if a file exists. If the file exists but is inaccessible, throw
		a runtime_error
	*/
	bool exists () const throw ( exception );

	/// get the size of a file
	long size() const throw ( exception );

	/// get the reason for the failure of the last operation
	const string reason() const;

	/// return the current filename
	const string & filename() const
	{
		return _filename;
	}

	/// set the current filename
	FileUtils & filename ( const string & filename )
	{
		_filename = filename;
		return *this;
	}

	/**
		convenience method for testing existence of a file without having
		to have instances floating around.
	*/
	static bool exists ( const string & _filename )
	{
		return FileUtils ( _filename ).exists();
	}

	static ErrorMessages & errorMessages();

protected:
	void init();

private:
	string _filename;
	mutable int _reason;
	static bool _initialised;
};

/**
	insertion operator
	\ingroup file
*/
ostream & operator << ( ostream & os, const FileUtils & aFileUtils );

/**
	extraction operator
	\ingroup file
*/
istream & operator >> ( istream & is, FileUtils & aFileUtils );

/**
	a helper function
	\ingroup file
*/
UTILS_DLL_API bool fileExists ( const string & filename ) throw ( exception );

/**
	return a vector containing the elements of a path
	\ingroup file
*/
UTILS_DLL_API vector<string> splitPath( const string & dirname, char splitOn = directorySeparator[0] );

/**
	make a directory containing subdirectories.
	Make all of them. Make every last one...
	\ingroup file
*/
UTILS_DLL_API void mkdir( const string & dirname ) throw ( runtime_error );

/**
	Return the directory, with trailing /,
	where the current executable lives.

	\param envvar allows you to specify an environment variable
	to search first

	\todo always returns ./ for non win32 systems, unless envvar is defined
	
	\ingroup file
*/
UTILS_DLL_API std::string executableDirectory( const std::string & envvar = "" );

/**
	Returns the name of the current executable, including the extension for win32.
	\ingroup file
*/
UTILS_DLL_API std::string executableName();

}

#pragma warning(default:4290)

#endif
