lib_LTLIBRARIES = libregex.la
libregex_la_SOURCES = Regex.cpp
	
#libregex_la_LDFLAGS = -version-info 1:0:2

bin_PROGRAMS = test
test_SOURCES = regexTest.cpp
test_LDADD = libregex.la -lutils -L/usr/local/boost/lib -lboost_regex
INCLUDES=-I../../utils/src