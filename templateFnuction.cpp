
#include <string>
#include <exception>
#include <functional>

using namespace std;

#pragma comment(lib, "rpcrt4.lib")
#include <rpc.h>

#define UTILS_DLL_API

template<class T>
class NormalDelete
{
public:
	void operator () ( T * ptr )
	{
		delete ptr;
	}
};

template<class T>
class UTILS_DLL_API ArrayDelete
{
public:
	void operator() ( T * ptr )
	{
		delete[] ptr;
	}
};

#pragma warning (disable:4284)
#pragma warning (disable:4522)

template <class T, class Deallocator = NormalDelete()>
class UTILS_DLL_API SmartPointer
{
public:
	/**
		default initialiser, so this acts as the default constructor as well.
		It will also be called for statements like:
		<pre>
		SmartPointer&lt;Object&gt; p = new Object ("Whatever");
		</pre>
		although if you need to specify that the instance should not
		be an owner, for some unlikely reason:
		<pre>
		SmartPointer&lt;Object&gt; p ( new Object ("Whatever"), false );
		</pre>
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
	SmartPointer ( const T * _ptr )
		: _ptr ( ptr )
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
		if ( owner ) deallocator ( _ptr );
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
		if ( owner ) deallocator ( _ptr );

		// assign pointer
		_ptr = right._ptr;

		// make sure ownership is transferred
		// Note that we don't use owner = true;
		owner = right.owner;

		// right no longer owns the pointer.
		right.owner = false;

		return *this;
	}

	/**
		for statements like:
		<pre>
		SmartPointer&lt;Object&gt; p;
		p = new Object ("Whatever");
		</pre>
	*/
	SmartPointer & operator = ( T * right )
	{
		if ( owner ) deallocator ( _ptr );
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
		if ( owner ) deallocator ( _ptr );
		_ptr = right;
		owner = false;

		return *this;
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
		In other words, say you have an <code>Object * ptr</code> which
		you change to a <code>SmartPointer&lt;Object&gt; ptr</code>. You can now do
		<code>ptr.data()</code>. But obviously you can't do <code>ptr.data()</code>
		with a variable of type <code>Object *</code>
	*/
	T * data() const
	{
		return _ptr;
	}

private:
	T * _ptr;
	mutable bool owner;
	Deallocator deallocator;
};

/*
template <class T, class FRET, pointer_to_unary_function<T*, FRET> >
SmartPointer<T, pointer_to_unary_function<T*, FRET> > makeSmartie ( pointer_to_unary_function<T*, FRET> deallocator )
{
	
}
*/

void fn()
{
	typedef VoidFunctionDelete<void, &free> freemem;
	SmartPointer<char, freemem> c_buffer;
	c_buffer = (char*)malloc ( 243 );
}

string testuuid()
{
	// create a Universally Unique Identifier
	// based on date, time and ethernet address or something
	// see MSVC documentation under the RPC subsystem

	//NOTE uuid generation is not supported by Windows 95

	UUID uuid;

	// make the new id
	if ( ::UuidCreate ( &uuid ) != RPC_S_OK )
		throw runtime_error ( "Couldn't create uuid" );

	// show the smart pointer how to free the buffer
	typedef StdCallFunctionDelete<unsigned char*, RPC_STATUS, &::RpcStringFree> RpcSmartFree;
	
	// make the buffer
	SmartPointer<unsigned char*, RpcSmartFree > buf;

	// get a string representation of the uuid
	if ( ::UuidToString ( &uuid, buf ) != RPC_S_OK )
		throw runtime_error ( "Couldn't convert uuid to string representation" );

	// make the string representation palatable
	string sReturnValue ( (char*)*buf );

	return sReturnValue;
}

