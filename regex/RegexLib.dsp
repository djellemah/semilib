# Microsoft Developer Studio Project File - Name="Regex Library" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Regex Library - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Regex Library.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Regex Library.mak" CFG="Regex Library - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Regex Library - Win32 Release" (based on\
 "Win32 (x86) Static Library")
!MESSAGE "Regex Library - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe

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
# ADD CPP /nologo /G5 /MD /W3 /GX /O2 /Ob2 /I ".\vu" /I ".\rx-1.9" /I "..\Utils" /I "..\\" /I ".\rx-1.5" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "__STDC__" /FD /c
# SUBTRACT CPP /YX
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\bin\Regex.lib"

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
# ADD CPP /nologo /G5 /MDd /W3 /GX /Z7 /Od /I "vu" /I "..\Utils" /I "..\\" /I ".\vu" /I ".\rx-1.9" /I ".\rx-1.5" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "__STDC__" /FD /c
# SUBTRACT CPP /YX
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
# Begin Group "rx-1.5"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\src\rx-1.5\_rx.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\hashrexp.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\inst-rxposix.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rx.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rx.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxall.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxanal.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxanal.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxbasic.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxbasic.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxbitset.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxbitset.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxcontext.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxcset.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxcset.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxdbug.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxgnucomp.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxgnucomp.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxhash.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxhash.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxnfa.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxnfa.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxnode.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxnode.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxposix.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxposix.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxproto.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxsimp.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxsimp.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxspencer.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxspencer.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxstr.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxstr.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxsuper.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxsuper.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxunfa.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.5\rxunfa.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.5"

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.5"

!ENDIF 

# End Source File
# End Group
# Begin Group "rx-1.9"

# PROP Default_Filter ""
# Begin Group "vu"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\src\rx-1.9\vu\=names.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\=shuffle.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\ar.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\ar.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\bitset.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\bitset.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\chrname.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\chrname.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\dstr.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\dstr.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\fmt.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\fmt.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\fname.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\fname.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\hashtab.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\hashtab.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\mem.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\mem.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\panic.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\panic.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\reserv.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\reserv.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\scan.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\scan.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\str.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\str.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\vfdbuf.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\vfdbuf.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\vu.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\vu.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\vustr.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\vustr.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\xmalloc.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\vu\xmalloc.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=".\src\rx-1.9\comp.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\comp.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\dbug.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\dbug.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\dfa.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\dfa.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\errnorx.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\errnorx.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\lexer.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\lexer.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\match-regexp.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\match-regexp.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\nfa.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\nfa.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\posix.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\posix.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\regex.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\rexp.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\rexp.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\super.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\super.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\unfa.c"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=".\src\rx-1.9\unfa.h"

!IF  "$(CFG)" == "Regex Library - Win32 Release"

# PROP Intermediate_Dir "..\Release\regex\1.9"
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "Regex Library - Win32 Debug"

# PROP Intermediate_Dir "..\Debug\regex\1.9"
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE=.\src\AbstractRegex.h
# End Source File
# Begin Source File

SOURCE=.\src\regex.cpp
# End Source File
# Begin Source File

SOURCE=.\src\Regex.h
# End Source File
# Begin Source File

SOURCE=.\src\SubExpression.h
# End Source File
# End Target
# End Project
