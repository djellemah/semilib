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

#ifndef SmartPointer_h
#define SmartPointer_h

/**
	\defgroup smartpointer Smart Pointer
	
	SmartPointer is your average smart pointer, but with templatized
	deallocators, so you can use it for things other than new/delete
	memory allocation. Ownership transfer on copy semantics.
	\code
		SmartPointer<char> ptr = new char[1024];
	\endcode
	
	RefCount is the same except that it's a proper reference count. More
	overhead than ownership transfer, but safer.
	
	cs_sptr is SmartPointer without an & operator, so you can use it
	in the std collection classes.
*/

#include <stdexcept>

#include "utilsdlldef.h"

// disable 'multiple assignment operator' warning
#pragma warning(disable: 4522)

namespace semilib
{

/**
	Normal delete operations, this is the default deallocator.
	\ingroup smartpointer
*/
template<class T>
class UTILS_DLL_API NormalDelete
{
public:
	void operator () ( T * ptr )
	{
		delete ptr;
	}
};

/**
	Array delete operations.
	\ingroup smartpointer
*/
template<class T>
class UTILS_DLL_API ArrayDelete
{
public:
	void operator() ( T * ptr )
	{
		delete[] ptr;
	}
};

/**
	To handle __stdcall deallocation functions, for example.
	\code
  	typedef StdCallFunctionDelete<unsigned char*, RPC_STATUS, &::RpcStringFree> RpcSmartFree;
	
	SmartPointer<unsigned char*, RpcSmartFree > buf;
	\endcode
	\ingroup smartpointer
*/
#ifdef _WIN32
template<class T, class Result, Result (__stdcall *deletefunction) (T*)>
class UTILS_DLL_API StdCallFunctionDelete
{
public:
	void operator() ( T * ptr )
	{
		Result r = deletefunction ( ptr );
	}
};

/**
	To handle __cdecl deallocation functions, for example.
	\code
	typedef FunctionDelete<void, void, &free> freemem;
	SmartPointer<char, freemem> c_buffer;
	c_buffer = malloc ( 243 );
	\endcode
	\ingroup smartpointer
*/
template<class T, class Result, Result ( *deletefunction) (T*)>
class UTILS_DLL_API FunctionDelete
{
public:
	void operator() ( T * ptr )
	{
		Result r = deletefunction ( ptr );
	}
};
#endif

/**
	Specialise to handle deallocation functions returning void.
	\ingroup smartpointer
*/
template<class T, void ( *deletefunction) (T*)>
class UTILS_DLL_API VoidFunctionDelete
{
public:
	void operator() ( T * ptr )
	{
		deletefunction ( ptr );
	}
};

/**
	A Smart Pointer template class to handle automatic deletion
	of dynamically allocated memory.
	This is similar to the Standard
	Library auto_ptr class, except with one or two useability
	enhancements. An instance of a smart pointer encapsulates a
	pointer to some other type and manages deallocation, for example:
	\code
	void ofn ( Object * );

	void fn()
	{
		SmartPointer<Object> p = new Object ("Whatever");
		p->method();

		ofn ( p );
	}
	\endcode
	The dynamically-allocated instance of Object will be deallocated
	by the destructor for p.

	SmartPointer has ownership-transfer semantics for copies, which
	doesn't work for every possible situation, but well enough most of
	the time. For situations where it isn't good enough (like multi-threading)
	see RefCount, which does full reference counting.

	If you see a 'multiple assignment operator' warning. Don't
	worry about it, there are supposed to be multiple assignment
	operators. Three, to be precise.
	
	This smart pointer has parameterised deallocation, so that
	you can used it with allocation and deallocation paradigms
	other than new/delete.

	\ingroup smartpointer
*/
template <class T, class Deallocator = NormalDelete<T> >
class UTILS_DLL_API SmartPointer
{
public:
	/**
		default initialiser, so this acts as the default constructor as well.
		It will also be called for statements like:
		\code
		SmartPointer<Object> p = new Object ("Whatever");
		\endcode
		although if you need to specify that the instance should not
		be an owner, for some unlikely reason:
		\code
		SmartPointer<Object> p ( new Object ("Whatever"), false );
		\endcode
	*/
	SmartPointer ( T * ptr = 0, bool aBool = true )
		: _ptr (ptr)
		, owner ( aBool )
	{
	}

	/**
		Allow const pointers to be used, but don't
		try to delete them
	*/
	SmartPointer ( const T * ptr )
		: _ptr ( const_cast<T*>(ptr) )
		, owner ( false )
	{
	}

	/// copy constructor. No, really?
	SmartPointer ( const SmartPointer & right )
		: _ptr (0)
		, owner ( false )
	{
		operator = ( right );
	}

	/// deallocate the pointer only if this instance is the owner
	~SmartPointer()
	{
		deallocate ();
	}

	/**
		copy the pointer, and make sure the other object is no
		longer the owner. After this instance has copied ownership
		(or not-ownership) from the instance being copied, the other
		smart pointer loses it's ownership.
		<p>
		Of course, if this smart pointer is already the owner of some
		memory object, it will delete it. otherwise memory leaks
		would happen every time you assigned a smart pointer.
	*/
	SmartPointer & operator = ( SmartPointer & other )
	{
		return operator = ( const_cast<const SmartPointer &>(other) );
	}

	/**
		Yet another assignment operator. This is necessary because
		otherwise in certain copying situations, operator T * gets
		called, followed by operator = ( T * ).  Which obviously
		destroys the copy semantics because the ownership is set to true
		regardless of the fact that actually it's another smart
		pointer being copied. This method simply calls the other
		assignment operator.
	*/
	SmartPointer & operator = ( const SmartPointer & right )
	{
		// deallocate previously held pointer
		deallocate ();

		// assign pointer
		_ptr = right._ptr;

		// make sure ownership is transferred
		// Note that we don't use owner = true;
		owner = right.owner;

		// right no longer owns the pointer.
		right.owner = false;

		// we need right's deallocator data, if any
		_deallocator = right._deallocator;
		
		return *this;
	}

	/**
		for statements like:
		\code
		SmartPointer<Object> p;
		p = new Object ("Whatever");
		\endcode
	*/
	SmartPointer & operator = ( T * right )
	{
		deallocate ();
		_ptr = right;
		owner = true;

		return *this;
	}

	/**
		This is to allow const pointers to be used by
		the SmartPointer, but they won't be deleted
		by default
	*/
	SmartPointer & operator = ( const T * right )
	{
		deallocate ();
		_ptr = right;
		owner = false;

		return *this;
	}

	/// for comparing with other pointers
	bool operator == ( void * rhs ) const
	{
		return _ptr == rhs;
	}

	/// for storing instances in STL collection classes
	bool operator == ( const SmartPointer & right ) const
	{
		return _ptr == right._ptr;
	}

	/// for storing instances in STL collection classes
	bool operator < ( const SmartPointer & right ) const
	{
		return _ptr < right._ptr;
	}

	/**
		for pointer comparisons. It may be that operators
		other than ==, != and < are needed, but I haven't found that
		yet.
	*/
	bool operator != ( const SmartPointer & right ) const
	{
		return _ptr != right._ptr;
	}

	/**
		member reference operator. In case what is being pointed
		to is a class obviously this won't work if is keeping
		a char * or some other basic type.
		<p>
		There is a specialisation for char *, but not for other
		basic types. This is trivial and left as an exercise
		for the reader (heehee)
	*/
	T * operator -> () const
	{
		return _ptr;
	}

	/// a dereference operator
	T & operator * ()
	{
		return *_ptr;
	}

	/// another derefence operator
	const T & operator * () const
	{
		return *_ptr;
	}

	/// an address-of operator operator
	T** operator & ()
	{
		return &_ptr;
	}

	/// an address-of operator operator
	const T** operator & () const
	{
		return &_ptr;
	}

	/**
		conversion operator. Use an instance
		of this object wherever a T * is expected.
	*/
	operator T * () const
	{
		return _ptr;
	}

	/**
		make this no longer the owner. Useful in certain situations. But
		beware of using it because it makes this behave not like a pointer.
	*/
	const SmartPointer & release () const
	{
		owner = false;
		return *this;
	}

	/**
		explicitly access the object being smartly pointed to. Breaks
		pointer semantics, so use only if the instance is does not need to
		be changed to and from the basic pointer type in the code.
		<p>
		In other words, say you have an \code Object * ptr \endcode which
		you change to a \code SmartPointer<Object> ptr \endcode . You can now do
		\code ptr.data() \endcode. But obviously you can't do \code ptr.data() \endcode
		with a variable of type \code Object * \endcode
	*/
	T * data() const
	{
		return _ptr;
	}

protected:
	T * ptr() const
	{
		return _ptr;
	}

	void ptr ( T* other )
	{
		operator = ( other );
	}
	
	Deallocator & deallocator()
	{
		return _deallocator;
	}
	
	void deallocate()
	{
		if ( owner )
		{
			deallocator() ( _ptr );
		}
	}

private:
	T * _ptr;
	mutable bool owner;
	Deallocator _deallocator;
};

/**
	SmartPointer specialised for char *, See the SmartPointer template
	documentation for details. This documentation contains some
	notes specific to SmartPointer\<char\>, whereas SmartPointer
	contains (surprise!) generic SmartPointer information.

	It works quite nicely for the
	ubiquitous buffers one has to assign in dealing with various
	API's and libraries.  For example:
	\code
	void fn()
	{
		SmartPointer<char*> ptr = new char[1024];
		strcpy ( ptr, "Hello, there" );
	}
	\endcode

	\b Don't do something like:
	\code
	SmartPointer<char*> ptr = "Some string constant";
	\endcode
	on compilers that treat string constants as char *, not as const
	char * as they should (IMNSHO, anyway).  What happens then is that
	when the ptr object goes out of scope, the destructor will attempt
	to delete[] an area of memory that's in the constant data segment.
	With corresponding error messages and chokings from the OS.
	\ingroup smartpointer
*/
template<>
class UTILS_DLL_API SmartPointer<char>
{
public:
	SmartPointer ( char * ptr = 0, bool aBool = true )
		: _ptr (ptr)
		, owner ( aBool )
	{
	}

	SmartPointer ( const SmartPointer & right )
		: _ptr (0)
		, owner ( false )
	{
		operator = ( right );
	}

	~SmartPointer()
	{
		if ( owner ) deallocator ( _ptr );
	}

	SmartPointer & operator = ( SmartPointer & other )
	{
		return operator = ( const_cast<const SmartPointer &>(other) );
	}

	SmartPointer & operator = ( const SmartPointer & right )
	{
		// deallocate previously held pointer
		if ( owner ) deallocator ( _ptr );

		// assign pointer
		_ptr = right;

		// make sure ownership is transferred
		// Note that we don't use owner = true;
		owner = right.owner;

		// right no longer owns the pointer.
		right.owner = false;

		return *this;
	}

	/**
		<strong>Don't</strong> do something like:
		\code
		SmartPointer<char*> ptr = "Some string constant";
		\endcode
		because some compilers treat string constants as
		char *, not as const char * as they should. See class
		documentation for details.
	*/
	SmartPointer & operator = ( char * right )
	{
		if ( owner ) deallocator ( _ptr );
		_ptr = right;
		owner = true;

		return *this;
	}

	bool operator == ( const SmartPointer & right ) const
	{
		return _ptr == right._ptr;
	}

	bool operator < ( const SmartPointer & right ) const
	{
		return _ptr < right._ptr;
	}

	bool operator != ( const SmartPointer & right ) const
	{
		return _ptr != right._ptr;
	}

	operator char * () const
	{
		return _ptr;
	}

	const SmartPointer & release () const
	{
		owner = false;
		return *this;
	}

	/**
		an attempt not to break pointer semantics doesn't work
		with compilers that treat string constants as char *,
		not as const char *. See class documentation for details.
	*/
	SmartPointer ( const char * )
	{
		throw std::runtime_error ("Bad idea to use a Smart Pointer with a const char *" );
	}

	/**
		another attempt not to break pointer semantics doesn't
		work with compilers that treat string constants as char *,
		not as const char *. See class documentation for details.
	*/
	SmartPointer & operator = ( const char * )
	{
		throw std::runtime_error ("Bad idea to use a Smart Pointer with a const char *" );
		return *this;
	}

	/**
		explicit reference to the ptr held by this object. Don't
		use this too much if you want a perfect replacement for
		a char *, because (obviously) a char * variable doesn't
		have a method called data().
	*/
	char * data() const
	{
		return _ptr;
	}

private:
	char * _ptr;
	mutable bool owner;
	ArrayDelete<char> deallocator;
};

#ifdef USE_VOID_SMARTPOINTER
// 'turn multiple assignment operator' warning back on
// doesn't work cos the warnings only get generated when the compiler
// instantiates the templates, which happens wherever they're referenced from
// #pragma warning(default: 4522)

/**
	Specialised to handle void*. A bit dodgy because
	deleting a void* is a fairly undefined operation
	\ingroup smartpointer
*/
template<>
class UTILS_DLL_API SmartPointer<void>
{
public:
	SmartPointer ( void * ptr = 0, bool aBool = true )
		: _ptr (ptr)
		, owner ( aBool )
	{
	}

	SmartPointer ( const SmartPointer & right )
		: _ptr (0)
		, owner ( false )
	{
		operator = ( right );
	}

	~SmartPointer()
	{
		if ( owner ) deallocator ( _ptr );
	}

	SmartPointer & operator = ( SmartPointer & other )
	{
		return operator = ( const_cast<const SmartPointer &>(other) );
	}

	SmartPointer & operator = ( const SmartPointer & right )
	{
		// deallocate previously held pointer
		if ( owner ) deallocator ( _ptr );

		// assign pointer
		_ptr = right;

		// make sure ownership is transferred
		// Note that we don't use owner = true;
		owner = right.owner;

		// right no longer owns the pointer.
		right.owner = false;

		return *this;
	}

	/**
		\b Don't do something like:
		\code
		SmartPointer<void*> ptr = "Some string constant";
		\endcode
		because some compilers treat string constants as
		char *, not as const char * as they should. See class
		documentation for details.
	*/
	SmartPointer & operator = ( void * right )
	{
		if ( owner ) deallocator ( _ptr );
		_ptr = right;
		owner = true;

		return *this;
	}

	bool operator == ( const SmartPointer & right ) const
	{
		return _ptr == right._ptr;
	}

	bool operator < ( const SmartPointer & right ) const
	{
		return _ptr < right._ptr;
	}

	bool operator != ( const SmartPointer & right ) const
	{
		return _ptr != right._ptr;
	}

	operator void * () const
	{
		return _ptr;
	}

	const SmartPointer & release () const
	{
		owner = false;
		return *this;
	}

	/**
		an attempt not to break pointer semantics doesn't work
		with compilers that treat string constants as void *,
		not as const void *. See class documentation for details.
	*/
	SmartPointer ( const void * _ptr )
	{
		throw std::runtime_error ("Bad idea to use a Smart Pointer with a const void *" );
	}

	/**
		another attempt not to break pointer semantics doesn't
		work with compilers that treat string constants as void *,
		not as const void *. See class documentation for details.
	*/
	SmartPointer & operator = ( const void * right )
	{
		throw std::runtime_error ("Bad idea to use a Smart Pointer with a const void *" );
		return *this;
	}

	/**
		explicit reference to the ptr held by this object. Don't
		use this too much if you want a perfect replacement for
		a void *, because (obviously) a void * variable doesn't
		have a method called data().
	*/
	void * data() const
	{
		return _ptr;
	}

private:
	void * _ptr;
	mutable bool owner;
	NormalDelete<void> deallocator;
};

#endif // void * smart pointer

}

#endif
