#include "winutils.h"

using namespace std;

ostream & operator << ( ostream & os , const _com_error & e )
{
	if ( (char*)e.Description() != 0 )
	{
		os << (char*)e.Description();
	}

	return os;
}

