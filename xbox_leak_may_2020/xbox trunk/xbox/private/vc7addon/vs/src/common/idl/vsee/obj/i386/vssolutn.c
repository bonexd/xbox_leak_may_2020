
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0347 */
/* at Mon Apr 29 23:13:26 2002
 */
/* Compiler settings for vssolutn.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AMD64)

#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IVsExposedObjectProvider,0xd0b027ca,0x8c1f,0x11d0,0x8a,0x34,0x00,0xa0,0xc9,0x1e,0x2a,0xcd);


MIDL_DEFINE_GUID(IID, IID_IVsExposedObjectProvider2,0x2bc4e9c5,0x66b3,0x11d1,0xb1,0x94,0x00,0xa0,0xc9,0x1e,0x2a,0xcd);


MIDL_DEFINE_GUID(IID, IID_IVsEnumExposedObjects,0xd0b027bc,0x8c1f,0x11d0,0x8a,0x34,0x00,0xa0,0xc9,0x1e,0x2a,0xcd);


MIDL_DEFINE_GUID(IID, IID_IVsExposedObject,0xd0b027bd,0x8c1f,0x11d0,0x8a,0x34,0x00,0xa0,0xc9,0x1e,0x2a,0xcd);


MIDL_DEFINE_GUID(IID, IID_IVsExposedCOMServer,0xd0b027be,0x8c1f,0x11d0,0x8a,0x34,0x00,0xa0,0xc9,0x1e,0x2a,0xcd);


MIDL_DEFINE_GUID(IID, IID_IVsExposedCOMServer2,0x2bc4e9c6,0x66b3,0x11d1,0xb1,0x94,0x00,0xa0,0xc9,0x1e,0x2a,0xcd);


MIDL_DEFINE_GUID(IID, IID_IVsExposedMainExe,0xd0b027de,0x8c1f,0x11d0,0x8a,0x34,0x00,0xa0,0xc9,0x1e,0x2a,0xcd);


MIDL_DEFINE_GUID(IID, IID_IVsPersistPropertyStream,0xd0b027cd,0x8c1f,0x11d0,0x8a,0x34,0x00,0xa0,0xc9,0x1e,0x2a,0xcd);


MIDL_DEFINE_GUID(IID, IID_IVsSolutionDebuggingAssistant,0x910E8282,0xF867,0x11d0,0xAB,0x36,0x00,0xA0,0xC9,0x0F,0x27,0x13);


MIDL_DEFINE_GUID(IID, IID_IVsSolutionBuilder,0xd0b027ce,0x8c1f,0x11d0,0x8a,0x34,0x00,0xa0,0xc9,0x1e,0x2a,0xcd);


MIDL_DEFINE_GUID(IID, IID_IVsGroupSelectionDialog,0x2B3B3A2D,0x4E79,0x11d3,0x94,0x77,0x00,0xC0,0x4F,0x68,0x36,0x46);


MIDL_DEFINE_GUID(IID, IID_IVsProjectFilter,0xd0b027d5,0x8c1f,0x11d0,0x8a,0x34,0x00,0xa0,0xc9,0x1e,0x2a,0xcd);


MIDL_DEFINE_GUID(IID, IID_IVsPropertyInterfaceBroker,0xd0b027d8,0x8c1f,0x11d0,0x8a,0x34,0x00,0xa0,0xc9,0x1e,0x2a,0xcd);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/
