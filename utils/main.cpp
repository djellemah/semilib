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

#pragma warning(disable: 4786)

#include <iostream>

#include "FileUtils.h"
#include "SmartPointer.h"

using namespace std;

/*
class Object
{
};

void fn()
{
	const Object o;
	SmartPointer<Object> n = &o;

	SmartPointer<char> p = new char[1024];
	p = "Hello there";
	SmartPointer<char> q = "Another const char *";
	strlen ( p );

}

void main()
{
	fn();
}
*/

int main ( int argc, char * argv[] )
{
	FileUtils fu ( argv[1] );
	cout << boolalpha << fu.exists() << endl;
	cout << fu.reason() << endl;

	cout << boolalpha << FileUtils::exists ( argv[1] );

	cout << boolalpha << FileUtils::exists("") << endl;
}

/*
#include "FlagsMapper.h"

void main()
{
	const char * flagsString = ""
		"REG_EXTENDED 1"
		"REG_ICASE 2"
		"REG_NEWLINE 4"
		"REG_NOSUB 8"
		;

	FlagsMapper fm ( flagsString );
	try
	{
		cout << fm["REG_NOSUB"] << endl;
		cout << fm[" REG_NOSUB|REG_EXTENDED "] << endl;
		for ( int i = 0; i < 16; ++i )
		{
			cout << fm[i] << endl;
		}
	}
	catch ( exception & e )
	{
		cerr << e.what() << endl;
	}

}
*/
