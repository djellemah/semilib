EXTRA_DIST = $(wildcard *.dsw *.dsp *.sln *.vcproj)

# convert to DOS line ends
dist-hook:
	for n in *.dsw *.dsp *.sln *.vcproj; do unix2dos $$n; done
