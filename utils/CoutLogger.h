#ifndef CoutLogger_h
#define CoutLogger_h

#include "Logger.h"

#include <string>

/**
	Logger instance that outputs to stdout
	
	\ingroup logger
*/
class CoutLogger : public Logger
{
public:
	void doLog ( const std::string & msg, Level::LogLevel level );
};

#endif
