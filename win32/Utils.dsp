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
# PROP Output_Dir "..\Release"
# PROP Intermediate_Dir "..\Release\utils\static"
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
# PROP Output_Dir "..\Debug"
# PROP Intermediate_Dir "..\Debug\utils\static"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /G5 /MDd /W3 /GX /Z7 /Od /I "..\Thread\src" /D "_DEBUG" /D "NO_USE_UTILS_DLL" /D "WIN32" /D "_WINDOWS" /FD /c
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

SOURCE=.\AbstractRegex.h
# End Source File
# Begin Source File

SOURCE=.\Change.h
# End Source File
# Begin Source File

SOURCE=.\Cloneable.h
# End Source File
# Begin Source File

SOURCE=.\FileUtils.cpp

!IF  "$(CFG)" == "Utils - Win32 Release"

# ADD CPP /Od

!ELSEIF  "$(CFG)" == "Utils - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\FileUtils.h
# End Source File
# Begin Source File

SOURCE=.\FlagsMapper.cpp
# End Source File
# Begin Source File

SOURCE=.\FlagsMapper.h
# End Source File
# Begin Source File

SOURCE=.\functions.cpp
# End Source File
# Begin Source File

SOURCE=.\functions.h
# End Source File
# Begin Source File

SOURCE=.\istring.cpp

!IF  "$(CFG)" == "Utils - Win32 Release"

!ELSEIF  "$(CFG)" == "Utils - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\istring.h
# End Source File
# Begin Source File

SOURCE=.\Lock.cpp
# End Source File
# Begin Source File

SOURCE=.\Lock.h
# End Source File
# Begin Source File

SOURCE=.\minwin.h
# End Source File
# Begin Source File

SOURCE=.\Persistence.cpp
# End Source File
# Begin Source File

SOURCE=.\Persistence.h
# End Source File
# Begin Source File

SOURCE=.\PersistenceManager.cpp
# End Source File
# Begin Source File

SOURCE=.\PersistenceManager.h
# End Source File
# Begin Source File

SOURCE=.\posException.h
# End Source File
# Begin Source File

SOURCE=.\RefCount.cpp
# End Source File
# Begin Source File

SOURCE=.\RefCount.h
# End Source File
# Begin Source File

SOURCE=.\Result.cpp
# End Source File
# Begin Source File

SOURCE=.\Result.h
# End Source File
# Begin Source File

SOURCE=.\SmartPointer.cpp
# End Source File
# Begin Source File

SOURCE=.\SmartPointer.h
# End Source File
# Begin Source File

SOURCE=.\Timer.h
# End Source File
# Begin Source File

SOURCE=.\utilsdlldef.h
# End Source File
# End Target
# End Project
