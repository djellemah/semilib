#include <iostream>
#include <string>

#include "Logger.h"

using namespace std;

int main()
{
	Logger::instance().log( "This is a message" );
	Logger::os() << "This is another message" << Logger::end();
	Logger::instance().los() << "This is a message" << endl;
	Logger::instance().los() << "That comes on two lines" << endl;
	Logger::os() << Logger::end();
}
