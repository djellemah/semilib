#ifndef CharArray_h
#define CharArray_h

#include <string>
#include <vector>

/**
	To allow easy insertion of elements into something that starts
	off as a char ** array, and must end up as a char ** array
*/
template <class CharType>
class CharArray
{
public:
	CharArray ( int argc, char ** argv )
		: _argsptr ( 0 )
	{
		for ( int i = 0; i < argc; ++i )
		{
			_elements.push_back ( std::string ( argv[i] ) );
		}
	}

	CharArray ( const std::vector<std::string> & elements )
		: _argsptr ( 0 )
	{
		std::vector<std::string>::const_iterator current = elements.begin();

		for ( int i = 0; i < elements.size(); ++i, ++current )
		{
			_elements.push_back ( *current );
		}
	}

	~CharArray()
	{
		cleanup();
	}

	std::vector<std::string> & elements()
	{
		return _elements;
	}
	
	char ** array()
	{
		cleanup();
		// convert args to a char **
		_argsptr = new CharType*[elements().size()];
		std::vector<std::string>::iterator current = elements().begin();
		for (int i = 0; i < elements().size(); ++i, ++current )
		{
			_argsptr[i] = new CharType[current->length() + 1];
			copyString ( _argsptr[i], current->c_str() );
		}
		return _argsptr;
	}

	operator CharType ** ()
	{
		return array();
	}

	int size()
	{
		return elements().size();
	}

protected:
	void copyString ( char * dest, const char * src )
	{
		strcpy ( dest, src );
	}

	void copyString ( wchar_t * dest, const char * src )
	{
		// convert string from 1 byte to 2 bytes per char
		mbstowcs ( dest, src, strlen ( src ) );
		dest[strlen ( src )] = 0;
	}

	void cleanup()
	{
		if ( _argsptr != 0 )
		{
			// remove the elements of the array
			for (int i = 0; i < elements().size(); ++i )
			{
				delete[] _argsptr[i];
			}

			// remove the array
			delete[] _argsptr;
			_argsptr = 0;
		}
	}

private:
	std::vector<std::string> _elements;
	CharType ** _argsptr;
};

#endif
