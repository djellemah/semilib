include_HEADERS = MatchFunction.h Soundex.h Ranking.h NGram.h

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
test_LDADD = libfuzzy.la ../utils/libutils.la ../regex/libregex.la -L${with_boost}/lib -lboost_regex
INCLUDES=-I../utils -I../regex -I${with_boost}/include