# Process this file with autoconf to produce a configure script.
#AC_INIT(fuzzy, 1.0.0, panic@semiosix.com)
#AM_INIT_AUTOMAKE(fuzzy, 1.0.0)
AM_CONFIG_HEADER(config.h)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LIBTOOL

# Checks for header files.
AC_HEADER_STDCPP
AC_CHECK_HEADERS([errno.h fcntl.h stddef.h stdlib.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T
AC_STRUCT_TM
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([mkdir strncasecmp])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
