#ifndef Lock_h
#define Lock_h

/**
	Lockhronisation class. Create on of these whenever a critical section is
	necessary. Then, on entering the critical section do:
	<pre>
		Lock alock ( mutex );
	</pre>
	the lock will be released when alock goes out of scope.

	The Lock object should be in a scope outside that of alock. A good
	way to do it is to make Lock class member, and then for each
	method that needs to control access, have the above line as the
	first line in the method implementation.

	\todo this is a _WIN32 specific class, but the functionality it uses
	should be available in any thread implementation. So, implement it, already!
*/
class Lock
{
public:

	/**
		create the Lockhronisation object
	*/
	inline Lock();

	/**
		lock the Lockhronisation object
	*/
	inline void lock();

	/**
		release the Lockhronisation object
	*/
	inline void release();

	/**
		delete the Lockhronisation object
	*/
	inline ~Lock();

private:
	/// where the OS-level Lockhronisation object is stored
#ifdef _WIN32
	CRITICAL_SECTION criticalSection;
#endif
};

#endif
