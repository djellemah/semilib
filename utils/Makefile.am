AM_LDFLAGS = -release ${VERSION}

pkginclude_HEADERS = \
	cs_sptr.h \
	Change.h \
	Cloneable.h \
	FileUtils.h \
	FlagsMapper.h \
	functions.h \
	istring.h \
	Line.h \
	Lock.h \
	Logger.h \
	MarkStream.h \
	MultiResult.h \
	Mutex.h \
	Persistence.h \
	PersistenceManager.h \
	posException.h \
	PredicateResult.h \
	Result.h \
	SingleResult.h \
	Singleton.h \
	SmartPointer.h \
	StaticInit.h \
	TempFile.h \
	Timer.h \
	utilsdlldef.h \
	utils.h

#	RefCount.h

lib_LTLIBRARIES = libutils.la liblogger.la

libutils_la_SOURCES = \
	FileUtils.cpp \
	FlagsMapper.cpp \
	Persistence.cpp \
	PersistenceManager.cpp \
	Result.cpp \
	Singleton.cpp \
	SmartPointer.cpp \
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
