AM_LDFLAGS = -release ${VERSION}

pkginclude_HEADERS = \
	Change.h \
	Cloneable.h \
	FileUtils.h \
	FlagsMapper.h \
	Line.h \
	Lock.h \
	MarkStream.h \
	Persistence.h \
	PersistenceManager.h \
	Result.h \
	SmartPointer.h \
	StaticInit.h \
	TempFile.h \
	Timer.h \
	functions.h \
	istring.h \
	posException.h \
	PredicateResult.h \
	SingleResult.h \
	MultiResult.h \
	utilsdlldef.h \
	utils.h \
	Singleton.h \
	Mutex.h

#	RefCount.h

lib_LTLIBRARIES = libutils.la liblogger.la

libutils_la_SOURCES = \
	FileUtils.cpp \
	FlagsMapper.cpp \
	Persistence.cpp \
	PersistenceManager.cpp \
	StaticInit.cpp \
	TempFile.cpp \
	functions.cpp \
	istring.cpp \
	posException.cpp \
	utils.cpp \
	Mutex.cpp
	
#	RefCount.cpp

libutils_la_LIBADD = -lpthread

liblogger_la_SOURCES = CoutLogger.cpp Logger.cpp

check_PROGRAMS = testPredicateResult

testPredicateResult_SOURCES = testPredicateResult.cpp
testPredicateResult_LDADD = libutils.la liblogger.la -lpthread

#TESTS=test
