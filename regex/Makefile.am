pkginclude_HEADERS = \
	Regex.h \
	regex-switch.h \
	regexdlldef.h \
	AbstractRegex.h

lib_LTLIBRARIES = libregex.la
libregex_la_SOURCES = Regex.cpp
	
libregex_la_LDFLAGS = -release ${VERSION} ${BOOST_LIBS}

check_PROGRAMS = test
test_SOURCES = regexTest.cpp
test_LDADD = libregex.la ../utils/libutils.la ${BOOST_LIBS}
INCLUDES=-I../utils ${BOOST_INCLUDE}

TESTS=test
