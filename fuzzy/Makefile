
FILES = \
BasicSoundex.o \
MatchFunction.o \
NGram.o \
Soundex.o \
matchfunctions.o \
FuzzyTextSearch.o

CPPFLAGS = -fPIC -fhonor-std
INCLUDE = ../../Utils
LINK = gcc
LINKFLAGS = -fhonor-std -lstdc++
LINKLIBS = -lfuzzy -lstdc++ -lutils

LIBNAME = libfuzzy
LIBDIR = /usr/local/lib/site
LIBVERMAJOR = 1
LIBVERMINOR = 0.1
LIBVER = $(LIBVERMAJOR).$(LIBVERMINOR)

.SUFFIXES: .cpp .o

.cpp.o:
	c++ $(CPPFLAGS) -I $(INCLUDE) -c -o $@ $<

all: $(FILES) $(LIBNAME).so fuzzy

$(LIBNAME).so:
	$(LINK) -shared -Wl,-soname,$(LIBNAME).so.$(LIBVERMAJOR) -o $(LIBDIR)/$(LIBNAME).so.$(LIBVER) $(FILES) -lc
	-ln -s $(LIBDIR)/$(LIBNAME).so.$(LIBVER) $(LIBDIR)/$(LIBNAME).so

fuzzy: $(FILES) $(LIBNAME).so FuzzyTextSearch.o
	 c++ $(CPPFLAGS) -L $(LIBDIR) $(LINKLIBS) -o fuzzy FuzzyTextSearch.o

clean:
	-rm *.o
	-rm *.so*

