#ifndef bapi_NiceDate_h
#define bapi_NiceDate_h

#pragma warning (disable:4244)
#pragma warning (disable:4267)
#pragma warning (disable:4800)
	#include <boost/date_time/posix_time/posix_time.hpp>
#pragma warning (default:4244)
#pragma warning (default:4267)
#pragma warning (default:4800)

#include "SmartPointer.h"

#include <string>
#include <iostream>

/**
	This class represents a full specification of a date
	and time. It's based on the boost::posix_time
	class.
	
	It allows for easy parsing of date strings, and
	formatting using the strftime format specifiers.

	\todo fix time zone issues properly
*/	
class NiceDate : public boost::posix_time::ptime
{
public:
	/**
		Default constructor gives the time & date now
	*/
	NiceDate();

	/**
		Construct a date for a string representation
		for the local (as opposed to UTC) time.
	*/
	NiceDate ( const std::string & data );

	/**
		Construct a date based on seconds since epoch
		ie Jan 01 1970.
	*/
	NiceDate ( unsigned long seconds );

	bool operator== ( const NiceDate & other ) const;
	
	std::string toString() const;

	std::string value() const
	{
		return toString();
	}
	
	/**
		Return the number of seconds since epoch for this
		date.
	*/
	unsigned long getTime() const;
	
	/// Return the year for this time
	int getYear() const;
	
	/// Return the month (1-12) for this time
	int getMonth() const;
	
	/// Produce a formatted string using strftime and the given format.
	std::string format ( const std::string & format );
};

std::ostream & operator << ( std::ostream &, const NiceDate & );

#endif
