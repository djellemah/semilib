#include "FileLogger.h"

#include "FileUtils.h"
#include "utils.h"

#include <fstream>
#include <iomanip>

using namespace std;

FileLogger::FileLogger ( const std::string & prefix, const std::string & home )
{
	if ( prefix.empty() )
	{
		_prefix = Utils::executableName();
	}
	else
	{
		_prefix = prefix;
	}
	
	if ( home.empty() )
	{
		_directory = Utils::executableDirectory ();
	}
	else
	{
		_directory = Utils::executableDirectory ( home );
	}
}

std::string FileLogger::home() const
{
	return _home;
}

std::string FileLogger::prefix() const
{
	return _prefix;
}

string FileLogger::logfilename() const
{
	// regenerate every time so we get different dates
	return directory() + prefix() + "-" + today() + ".log";
}

const string & FileLogger::directory() const
{
	return _directory;
}

void FileLogger::logToFile ( const string & msg, Level::LogLevel )
{
	ofstream ofs ( logfilename().c_str(), ios_base::out | ios_base::app );
	ofs << timestamp() << " [" << setw(5) << pid();
#ifdef _WIN32
	// linux currently doesn't have thread id
	ofs << ":" << setw(5) << thread();
#endif
	ofs << "] " << msg;
	ofs << endl;
}

void FileLogger::doLog ( const string & msg, Level::LogLevel level )
{
	logToFile ( msg, level );
}
