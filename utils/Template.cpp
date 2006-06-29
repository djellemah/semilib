#include "Template.h"

#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <typeinfo>

using namespace std;
using namespace semilib;

std::ostream & semilib::operator << ( std::ostream & os, const Chunk & chunk )
{
	os << typeid ( chunk ).name() << " { ";
	os << "name: " << chunk.name();
	os << " ";
	os << "value: " << chunk.value();
	os << " }";
	
	return os;
}

std::ostream & semilib::operator << ( std::ostream & os, const Chunk * ptr )
{
	os << *ptr;
	
	return os;
}

Text::Text ( const std::string & value )
: _value ( value )
{
}

Text::~Text()
{
}

std::string Text::name() const
{
	return string();
}

std::string Text::value() const
{
	return _value;
}

std::string Text::replacement() const
{
	return value();
}

Variable::Variable ( const std::string & name )
: _name ( name )
{
}

Variable::~Variable()
{
}

std::string Variable::name() const
{
	return _name;
}

std::string Variable::value() const
{
	return "";
}

std::string Variable::replacement() const
{
	return value();
}

Template::Template ( const std::string & rhs )
: _template ( rhs )
{
	parse();
}

Template::~Template()
{
	for ( Chunks::iterator it = _chunks.begin(); it != _chunks.end(); ++it )
	{
		delete *it;
		*it = 0;
	}
}

void Template::parse()
{
	string::iterator prev = _template.begin();
	string::iterator pos = find ( _template.begin(), _template.end(), '$' );
	
	while ( pos != _template.end() )
	{
		// remember the non-variable
		if ( prev != pos )
		{
			string val ( prev, pos );
			Text * chunk = new Text ( val );
			_chunks.push_back ( chunk );
		}
		
		if ( *(pos+1) == '$' )
		{
			// this is a $$, ie a dollar sign
			
			_chunks.push_back ( new Text ( "$" ) );
			// go past the $$
			pos += 2;
		}
		else
		{
			// this is a variable

			// go past $
			++pos;
			char next = *pos;
			
			// assume the variable is unencapsulated
			// ' ' must be first or other things break
			string finals = " $.";
			
			// if the variable is encapsulated, set the appropriate end character
			if ( next == '(' ) finals = ")"; 
			else if ( next == '{' ) finals = "}";
			
			// go past the encapsulator if there is ones
			if ( finals[0] != ' ' ) ++pos;
			
			// find the last character of the variable
			string::iterator last = find_first_of ( pos, _template.end(), finals.begin(), finals.end() );
			if ( pos != last )
			{
				string var ( pos, last );
				Variable * v = new Variable ( var );
				_chunks.push_back ( v );
				
				pos = last;
				
				// go past the last encapsulator
				if ( finals[0] != ' ' && pos != _template.end() ) ++pos;
			}
		}
		
		prev = pos;
		pos = find ( pos, _template.end(), '$' );
	}
	
	// get the last piece
	if ( prev != pos )
	{
		Text * chunk = new Text ( string ( prev, pos ) );
		_chunks.push_back ( chunk );
	}
}

std::string Template::subst ( std::map<std::string,std::string> values ) const
{
	ostringstream os;
	Chunks::const_iterator it = _chunks.begin();
	for (; it != _chunks.end(); ++it )
	{
		Chunk & chunk = **it;
		if ( chunk.isVariable() )
		{
			if ( values.find ( chunk.name() ) == values.end() )
			{
				throw runtime_error ( chunk.name() + " is not a variable in " + _template );
			}
			os << values[chunk.name()];
		}
		else
		{
			os << chunk.value();
		}
	}
	
	return os.str();
}

std::string Template::subst ( const string & key, const string & value ) const
{
	ostringstream os;
	Chunks::const_iterator it = _chunks.begin();
	for (; it != _chunks.end(); ++it )
	{
		Chunk & chunk = **it;
		if ( chunk.isVariable() )
		{
			if ( key != chunk.name() )
			{
				throw runtime_error ( chunk.name() + " is not a variable in " + _template );
			}
			os << value;
		}
		else
		{
			os << chunk.value();
		}
	}
	
	return os.str();
}
