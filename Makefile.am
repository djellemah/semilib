SUBDIRS = utils regex win32
INCLUDES = -I../utils -I../regex -I../fuzzy

AM_CPPFLAGS = -std=c++11

dist-hook:
	rm -rf `find $(distdir)/win32 -name CVS`

uninstall-local:
	-rm -R $(prefix)/doc
	
clean-local:
	rm -R $(srcdir)/doc

docs:
	doxygen

install-docs:
	$(INSTALL_DATA) -d -m 0755 $(prefix)/doc/html
	$(INSTALL_DATA) $(srcdir)/doc/html/* $(prefix)/doc/html

install-data-local:

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = semilib.pc semilogger.pc semiregex.pc semiutils.pc

EXTRA_DIST = Doxyfile $(pkgconfig_DATA)
