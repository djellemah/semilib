#ifndef StaticInit_h
#define StaticInit_h

#include <memory>

using namespace std;

#include "utilsdlldef.h"

/**
	This provices a once-off initialisation of something
	when static members can't be relied upon. It also
	optimises accesses to the data member by uses a function
	pointer which points to different functions for the first
	call when all the initialisation is done, and for subsequent
	calls when all it has to do is return the object that has
	already been constructed.
*/
template <class Object, class Allocator = allocator<Object> >
class UTILS_DLL_API StaticInit
{
public:
	/*
		This uses one function for the first call
		and then the other function for all subsequent calls.
		This avoids the overhead of having to check for
		_item == 0 on every call to getFreeList
	*/
	static Object & getStaticItem()
	{
		return whichTime();
	}
	
	Object & operator () ()
	{
		return getStaticItem();
	}

private:
	
	// The instance is stored here
	static Object * _item;

	// pointer to which function to use
	static Object & (*whichTime)();

	// the function called on subseqent times
	static Object & subsequentTime()
	{
		return *_item;
	}

	// the function called the first time
	static Object & firstTime()
	{
		Allocator a;

		// don't use a.allocate because we then run into an endless loop
		// if smartnew.cpp is being used.
		_item = a.allocate ( sizeof ( Object ), 0 );
		//_item = static_cast<Object*>( calloc ( 1, sizeof ( Object ) ) );
		a.construct ( _item, Object() );
		
		// make sure we don't get null here
		//assert(_item != 0);

		// otherwise make sure we go to the other function next time
		whichTime = subsequentTime;

		return *_item;
	}
};

template <class Object, class Allocator>
Object * StaticInit<Object, Allocator>::_item;

template <class Object, class Allocator>
Object & (*StaticInit<Object, Allocator>::whichTime)() = StaticInit<Object, Allocator>::firstTime;

#endif