# Process this file with autoconf to produce a configure script.
AC_INIT([semilib],2.3.0,[panic@semiosix.com])
AM_INIT_AUTOMAKE(dist-bzip2 dist-zip)
AC_CONFIG_SRCDIR([utils/istring.h])
AM_CONFIG_HEADER([config.h])

AC_PREFIX_DEFAULT(/usr/local/semiosix)

# check to see if the user wants to use the boost regex library
AC_ARG_WITH(boost,
AC_HELP_STRING(
	[--with-boost]
	, [use boost libraries. default is to use system regex (regex.h) ])
	,
		test "$withval" = no || with_boost=$withval
		BOOST_LIBS="-lboost_regex -L$withval/lib"
		BOOST_INCLUDE=-I$withval/boost
		BOOST_DEFINE=true
	,
		with_boost=no
		BOOST_DEFINE=false
)
AC_SUBST(with_boost)
AC_SUBST(BOOST_INCLUDE)
AC_SUBST(BOOST_LIBS)
AC_SUBST(BOOST_DEFINE)

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

# Checks for libraries.

# Checks for header files.
#AC_HEADER_STDC
#AC_CHECK_HEADERS([errno.h fcntl.h stddef.h stdlib.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
#AC_C_CONST
#AC_C_INLINE
#AC_TYPE_SIZE_T
#AC_STRUCT_TM
#AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
#AC_FUNC_MALLOC
#AC_CHECK_FUNCS([memset mkdir strncasecmp regcomp])

AC_CONFIG_FILES([
	Makefile
	semilib.pc
	semilogger.pc
	utils/Makefile
	regex/Makefile
	regex/regex-switch.h
	win32/Makefile
])
AC_OUTPUT
