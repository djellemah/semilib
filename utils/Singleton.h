#ifndef Singleton_h
#define Singleton_h

#include "SmartPointer.h"

/**
	This class is a threadsafe, polymorphic Singleton implementation.
	It uses double-check utex locking to minimise overhead on calls
	to the instance() method. In other words, once the instance has
	been created, no attempt is made to acquire a mutex lock.
	
	One of the differences between this implementation and a more standard
	single-thread implementation is that the _instance variable cannot
	be declared static within the instance() static method.
	Neither can the mutex. This is because
	if they were, they would be initialised when the first thread
	enters the instance() method. And there may be several threads
	entering the method at moreorless the same time.
	So in a worst case scenario, the mutex
	and/or the _instance variable might be initialised twice. This is
	especially a problem for SmartPointer<instance> because the pointer
	mebmer of the SmartPointer may be reset to 0 just after it's been
	created, causing havoc.
	
	You use it something like this:
	
	\code
	class Something : public Singleton<Something, MutexClass, LockClass>
	{
	public:
		void method()
		{
		}
	};
	
	Something * newInstance ( Something * dummy );
	
	int somefunc()
	{
		Something::instance().method();
	}
	\endcode
	
	MutexClass and LockClass should behave like this:
	
	if there is an instance of MutexClass called _mutex,
	
	\c LockClass lock ( _mutex )
	
	should acquire a lock on the mutex, which will be released
	when lock goes out of scope.
	
	The newInstance function is called to create an instance of the class.
	It will only ever be called once. The parameter is a dummy parameter
	so that the various newInstance methods can be differentiated. This
	function is where the polymorphism fits in: you can return a pointer
	to a subclass of Something.
	
	\warning This class may be a source of deadlock, if many template
	instances of it are used in a deadlock-producing way. It shouldn't
	be a problem because it's only used on startup, and threads all follow
	the same startup code path.
*/
template<class InstanceType, class Mutex, class Lock>
class Singleton
{
public:
	/**
		Return the singleton instance of this class. This use
		a double-checked lock to minimise overhead.
	*/
	static InstanceType & instance()
	{
		/*
			This is the normal case, the instance will already exist.
			So there's no need to create a lock for every time
			the instance is accessed, only for when the instance is created.
		*/
		if ( _instance == 0 )
		{
			// the instance doesn't yet exist, so make all threads
			// wait here.
			Lock lock(_mutex);
			
			/*
				one thread gets through, creates the instance. As
				soon as it's finished, the lock is released, the other
				threads come through to find the instance does exist
				after all.
			*/
			if ( _instance == 0 )
			{
				InstanceType * dummy = 0;
				_instance = newInstance( dummy );
			}
		}
		return *_instance;
	}
	
protected:
	/**
		Descendants should declare the default constructor as
		protected, unless they want to break the Singleton pattern.
	*/
	Singleton()
	{
	}
	
	/**
		It should never be necessary to create an implementation
		for the copy constructor.
	*/
	Singleton ( Singleton & other );
	
	/**
		The mutex that guards the instantiation double-lock. Since
		The instance is likely to be a shared resource, the mutex
		is protected to allow subclass usage.
	*/
	static Mutex _mutex;
	
private:
	/**
		The actual instance
	*/
	static SmartPointer<InstanceType> _instance;
};

/**
	Instantiate the mutex. This must be done at startup otherwise
	there might be a race condition when instantiating it. Although
	I'm not sure when static local variables are instantiated.
*/
template<class InstanceType, class Mutex, class Lock>
Mutex Singleton<InstanceType, Mutex, Lock>::_mutex;

template<class InstanceType, class Mutex, class Lock>
SmartPointer<InstanceType> Singleton<InstanceType, Mutex, Lock>::_instance;

#endif
