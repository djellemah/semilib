#include <iostream>
#include <string>

#include "FileLogger.h"

using namespace std;
using namespace semilib;

Logger * ::newInstance ( Logger * )
{
	return new FileLogger();
}

int main()
{
	try
	{
#if 0
		cout << "Starting " << &logger << endl;
		cout << "instance " << &Logger::instance() << endl;
		Logger::instance().log( "This is a message" );
	//	cout << hex << &Logger::instance() << endl;
		cout << hex << &logger << endl;
#endif
//		logger.filter ( Level::warning );
		logger << "This is another message" << elog(Level::info);
		logger << "This is a message" << endl;
		logger << "That comes on two lines" << endl;
		logger << "OK, I lied, 3 lines" << endl;
		logger << "<gasp> 4 lines" << endl;
		logger << elog(Level::info);
		
		logger << "This is straight to the logger" << elog( Level::error );
#ifndef _MSC_VER
		logger << "This is straight to the logger with manip" << elog;
#endif
	}
	catch ( exception & e )
	{
		cout << "exception: " << e.what() << endl;
	}
}
