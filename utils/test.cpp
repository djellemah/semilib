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
#include <sstream>
#include <ctime>
#include <cstdlib>

#include <vector>
#include <string>
#include <functional>

using namespace std;

#include "FileUtils.h"
#include "functions.h"
#include "SmartPointer.h"

inline int calc_alloc_size(int max_alloc_size)
{
	int size = rand() % max_alloc_size;
	return size;
}

using std::cout;
using std::endl;
using std::string;
using std::istringstream;

int testSmartnew(int argc, char* argv[])
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

int testDllLink ( int argc, char * argv[] )
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

int testSmartPointer ( int argc, char * argv[] )
{
	SmartPointer<char> p = new char[256];
	SmartPointer<char> q = p;
	p = q;
	p = q;

	strcpy ( p, "hello" );
	cout << toUpper ( p ) << endl;
	cout << p << endl;

	return 0;
}

int test_ssprintf ( int argc, char * argv[] )
{
	cout << ssprintf ( "%s %s", "hello", "you" );
	cout << ssprintf ( "%s %69s", "hello", "you" );
	return 0;
}

/**************************
Test persistence manager
**************************/

class TestPersist
{
public:
	TestPersist( int value = 0 )
	{
		_value = value;
	}
	const int value() const
	{
		return _value;
	}

	TestPersist & value ( const int other )
	{
		_value = other;
		return *this;
	}

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
	Constructor<TestPersist> c;
}

int test_Persistence ( int argc, char * argv[] )
{
	Constructor<TestPersist> c;
	try
	{
		ostringstream os;
		TestPersist p ( 5 );
		PersistenceManager<TestPersist> pm;
		pm.persist ( os, p );

		istringstream is ( os.str() );
		SmartPointer<TestPersist> ptr = pm.restore ( is );

		cout << "Original: " << p.value() << endl;
		cout << "Restored: " << ptr->value() << endl;

		if ( p == *ptr ) return -1;
	}
	catch ( exception & e )
	{
		cout << e.what() << endl;
		return -1;
	}

	return 0;
}

int main ( int argc, char * argv[] )
{
	return test_Persistence ( argc, argv );
}
