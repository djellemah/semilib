#include "NiceDate.h"

#include <boost/date_time/time_defs.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace std;

NiceDate::NiceDate()
: ptime ( second_clock::local_time() )
{
}

NiceDate::NiceDate( const string & data )
: ptime ( time_from_string ( data ) )
{
}

/**
	\warning this has a hack for GMT + 2, ie South Africa
*/
NiceDate::NiceDate( unsigned long seconds )
: ptime (
	boost::gregorian::date ( 1970, Jan, 01 )
	// time zone correction
	, boost::posix_time::seconds ( seconds ) + hours(2)
)
{
}

bool NiceDate::operator== ( const NiceDate & other ) const
{
	return ptime::operator== ( other );
}

std::string NiceDate::toString() const
{
	return to_simple_string ( *this );
}

unsigned long NiceDate::getTime() const
{
	// fetch the difference between now and epoch
	ptime epoch ( boost::gregorian::date ( 1970, Jan, 01 ) );
	
	// time zone correction
	time_duration diff = *this - epoch - hours(2);
	
	// this seems to be the only safe way to
	// get ticks_per_second out of the library
	// at the moment
	boost::int64_t res = 0;
	switch ( time_duration::resolution() )
	{
		case boost::date_time::milli:
			res = 1000;
			break;
		case boost::date_time::ten_thousandth:
			res = 10000;
			break;
		case boost::date_time::micro:
			res = 1000000;
			break;
		case boost::date_time::nano:
			res = 1000000000UL;
			break;
		default:
			throw runtime_error ( "Can't find tick resolution in NiceDate::getTime()" );
	}

	// convert to seconds and return
	return diff.ticks() / res;
}

int NiceDate::getYear() const
{
	return date().year();
}
	
int NiceDate::getMonth() const
{
	return date().month();
}

string NiceDate::format ( const string & format )
{
	time_t t = getTime();
	struct tm tm_time;
	tm_time = *::localtime ( & t );
	const int bufsize = 128;
	char temp[bufsize];
	int written = ::strftime ( temp, bufsize, format.c_str(), &tm_time );
	return string ( string ( temp, written ) );
}

std::ostream & operator << ( std::ostream & os, const NiceDate & date )
{
	os << date.toString();
	return os;
}
