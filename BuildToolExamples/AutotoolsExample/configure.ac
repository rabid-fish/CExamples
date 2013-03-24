AC_INIT([TimeManagement], [1.0])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE
AC_PROG_CC

dnl Check for glib
dnl AM_PATH_GLIB_2_0(2.0.0,,AC_MSG_ERROR([No glib found]), glib)

PKG_CHECK_MODULES([GLIB], [glib-2.0])

AC_CONFIG_FILES([Makefile])
AC_CONFIG_SRCDIR(main.c)
AC_CONFIG_MACRO_DIR([m4])
AC_OUTPUT
