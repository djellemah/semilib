SUBDIRS = utils regex win32
INCLUDES = -I../utils -I../regex -I../fuzzy

dist-hook:
	rm -rf `find $(distdir)/win32 -name CVS`

uninstall-local:
	-rm -R $(prefix)/doc
	
clean-local:
	rm -R $(srcdir)/doc

docs:
	doxygen

install-data-local: docs
	$(INSTALL_DATA) -d -m 0755 $(prefix)/doc/html
	$(INSTALL_DATA) $(srcdir)/doc/html/* $(prefix)/doc/html

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = semilib.pc semilogger.pc semiregex.pc semiutils.pc

EXTRA_DIST = Doxyfile $(pkgconfig_DATA)
