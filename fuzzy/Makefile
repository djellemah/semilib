
FILES = \
BasicSoundex.o \
MatchFunction.o \
NGram.o \
Soundex.o \
matchfunctions.o \
SoundexCharLookup.o \
FuzzyTextSearch.o

TOOLDIR = /usr/local/v3/bin
CPP = $(TOOLDIR)/g++
CPPFLAGS = -fPIC -g -O2
INCLUDE = ../../Utils
LINK = $(TOOLDIR)/g++
LINKFLAGS = -lstdc++
LINKLIBS = -lfuzzy -lutils

LIBNAME = libfuzzy
LIBDIR = /usr/local/lib/site
LIBVERMAJOR = 1
LIBVERMINOR = 0.1
LIBVER = $(LIBVERMAJOR).$(LIBVERMINOR)

.SUFFIXES: .cpp .o

.cpp.o:
	$(CPP) -I $(INCLUDE) $(CPPFLAGS) -c -o $@ $<

all: $(FILES) $(LIBNAME).so.$(LIBVER)

$(LIBNAME).so.$(LIBVER): $(FILES)
	$(LINK) $(CPPFLAGS) -L $(LIBDIR) -shared -Wl,-soname,$(LIBNAME).so.$(LIBVERMAJOR) -o $(LIBNAME).so.$(LIBVER) $(FILES)
	-cp $(LIBNAME).so.$(LIBVER) $(LIBDIR)/$(LIBNAME).so.$(LIBVER)
	-ln -sf $(LIBDIR)/$(LIBNAME).so.$(LIBVER) $(LIBDIR)/$(LIBNAME).so.$(LIBVERMAJOR)
	-ln -sf $(LIBDIR)/$(LIBNAME).so.$(LIBVERMAJOR) $(LIBDIR)/$(LIBNAME).so

fuzzy: $(FILES) $(LIBNAME).so.$(LIBVER) FuzzyTextSearch.o
	 $(CPP) $(CPPFLAGS) -L $(LIBDIR) $(LINKLIBS) -o fuzzy FuzzyTextSearch.o

clean:
	-rm *.o *.so* fuzzy core
