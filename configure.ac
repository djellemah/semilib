# Process this file with autoconf to produce a configure script.
AC_INIT([semilib],1.2.0,[utils@semiosix.com])
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
		AC_DEFINE(WITH_BOOST, 1, [Are we using the boost regex library?]) 
		BOOST_LIB=-L$withval/lib -lboost_regex
		AC_SUBST(BOOST_LIB)
		BOOST_INCLUDE=-I$withval/include
		AC_SUBST(BOOST_INCLUDE)
	, with_boost=no
)
AC_SUBST(with_boost)

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

AC_CONFIG_FILES([Makefile utils/Makefile fuzzy/Makefile regex/Makefile])
AC_OUTPUT
