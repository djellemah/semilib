include_HEADERS = \
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
	utilsdlldef.h

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
	Mutex.cpp \
	Logger.cpp

#	RefCount.cpp

libutils_la_LDFLAGS = -release ${VERSION} -lpthread

liblogger_la_SOURCES = CoutLogger.cpp
liblogger_la_LDFLAGS = -release ${VERSION}

check_PROGRAMS = testPredicateResult

testPredicateResult_SOURCES = testPredicateResult.cpp
testPredicateResult_LDADD = libutils.la liblogger.la -lpthread

#TESTS=test