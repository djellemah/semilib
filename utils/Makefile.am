include_HEADERS = \
	AbstractRegex.h \
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

libutils_la_LDFLAGS = -release ${VERSION}

check_PROGRAMS = test
test_SOURCES = test.cpp
test_LDADD = libutils.la

TESTS=test