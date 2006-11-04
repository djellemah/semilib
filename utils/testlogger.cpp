#include <iostream>
#include <string>
#include <stdexcept>

#include "Logger.h"
#include "Timer.h"
#include "CoutLogger.h"

using namespace std;
using namespace semilib;

std::string nocall()
{
	throw runtime_error( "nocall should not be called" );
}

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
	
	using namespace Level;
	
	logger.filter(message);
	// test the macros
	glog(debug) << "This is a debug message" << nocall();
	glog(warning) << "This is a warning message on glog";
	
	CoutLogger coutLogger;
	llog(coutLogger,Level::debug) << "coutLogger debug message" << nocall();
	llog(coutLogger,Level::warning) << "coutLogger warning message llog";
	
	// test the timing
	Timer timer;
	for ( int i = 0; i < 1000000; ++i )
	{
		glog(debug) << "This is a debug message";
		glog(message) << "This is a message message";
	}
	cout << "glog elapsed: " << dec << timer.stop() << endl;
	
	timer.start();
	for ( int i = 0; i < 1000000; ++i )
	{
		loch(debug) << "This is a debug message";
		loch(message) << "This is a message message";
	}
	cout << "loch elapsed: " << dec << timer.stop() << endl;
}
