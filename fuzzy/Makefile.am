include_HEADERS = \
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
	
libfuzzy_la_LDFLAGS = -release ${VERSION}

check_PROGRAMS = test
test_SOURCES = FuzzyTextSearch.cpp
test_LDADD = libfuzzy.la ../utils/libutils.la ../regex/libregex.la ${BOOST_LIB}
INCLUDES=-I../utils -I../regex ${BOOST_INCLUDE}

TESTS=testsearch.sh