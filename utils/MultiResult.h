#ifndef MultiResult_h
#define MultiResult_h

#include "PredicateResult.h"

#include <set>
#include <stdexcept>
#include <iostream>
#include <iterator>

using namespace std;

/**
	This class allows for multiple trigger errors, with the
	restriction that you can only use equal_to as a comparator.
	Which means that you can only specify a set of trigger errors
	for which exceptions must be thrown. The inverse would be useful
	but I haven't thought of a good way of doing that yet.
	
	\todo provide facilities to create the set of trigger errors
	from other containers.
	
	\ingroup result
*/
template <
	class Type
	, class ExceptionType = SimpleMessageMaker<Type, runtime_error>
>
class MultiResult : public PredicateResult<Type, equal_to<Type>, ExceptionType>
{
	typedef PredicateResult<Type, equal_to<Type>, ExceptionType> Base;
public:
	/**
		Make a new result checker instance. This will have no trigger
		errors.
	*/
	explicit MultiResult ()
	{
	}

	/**
		Make a new result checker instance. This will have 
		exactly one trigger error, being the parameter.
	*/
	explicit MultiResult ( Type error )
	{
		exclude ( error );
	}

	const MultiResult & operator = ( const MultiResult & other )
	{
		_error = other._error;
		Base::operator = ( other );
		return *this;
	}

	const MultiResult & operator = ( const Type & result )
	{
		Base::operator = ( result );
		return *this;
	}

	void write ( ostream & os ) const
	{
		copy ( _errors.begin(), _errors.end(), ostream_iterator<Type> ( os, ", " ) );
	}

	bool checkResult()
	{
		return
		find (
			_errors.begin()
			, _errors.end()
			, _result
		)
		!= _errors.end()
		;
	}
	
	virtual void exclude ( Type value )
	{
		_errors.insert ( value );
	}
	
	virtual void unexclude ( Type value )
	{
		_errors.erase ( value );
	}
	
	virtual void read ( istream & is )
	{
		throw runtime_error ( "read (istream&) not implemented" );
	}
	
private:
	set<Type> _errors;
};

#endif
