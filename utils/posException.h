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

#ifndef posException_h
#define posException_h

#include <sstream>
#include <string>
#include <stdexcept>

#include "utilsdlldef.h"

namespace semilib
{

/**
	Used by PersistenceManager to report that it couldn't restore
	an object from a stream. Part of the error message is the byte
	position in the stream.
	\ingroup persistence
*/
// warning about base class not a dll interface. Which it is.
#pragma warning(disable:4275)
class UTILS_DLL_API posException : public std::runtime_error
{
public:
	posException( long savepos, const std::string & msg )
		: std::runtime_error ( makeMsg ( savepos, msg ) )
	{
	}

protected:
	static std::string makeMsg ( long savepos, const std::string & message )
	{
		using namespace std;
		ostringstream os;
		os << "Error in stream at Position: ";
		os << savepos;
		os << endl;
		os << message;
		return os.str();
	}
};
#pragma warning(default:4275)

}

#endif
