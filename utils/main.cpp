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

int main ( int argc, char * argv[] )
{
	FileUtils fu ( argv[1] );
	cout << boolalpha << fu.exists() << endl;
	cout << fu.reason() << endl;

	cout << boolalpha << FileUtils::exists ( argv[1] );

	cout << boolalpha << FileUtils::exists("") << endl;
}
*/

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

void main()
{

}