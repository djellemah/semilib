# Microsoft Developer Studio Project File - Name="Utils" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Utils - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Utils.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Utils.mak" CFG="Utils - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Utils - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Utils - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Utils - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\Release"
# PROP Intermediate_Dir "..\..\Release\utils\static"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /G5 /MD /W3 /GX /O2 /Ob2 /I "..\Thread\src" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "NO_USE_UTILS_DLL" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "Utils - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Utils___"
# PROP BASE Intermediate_Dir "Utils___"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\Debug"
# PROP Intermediate_Dir "..\..\Debug\utils\static"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /G5 /MDd /W3 /GX /Z7 /Od /I "..\Thread\src" /D "_DEBUG" /D "UTILS_NO_USE_DLL" /D "WIN32" /D "_WINDOWS" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "Utils - Win32 Release"
# Name "Utils - Win32 Debug"
# Begin Source File

SOURCE=..\utils\AbstractRegex.h
# End Source File
# Begin Source File

SOURCE=..\utils\Change.h
# End Source File
# Begin Source File

SOURCE=..\utils\Cloneable.h
# End Source File
# Begin Source File

SOURCE=..\utils\FileUtils.cpp

!IF  "$(CFG)" == "Utils - Win32 Release"

# ADD CPP /Od

!ELSEIF  "$(CFG)" == "Utils - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\utils\FileUtils.h
# End Source File
# Begin Source File

SOURCE=..\utils\FlagsMapper.cpp
# End Source File
# Begin Source File

SOURCE=..\utils\FlagsMapper.h
# End Source File
# Begin Source File

SOURCE=..\utils\functions.cpp
# End Source File
# Begin Source File

SOURCE=..\utils\functions.h
# End Source File
# Begin Source File

SOURCE=..\utils\istring.cpp
# End Source File
# Begin Source File

SOURCE=..\utils\istring.h
# End Source File
# Begin Source File

SOURCE=..\utils\Lock.cpp
# End Source File
# Begin Source File

SOURCE=..\utils\Lock.h
# End Source File
# Begin Source File

SOURCE=..\utils\minwin.h
# End Source File
# Begin Source File

SOURCE=..\utils\posException.h
# End Source File
# Begin Source File

SOURCE=..\utils\RefCount.cpp
# End Source File
# Begin Source File

SOURCE=..\utils\RefCount.h
# End Source File
# Begin Source File

SOURCE=..\utils\Result.cpp
# End Source File
# Begin Source File

SOURCE=..\utils\Result.h
# End Source File
# Begin Source File

SOURCE=..\utils\SmartPointer.cpp
# End Source File
# Begin Source File

SOURCE=..\utils\SmartPointer.h
# End Source File
# Begin Source File

SOURCE=..\utils\Timer.h
# End Source File
# Begin Source File

SOURCE=..\utils\utilsdlldef.h
# End Source File
# End Target
# End Project
