/*
Copyright (C) 1998, John Anderson

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU Library General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#pragma warning(disable: 4786)

#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

#include "Regex.h"
#include "SmartPointer.h"

const char * flagsString = ""
	"REG_EXTENDED 1"
	"REG_ICASE 2"
	"REG_NEWLINE 4"
	"REG_NOSUB 8"
	;

SmartPointer<FlagsMapper> Regex::_mapper;

#if !defined __BCPLUSPLUS__ && defined RSXPACE
	using namespace rxSpace;
#endif

/*
	rx_exception implementations
*/
rx_exception::rx_exception ( int rxError, const regex_t & compiled, const string & pattern )
{
	size_t length = regerror ( rxError, &compiled, NULL, 0 );
	SmartPointer<char> buffer ( new char[length+1] );
	regerror ( rxError, &compiled, buffer, length );
	msg = string ( "Regex compilation error: " ) + (char*)buffer + ". ";
	msg += "Pattern was: " + pattern;
}

const char * rx_exception::what() const throw()
{
	return msg.c_str();
}

/*
	Regex implementations
*/
const int Regex::notRegexFlag = ~ (REG_EXTENDED | REG_ICASE | REG_NEWLINE | REG_NOSUB);

Regex::Regex()
	: _patternBufferAllocated ( false )
	, _flags ( REG_EXTENDED )
	, _changed ( true )
{
}

Regex::Regex ( const string & pattern, int flags )
	: _patternBufferAllocated ( false )
	, _pattern ( pattern )
	, _flags ( flags )
	, _changed ( true )
{
	compile();
}

Regex::~Regex()
{
	if ( _patternBufferAllocated )
		regfree ( & _patternBuffer );
}

Regex::Regex ( const Regex & other )
	: _patternBufferAllocated ( false )
{
	operator = ( other );
}


void Regex::flag ( int theflag, bool setting )
{
	if ( setting )
	{
		flags ( flags() | theflag );
	}
	else
	{
		flags ( flags() & ~theflag );
	}
	_changed = true;
}

bool Regex::flag ( int theflag )
{
	return (flags() & theflag) > 0;
}

/*
	This is not the most efficient way to copy a Regex.

	But the most efficient way involves knowing the internals
	of the regex_t structure. Which is actually a C structure
	and quite ugly.
*/
const Regex & Regex::operator = ( const Regex & other)
{
	setPattern ( other._pattern, other._flags );

	_matched = other._matched;
	_changed = true;

	if ( !_matched.empty() )
		match ( _matched );

	return *this;
}

FlagsMapper & Regex::mapper() const
{
	if ( _mapper == 0 )
	{
		_mapper = new FlagsMapper( flagsString );
	}
	return *_mapper;
}

Regex & Regex::setPattern ( const string & pattern, int CFLAGS )
{
#ifdef __GNUG__
	_matched.remove();
#else
	_matched.erase();
#endif

	// make sure the new pattern gets compiled
	_changed = true;

	// remember the values
	_pattern = pattern;
	flags ( CFLAGS );

	return *this;
}

int Regex::numberOfSubexpressions() const
{
	testValid();
	return subexps();
}

bool Regex::match ( const string & toMatch, unsigned long pos ) const
{
	testValid();

	if ( pos < 0 || pos > toMatch.length() )
	{
		ostringstream os;
		os << "Start position " << pos << " for Regular Expression match out of range. ";
		os << "String to match has length " << toMatch.length() << "." << endl;
		throw out_of_range ( os.str().c_str() );
	}

	int result = regexec (
		&_patternBuffer // the pattern to match
		, toMatch.c_str() + pos // the string to match
// commented out cos jregex doesn't need it
//		, toMatch.length() - pos
		, hasSubexp() ? subexps() : 0 // number of subexpressions
		, hasSubexp() ? _subExpressions.data() : 0 // the array of subexpressions
		, 0 // flags REG_BOL and REG_EOL
	);

	if ( result == REG_NOMATCH )
	{
		// no match, so we don't want people asking for subexpressions
		// that were matched ;-)
#ifdef __GNUG__
		_matched.remove();
#else
		_matched.erase();
#endif
		return false;
	}
	else if ( result == REG_ESPACE )
	{
		throw runtime_error ( "Regular expression matcher ran out of memory." );
	}

	// save matched string for operator [], if necessary
	if ( hasSubexp() )
		_matched = toMatch.substr ( pos );
	else
#ifdef __GNUG__
		_matched.remove();
#else
		_matched.erase();
#endif

	// match, so return true
	return true;
}

void Regex::checkSubs( int index ) const
{
	testValid();

	if ( !hasSubexp() )
		throw runtime_error ( "You _told_ this regex that it couldn't use subexpressions, and now you're asking for them!? Sheesh!" );

	if ( index < 0 || index >= subexps() )
	{
		ostringstream os;
		os << "No subexpression at index " << index << ". ";
		os << "There are only " << subexps() << " subexpressions, ";
		os << "and they're zero-based." << endl;
		throw out_of_range ( os.str().c_str() );
	}

}

string Regex::operator [] ( int index ) const
{
	checkSubs ( index );

	// get the beginning and end of the subexpression from
	// the array of regmatch_t.
	int begin = _subExpressions[index].rm_so;
	int end = _subExpressions[index].rm_eo;
	if ( begin == -1 || end == -1 )
	{
		// return a null string
		return string ( _matched.end(), _matched.end() );
	}

	// _matched.begin() is an iterator that points to the beginning of the string
	// _matched.begin() + begin is the beginning of the subexpression
	// _matched.begin() + end is one past the end of the subexpression.
	return string ( _matched.begin() + begin, _matched.begin() + end );
}

int Regex::subExpBegin ( int index ) const
{
	checkSubs ( index );

	// get the beginning and end of the subexpression from
	// the array of regmatch_t.
	return _subExpressions[index].rm_so;
}

int Regex::subExpEnd ( int index ) const
{
	checkSubs( index );

	// get the beginning and end of the subexpression from
	// the array of regmatch_t.
	return _subExpressions[index].rm_eo;
}

void Regex::compile()
{
	// initialise the pattern buffer
	memset ( &_patternBuffer, 0, sizeof(regex_t ) );

	// compile the regex
	int result = regcomp ( &_patternBuffer, pattern().c_str(), flags() );

	// check for problems with the compile
	if ( result != 0 )
		throw rx_exception ( result, _patternBuffer, pattern() );

	// allocate space for subexpressions if necessary
	if ( hasSubexp() )
	{
		_subExpressions = new regmatch_t[subexps()];
	}

	// the pattern buffer should be deleted
	_patternBufferAllocated = true;

	_changed = false;
}

void Regex::testValid() const
{
	if ( _flags == notRegexFlag )
		throw runtime_error ( "Oops. Regex not yet initialised properly. Make a Bug Report." );

	//dunno if this cast is appropriate here...
	if ( _changed ) const_cast<Regex*>(this)->compile();
}

ostream & operator << ( ostream & os, const Regex & regex )
{
	os << regex.getPattern() << endl;
	//os << regex.mapper()[regex.flags()] << endl;
	return os;
}

istream & operator >> ( istream & is, Regex & regex )
{
	string pattern;
	getline ( is, pattern );
	string flags;
	getline ( is, flags );

	regex.setPattern ( pattern, regex.mapper()[flags] );
	return is;
}

/*
 some built-in Regular expressions
*/

/*
Regex Regex::whitespace ( "[ \n\t\r\v\f]+" );
Regex Regex::integer ( "-?[0-9]+" );
Regex Regex::rxdouble ( "-?\\(\\([0-9]+\\.[0-9]*\\)\\|\\([0-9]+\\)\\|\\(\\.[0-9]+\\)\\)\\([eE][---+]?[0-9]+\\)?" );
Regex Regex::alpha ( "[A-Za-z]+" );
Regex Regex::lowercase ( "[a-z]+" );
Regex Regex::uppercase ( "[A-Z]+" );
Regex Regex::alphanum ( "[0-9A-Za-z]+" );
Regex Regex::identifier ( "[A-Za-z_][A-Za-z0-9_]*" );
*/
