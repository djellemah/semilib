# Regex Makefile
# Places to install libraries, binaries, etc.
prefix     = /usr/local
bindir     = $(prefix)/bin
libdir     = $(prefix)/lib
includedir = $(prefix)/include

# For some losing Unix makes.
SHELL = /bin/sh

# The C and C++ compilers to use.
CC         = gcc
CXX        = g++

# Various programs used in compilation and running of the programs.
RANLIB     = ranlib
AR			= ar
LD			= ld
MAKEDEPEND = :  -D__cplusplus
EXEXT		=

# Compilation and linking flags.
CFLAGS            = -x c -D__STDC__ -ansi
CXXFLAGS          = -fhandle-exceptions -frtti -x c++
LDFLAGS           =

CXXFLAGS_EXTRA    = -I. -I../../Utils -I ../../compatibility
CXXFLAGS_ALL      = $(CXXFLAGS) $(CXXFLAGS_EXTRA)
EXTRA_ARFLAGS	  =

CPPFILES = Regex.cpp

OFILES = $(CPPFILES:.cpp=.o)

REGEXLIB = regex.so

$(REGEXLIB): $(OFILES)
	$(CXX) -shared -Wl,-soname,$(REGEXLIB).1 -o $(REGEXLIB).1.0 $(OFILES)
	cp $(REGEXLIB).1.0 $(REGEXLIB).1
	cp $(REGEXLIB).1 $(REGEXLIB)
#	ln -s $(REGEXLIB).1.0 $(REGEXLIB).1
#	ln -s $(REGEXLIB).1.0 $(REGEXLIB)

regextest$(EXEXT): $(REGEXLIB)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS_ALL) regexTest.cpp -x none -o $@ $(REGEXLIB)

.SUFFIXES: .o .cpp .c

.cpp.o:
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS_ALL) $< -o $@

.c.o:
	$(CXX) -c $(CFLAGS) $(CXXFLAGS_EXTRA) $< -o $@

.PHONY: depend
depend:
	$(MAKEDEPEND) $(CFILES)

clean:
	-rm -f *.o *~ *.bak core *.so.* *.obj
