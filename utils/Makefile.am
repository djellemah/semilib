include_HEADERS = \
	AbstractRegex.h Change.h Cloneable.h FileUtils.h FlagsMapper.h Line.h \
	Lock.h MarkStream.h Persistence.h PersistenceManager.h RefCount.h \
	Result.h SmartPointer.h SmartPointer.specialised.h StaticInit.h \
	TempFile.h Timer.h functions.h istring.h \
	posException.h utilsdlldef.h

lib_LTLIBRARIES = libutils.la
libutils_la_SOURCES = FileUtils.cpp \
FlagsMapper.cpp Lock.cpp Persistence.cpp PersistenceManager.cpp RefCount.cpp Result.cpp SmartPointer.cpp StaticInit.cpp TempFile.cpp functions.cpp istring.cpp posException.cpp
libutils_la_LDFLAGS = -version-info 1:0:0

check_PROGRAMS = test
test_SOURCES = test.cpp
test_LDADD = libutils.la

TESTS=test