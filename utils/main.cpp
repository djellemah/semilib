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

class Object
{
};

#include "FlagsMapper.h"

void starthere()
{
	cout << "Starting" << endl;
}

int main( int argc, char * argv[] )
{
	starthere();
	
	if ( argc > 1 )
	{
		cout << "Starting tests for fileutils" << endl;

		// test file utils
		FileUtils fu ( argv[1] );
		cout << boolalpha << fu.exists() << endl;
		cout << fu.reason() << endl;

		cout << boolalpha << FileUtils::exists ( argv[1] );

		cout << boolalpha << FileUtils::exists("") << endl;
	}

	return 0;
}
