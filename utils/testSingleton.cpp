#include "Mutex.h"
#include "Lock.h"
#include "Singleton.h"

#include <iostream>
#include <string>

using namespace std;

class Alibi
{
public:
	Alibi ( const std::string & rhs )
	: value ( rhs )
	{
		cout << "Alibi()" << endl;
	}
	
	void * whereami()
	{
		return this;
	}
	
	string value;
};

Alibi * newInstance ( Alibi * )
{
	return new Alibi( "atom bomb" );
}

int main ( int argc, char * argv[] )
{
	cout << Singleton<Alibi,Mutex,Lock>::instance().whereami() << endl;
	cout << "main()" << endl;
	cout << Singleton<Alibi,Mutex,Lock>::instance().whereami() << endl;
	return 0;
}
