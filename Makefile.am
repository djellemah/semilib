SUBDIRS = utils regex fuzzy win32
INCLUDES = -I../utils -I../regex -I../fuzzy
EXTRA_DIST = Doxyfile semilib.pc

dist-hook:
	rm -rf `find $(distdir)/win32 -name CVS`

uninstall-local:
	-rm -R $(prefix)/doc
	
clean-local:
	rm -R $(srcdir)/doc

doc:
	doxygen

install-data-local: doc
	$(INSTALL_DATA) -d -m 0755 $(prefix)/doc/html
	$(INSTALL_DATA) $(srcdir)/doc/html/* $(prefix)/doc/html

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = semilib.pc
