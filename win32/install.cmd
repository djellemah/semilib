mkdir ..\..\include
mkdir ..\..\include\semilib
del /q ..\..\include\semilib\*
copy ..\utils\*.h ..\..\include\semilib
copy ..\fuzzy\*.h ..\..\include\semilib
copy ..\regex\*.h ..\..\include\semilib
