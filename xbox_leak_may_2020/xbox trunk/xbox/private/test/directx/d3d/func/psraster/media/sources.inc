!include ..\..\..\..\sources.inc

TARGETNAME=m_psrast
TARGETTYPE=LIBRARY
TARGETPATH=$(TEST_LIB_DEST)

USER_C_FLAGS=$(USER_C_FLAGS) /Zm180

SOURCES=\
    zealot.bmp.cpp