/*
Copyright (C) 1998, 1999, 2000 John Anderson

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

#ifndef Line_h
#define Line_h

/**
	This is a specialisation of basic_string which reads in a line
	(\n terminated) at
	a time from some stream. Not all operators
	and constructors are provided.
	
	\ingroup string
*/
template<class charT>
class basic_Line : public basic_string<charT>
{
public:
	/// read one line from the stream
	void read ( basic_istream<charT> & is )
	{
		getline ( is, *this );
	}

	/// copy other basic_Lines
	basic_Line & operator = ( const basic_Line & other )
	{
		basic_string<charT>::operator = ( other );
		return *this;
	}

	/// copy basic_strings
	basic_Line & operator = ( const basic_string<charT> & other )
	{
		basic_string<charT>::operator = ( other );
		return *this;
	}
};

/**
	an extraction operator for basic_stream
	\ingroup string
*/
template<class charT>
basic_istream<charT> & operator >> ( basic_istream<charT> & is, basic_Line<charT> & line )
{
	line.read ( is );
	return is;
}

typedef basic_Line<char> Line;

#endif

