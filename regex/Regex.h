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

#ifndef Regex_h
#define Regex_h

#include <string>

using namespace std;

#include "regexdlldef.h"
#include "AbstractRegex.h"
#include "FlagsMapper.h"

#include "SmartPointer.h"
#include "StaticInit.h"

#define RE_POSIX_COMPAT
#include "Regexpp/jregex.h"
#define RXSPACE



/**
	exception for problems compiling a particular regular expression
*/
class REGEX_DLL_API rx_exception : public exception
{
public:
	rx_exception ( int rxError, const RXSPACE regex_t & compiled, const string & pattern );
	virtual const char * what() const throw();
protected:
	string msg;
};

/*
You can also set these parameters at run-time (before calling any
regexp functions) by tweaking the corresponding variables:
	rx_default_cache->bytes_allowed
and
	rx_basic_unfaniverse_delay
There is also a lower level interface, explained in rxposix.h:
	rx_make_solutions, rx_next_solution, rx_free_solutions
*/

/**
	What normally happens is that you create pattern which defines
	a set of strings to be matched. In order to make matching fast,
	the pattern is 'compiled' into a different representation. The
	'compilation' will also pick up any syntactical errors you
	may have made in the pattern. See
	<a href="rx.html#SEC4">An Introduction to Regexps</a>
	for an explanation of how the syntax
	of a regular expression works.
	<p>
	You use it like this:
	<pre>
	#include <iostream>
	#include "Regex.h"

	void main()
	{
		Regex someRegex ( "^(.*)=(.*)$" );
		string someString ( "path=.;..;c:\\windows;c:\\windows\\system" );
		if ( someRegex.match ( someString ) )
		{
			cout << "The whole matched string is: " << someRegex[0] << endl;
			cout << "Name is: " << someRegex[1] << endl;
			cout << "Value is: " << someRegex[2] << endl;
		}
		else
			cout << "No Match" << endl;
	}
	</pre>
	You can also use a const char * as a parameter to match (...) because string has a constructor that takes a const char *. Like this:
	<pre>
		Regex someRegex ( "^(.*)=(.*)$" );
		if ( someRegex.match ( "Greeting=Hello" );
		{
		...
		}
	</pre>
	<p>
	Note that this class default uses REG_EXTENDED. This means that the operators
	? | { } ( ) { } + should not be prefixed by a \. The examples in the
	<a href=rx_toc.html>rx-1.5 documentation</a> do not use REG_EXTENDED, and
	so have \ in front of the operators.
	<p>
	Possible values for the flags method and the constructor are
	<table border=1>
	<tr>
		<td valign=top>REG_EXTENDED
		<td>Treat the pattern as an extended regular expression, rather than as a basic regular expression.
	<tr>
		<td valign=top>REG_ICASE
		<td>Ignore case when matching letters.
	<tr>
		<td valign=top>REG_NOSUB
		<td>Don't bother storing the contents of the matches-ptr array.
	<tr>
		<td valign=top>REG_NEWLINE
		<td>Treat a newline in string as dividing string into multiple lines, so that $ can match before the newline and ^ can
			match after. Also, don't permit `.' to match a newline, and don't permit `[^...] to match a newline.
			<p>
		    Otherwise, newline acts like any other ordinary character.
	</table>

	@author John Anderson <a href="mailto:panic@global.co.za">panic@global.co.za</a>
*/
class REGEX_DLL_API Regex : public AbstractRegex
{
public:
	/**
		initialises with no pattern, and flags set to REG_EXTENDED.
	*/
	Regex();

	/**
		should be used most of the time. The regular expression
		is compiled during a call to this constructor, so you'll
		get instant feedback on syntactical errors. You can also
		be sure that the first call to match() happens as
		quickly as possible, because it won't need to still call
		the compile method, as would happen if you call
		pattern ( somePattern ), followed by flags ( someFlags )
		followed by match. This will cause match to recompile the
		expression because the flags have changed.
	*/
	Regex ( const string & pattern, int CFLAGS = REG_EXTENDED );
	~Regex();

	Regex ( const Regex & );
	const Regex & operator = ( const Regex & );

	/**
		@name Accessors
	*/
	//@{
	/**
		Deprecated. use a call to flags ( ) or flag ( ), followed by
		a call to pattern ( string ).
	*/
	Regex & setPattern ( const string & pattern, int CFLAGS = REG_EXTENDED );

	/**
		Deprecated. Use pattern() instead
	*/
	const string & getPattern () const
	{
		return _pattern;
	}
	
	/**
		The way to set the regular expression if you haven't
		already done so in the constructor. This compiles
		the regular expression now so you can get instant
		feedback if you made a mistake.
	*/
	Regex & pattern ( const string & pattern )
	{
		return setPattern ( pattern, flags() );
	}

	/// returns the pattern currently used by this instance
	const string & pattern () const
	{
		return getPattern();
	}

	/// returns the flags used by this instance. See <a href="#flags">Explanation</a>
	int flags () const
	{
		return _flags;
	}

	/// set the flags See <a href="#flags">Explanation</a>
	void flags ( int newFlags )
	{
		_flags = newFlags;
		_changed = true;
	}

	/// set a particular flag on or off, according to the setting
	void flag ( int theflag, bool setting );

	/// get a particular flag
	bool flag ( int theflag );
	//@}

	/**
		returns true or false depending on the match from the beginning
		of the string. Remember to use the ^ and $ operators
		if you want to match from the beginning of a string to the end
		as efficiently as possible.

		This calls compile() if the pattern or the flags have changed
		since the last time the regex was compiled.
	*/
	bool match ( const string & s, unsigned long pos = 0 ) const;

	/**
		returns the indexed subexpression. Throws an exception
		if this instance doesn't have subxpressions enabled ( the REG_NOSUB flag)
		or you've asked for an index that doesn't exist.

		An index of 0 retrieves the part of the string passed to match (...)
		that matches the whole regular expression.
	*/
	string operator [] ( int index ) const;

	/**
		returns the index into the string of the beginning of
		a subexpression.  Somewhat faster than operator[], but
		less convenient because you also have to get the entire
		string matched using operator[](0).
	*/
	int subExpBegin ( int index ) const;

	/**
		returns the index into the string of the end of a
		subexpression.	Somewhat faster than operator[], but
		less convenient because you also have to get the entire
		string matched using operator[](0)
	*/
	int subExpEnd ( int index ) const;

	/**
		returns the number of subexpressions in this match of
		the regular expression. Effectively gives you the maximum value
		you can pass to operator[] (int) and subExpBegin and subExpEnd.
	*/
	int numberOfSubexpressions() const;

	/**
		for keeping Regexes in STL containers. Orders according to the lexical
		order of the pattern.
	*/
	bool operator < ( const Regex & other ) const
	{
		return _pattern < other._pattern;
	}

	/**
		for keeping Regexes in STL containers. orders according to the lexical
		order of the pattern.
	*/
	bool operator == ( const Regex & other ) const
	{
		return _pattern == other._pattern;
	}

/*
	// some example regular expressions

	static Regex whitespace;          // = "[ \n\t\r\v\f]"
	static Regex integer;            // = "-?[0-9]+"
	static Regex rxdouble;         // = "-?\\(\\([0-9]+\\.[0-9]*\\)\\|
										 //    \\([0-9]+\\)\\|\\(\\.[0-9]+\\)\\)
										 //    \\([eE][---+]?[0-9]+\\)?"
	static Regex alpha;          // = "[A-Za-z]"
	static Regex lowercase;      // = "[a-z]"
	static Regex uppercase;      // = "[A-Z]"
	static Regex sentencecase;   // = "[A-Z][a-z]*"
	static Regex alphanum;       // = "[0-9A-Za-z]"
	static Regex identifier;     // = "[A-Za-z_][A-Za-z0-9_]*"
*/

	/**
		FlagsMapper provides a string representation of a set of bitmapped flags.
	*/
	FlagsMapper & mapper() const;

protected:
	/**
		compile the regex. Allows for lazy evaluation
		to take place. Say for example that someone changes
		several flags one after another. There's no point
		in recompiling after each one. Only recompile just
		before the first match after relevant changes
	*/
	void compile ();

	/**
		check that flags are valid, ie that the regex has been initialised.
		Oh, and call compile if necessary
	*/
	void testValid() const;

	/**
		makes sure that everything's in order before
		returning a subexpression. Throws a runtime_error
		if they're not, ie if the index is out of range, or
		if the regex has been compiled with REG_NOSUB
	*/
	void checkSubs( int index ) const;

	/// was the regex compiled with REG_NOSUB
	bool hasSubexp() const
	{
		return !( _flags & REG_NOSUB );
	}

	int subexps() const
	{
#ifdef rx
		return _patternBuffer.re_nsub;
#else
		return _patternBuffer.re_nsub + 1;
#endif
	}

private:
	/// used by rx-1.5 to store the compiled regex.
	RXSPACE regex_t _patternBuffer;

	/// do we need to delete _patternBuffer on destruction?
	mutable bool _patternBufferAllocated;

	/// where the flags (REG_EXTENDED & friend) are stored
	int _flags;

	/// where the string that gets compiled is stored.
	string _pattern;

	/// use this to determine if a call to compile() is necessary
	bool _changed;

	/// the array of subexpression from the last call to match(...)
	/// regmatch_t is defined in inst_rxposix.h
	mutable SmartPointer<RXSPACE regmatch_t> _subExpressions;

	// keeps track of the string we were asked to match
	mutable string _matched;

	/// provides a string representation of the flags bitmapped flags
	static SmartPointer<FlagsMapper> _mapper;

	/// a constant that probably deprecated. I think.
	static const int notRegexFlag;
};


/// for persistence to a stream. Stores the pattern and the flags, using FlagsMapper
REGEX_DLL_API ostream & operator << ( ostream & os, const Regex & regex );

// for persistence from a stream. Retrieves the pattern and the flags, using FlagsMapper
REGEX_DLL_API istream & operator >> ( istream & is, Regex & regex );

#endif