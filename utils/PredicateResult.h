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

#ifndef Result_h
#define Result_h

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <set>
#include <functional>

#include "SmartPointer.h"

using namespace std;

/**
	To simplify interacting with API function calls that return an error code
	of some kind. Use it like this:
	<pre>
		try
		{
			typedef
				Result<HANDLE, equal_to, ErrnoMessageMaker<HANDLE, runtime_error> >
				CResult ( -1 )
			;
			CResult result = open ( "somefilename" );
			int next = fgetc ( result );
		}
		catch ( exception & e )
		{
			cerr << e.what() << endl;
		}	
	</pre>
	
	If the called function returns a disallowed value, -1 in this
	case, and the comparator (equal_to in this case) returns true,
	a runtime_error will be thrown. The message given to
	runtime_error is defined by the MessageMaker. You can
	still check the result using the normal if statement handling
	because the Result class has a conversion operator to the type
	you've designated.
	
	The reason there are so many template parameters is that overridding
	classes with overloaded operator =() is a pain. So it seemed easier
	to parameterise the kinds of things a result class could do. Needing
	to repeat (in the example) the HANDLE parameter is also somewhat
	painful. I spose you could typedef it once and reuse it.

	\defgroup result Result Handling
*/

/**
	This is a class that takes an exception type
	and creates a message for it containing simply the
	error code.
	
	\ingroup Result
*/
template<class Type, class Exception>
class SimpleMessageMaker
{
public:
	Exception operator () ( const Type & result )
	{
		ostringstream os;
		os << "Caught error " << result;
		return Exception ( os.str() );
	}
};

/**
	This creates a
	message string using the C API calls. In this case,
	result will almost always be -1, so we just use errno.

	\ingroup Result
*/
template<class Type, class Exception>
class ErrnoMessageMaker
{
public:
	Exception operator () ( const Type & result )
	{
		ostringstream os;
		SmartPointer<char> buf = new char[1024];
		os << "Caught error: ";
		os << strerror_r (errno, buf, 1024);
		return Exception ( os.str() );
	}
};

#ifdef _MSC_VER
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
/**
	A MessageMaker to fetch win32 errors.

	\todo This is not tested.

	\ingroup result
*/
template<class Type, class Exception>
class Win32MessageMaker
{
public:
	Exception operator() ( const Type & result )
	{
		DWORD lastError = ::GetLastError();
		
		LPVOID lpMsgBuf;
		::FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS
			, NULL
			, GetLastError()
			, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT) // Default language
			, (LPTSTR) &lpMsgBuf
			, 0
			, NULL
		);
		
		ostringstream os;
		os << "Windows Error: " << (char*)lpMsgBuf;
		// Free the buffer.
		::LocalFree( lpMsgBuf );
		return os.str();
	}
};
#endif

/**
	This template class is used to create instances of objects
	which can have results assigned to them.
	
	- Type is the error code type. Usually some flavour of int
	- Comparator is one of the comparison predicates from <functional>
	- MessageMaker is a functor defining operator() ( const Type & value )
	that creates an exception to be thrown with a message based
	on the value.
	
	\ingroup result
*/
template <
	class Type
	, class Comparator = equal_to<Type>
	, class MessageMaker = SimpleMessageMaker<Type, runtime_error>
>
class PredicateResult
{
public:
	PredicateResult() {};
	PredicateResult ( const PredicateResult & other )
		: _result ( 0 )
	{
		operator = ( other );
	}

	const PredicateResult & operator = ( const PredicateResult & other )
	{
		_result = other._result;
		return *this;
	}

	/**
		assignment operator for using with function calls.
		This checks to see whether the return value from the
		function should throw an exception, and then throws
		the specified exception with a string generated by the
		message virtual method.
	*/
	const PredicateResult & operator = ( const Type & result )
	{
		_result = result;
		if ( checkResult() )
		{
			throw _messageMaker ( result );
		}
		return *this;
	}

	/// for inclusion in STL containers
	bool operator < ( const PredicateResult & other ) const
	{
		return _result < other._result;
	}

	/// for inclusion in STL containers
	bool operator == ( const PredicateResult & other ) const
	{
		return _result == other._result;
	}

	/// for comparison to the type being checked
	bool operator < ( Type other ) const
	{
		return _result < other;
	}

	/// for comparison to the type being checked
	bool operator == ( Type other ) const
	{
		return _result == other;
	}

	/// conversion operator to the type being checked
	operator Type & ()
	{
		return _result;
	}

	/**
		Exclude the given value from being an error.
	*/
	virtual void exclude ( Type value ) = 0;

	/**
		Prevent the given value from being excluded.
	*/
	virtual void unexclude ( Type value ) = 0;

	const Type & result() const
	{
		return _result;
	}

	PredicateResult & result ( const Type & other )
	{
		_result = other;
		return *this;
	}
	
	/**
		to write out the trigger errors to a stream
	*/
	virtual void write ( ostream & os ) const = 0;

	/**
		to read in trigger codes from a stream
	*/
	virtual void read ( istream & is ) = 0;

protected:
	/**
		Override this to check whether the stored _result
		matches something in the trigger errors. Returns
		true if an exception should be thrown, false otherwise.
	*/
	virtual bool checkResult() = 0;

	Comparator _comparator;

	Type _result;
	MessageMaker _messageMaker;
};

/**
	Insertion operator that displays the list of trigger errors.
*/
template <
	class Type
	, class Comparator
	, class ExceptionType
>
ostream &
operator << ( ostream & os, const PredicateResult<Type,Comparator,ExceptionType> & result )
{
	result.write ( os );
	return os;
}

/**
	Extraction operator to fetch a set of exception errors from a stream
*/
template <
	class Type
	, class Comparator
	, class ExceptionType
>
istream &
operator >> ( istream & is, const PredicateResult<Type,Comparator,ExceptionType> & result )
{
	result.read ( is );
	return is;
}

/**
	A stream-type operator to provide several trigger errors.
*/
template <
	class Type
	, class Comparator
	, class ExceptionType
>
PredicateResult<Type,Comparator,ExceptionType> &
operator << (
	PredicateResult<Type,Comparator,ExceptionType> & result
, const Type & error
)
{
	result.exclude ( error );
	return result;
}

/**
	A stream-type operator to provide several error codes to be
	removed from the list of trigger errors.
*/
template <
	class Type
	, class Comparator
	, class ExceptionType
>
PredicateResult<Type,Comparator,ExceptionType> &
operator >> (
	PredicateResult<Type,Comparator,ExceptionType> & result
, const Type & error
)
{
	result.unexclude ( error );
	return result;
}

#endif
