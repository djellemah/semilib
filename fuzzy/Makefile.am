AM_LDFLAGS = -release ${VERSION}
INCLUDES=-I../utils -I../regex ${BOOST_INCLUDE}

pkginclude_HEADERS = \
	NGramFunctor.h \
	SoundexFunctor.h \
	Ranking.h \
	NGram.h \
	fuzzydlldef.h \
	matchfunctions.h

lib_LTLIBRARIES = libfuzzy.la
libfuzzy_la_SOURCES = \
	NGramFunctor.cpp \
	SoundexFunctor.cpp \
	Ranking.cpp \
	NGram.cpp \
	matchfunctions.cpp

check_PROGRAMS = test
test_SOURCES = FuzzyTextSearch.cpp
test_LDADD = libfuzzy.la ../utils/libutils.la ../regex/libregex.la ${BOOST_LIB}

TESTS=testsearch.sh
