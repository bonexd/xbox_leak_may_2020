# Microsoft Developer Studio Project File - Name="base" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 60000
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) External Target" 0x0106

CFG=base - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "base.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "base.mak" CFG="base - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "base - Win32 Release" (based on "Win32 (x86) External Target")
!MESSAGE "base - Win32 Debug" (based on "Win32 (x86) External Target")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName "base"
# PROP Scc_LocalPath ".."

!IF  "$(CFG)" == "base - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Cmd_Line "NMAKE /f base.mak"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "base.exe"
# PROP BASE Bsc_Name "base.bsc"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Cmd_Line "d:\xbox\public\tools\razzle.cmd build -Z"
# PROP Rebuild_Opt "-c"
# PROP Target_File "xactgui.lib"
# PROP Bsc_Name ""
# PROP Target_Dir ""

!ELSEIF  "$(CFG)" == "base - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Cmd_Line "NMAKE /f base.mak"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "base.exe"
# PROP BASE Bsc_Name "base.bsc"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Cmd_Line "d:\xbox\public\tools\razzle.cmd build -Z"
# PROP Rebuild_Opt "-c"
# PROP Target_File "xactguid.lib"
# PROP Bsc_Name ""
# PROP Target_Dir ""

!ENDIF 

# Begin Target

# Name "base - Win32 Release"
# Name "base - Win32 Debug"

!IF  "$(CFG)" == "base - Win32 Release"

!ELSEIF  "$(CFG)" == "base - Win32 Debug"

!ENDIF 

# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\dlgwrap.cpp
# End Source File
# Begin Source File

SOURCE=.\mdiwrap.cpp
# End Source File
# Begin Source File

SOURCE=.\registry.cpp
# End Source File
# Begin Source File

SOURCE=.\strhlp.cpp
# End Source File
# Begin Source File

SOURCE=.\wndwrap.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\dlgwrap.h
# End Source File
# Begin Source File

SOURCE=.\mdiwrap.h
# End Source File
# Begin Source File

SOURCE=.\registry.h
# End Source File
# Begin Source File

SOURCE=.\strhlp.h
# End Source File
# Begin Source File

SOURCE=.\wndwrap.h
# End Source File
# Begin Source File

SOURCE=.\xactgui.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# Begin Source File

SOURCE=.\sources
# End Source File
# End Target
# End Project