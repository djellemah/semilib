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
# PROP Intermediate_Dir "..\..\Release\dllUtils"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /G5 /MD /W3 /GR /GX /O2 /Ob2 /I "..\Regex\src" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "UTILS_BUILD_DLL" /FD /c
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
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386 /out:"../../dlls/utils.dll"
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
# PROP Intermediate_Dir "..\..\Debug\dllUtils"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "..\Regex\src" /I "..\sxl\include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "UTILS_BUILD_DLL" /FD /c
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
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"../../dlls/utils.debug.dll" /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "dllUtils - Win32 Release"
# Name "dllUtils - Win32 Debug"
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

!IF  "$(CFG)" == "dllUtils - Win32 Release"

!ELSEIF  "$(CFG)" == "dllUtils - Win32 Debug"

# ADD CPP /Ze

!ENDIF 

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

!IF  "$(CFG)" == "dllUtils - Win32 Release"

!ELSEIF  "$(CFG)" == "dllUtils - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\utils\Lock.h

!IF  "$(CFG)" == "dllUtils - Win32 Release"

!ELSEIF  "$(CFG)" == "dllUtils - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\utils\minwin.h
# End Source File
# Begin Source File

SOURCE=..\utils\Mutex.cpp
# End Source File
# Begin Source File

SOURCE=..\utils\Mutex.h
# End Source File
# Begin Source File

SOURCE=..\utils\posException.cpp
# End Source File
# Begin Source File

SOURCE=..\utils\posException.h
# End Source File
# Begin Source File

SOURCE=..\utils\RefCount.cpp

!IF  "$(CFG)" == "dllUtils - Win32 Release"

!ELSEIF  "$(CFG)" == "dllUtils - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\utils\RefCount.h

!IF  "$(CFG)" == "dllUtils - Win32 Release"

!ELSEIF  "$(CFG)" == "dllUtils - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\utils\Result.cpp
# End Source File
# Begin Source File

SOURCE=..\utils\Result.h
# End Source File
# Begin Source File

SOURCE=..\utils\Singleton.cpp
# End Source File
# Begin Source File

SOURCE=..\utils\Singleton.h
# End Source File
# Begin Source File

SOURCE=..\utils\smartnew.cpp
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\utils\SmartPointer.cpp
# End Source File
# Begin Source File

SOURCE=..\utils\SmartPointer.h
# End Source File
# Begin Source File

SOURCE=..\utils\StaticInit.h
# End Source File
# Begin Source File

SOURCE=..\utils\TempFile.cpp
# End Source File
# Begin Source File

SOURCE=..\utils\TempFile.h
# End Source File
# Begin Source File

SOURCE=..\utils\Timer.h
# End Source File
# Begin Source File

SOURCE=..\utils\utilsdlldef.h
# End Source File
# Begin Source File

SOURCE=..\utils\WinResult.h
# End Source File
# End Target
# End Project
