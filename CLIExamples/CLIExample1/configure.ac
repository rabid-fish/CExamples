AC_INIT([TimeManagement], [1.0])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE
AM_PATH_CHECK
AC_PROG_CC
AC_PROG_LIBTOOL

dnl Check for glib
AM_PATH_GLIB_2_0(2.0.0,,AC_MSG_ERROR([No glib found]), glib)

AC_CONFIG_FILES([Makefile lib/Makefile src/Makefile tests/Makefile])
AC_CONFIG_SRCDIR(src/main.c)
AC_CONFIG_MACRO_DIR([m4])
AC_OUTPUT
