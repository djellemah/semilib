#ifndef cs_sptr_h
#define cs_sptr_h

/**
	This is a collection-safe smart pointer class
	in that it lacks operator&
	\ingroup SmartPointer
*/
template <class T, class Deallocator = NormalDelete<T> >
class UTILS_DLL_API cs_sptr
{
public:
	/**
		default initialiser, so this acts as the default constructor as well.
		It will also be called for statements like:
		<pre>
		cs_sptr&lt;Object&gt; p = new Object ("Whatever");
		</pre>
		although if you need to specify that the instance should not
		be an owner, for some unlikely reason:
		<pre>
		cs_sptr&lt;Object&gt; p ( new Object ("Whatever"), false );
		</pre>
	*/
	cs_sptr ( T * ptr = 0, bool aBool = true )
		: _ptr (ptr)
		, owner ( aBool )
	{
	}

	/**
		Allow const pointers to be used, but don't
		try to delete them
	*/
	cs_sptr ( const T * _ptr )
		: _ptr ( ptr )
		, owner ( false )
	{
	}

	/// copy constructor. No, really?
	cs_sptr ( const cs_sptr & right )
		: _ptr (0)
		, owner ( false )
	{
		operator = ( right );
	}

	/// deallocate the pointer only if this instance is the owner
	~cs_sptr()
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
	cs_sptr & operator = ( cs_sptr & other )
	{
		return operator = ( const_cast<const cs_sptr &>(other) );
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
	cs_sptr & operator = ( const cs_sptr & right )
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
		<pre>
		cs_sptr&lt;Object&gt; p;
		p = new Object ("Whatever");
		</pre>
	*/
	cs_sptr & operator = ( T * right )
	{
		deallocate ();
		_ptr = right;
		owner = true;

		return *this;
	}

	/**
		This is to allow const pointers to be used by
		the cs_sptr, but they won't be deleted
		by default
	*/
	cs_sptr & operator = ( const T * right )
	{
		deallocate ();
		_ptr = right;
		owner = false;

		return *this;
	}

	/// for storing instances in STL collection classes
	bool operator == ( const cs_sptr & right ) const
	{
		return _ptr == right._ptr;
	}

	/// for storing instances in STL collection classes
	bool operator < ( const cs_sptr & right ) const
	{
		return _ptr < right._ptr;
	}

	/**
		for pointer comparisons. It may be that operators
		other than ==, != and < are needed, but I haven't found that
		yet.
	*/
	bool operator != ( const cs_sptr & right ) const
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
	const cs_sptr & release () const
	{
		owner = false;
		return *this;
	}

	/**
		explicitly access the object being smartly pointed to. Breaks
		pointer semantics, so use only if the instance is does not need to
		be changed to and from the basic pointer type in the code.
		<p>
		In other words, say you have an <code>Object * ptr</code> which
		you change to a <code>cs_sptr&lt;Object&gt; ptr</code>. You can now do
		<code>ptr.data()</code>. But obviously you can't do <code>ptr.data()</code>
		with a variable of type <code>Object *</code>
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

#endif
