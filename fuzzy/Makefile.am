include_HEADERS = MatchFunction.h Soundex.h \
	Ranking.h NGram.h fuzzydlldef.h \
	BasicSoundex.h SoundexCharLookup.h \
	matchfunctions.h

lib_LTLIBRARIES = libfuzzy.la
libfuzzy_la_SOURCES = \
	BasicSoundex.cpp \
	MatchFunction.cpp \
	Ranking.cpp \
	SoundexCharLookup.cpp \
	NGram.cpp \
	Soundex.cpp \
	matchfunctions.cpp
	
libfuzzy_la_LDFLAGS = -version-info 1:0:0

check_PROGRAMS = test
test_SOURCES = FuzzyTextSearch.cpp
test_LDADD = libfuzzy.la ../utils/libutils.la ../regex/libregex.la ${BOOST_LIB}
INCLUDES=-I../utils -I../regex ${BOOST_INCLUDE}

TESTS=testsearch.sh