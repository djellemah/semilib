include_HEADERS = Regex.h regexdlldef.h

lib_LTLIBRARIES = libregex.la
libregex_la_SOURCES = Regex.cpp
	
libregex_la_LDFLAGS = -release ${VERSION}

check_PROGRAMS = test
test_SOURCES = regexTest.cpp
test_LDADD = libregex.la ../utils/libutils.la ${BOOST_LIB}
INCLUDES=-I../utils ${BOOST_INCLUDE}

TESTS=test