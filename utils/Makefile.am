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
	RefCount.h \
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

lib_LTLIBRARIES = libutils.la

libutils_la_SOURCES = \
	FileUtils.cpp \
	FlagsMapper.cpp \
	Persistence.cpp \
	PersistenceManager.cpp \
	RefCount.cpp \
	StaticInit.cpp \
	TempFile.cpp \
	functions.cpp \
	istring.cpp \
	posException.cpp
	utils.cpp \
	Mutex.cpp \
	Logger.cpp

libutils_la_LDFLAGS = -release ${VERSION}

check_PROGRAMS = testPredicateResult

testPredicateResult_SOURCES = testPredicateResult.cpp
testPredicateResult_LDADD = libutils.la

TESTS=test