LIBADD = -lpthread
AM_LDFLAGS = -release ${VERSION} ${LIBADD}

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

# utils contains everything.
# logger contains only logger because of a dependency
# on something to provide a newInstance
# libcoutlogger contains a logger that goes to cout
lib_LTLIBRARIES = libutils.la liblogger.la libcoutlogger.la

libutils_la_SOURCES = \
	FileUtils.cpp \
	FlagsMapper.cpp \
	Mutex.cpp \
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
	utils.cpp

#	RefCount.cpp

LDADD = libutils.la liblogger.la -lpthread ${LIBADD}

liblogger_la_SOURCES = Logger.cpp
libcoutlogger_la_SOURCES = CoutLogger.cpp

check_PROGRAMS = testPredicateResult testLogger
testPredicateResult_SOURCES = testPredicateResult.cpp
testLogger_SOURCES = testlogger.cpp

#TESTS=test
