#ifndef FileLogger_h
#define FileLogger_h

#include "Logger.h"

#include <string>

namespace semilib
{

/**
	Specialisation of the Logger class that writes to a log file.
	
	\ingroup logger
*/
class FileLogger : public Logger
{
public:
	/**
		\param prefix defaults to the current executable name
	
		\param home specifies an environment variable that contains
		the directory into which to write the log file. Defaults
		to the directory in which the executable lives.
	*/
	FileLogger ( const std::string & prefix = "", const std::string & home = "" );
	
protected:
	/**
		Return the fully-qualified filename of the log file
	*/
	std::string logfilename() const;

	/**
		Return the full-qualified directory path into which 
		the log file is written.
	*/
	const std::string & directory() const;

	/**
		Write a message to the file. Called by doLog, but
		separate for subclasses.
	*/
	void logToFile ( const std::string & msg, Level::LogLevel );

	/**
		Override the Logger virtual method
	*/
	virtual void doLog ( const std::string & msg, Level::LogLevel level );

	/**
		Return the environment variable that contains
		the directory in which the log file should be written.
	*/
	virtual std::string home() const;

	/**
		Return the prefix of the log file name. Log file will
		be

		[home]-dd-mmm-yyyy.log
	*/
	virtual std::string prefix() const;

private:	
	std::string _directory;
	std::string _home;
	std::string _prefix;
};

}

#endif
