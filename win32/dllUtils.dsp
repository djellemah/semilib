# Microsoft Developer Studio Project File - Name="dllUtils" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=dllUtils - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "dllUtils.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "dllUtils.mak" CFG="dllUtils - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "dllUtils - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "dllUtils - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "dllUtils - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\bin"
# PROP Intermediate_Dir "..\Release\dllUtils"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /G5 /MD /W3 /GX /O2 /Ob2 /I "..\Regex\src" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "BUILD_UTILS_DLL" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 sxlrt.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"..\bin/utils.dll"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "dllUtils - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\bin"
# PROP Intermediate_Dir "..\Debug\dllUtils"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\Regex\src" /I "..\sxl\include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "BUILD_UTILS_DLL" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 sxlrt.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /nodefaultlib:"msvcprtd.lib" /nodefaultlib:"msvcrtd.lib" /out:"..\bin/utils.debug.dll" /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "dllUtils - Win32 Release"
# Name "dllUtils - Win32 Debug"
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

!IF  "$(CFG)" == "dllUtils - Win32 Release"

!ELSEIF  "$(CFG)" == "dllUtils - Win32 Debug"

# ADD CPP /Ze

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\functions.h
# End Source File
# Begin Source File

SOURCE=.\istring.cpp
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

SOURCE=.\smartnew.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\SmartPointer.cpp
# End Source File
# Begin Source File

SOURCE=.\SmartPointer.h
# End Source File
# Begin Source File

SOURCE=.\StaticInit.h
# End Source File
# Begin Source File

SOURCE=.\Timer.h
# End Source File
# Begin Source File

SOURCE=.\utilsdlldef.h
# End Source File
# End Target
# End Project
