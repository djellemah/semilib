#ifndef Line_h
#define Line_h

// This reads in a line at a time from some stream. Other
// than that it's a string. Except maybe some of the operators
// and constructors aren't re-implemented here
template<class charT>
class basic_Line : public basic_string<charT>
{
public:
	void read ( basic_istream<charT> & is )
	{
		getline ( is, *this );
	}

	basic_Line & operator = ( const basic_Line & other )
	{
		basic_string<charT>::operator = ( other );
		return *this;
	}

	basic_Line & operator = ( const basic_string<charT> & other )
	{
		basic_string<charT>::operator = ( other );
		return *this;
	}
};

template<class charT>
basic_istream<charT> & operator >> ( basic_istream<charT> & is, basic_Line<charT> & line )
{
	line.read ( is );
	return is;
}

typedef basic_Line<char> Line;

ostream & operator << ( ostream & os, const pair<float,string> & value )
{
	os << fixed << value.first << " " << value.second;
	return os;
}

#endif

