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

#ifdef _MSC_VER
// ignore debug info truncated messages
#pragma warning(disable: 4786)

// ignore "c++ exception specification ignored" messages
#pragma warning(disable: 4290)
#endif

#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include <vector>
#include <string>
#include <functional>

using namespace std;

#include "FileUtils.h"
#include "functions.h"
#include "SmartPointer.h"
#include "Result.h"
#include "TempFile.h"

using namespace Utils;

using std::cout;
using std::endl;
using std::string;
using std::istringstream;

/******************************************
	FlagsMapper - convert between bitmapped
	integers and option names. Mostly for
	debugging
******************************************/
#include "FlagsMapper.h"

int test_FlagsMapper ( int argc, char * argv[] )
{
	// test flags mapper
	const char * flagsString = ""
		"REG_EXTENDED 1 "
		"REG_ICASE 2 "
		"REG_NEWLINE 4 "
		"REG_NOSUB 8 "
		;

	FlagsMapper fm ( flagsString );
	try
	{
		cout << "Should be 8" << endl;
		cout << fm["REG_NOSUB"] << endl;
		for ( int i = 1; i < 16; ++i )
		{
			cout << fm[i] << endl;
		}
		cout << "Should be 9" << endl;
		cout << fm[" REG_NOSUB|REG_EXTENDED "] << endl;
	}
	catch ( exception & e )
	{
		cerr << e.what() << endl;
	}
	
	return 0;
}

/******************************************
	A memory allocation algorithm that's faster
	and uses less memory. From Dr Dobbs originally.
	
	Look in smartnew.cpp for the implementation
******************************************/

inline int calc_alloc_size(int max_alloc_size)
{
	int size = rand() % max_alloc_size;
	return size;
}

int test_Smartnew(int argc, char* argv[])
{
	if ( argc < 4 )
	{
		cout << "Usage: random_alloc <num_cells> <max_size> <num_iters>" << endl;
		return 0;
	}
	string num_cells_str = argv[1];
	string max_size_str = argv[2];
	string num_iterations_str = argv[3];
	cout << "num_cells: " << num_cells_str
	<< " max_size: " << max_size_str
	<< " num_iter: " << num_iterations_str
	<< endl;

	int num_cells, max_alloc_size, num_iterations;
	istringstream(num_cells_str) >> num_cells;
	istringstream(max_size_str) >> max_alloc_size;
	istringstream(num_iterations_str) >> num_iterations;

	//srand(time(0));
	typedef char* pchar;
	char** cells = new pchar[num_cells];
	int* sizes = new int[num_cells];
	{
		for ( int i=0; i<num_cells; ++i )
		{
			cells[i] = 0;
			sizes[i] = 0;
		}
	}
	cout << "allocated cells" << endl;

	int total_alloc = 0;
	int total_freed = 0;
	clock_t start = clock();

	for ( int i=0; i<num_iterations; ++i )
	{
		if ( i % 1000 == 0 )
		{
			cout << i << "\r";
		}
		int index = rand() * rand() % num_cells;
		total_freed += sizes[index];
		if ( cells[index] != 0 ) delete [] cells[index];

		int alloc_size = calc_alloc_size(max_alloc_size);
		total_alloc += alloc_size;
		sizes[index] = alloc_size;
		cells[index] = new char[alloc_size];
		for ( int j=0; j<alloc_size; ++j )
			cells[index][j] = i;
	}

	clock_t end = clock();
	double interval = end - start;
	cout << "ncells: " << num_cells;
	cout << " max size: " << max_alloc_size;
	cout << " n.iters: " << num_iterations << endl;
	cout << "Time: " << interval / CLOCKS_PER_SEC << endl;
	cout << " prog. left: " << (total_alloc - total_freed)/1024 << " kb." << endl;
	return 0;
}

/******************************************
	Test that MSVC dll linkage with the libraries
	works OK.
******************************************/
int test_DllLink ( int argc, char * argv[] )
{
	vector<string> parts = splitPath( argv[0] );
	map<string,string> test;
	vector<string>::iterator current = parts.begin();
	for (; current != parts.end(); ++current )
	{
		string temp ( *current );
		test[temp] = temp.length();
	}

	copy (
		 parts.begin()
		 , parts.end()
		 , ostream_iterator<string> ( cout, "\n" )
	);
	return 0;
}

/******************************************
******************************************/

int test_SmartPointer ( int argc, char * argv[] )
{
	SmartPointer<char> p = new char[256];
	SmartPointer<char> q = p;

	// actually, two assignments in a row like this
	// cause ownership to be lost...
	p = q;
	p = q;

	strcpy ( p, "the same" );

	cout << "These two lines should be the same" << endl;
	cout << p << endl;
	cout << q << endl;

	return strcmp ( p, q ) == 0 ? 0 : 1;
}

/******************************************
******************************************/

#ifdef _WIN32
int test_ssprintf ( int argc, char * argv[] )
{
	cout << ssprintf ( "%s %s", "hello", "you" );
	cout << ssprintf ( "%s %69s", "hello", "you" );
	return 0;
}
#endif

/******************************************
Test persistence manager
******************************************/

/*
	A little baby class to test the persistence framework
*/
class TestPersist
{
public:
	
	// required for persistence
	TestPersist( int value = 0 )
	{
		_value = value;
	}
	
	// 'value' accessors
	const int value() const
	{
		return _value;
	}

	TestPersist & value ( const int other )
	{
		_value = other;
		return *this;
	}

	// for easy testing of the restored object
	bool operator == ( const TestPersist & other )
	{
		return value() == other.value();
	}

	bool operator != ( const TestPersist & other )
	{
		return value() != other.value();
	}

private:
	int _value;
	
	// required for persistence
	friend ostream & operator << ( ostream &, const TestPersist & );
	friend istream & operator >> ( istream &, TestPersist & );
};

ostream & operator << ( ostream & os, const TestPersist & obj )
{
	os << obj._value;
	
	return os;
}

istream & operator >> ( istream & is, TestPersist & obj )
{
	is >> obj._value;
	
	return is;
}

#include "PersistenceManager.h"

namespace {
	/*
		You actually only need one of these two declarations to register a class with
		the persistence framework, but there are two here to test the registration code
	*/
	// this should be added to the list
	Constructor<TestPersist> a;

	// this one shouldn't be added to the list
	Constructor<TestPersist> b;
}

int test_Persistence ( int argc, char * argv[] ) throw ( runtime_error )
{
	TestPersist p ( 5 );
	PersistenceManager<TestPersist> pm;
	bool result = true;
	
	// test with stringstreams
	{
		cout << "Testing with stringstreams"<< endl;
		
		// make it persistent
		ostringstream ostr;
		pm.persist ( ostr, p );
		
		// restore it
		istringstream istr ( ostr.str() );
		SmartPointer<TestPersist> ptr = pm.restore ( istr );

		// results
		cout << "Original: " << p.value() << endl;
		cout << "Restored: " << ptr->value() << endl;
		result = result && ( p == *ptr );
	}
	
	// test with fstreams
	{
		cout << "Testing with iostreams"<< endl;
		
		// make it persistent
		TempFile tempfile;
		ofstream ofs ( tempfile );
		pm.persist ( ofs, p );
		
		// shouldn't really be necessary in a line-based persistence,
		// but put it here to be safe
		ofs.flush();
		
		// restore it
		ifstream ifs ( tempfile );
		SmartPointer<TestPersist> ptr = pm.restore ( ifs );
		
		// results
		cout << "Original: " << p.value() << endl;
		cout << "Restored: " << ptr->value() << endl;
		
		result = result && ( p == *ptr );
	}
	
	return result ? 0 : -1;
}

#ifdef _WIN32
	#define TEMPDIR "d:\\temp"
#else
	#define TEMPDIR "/tmp"
#endif

/******************************************
	Test TempFile
******************************************/

#include "TempFile.h"

int test_TempFile ( int argc, char * argv[] ) throw ( runtime_error )
{
	cout << "Testing TempFile" << endl;
	// test in local directory with generated name
	TempFile t1;
	cout << "Create temporary filename: " << t1.asString();
	if ( FileUtils::exists ( t1.asString() ) )
		throw runtime_error ( "file " + t1.asString() + " already exists" );
	cout << " OK" << endl;

	// test in local directory with supplied prefix
	TempFile t3 ( "bgot" );
	cout << "Create temporary filename: " << t3.asString();
	if ( FileUtils::exists ( t3.asString() ) )
		throw runtime_error ( "file " + t3.asString() + " already exists" );
	cout << " OK" << endl;

	// test with a specified directory
	TempFile t2 ( "tmp", TEMPDIR );
	cout << "Create temporary filename: " << t3.asString();
	if ( FileUtils::exists ( t2.asString() ) )
		throw runtime_error ( "file " + t1.asString() + " already exists" );
	cout << " OK" << endl;

	return 0;
}

/******************************************
	Test mkdir
******************************************/

int test_mkdir ( int argc, char * argv[] )
{
	cout << "Testing mkdir" << endl;
	string temp;

	temp = string ( TEMPDIR ) + directorySeparator + "dirone" + directorySeparator + "dirtwo";
	cout << "Create " << temp;
	Utils::mkdir ( temp );
	if ( !FileUtils::exists ( temp ) )
		throw runtime_error ( "directory " + temp + " not created" );
	cout << "OK" << endl;

	temp = string ( "dirone" ) + directorySeparator + "dirtwo";
	cout << "Create " << temp;
	Utils::mkdir ( temp );
	if ( !FileUtils::exists ( temp ) )
		throw runtime_error ( "directory " + temp + " not created" );
	cout << "OK" << endl;
	cout << "removing dirone: ";
	cout << system ( "rm -R dirone" );
	cout << endl;
	
	temp = string ( "dirdotone" ) + directorySeparator + "dirtwo";
	cout << "Create " << temp;
	Utils::mkdir ( temp );
	if ( !FileUtils::exists ( temp ) )
		throw runtime_error ( "directory " + temp + " not created" );
	cout << "OK" << endl;
	cout << "removing dirdotone: ";
	cout << system ( "rm -R dirdotone" );
	cout << endl;

	return 0;
}

/******************************************
	Test istring
******************************************/

#include "istring.h"

bool search ( const string & tofind, const istring & in )
{
	bool result = in.find ( istring ( tofind ) ) != string::npos;
	cout
		<< boolalpha << result
		<< ": " << "Case-insensitive search for "
		<< tofind
		<< " in "
		<< '"' << in << '"'
		<< endl
	;
	return result;
}

int test_istring ( int argc, char * argv[] )
{
	istring query( "select count (*) from pcodes;" );
	bool result = true;
	
	cout << "Should be true" << endl;
	result = result && search ( "count", query );
	
	cout << "Should be true" << endl;
	result = result && search ( "Count", query );
	
	cout << "Should be true" << endl;
	result = result && search ( "COUNT", query );
	
	cout << "Should be false" << endl;

	// NOTE ---------- !
	//                 |
	//                 v
	result = result && !search ( "blount", query );
	
	return result ? 0 : -1;
}

/******************************************
	Test file existence
******************************************/
int test_exists ( int argc, char * argv[] )
{
	// test file utils
	
	string filename = argv[0];

	{
		cout << "Testing for file: " << filename << endl;
		FileUtils fu ( filename );
		cout << boolalpha << fu.exists() << endl;
		cout << fu.reason() << endl;
		cout << boolalpha << FileUtils::exists ( filename ) << endl;
	}

	filename ="somedumfilename";
	{
		FileUtils fu ( filename );
		cout << "Testing for file: " << filename << endl;
		cout << boolalpha << fu.exists() << endl;
		cout << fu.reason() << endl;
		cout << boolalpha << FileUtils::exists ( filename ) << endl;
	}

	cout << "Should get 'No filename specified' exception" << endl;
	try
	{
		cout << boolalpha << FileUtils::exists("") << endl;
	}
	catch ( exception & e )
	{
		cout << "Exception caught: " << e.what() << endl;
		cout << "Next" << endl;
		return 0;
	}

	return 1;
}

/*
	Call one of the test functions
*/
int main ( int argc, char * argv[] )
{
	// so gdb has somewhere to stop
	cout << "Starting" << endl;
	
	// this will throw an exception if one of the tests
	// returns a nonzero result
	Result<int> result;

	try
	{
#if 0
		// don't use this much
		result = test_Smartnew(argc, char* argv);
#endif

#ifdef _WIN32
		result = test_DllLink ( argc, argv );
		result = test_ssprintf ( argc, argv );
#endif
		cout << "Test at " << __LINE__ << endl;
		result = test_exists ( argc, argv );
		cout << "Test at " << __LINE__ << endl;
		result = test_TempFile ( argc, argv );
		cout << "Test at " << __LINE__ << endl;
		result = test_FlagsMapper ( argc, argv );
		cout << "Test at " << __LINE__ << endl;
		result = test_SmartPointer ( argc, argv );
		cout << "Test at " << __LINE__ << endl;
		result = test_Persistence ( argc, argv );
		cout << "Test at " << __LINE__ << endl;
		result = test_mkdir ( argc, argv );
		cout << "Test at " << __LINE__ << endl;
		result = test_istring ( argc, argv );

		cout << "All testes [sic] successful" << endl;
	}
	catch ( exception & e )
	{
		cout << e.what() << endl;
		return result;
	}
	catch ( ... )
	{
		cout << "Caught ..." << endl;
		return result;
	}
	return result;
}
