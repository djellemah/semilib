SUBDIRS = utils regex fuzzy
INCLUDES = -I../utils -I../regex -I../fuzzy
EXTRA_DIST = Doxyfile win32 doc/html

dist-hook:
	rm -rf `find $(distdir)/win32 -name CVS`

uninstall-local:
	-rm -R $(prefix)/doc
	
clean-local:
	rm -R $(srcdir)/doc

doc:
	doxygen

install-data-local: doc
	$(INSTALL_DATA) -d $(prefix)/doc/html
	$(INSTALL_DATA) $(srcdir)/doc/html/* $(prefix)/doc/html

