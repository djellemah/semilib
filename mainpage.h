/**
/\mainpage
This is the Semiosix library of Useful c++ Things (tm). It contains
various utility classes:
	- Logging framework using iostream operators
	- SmartPointer & RefCount smart pointers
	- Singleton
	- various string formatting functions, including join, sprintf and strftime
	- Regex posix regex wrapper, with [] access to subexpressions
	- Lightweight Persistence framework
	- FileUtils various file handling objects and methods
	- Result function error code return value object
	- FlagsMapper maps a set of ints (usually defines) to string error messages
	- StaticInit for optimised static initialisation

The philosophy behind these is that things should be as easy as possible
to code without sacrifices in terms of performance. But they should
still be safe, and not make memory handling an issue.

\todo Do a start/end of function logger and timer

\todo put everthing in namespace semilib

\author John Anderson <a href="mailto:panic at semiosix.com">panic at semiosix.com</a>
*/