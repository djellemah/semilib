#include <iostream>
#include <string>

#include "Logger.h"

using namespace std;

int main()
{
	Logger::instance().log( "This is a message" );
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
