dnl Process this file with autoconf to produce a configure script.
AC_INIT(test.cpp)
AM_INIT_AUTOMAKE(utils, 1.0.0)
AM_CONFIG_HEADER(config.h)

dnl Set of available languages.
ALL_LINGUAS="en"

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_ISC_POSIX

dnl Checks for libraries.

dnl Checks for header files.
AC_STDC_HEADERS
AC_HAVE_HEADERS(string)

dnl Checks for library functions.
AC_FUNC_ALLOCA

dnl Check for st_blksize in struct stat
AC_ST_BLKSIZE

dnl internationalization macros
AC_OUTPUT([Makefile])
