mkdir ..\..\include
mkdir ..\..\include\semilib
rem del /q ..\..\include\semilib\*
rem copy ..\utils\*.h ..\..\include\semilib
rem copy ..\fuzzy\*.h ..\..\include\semilib
rem copy ..\regex\*.h ..\..\include\semilib

echo %path%

call rsync -vt --delete ../utils/*.h ../../include/semilib
call rsync -vt --delete ../fuzzy/*.h ../../include/semilib
call rsync -vt --delete ../regex/*.h ../../include/semilib
