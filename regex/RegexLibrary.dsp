# Microsoft Developer Studio Project File - Name="Regex Library" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Regex Library - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "RegexLibrary.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "RegexLibrary.mak" CFG="Regex Library - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Regex Library - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Regex Library - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Regex_Li"
# PROP BASE Intermediate_Dir "Regex_Li"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\bin"
# PROP Intermediate_Dir "..\Release\regex"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /G5 /MD /W3 /GX /O2 /Ob2 /I "..\Utils" /I "..\regexpp\include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "NO_USE_REGEX_DLL" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\Release\Regex.lib"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Regex_L0"
# PROP BASE Intermediate_Dir "Regex_L0"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\bin"
# PROP Intermediate_Dir "..\Debug\regex"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /G5 /MDd /W3 /GX /Z7 /Od /I "..\Utils" /I "..\regexpp\include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "NO_USE_REGEX_DLL" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\bin\Regex.debug.lib"

!ENDIF 

# Begin Target

# Name "Regex Library - Win32 Release"
# Name "Regex Library - Win32 Debug"
# Begin Source File

SOURCE=.\src\regex.cpp

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# ADD CPP /Od
# SUBTRACT CPP /Z<none>

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\src\Regex.h
# End Source File
# Begin Source File

SOURCE=.\src\regexlib.h
# End Source File
# End Target
# End Project
