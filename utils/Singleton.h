#ifndef Singleton_h
#define Singleton_h

#include "SmartPointer.h"
#include "Mutex.h"
#include "Lock.h"

#ifdef _WIN32
#include <string>
#include "utilsdlldef.h"

namespace semilib
{

/*
	Functions so we can define them all in one dll
*/
UTILS_DLL_API bool haveInstance ( const std::string & name );
UTILS_DLL_API void keepInstance ( const std::string & name, void * );
UTILS_DLL_API void removeInstance ( const std::string & name );
UTILS_DLL_API void * getInstance ( const std::string & name );
UTILS_DLL_API void acquireLock();
UTILS_DLL_API void releaseLock();
UTILS_DLL_API void deleteSingletons();
UTILS_DLL_API Mutex & getMutex();

}

#endif

namespace semilib
{

/**
	This class is a threadsafe, cross-DLL (for windoze), polymorphic Singleton
	implementation.
	It uses double-check mutex locking to minimise overhead on calls
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
	
	There are two usage patterns. One is like this:
	
	\code
	class Something : public Singleton<Something, MutexClass, LockClass>
	{
	public:
		void method()
		{
		}
	};
	
	Something * ::newInstance ( Something * dummy );
	
	int somefunc()
	{
		Something::instance().method();
	}
	\endcode
	
	The other is like this:
	\include testSingleton.cpp
	
	MutexClass and LockClass should behave like this:
	
	if there is an instance of MutexClass called _mutex,
	
	\c LockClass lock ( _mutex )
	
	should acquire a lock on the mutex, which will be released
	when lock goes out of scope.
	
	The ::newInstance function is called to create an instance of the class.
	It will only ever be called once. The parameter is a dummy parameter
	so that the various newInstance methods can be differentiated. This
	function is where the polymorphism fits in: you can return a pointer
	to a subclass of Something.
	
	\warning This class may be a source of deadlock, if many template
	instances of it are used in a deadlock-producing way. It shouldn't
	be a problem because it's only used on startup, and threads all follow
	the same startup code path.
	
	\ingroup utils
*/
template<class InstanceType, class MutexClass=semilib::Mutex, class LockClass=semilib::Lock>
class UTILS_DLL_API Singleton
{
public:
	/**
		Return the singleton instance of this class. This use
		a double-checked lock to minimise overhead.
	*/
	static InstanceType & instance()
	{
#ifndef _WIN32
		/*
			This is the normal case, the instance will already exist.
			So there's no need to create a lock for every time
			the instance is accessed, only for when the instance is created.
		*/
		if ( _instance == 0 )
		{
			// the instance doesn't yet exist, so make all threads
			// wait here.
			LockClass lock(_mutex);
			
			/*
				one thread gets through, creates the instance. As
				soon as it's finished, the lock is released, the other
				threads come through to find the instance does exist
				after all.
			*/
			if ( _instance == 0 )
			{
				InstanceType * dummy = 0;
				_instance = ::newInstance ( dummy );
			}
		}
		return *_instance;
#else
		/*
			Because the MSVC linker insists on creating one instance of static
			variables per dll or executable, we have to make horrible hacks
			to get around it.
		*/
		InstanceType * instance = 0;
		std::string name = typeid ( instance ).name();
		if ( !haveInstance ( name ) )
		{
			// the instance doesn't yet exist, so make all threads
			// wait here.
			acquireLock();
			
			/*
				one thread gets through, creates the instance. As
				soon as it's finished, the lock is released, the other
				threads come through to find the instance does exist
				after all.
			*/
			if ( !haveInstance ( name ) )
			{
				instance = ::newInstance ( instance );
				keepInstance ( name, instance );
			}
			releaseLock();
		}
		return *static_cast<InstanceType*> ( getInstance ( name ) );
#endif
	}

#if 0
	static MutexClass & mutex()
	{
#ifndef _WIN32
		return _mutex;
#else
		return instance()._mutex;
#endif
	}
#endif

#ifdef _WIN32
	/*
		Deregister the singleton from the list under win32
	*/
	~Singleton()
	{
		InstanceType * dummy = 0;
		std::string name = typeid ( dummy ).name();
		removeInstance ( name );
	}
#endif

	/**
		Descendants should declare the default constructor as
		protected, unless they want to break the Singleton pattern.
	*/
	Singleton()
	{
	}
	
protected:
	/**
		It should never be necessary to create an implementation
		for the copy constructor.
	*/
	Singleton ( Singleton & other );
	
#ifndef _WIN32
	/**
		The mutex that guards the instantiation double-lock. Since
		The instance is likely to be a shared resource, the mutex
		is protected to allow subclass usage.
	*/
	static MutexClass _mutex;
#else
	/**
		A mutex for children and outsiders to use
	*/
	MutexClass _mutex;
#endif
	
private:
#ifndef _WIN32
	/**
		The actual instance
	*/
	static SmartPointer<InstanceType> _instance;
#endif
};

#ifndef _WIN32
/**
	Instantiate the mutex. This must be done at startup otherwise
	there might be a race condition when instantiating it. Although
	I'm not sure when static local variables are instantiated.
*/
template<class InstanceType, class MutexClass, class LockClass>
MutexClass Singleton<InstanceType, MutexClass, LockClass>::_mutex;

template<class InstanceType, class MutexClass, class LockClass>
SmartPointer<InstanceType> Singleton<InstanceType, MutexClass, LockClass>::_instance;
#endif

}

#endif
