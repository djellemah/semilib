#pragma warning(disable: 4786)

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "Regex.h"

#include "..\..\Thread\src\Thread.h"
#include "SmartPointer.h"


// The target for each thread
class Match : public Runnable
{
public:
	Match ( const Regex & regex, const string & toMatch )
		: _toMatch ( toMatch )
		, _regex ( regex )
	{
	}

	void run ()
	{
		cout << boolalpha << _regex.match ( _toMatch ) << endl;
	}

private:
	string _toMatch;
	const Regex & _regex;
};

// read a file given a filename
string readFile ( const char * filename )
{
	ifstream in ( filename );
	string retval;
	const long bufsize = 4096;
	SmartPointer<char> buffer ( new char [bufsize] );

	while ( in.good() )
	{
		in.read ( buffer, bufsize - 1 );
		buffer[in.gcount()] = 0;
		retval += buffer;
	}

	return retval;
}

// Test that the Regex class will multithread nicely
int main ( int argc, char * argv[] )
{
	string fileOneContents = readFile ( "d:\\users\\panic\\desktop\\files\\projects\\regex\\src\\\\rxgnucomp.c" );
	string fileTwoContents = readFile ( "d:\\users\\panic\\desktop\\files\\projects\\regex\\src\\\\rxgnucomp.h" );
	Regex regexOne ( ".*inv.{4}_trans.*" );
	Regex regexTwo ( ".*this should not match" );

	Match matchOne ( regexOne, fileOneContents );
	Match matchTwo ( regexTwo, fileTwoContents );

//	Thread firstThread ( matchOne );
	Thread secondThread ( matchTwo );

	// sleep pour quelques minuits
	::Sleep ( 10 * 60 * 1000 );

	return 0;
}
