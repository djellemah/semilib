#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <lm.h>
#include <ntsecapi.h>

#include "SmartPointer.h"

template <class Result, class Arg>
class caller
{
public:
	typedef Result ( * Function ) ( Arg * );
	caller ( Function function )
		: _function ( function )
	{
	}

	void operator () ( void * _ptr )
	{
		function ( _ptr );
	}
private:
	Function _function;
};

template <class Result, class Arg>
caller <Result, Arg> makeDeallocator ( Result ( __stdcall *deallocator) ( Arg * ) )
{
	return caller<Result, Arg> ( deallocator );
}

void func()
{
}

void main()
{
	SmartPointer <USER_MODALS_INFO_1, caller<long,void> >;
}

