#ifndef Winresult_h
#define Winresult_h

#include "Result.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

template <class Type = unsigned long, class ErrorType = ErrorOnZero<Type> >
class WinResult : public Result <Type, ErrorType, runtime_error>
{
	typedef Result <Type, ErrorType, runtime_error> SuperClass;
public:
	WinResult()
	{
	}
	
	explicit WinResult( Type result )
	: Result ( result )
	{
	}
	
	/// standard assignment operator
	const WinResult & operator = ( const WinResult & other )
	{
		SuperClass::operator = ( other );
		return *this;
	}

	const WinResult & operator = ( Type result )
	{
		SuperClass::operator = ( result );
		return *this;
	}

	
	virtual string message ()
	{
		DWORD lastError = ::GetLastError();
		
		LPVOID lpMsgBuf;
		FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS
			, NULL
			, GetLastError()
			, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT) // Default language
			, (LPTSTR) &lpMsgBuf
			, 0
			, NULL
		);
		// Process any inserts in lpMsgBuf.
		// huh?
		
		ostringstream os;
		os << "Windows Error: " << (char*)lpMsgBuf;
		// Free the buffer.
		LocalFree( lpMsgBuf );
		return os.str();
	}

/*
	virtual void throwException()
	{
		throw ExceptionType ( message() + extra() );
	}
*/
};

#endif

