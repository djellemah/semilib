#ifndef SingleResult_h
#define SingleResult_h

#include "PredicateResult.h"

/**
	This class allows for exactly one trigger error.
	
	\see MultiResult for a class that allows for multiple trigger errors.
	
	\ingroup result
*/
template <
	class Type
	, class Comparator = equal_to<Type>
	, class ExceptionType = SimpleMessageMaker<Type, runtime_error>
>
class SingleResult : public PredicateResult<Type, Comparator, ExceptionType>
{
	typedef PredicateResult<Type, Comparator, ExceptionType> Base;
public:
	/**
		Make a new result checker instance. By default it checks for
		values of -1.
	*/
	explicit SingleResult ( Type error = -1 )
	: _error ( error )
	{
	}

	const SingleResult & operator = ( const SingleResult & other )
	{
		_error = other._error;
		Base::operator = ( other );
		return *this;
	}

	const SingleResult & operator = ( const Type & result )
	{
		Base::operator = ( result );
		return *this;
	}

	void write ( ostream & os ) const
	{
		os << _error;
	}
	
	bool checkResult()
	{
		return _active && _comparator( _error, _result );
	}
	
	virtual void exclude ( Type value )
	{
		_active = true;
		_error = value;
	}
	
	virtual void unexclude ( Type value )
	{
		_active = false;
	}
	
	virtual void read ( istream & is )
	{
		throw runtime_error ( "read (istream&) not implemented" );
	}
	
private:
	Type _error;
	bool _active;
};

#endif
