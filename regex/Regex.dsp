# Microsoft Developer Studio Project File - Name="Regex" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Regex - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Regex.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Regex.mak" CFG="Regex - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Regex - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Regex - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe

!IF  "$(CFG)" == "Regex - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ""
# PROP BASE Intermediate_Dir ""
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ""
# PROP Intermediate_Dir ""
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /G5 /W3 /GX /O2 /Ob2 /I "..\Utils" /I "..\Regex" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /FD /c
# SUBTRACT CPP /YX
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "Regex - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "..\Debug"
# PROP BASE Intermediate_Dir "..\Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\Debug"
# PROP Intermediate_Dir "..\Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Z7 /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /G5 /W3 /GX /Z7 /Od /I "..\Utils" /I "..\Regex" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /FD /c
# SUBTRACT CPP /YX
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "Regex - Win32 Release"
# Name "Regex - Win32 Debug"
# Begin Group "cfiles"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\_rx.h
# End Source File
# Begin Source File

SOURCE=.\hashrexp.c
# End Source File
# Begin Source File

SOURCE=".\inst-rxposix.h"
# End Source File
# Begin Source File

SOURCE=.\rx.c
# End Source File
# Begin Source File

SOURCE=.\rx.h
# End Source File
# Begin Source File

SOURCE=.\rxall.h
# End Source File
# Begin Source File

SOURCE=.\rxanal.c
# End Source File
# Begin Source File

SOURCE=.\rxanal.h
# End Source File
# Begin Source File

SOURCE=.\rxbasic.c
# End Source File
# Begin Source File

SOURCE=.\rxbasic.h
# End Source File
# Begin Source File

SOURCE=.\rxbitset.c
# End Source File
# Begin Source File

SOURCE=.\rxbitset.h
# End Source File
# Begin Source File

SOURCE=.\rxcontext.h
# End Source File
# Begin Source File

SOURCE=.\rxcset.c
# End Source File
# Begin Source File

SOURCE=.\rxcset.h
# End Source File
# Begin Source File

SOURCE=.\rxdbug.c
# End Source File
# Begin Source File

SOURCE=.\rxgnucomp.c
# End Source File
# Begin Source File

SOURCE=.\rxgnucomp.h
# End Source File
# Begin Source File

SOURCE=.\rxhash.c
# End Source File
# Begin Source File

SOURCE=.\rxhash.h
# End Source File
# Begin Source File

SOURCE=.\rxnfa.c
# End Source File
# Begin Source File

SOURCE=.\rxnfa.h
# End Source File
# Begin Source File

SOURCE=.\rxnode.c
# End Source File
# Begin Source File

SOURCE=.\rxnode.h
# End Source File
# Begin Source File

SOURCE=.\rxposix.c
# End Source File
# Begin Source File

SOURCE=.\rxposix.h
# End Source File
# Begin Source File

SOURCE=.\rxproto.h
# End Source File
# Begin Source File

SOURCE=.\rxsimp.c
# End Source File
# Begin Source File

SOURCE=.\rxsimp.h
# End Source File
# Begin Source File

SOURCE=.\rxspencer.c
# End Source File
# Begin Source File

SOURCE=.\rxspencer.h
# End Source File
# Begin Source File

SOURCE=.\rxstr.c
# End Source File
# Begin Source File

SOURCE=.\rxstr.h
# End Source File
# Begin Source File

SOURCE=.\rxsuper.c
# End Source File
# Begin Source File

SOURCE=.\rxsuper.h
# End Source File
# Begin Source File

SOURCE=.\rxunfa.c
# End Source File
# Begin Source File

SOURCE=.\rxunfa.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Makefile
# End Source File
# Begin Source File

SOURCE=.\Regex.cpp
# End Source File
# Begin Source File

SOURCE=.\Regex.h
# End Source File
# End Target
# End Project
