#ifndef Timer_h
#define Timer_h

class UTILS_DLL_API Timer
{
public:
	Timer( bool shouldStart = true )
	{
		if ( shouldStart )
			start();
	}

	unsigned start()
	{
		_start = ::GetTickCount();
		running = true;
		return _start;
	}

	// returns the number of seconds since start
	// also stops the timer running
	unsigned int stop()
	{
		_stop = ::GetTickCount();
		running = false;
		return elapsed();
	}

	// returns the number of milliseconds since start
	unsigned int elapsed()
	{
		if ( running )
		{
			DWORD current = ::GetTickCount();
			return current - _start;
		}
		else
		{
			return _stop - _start;
		}
	}

private:
	unsigned int _start;
	unsigned int _stop;
	bool running;
};


#endif