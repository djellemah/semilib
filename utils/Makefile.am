LIBADD = -lpthread -luuid

AM_LDFLAGS = -release ${VERSION} ${LIBADD}

pkginclude_HEADERS = \
	cs_sptr.h \
	Change.h \
	CharArray.h \
	Cloneable.h \
	CoutLogger.h \
	FileLogger.h \
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
	RefCount.h \
	Result.h \
	SingleResult.h \
	Singleton.h \
	SmartPointer.h \
	StaticInit.h \
	TempFile.h \
	Template.h \
	Timer.h \
	utilsdlldef.h \
	utils.h

# utils contains everything.
# logger contains only logger because of a dependency
# on something to provide a newInstance
# libcoutlogger contains a logger that goes to cout
lib_LTLIBRARIES = libsemiutils.la libsemilogger.la libsemicoutlogger.la

libsemiutils_la_SOURCES = \
	FileUtils.cpp \
	FlagsMapper.cpp \
	Lock.cpp \
	Mutex.cpp \
	Persistence.cpp \
	PersistenceManager.cpp \
	Result.cpp \
	RefCount.cpp \
	Singleton.cpp \
	SmartPointer.cpp \
	StaticInit.cpp \
	TempFile.cpp \
	Template.cpp \
	functions.cpp \
	istring.cpp \
	posException.cpp \
	utils.cpp

libsemiutils_la_LDFLAGS = \
	$(AM_LDFLAGS)

LDADD = libsemiutils.la -lpthread ${LIBADD}

libsemilogger_la_SOURCES = Logger.cpp FileLogger.cpp

libsemicoutlogger_la_SOURCES = CoutLogger.cpp

noinst_PROGRAMS = \
	testCoutLogger \
	testPredicateResult \
	testFileLogger \
	testLogger \
	testJoin \
	testRefcount \
	testSingleton \
	testTimer \
	test_strftime

testPredicateResult_SOURCES = testPredicateResult.cpp
testPredicateResult_LDADD = ${LDADD} libsemilogger.la libsemicoutlogger.la

testLogger_SOURCES = testlogger.cpp
testLogger_LDADD = ${LDADD} libsemilogger.la libsemicoutlogger.la

testJoin_SOURCES = testJoin.cpp

testRefcount_SOURCES = testRefcount.cpp

testTimer_SOURCES = testTimer.cpp

testFileLogger_SOURCES = testFileLogger.cpp
testFileLogger_LDADD = ${LDADD} libsemilogger.la

test_strftime_SOURCES = test_strftime.cpp
testSingleton_SOURCES = testSingleton.cpp
testCoutLogger_SOURCES = testCoutLogger.cpp
testCoutLogger_LDADD = libsemicoutlogger.la libsemilogger.la libsemiutils.la
