/*
Copyright (C) 1998, John Anderson

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

#include <string>
#include <map>
#include <stdexcept>
#include <vector>

#include <io.h>
#include <fcntl.h>

using namespace std;

#include "utilsdlldef.h"

/**
This is the central place for file utilities.
Currently it:
<ul>
<li>tests for the existence of a file
<li>creates a directory, even when it means creating several subdirectories.
</ul>
And this doc++ stuff doesn't seem to cope very well with markup here.
*/
class UTILS_DLL_API FileUtils
{
	typedef map<int, string> ErrorMessages;
	static ErrorMessages * _errorMessages;
public:

	// Default Constructor
	FileUtils()
	{
		init();
	}

	// Copy Constructor
	FileUtils ( const FileUtils & other )
	{
		operator = ( other );
	}

	FileUtils ( const string & filename )
		: _filename ( filename )
	{
		init();
	}

	// Destructor
	virtual ~FileUtils()
	{
	}

	// assignment operator
	const FileUtils & operator = ( const FileUtils & other )
	{
		return *this;
	}

	// need these for inclusion in STL containers
	bool operator < ( const FileUtils & other ) const
	{
		return _filename < other._filename;
	}

	bool operator == ( const FileUtils & other ) const
	{
		return _filename == other._filename;
	}

	/**
		find out if a file exists. If the file exists but is inaccessible, throw
		a runtime_error
	*/
#pragma warning(disable:4290)
	bool exists () const throw ( exception );

	/// get the size of a file
	long size() const throw ( exception );
#pragma warning(default:4290)

	// get the reason for the failure of the last operation
	const string reason() const;

	const string & filename() const
	{
		return _filename;
	}

	FileUtils & filename ( const string & filename )
	{
		_filename = filename;
		return *this;
	}

	/// convenience method for testing exitence of a file without having
	/// to have instances floating around.
	static bool exists ( const string & _filename )
	{
		return FileUtils ( _filename ).exists();
	}

	static ErrorMessages & errorMessages();

protected:
	void init();

private:
	// data members
	string _filename;
	mutable int _reason;
	static bool _initialised;
};

// insertion operator
ostream & operator << ( ostream & os, const FileUtils & aFileUtils );

// extraction operator
istream & operator >> ( istream & is, FileUtils & aFileUtils );

// a helper function
UTILS_DLL_API bool fileExists ( const string & filename );

/// return a vector containing the elements of a path
UTILS_DLL_API vector<string> splitPath( const string & dirname, char splitOn = '\\' );

/// make a directory containing subdirectories. Make all of them. Make every last one...
UTILS_DLL_API void mkdir ( const string & name );

#endif
