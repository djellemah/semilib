pkginclude_HEADERS = \
	Regex.h \
	regex-switch.h \
	regexdlldef.h \
	AbstractRegex.h

lib_LTLIBRARIES = libsemiregex.la
libsemiregex_la_SOURCES = Regex.cpp
	
libsemiregex_la_LDFLAGS = -release ${VERSION} ${BOOST_LIB}

check_PROGRAMS = test
test_SOURCES = regexTest.cpp
test_LDADD = libsemiregex.la ../utils/libsemiutils.la ${BOOST_LIB}
INCLUDES=-I../utils ${BOOST_INCLUDE}

TESTS=test
