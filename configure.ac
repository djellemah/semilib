# Process this file with autoconf to produce a configure script.
AC_INIT([semilib],2.4.2,[panic@semiosix.com])
AM_INIT_AUTOMAKE(dist-bzip2 dist-zip)
AC_CONFIG_SRCDIR([utils/istring.h])
AM_CONFIG_HEADER([config.h])

AC_PREFIX_DEFAULT(/usr/local/semiosix)

# check to see if the user wants to use the boost regex library
AC_ARG_WITH(boost-regex,
AC_HELP_STRING(
	[--with-boost-regex]
	, [use boost regex library. default is to use system regex (regex.h) ])
	,
		test "$withval" = no || with_boost=$withval
		BOOST_LIB="$(BOOST_LIB) -lboost_regex-gcc-mt"
		WITH_BOOST_REGEX=true
	,
		with_boost=no
		WITH_BOOST_REGEX=false
)
AC_SUBST(with_boost)
AC_SUBST(BOOST_INCLUDE)
AC_SUBST(BOOST_LIB)
AC_SUBST(WITH_BOOST_REGEX)

AC_ARG_ENABLE(debug,
AC_HELP_STRING(
	[--enable-debug]
	, [use debugging. default is no])
	, CXXFLAGS=-g
	,
)
AC_SUBST(CXXFLAGS)

# we don't want static libs by default
AC_DISABLE_STATIC 

# Checks for programs.
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LIBTOOL
AC_PROG_MAKE_SET

AC_CONFIG_FILES([
	Makefile
	env
	semilib.pc
	semilogger.pc
	semiregex.pc
	semiutils.pc
	utils/Makefile
	regex/Makefile
	regex/regex-switch.h
	win32/Makefile
])
AC_OUTPUT
