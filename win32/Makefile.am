EXTRA_DIST = $(wildcard *.dsw *.dsp *.sln *.vcproj)

# convert to DOS line ends
dist-hook:
	for n in *.dsw *.dsp *.sln *.vcproj; do mv $$n $$n.bak; todos <$$n.bak >$$n; done
	rm *.bak

#	rm -rf `find $(distdir)/doc -name CVS`
