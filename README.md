## intro
from Fri 01-Nov-2024

This was originally written in 2000-2004, updated slightly in 2019 and 2024.

Really, it's just ancient personal history ;-)

## description
from Fri 22-Mar-2002

This package contains some c++ classes I've written along the
way to make things easier. They're aimed at coder-friendliness.

regex - contains a Regex class to wrap up the POSIX regex calls.

utils - various stuff

## Building

### linux

The usual.

``` bash
./autogen.sh
./configure
make
make install
```

default prefix for configure is `/usr/local/semiosix`

`--with-boost` allows you to specify that the boost regex library should
be used rather than the system regex. Boost is at http://www.boost.org

### win32

You'll need rsync to automagically copy headers, or just use them in
place if you like.

You'll need boost to implement the regex stuff, or some other regex
compatible library and light hacking.
