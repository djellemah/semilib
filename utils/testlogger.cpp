#include <iostream>
#include <string>

#include "Logger.h"

using namespace std;

int main()
{
	cout << "Starting " << &logger << endl;
	cout << "instance " << &Logger::instance() << endl;
	Logger::instance().log( "This is a message" );
//	cout << hex << &Logger::instance() << endl;
	cout << hex << &logger << endl;
	logger.filter ( Level::warning );
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
	
	logger.filter(Level::all);
	loch(Level::debug) << "This is a debug message";
	// break it up to test the decorator copying
	loch(Level::debug) << "This " << "is " << "another " << "debug " << "message";
	logger.filter(Level::none);
	loch(Level::debug) << "This is not a debug message";
}
