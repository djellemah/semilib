/*
	This represents the result of a Regex match. It has a conversion
	operator for string, but it also allows the string to be specified in
	terms of iterators.
	Something of a failed experiment that I didn't have a good reason
	to throw out.
*/
/*
class SubExpression : public string
{
public:
	SubExpression ()
		: _valid ( false )
	{
		//rely on default constructors for _begin and _end
	}

	SubExpression ( const string::const_iterator & begin, const string::const_iterator & end )
		: _begin ( begin )
		, _end  ( end )
		, _valid ( true )
	{
	}

	// compiler-provided operator = works perfectly. Well, provided the compiler
	// in question isn't msvc version 5, which seems to have some problems
	// with compiler generated assignment operators.

	operator string () const
	{
		testValid();
		// Don't call asString here. Efficiency.
		return string ( _begin, _end );
	}

	string asString() const
	{
		testValid();
		return string ( _begin, _end );
	}
	const string::const_iterator & begin() const
	{
		testValid();
		return _begin;
	}

	const string::const_iterator & end() const
	{
		testValid();
		return _end;
	}

	bool isValid() const
	{
		return _valid;
	}

protected:
	void testValid() const
	{
		if ( !_valid )
			throw exception ( "You haven't initialised the SubExpression" );
	}

private:
	bool _valid;
};
*/

//ostream & operator << ( ostream & os, const SubExpression & subexp );
// doesn't make sense to provide this.
// istream & operator >> ( istream & is, SubExpression & subexp );
