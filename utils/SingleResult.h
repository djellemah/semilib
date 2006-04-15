#ifndef SingleResult_h
#define SingleResult_h

#include "PredicateResult.h"

namespace semilib
{

/**
	This class allows for exactly one trigger error.
	
	\see MultiResult for a class that allows for multiple trigger errors.
	
	\ingroup result
*/
template <
	class Type
	, class Comparator = std::equal_to<Type>
	, class ExceptionType = SimpleMessageMaker<Type, std::runtime_error>
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
	, _active ( true )
	{
	}

	const SingleResult & operator = ( const SingleResult & other )
	{
		_error = other._error;
		_active = other._active;
		Base::operator = ( other );
		return *this;
	}

	const SingleResult & operator = ( const Type & result )
	{
		Base::operator = ( result );
		return *this;
	}

	void write ( std::ostream & os ) const
	{
		os << _error;
	}
	
	bool checkResult()
	{
		return _active && _comparator( _error, this->_result );
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
	
	virtual void read ( std::istream & is )
	{
		throw std::runtime_error ( "read (istream&) not implemented" );
	}
	
protected:
	Type _error;
	bool _active;
};

}

#endif
