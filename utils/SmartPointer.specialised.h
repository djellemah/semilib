/**
	SmartPointer specialised for char *, See the SmartPointer template
	documentation for details. This documentation contains some
	notes specific to SmartPointer&lt;char&gt;, whereas SmartPointer
	contains (surprise!) generic SmartPointer information.
	<p>
	It works quite nicely for the
	ubiquitous buffers one has to assign in dealing with various
	API's and libraries.  For example:
	<pre>
	void fn()
	{
		SmartPointer&lt;char*&gt; ptr = new char[1024];
		strcpy ( ptr, "Hello, there" );
	}
	</pre>

	<strong>Don't</strong> do something like:
	<pre>
	SmartPointer&lt;char*&gt; ptr = "Some string constant";
	</pre>
	on compilers that treat string constants as char *, not as const
	char * as they should (IMNSHO, anyway).  What happens then is that
	when the ptr object goes out of scope, the destructor will attempt
	to delete[] an area of memory that's in the constant data segment.
	With corresponding error messages and chokings from the OS.
*/
template<>
class SmartPointer<char>
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

	virtual ~SmartPointer()
	{
		if ( owner ) delete _ptr;
	}

	SmartPointer & operator = ( SmartPointer & other )
	{
		return operator = ( const_cast<const SmartPointer &>(other) );
	}

	SmartPointer & operator = ( const SmartPointer & right )
	{
		// deallocate previously held pointer
		if ( owner ) delete _ptr;

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
		<pre>
		SmartPointer<char*> ptr = "Some string constant";
		</pre>
		because some compilers treat string constants as
		char *, not as const char * as they should. See class
		documentation for details.
	*/
	SmartPointer & operator = ( char * right )
	{
		if ( owner ) delete _ptr;
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
	SmartPointer ( const char * _ptr )
	{
		throw runtime_error ("Bad idea to use a Smart Pointer with a const char *" );
	}

	/**
		another attempt not to break pointer semantics doesn't
		work with compilers that treat string constants as char *,
		not as const char *. See class documentation for details.
	*/
	SmartPointer & operator = ( const char * right )
	{
		throw runtime_error ("Bad idea to use a Smart Pointer with a const char *" );
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
};

// 'turn multiple assignment operator' warning back on
// doesn't work cos the warnings only get generated when the compiler
// instantiates the templates, which happens wherever they're referenced from
// #pragma warning(default: 4522)

template<>
class SmartPointer<void>
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

	virtual ~SmartPointer()
	{
		if ( owner ) delete _ptr;
	}

	SmartPointer & operator = ( SmartPointer & other )
	{
		return operator = ( const_cast<const SmartPointer &>(other) );
	}

	SmartPointer & operator = ( const SmartPointer & right )
	{
		// deallocate previously held pointer
		if ( owner ) delete _ptr;

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
		<pre>
		SmartPointer<void*> ptr = "Some string constant";
		</pre>
		because some compilers treat string constants as
		void *, not as const void * as they should. See class
		documentation for details.
	*/
	SmartPointer & operator = ( void * right )
	{
		if ( owner ) delete _ptr;
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
		throw runtime_error ("Bad idea to use a Smart Pointer with a const void *" );
	}

	/**
		another attempt not to break pointer semantics doesn't
		work with compilers that treat string constants as void *,
		not as const void *. See class documentation for details.
	*/
	SmartPointer & operator = ( const void * right )
	{
		throw runtime_error ("Bad idea to use a Smart Pointer with a const void *" );
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
};

