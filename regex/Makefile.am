include_HEADERS = Regex.h

lib_LTLIBRARIES = libregex.la
libregex_la_SOURCES = Regex.cpp
	
libregex_la_LDFLAGS = -version-info 1:0:0

check_PROGRAMS = test
test_SOURCES = regexTest.cpp
test_LDADD = libregex.la ../utils/libutils.la ${BOOST_LIB}
INCLUDES=-I../utils ${BOOST_INCLUDE}