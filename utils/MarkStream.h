#ifndef MarkStream_h
#define MarkStream_h

#include <iostream>

using namespace std;
/*
	On construction this acquires a position in an istream.

	On destruction it resets the stream to that position.
*/
class MarkStream
{
public:
	MarkStream ( istream & _is, bool _active = true )
		: is ( _is )
		, active ( _active )
	{
		pos = is.tellg();
	}

	// make sure we don't go back to the mark
	void restore ()
	{
		is.seekg ( pos );
	}

	// set a new mark
	void set ()
	{
		pos = is.tellg();
	}
	
	// make sure we don't go back to the mark on destruction
	void release()
	{
		active = false;
	}

	~MarkStream ()
	{
		if ( active )
			restore ();
	}

private:
	long pos;
	istream & is;
	bool active;
};


#endif
