#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([cairo], [main])
AC_CHECK_LIB([gnutls], [main])
AC_CHECK_LIB([z], [main])

AC_CHECK_LIB([vte-2.91], [vte_terminal_spawn_async])
AC_CHECK_LIB([gtk-3], [gtk_window_new])
AC_CHECK_LIB([gdk-3], [gdk_screen_get_rgba_visual])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
