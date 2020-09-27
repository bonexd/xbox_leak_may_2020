/*
    snaoledb.h
    Constant values for the Microsoft OLE DB Provider for AS/400 and VSAM
    Version 02.01 (DBPROP_PROVIDERVER)
    Copyright (c) 1998, Microsoft Corporation.  All rights reserved.
*/

#ifndef __SNAOLEDB_h__
#define __SNAOLEDB_h__

DEFINE_GUID(CLSID_SNAOLEDB,
0xb15ff21, 0xb29, 0x11d0, 0x8c, 0x61, 0x0, 0xc0, 0xf0, 0xb, 0xc2, 0x49);

DEFINE_GUID(CLSID_SNAOLEDB_ERROR_LOOKUP_SERVICE, 
0xb15ff24, 0xb29, 0x11d0, 0x8c, 0x61, 0x0, 0xc0, 0xf0, 0xb, 0xc2, 0x49);

DEFINE_GUID(SNAOLEDB_DBPROPSET_DBINIT, 
0xc7f24a12, 0x4a9d, 0x11d2, 0x85, 0x7, 0x0, 0x0, 0xf8, 0x7a, 0x53, 0xf8);

// Provider specific SNAOLEDB_DBPROPSET_DBINIT property IDs.
enum SNAOLEDB_DBPROPENUM
{
	DBPROP_SNAOLEDB_REMOTELU	= 0x02,         /* APPC Remote LU Alias. For SNA NETTYPE. */
	DBPROP_SNAOLEDB_LOCALLU		= 0x03,         /* APPC Local LU Alias. For SNA NETTYPE. */
	DBPROP_SNAOLEDB_APPCMODE	= 0x04,         /* APPC Mode Name. For SNA NETTYPE. */
	DBPROP_SNAOLEDB_LIBRARY		= 0x05,         /* Default Library Name */
	DBPROP_SNAOLEDB_HOSTCCSID	= 0x06,         /* Host CCSID. See SNA Server docs for supported values. */
	DBPROP_SNAOLEDB_PCCODEPAGE	= 0x07,         /* PC Code Page. See SNA Server docs for supported values. */
	DBPROP_SNAOLEDB_HCDPATH		= 0x08,         /* Path of Host Column Description file */
	DBPROP_SNAOLEDB_BINASCHAR	= 0x09,         /* Process Binary as Character */
	DBPROP_SNAOLEDB_REPAIRKEY	= 0x0a,         /* TRUE will cause the provider to repair invalid key information returned by older versions of OS/400 */
	DBPROP_SNAOLEDB_STRICTVAL	= 0x0b,         /* Reserved for future use. */
	DBPROP_SNAOLEDB_NETTYPE		= 0x0c,         /* Network Transport Library "SNA" or "TCPIP" */
	DBPROP_SNAOLEDB_NETADDRESS	= 0x0d,         /* Network Address. For TCPIP NETTYPE.  IP address or hostname */
    DBPROP_SNAOLEDB_NETPORT     = 0x0e          /* Network Port. For TCPIP NETTYPE. */
};

/* Native Error Codes: */
#define SNAOLEDB_ERROR                      -1
#define SNAOLEDB_ERROR_SEND                 -2
#define SNAOLEDB_ERROR_RECEIVE              -3
#define SNAOLEDB_INVALID_POINTER            -4
#define SNAOLEDB_INVALID_PARAM              -5
#define SNAOLEDB_INVALID_DATA               -6
#define SNAOLEDB_INVALID_CONVERSION         -7
#define SNAOLEDB_INVALID_USER               -8
#define SNAOLEDB_ERROR_WRITE                -9
#define SNAOLEDB_ERROR_READ                 -10
#define SNAOLEDB_FILE_NOT_FOUND             -11
#define SNAOLEDB_INDEX_NOT_FOUND            -12
#define SNAOLEDB_RECORD_NOT_FOUND           -13
#define SNAOLEDB_KEY_NOT_FOUND              -14
#define SNAOLEDB_INVALID_FORMAT             -15
#define SNAOLEDB_MAX_CONNECTIONS            -16
#define SNAOLEDB_NOT_CONNECTED              -17
#define SNAOLEDB_NETWORK_ERROR              -18
#define SNAOLEDB_INVALID_DATASOURCE         -19
#define SNAOLEDB_ACCESS_DENIED              -20
#define SNAOLEDB_FILE_NOT_OPENED            -21
#define SNAOLEDB_MEMORY_ALLOC               -22
#define SNAOLEDB_DATA_NOT_FOUND             -23
#define SNAOLEDB_INDEX_EXISTS               -24
#define SNAOLEDB_FUNCTION_NOT_SUPPORTED     -25
#define SNAOLEDB_NO_CACHE                   -26
#define SNAOLEDB_FILE_LENGTH                -27
#define SNAOLEDB_INVALID_CONN_ID            -28
#define SNAOLEDB_INVALID_FILE_ID            -29
#define SNAOLEDB_INVALID_FILENAME           -30
#define SNAOLEDB_LOCAL_FILE_ERROR           -31
#define SNAOLEDB_INVALID_VIEW_ID            -32
#define SNAOLEDB_INVALID_VIEW               -33
#define SNAOLEDB_DISK_FULL                  -34
#define SNAOLEDB_DEST_FILE_CHANGED          -35
#define SNAOLEDB_FTX_FAILED                 -36
#define SNAOLEDB_FTX_ABORTED_BY_HOST        -37
#define SNAOLEDB_CONNECTION_LOST            -38
#define SNAOLEDB_CONNECTION_BUSY            -39
#define SNAOLEDB_HOST_NOT_RESPONDING        -40
#define SNAOLEDB_INVALID_DATA_CONV          -41
#define SNAOLEDB_DATA_TYPE_NOT_SUPPORTED    -42
#define SNAOLEDB_TIMEOUT                    -43
#define SNAOLEDB_DDMAGENT_NOT_LOADED        -44
#define SNAOLEDB_COMPONENT_MISSING          -45
#define SNAOLEDB_DCONV_DLL_NOT_FOUND        -46
#define SNAOLEDB_INVALID_STMT_HANDLE        -47
#define SNAOLEDB_VALUE_NOT_SUPPORTED        -48
#define SNAOLEDB_SQL_ERROR                  -49


/* 
    DDM originated error codes
    The last segment of the constant identifier is the DDM Code Point name returned from the host
    Refer to IBM Publication: SC21-9526 DDM Architecture Reference
*/
#define SNAOLEDB_DDM_ERROR_START    -256
#define SNAOLEDB_DDM_ABNUOWRM    	(SNAOLEDB_DDM_ERROR_START-0)        /* -256 */
#define SNAOLEDB_DDM_ACCATHRM    	(SNAOLEDB_DDM_ERROR_START-1) 
#define SNAOLEDB_DDM_ACCINTRM    	(SNAOLEDB_DDM_ERROR_START-2) 
#define SNAOLEDB_DDM_ACCMTHRM    	(SNAOLEDB_DDM_ERROR_START-3) 
#define SNAOLEDB_DDM_ACCRDBRM    	(SNAOLEDB_DDM_ERROR_START-4) 
#define SNAOLEDB_DDM_AGNPRMRM    	(SNAOLEDB_DDM_ERROR_START-5) 
#define SNAOLEDB_DDM_BASNAMRM    	(SNAOLEDB_DDM_ERROR_START-6) 
#define SNAOLEDB_DDM_BGNBNDRM    	(SNAOLEDB_DDM_ERROR_START-7) 
#define SNAOLEDB_DDM_CHGFATRM    	(SNAOLEDB_DDM_ERROR_START-8) 
#define SNAOLEDB_DDM_CLSDMGRM    	(SNAOLEDB_DDM_ERROR_START-9) 
#define SNAOLEDB_DDM_CMBACCAM    	(SNAOLEDB_DDM_ERROR_START-10)       /* -266 */
#define SNAOLEDB_DDM_CMBKEYAM    	(SNAOLEDB_DDM_ERROR_START-11) 
#define SNAOLEDB_DDM_CMBRNBAM    	(SNAOLEDB_DDM_ERROR_START-12) 
#define SNAOLEDB_DDM_CMDATHRM    	(SNAOLEDB_DDM_ERROR_START-13) 
#define SNAOLEDB_DDM_CMDCHKRM    	(SNAOLEDB_DDM_ERROR_START-14) 
#define SNAOLEDB_DDM_CMDCMPRM    	(SNAOLEDB_DDM_ERROR_START-15) 
#define SNAOLEDB_DDM_CMDNSPRM    	(SNAOLEDB_DDM_ERROR_START-16) 
#define SNAOLEDB_DDM_CMDVLTRM    	(SNAOLEDB_DDM_ERROR_START-17) 
#define SNAOLEDB_DDM_CMMRQSRM    	(SNAOLEDB_DDM_ERROR_START-18) 
#define SNAOLEDB_DDM_CSRNSARM    	(SNAOLEDB_DDM_ERROR_START-19) 
#define SNAOLEDB_DDM_DCLCNFRM    	(SNAOLEDB_DDM_ERROR_START-20)       /* -276 */
#define SNAOLEDB_DDM_DCLNAMRM    	(SNAOLEDB_DDM_ERROR_START-21) 
#define SNAOLEDB_DDM_DCLNFNRM    	(SNAOLEDB_DDM_ERROR_START-22) 
#define SNAOLEDB_DDM_DRCATHRM    	(SNAOLEDB_DDM_ERROR_START-23) 
#define SNAOLEDB_DDM_DRCDMGRM    	(SNAOLEDB_DDM_ERROR_START-24) 
#define SNAOLEDB_DDM_DRCENTRM    	(SNAOLEDB_DDM_ERROR_START-25) 
#define SNAOLEDB_DDM_DRCFULRM    	(SNAOLEDB_DDM_ERROR_START-26) 
#define SNAOLEDB_DDM_DRCIUSRM    	(SNAOLEDB_DDM_ERROR_START-27) 
#define SNAOLEDB_DDM_DRCNAMRM    	(SNAOLEDB_DDM_ERROR_START-28) 
#define SNAOLEDB_DDM_DRCNEMRM    	(SNAOLEDB_DDM_ERROR_START-29) 
#define SNAOLEDB_DDM_DRCNFNRM    	(SNAOLEDB_DDM_ERROR_START-30)       /* -286 */
#define SNAOLEDB_DDM_DRCSNARM    	(SNAOLEDB_DDM_ERROR_START-31) 
#define SNAOLEDB_DDM_DRCSUBRM    	(SNAOLEDB_DDM_ERROR_START-32) 
#define SNAOLEDB_DDM_DRCTNARM    	(SNAOLEDB_DDM_ERROR_START-33) 
#define SNAOLEDB_DDM_DSCINVRM    	(SNAOLEDB_DDM_ERROR_START-34) 
#define SNAOLEDB_DDM_DTAMAPRM    	(SNAOLEDB_DDM_ERROR_START-35) 
#define SNAOLEDB_DDM_DTAMCHRM    	(SNAOLEDB_DDM_ERROR_START-36) 
#define SNAOLEDB_DDM_DTANFNRM    	(SNAOLEDB_DDM_ERROR_START-37) 
#define SNAOLEDB_DDM_DTARECRM    	(SNAOLEDB_DDM_ERROR_START-38) 
#define SNAOLEDB_DDM_DUPDCLRM    	(SNAOLEDB_DDM_ERROR_START-39) 
#define SNAOLEDB_DDM_DUPDRCRM    	(SNAOLEDB_DDM_ERROR_START-40)       /* -296 */
#define SNAOLEDB_DDM_DUPFILRM    	(SNAOLEDB_DDM_ERROR_START-41) 
#define SNAOLEDB_DDM_DUPKDIRM    	(SNAOLEDB_DDM_ERROR_START-42) 
#define SNAOLEDB_DDM_DUPKSIRM    	(SNAOLEDB_DDM_ERROR_START-43) 
#define SNAOLEDB_DDM_DUPQUERM    	(SNAOLEDB_DDM_ERROR_START-44) 
#define SNAOLEDB_DDM_DUPRNBRM    	(SNAOLEDB_DDM_ERROR_START-45) 
#define SNAOLEDB_DDM_ENDFILRM    	(SNAOLEDB_DDM_ERROR_START-46) 
#define SNAOLEDB_DDM_ENDQRYRM    	(SNAOLEDB_DDM_ERROR_START-47) 
#define SNAOLEDB_DDM_ENDUOWRM    	(SNAOLEDB_DDM_ERROR_START-48) 
#define SNAOLEDB_DDM_EXSCNDRM    	(SNAOLEDB_DDM_ERROR_START-49) 
#define SNAOLEDB_DDM_FILATHRM    	(SNAOLEDB_DDM_ERROR_START-50)       /* -306 */
#define SNAOLEDB_DDM_FILDMGRM    	(SNAOLEDB_DDM_ERROR_START-51) 
#define SNAOLEDB_DDM_FILFULRM    	(SNAOLEDB_DDM_ERROR_START-52) 
#define SNAOLEDB_DDM_FILIUSRM    	(SNAOLEDB_DDM_ERROR_START-53) 
#define SNAOLEDB_DDM_FILNAMRM    	(SNAOLEDB_DDM_ERROR_START-54) 
#define SNAOLEDB_DDM_FILNFNRM    	(SNAOLEDB_DDM_ERROR_START-55) 
#define SNAOLEDB_DDM_FILNOPRM    	(SNAOLEDB_DDM_ERROR_START-56) 
#define SNAOLEDB_DDM_FILOLORM    	(SNAOLEDB_DDM_ERROR_START-57) 
#define SNAOLEDB_DDM_FILSNARM    	(SNAOLEDB_DDM_ERROR_START-58) 
#define SNAOLEDB_DDM_FILTNARM    	(SNAOLEDB_DDM_ERROR_START-59) 
#define SNAOLEDB_DDM_INTATHRM    	(SNAOLEDB_DDM_ERROR_START-60)       /* -316 */
#define SNAOLEDB_DDM_INTTKNRM    	(SNAOLEDB_DDM_ERROR_START-61) 
#define SNAOLEDB_DDM_INVRQSRM    	(SNAOLEDB_DDM_ERROR_START-62) 
#define SNAOLEDB_DDM_INVUSRRM    	(SNAOLEDB_DDM_ERROR_START-63) 
#define SNAOLEDB_DDM_KEYDEFRM    	(SNAOLEDB_DDM_ERROR_START-64) 
#define SNAOLEDB_DDM_KEYLENRM    	(SNAOLEDB_DDM_ERROR_START-65) 
#define SNAOLEDB_DDM_KEYMODRM    	(SNAOLEDB_DDM_ERROR_START-66) 
#define SNAOLEDB_DDM_KEYUDIRM    	(SNAOLEDB_DDM_ERROR_START-67) 
#define SNAOLEDB_DDM_KEYUSIRM    	(SNAOLEDB_DDM_ERROR_START-68) 
#define SNAOLEDB_DDM_KEYVALRM    	(SNAOLEDB_DDM_ERROR_START-69) 
#define SNAOLEDB_DDM_LODSTRRM    	(SNAOLEDB_DDM_ERROR_START-70)       /* -326 */
#define SNAOLEDB_DDM_MGMATHRM    	(SNAOLEDB_DDM_ERROR_START-71) 
#define SNAOLEDB_DDM_MGMCLSNM    	(SNAOLEDB_DDM_ERROR_START-72) 
#define SNAOLEDB_DDM_MGMCNFRM    	(SNAOLEDB_DDM_ERROR_START-73) 
#define SNAOLEDB_DDM_MGMNFNRM    	(SNAOLEDB_DDM_ERROR_START-74) 
#define SNAOLEDB_DDM_MGRDEPRM    	(SNAOLEDB_DDM_ERROR_START-75) 
#define SNAOLEDB_DDM_MGRLVLRM    	(SNAOLEDB_DDM_ERROR_START-76) 
#define SNAOLEDB_DDM_NEWDRNRM    	(SNAOLEDB_DDM_ERROR_START-77) 
#define SNAOLEDB_DDM_NEWNAMRM    	(SNAOLEDB_DDM_ERROR_START-78) 
#define SNAOLEDB_DDM_OBJNSPRM    	(SNAOLEDB_DDM_ERROR_START-79) 
#define SNAOLEDB_DDM_OPNCNFRM    	(SNAOLEDB_DDM_ERROR_START-80)       /* -336 */
#define SNAOLEDB_DDM_OPNEXCRM    	(SNAOLEDB_DDM_ERROR_START-81) 
#define SNAOLEDB_DDM_OPNMAXRM    	(SNAOLEDB_DDM_ERROR_START-82) 
#define SNAOLEDB_DDM_OPNQFLRM    	(SNAOLEDB_DDM_ERROR_START-83) 
#define SNAOLEDB_DDM_OPNQRYRM    	(SNAOLEDB_DDM_ERROR_START-84) 
#define SNAOLEDB_DDM_PKGBNARM    	(SNAOLEDB_DDM_ERROR_START-85) 
#define SNAOLEDB_DDM_PKGBPARM    	(SNAOLEDB_DDM_ERROR_START-86) 
#define SNAOLEDB_DDM_PRCCNVRM    	(SNAOLEDB_DDM_ERROR_START-87) 
#define SNAOLEDB_DDM_PRMNSPRM    	(SNAOLEDB_DDM_ERROR_START-88) 
#define SNAOLEDB_DDM_QRYNOPRM    	(SNAOLEDB_DDM_ERROR_START-89) 
#define SNAOLEDB_DDM_QRYPOPRM    	(SNAOLEDB_DDM_ERROR_START-90)       /* -346 */
#define SNAOLEDB_DDM_QUEATHRM    	(SNAOLEDB_DDM_ERROR_START-91) 
#define SNAOLEDB_DDM_QUEDMGRM    	(SNAOLEDB_DDM_ERROR_START-92) 
#define SNAOLEDB_DDM_QUEFULRM    	(SNAOLEDB_DDM_ERROR_START-93) 
#define SNAOLEDB_DDM_QUEIUSRM    	(SNAOLEDB_DDM_ERROR_START-94) 
#define SNAOLEDB_DDM_QUELENRM    	(SNAOLEDB_DDM_ERROR_START-95) 
#define SNAOLEDB_DDM_QUENAMRM    	(SNAOLEDB_DDM_ERROR_START-96) 
#define SNAOLEDB_DDM_QUENFNRM    	(SNAOLEDB_DDM_ERROR_START-97) 
#define SNAOLEDB_DDM_QUETNARM    	(SNAOLEDB_DDM_ERROR_START-98) 
#define SNAOLEDB_DDM_QUEVANRM    	(SNAOLEDB_DDM_ERROR_START-99) 
#define SNAOLEDB_DDM_RDBACCRM    	(SNAOLEDB_DDM_ERROR_START-100)      /* -356 */
#define SNAOLEDB_DDM_RDBAFLRM    	(SNAOLEDB_DDM_ERROR_START-101) 
#define SNAOLEDB_DDM_RDBATHRM    	(SNAOLEDB_DDM_ERROR_START-102) 
#define SNAOLEDB_DDM_RDBNACRM    	(SNAOLEDB_DDM_ERROR_START-103) 
#define SNAOLEDB_DDM_RDBNFNRM    	(SNAOLEDB_DDM_ERROR_START-104) 
#define SNAOLEDB_DDM_RDBUPDRM    	(SNAOLEDB_DDM_ERROR_START-105) 
#define SNAOLEDB_DDM_RECCNTRM    	(SNAOLEDB_DDM_ERROR_START-106) 
#define SNAOLEDB_DDM_RECDMGRM    	(SNAOLEDB_DDM_ERROR_START-107) 
#define SNAOLEDB_DDM_RECINARM    	(SNAOLEDB_DDM_ERROR_START-108) 
#define SNAOLEDB_DDM_RECIUSRM    	(SNAOLEDB_DDM_ERROR_START-109) 
#define SNAOLEDB_DDM_RECLENRM    	(SNAOLEDB_DDM_ERROR_START-110)      /* -366 */
#define SNAOLEDB_DDM_RECNAVRM    	(SNAOLEDB_DDM_ERROR_START-111) 
#define SNAOLEDB_DDM_RECNBRRM    	(SNAOLEDB_DDM_ERROR_START-112) 
#define SNAOLEDB_DDM_RECNFNRM    	(SNAOLEDB_DDM_ERROR_START-113) 
#define SNAOLEDB_DDM_RSCLMTRM    	(SNAOLEDB_DDM_ERROR_START-114) 
#define SNAOLEDB_DDM_SHDEXSRM    	(SNAOLEDB_DDM_ERROR_START-115) 
#define SNAOLEDB_DDM_SQLERRRM    	(SNAOLEDB_DDM_ERROR_START-116) 
#define SNAOLEDB_DDM_STGATHRM    	(SNAOLEDB_DDM_ERROR_START-117) 
#define SNAOLEDB_DDM_STGNFNRM    	(SNAOLEDB_DDM_ERROR_START-118) 
#define SNAOLEDB_DDM_STPCMPRM    	(SNAOLEDB_DDM_ERROR_START-119) 
#define SNAOLEDB_DDM_STRDMGRM    	(SNAOLEDB_DDM_ERROR_START-120)      /* -376 */
#define SNAOLEDB_DDM_STRIUSRM    	(SNAOLEDB_DDM_ERROR_START-121) 
#define SNAOLEDB_DDM_SUBSTRRM    	(SNAOLEDB_DDM_ERROR_START-122) 
#define SNAOLEDB_DDM_SYNTAXRM    	(SNAOLEDB_DDM_ERROR_START-123) 
#define SNAOLEDB_DDM_SYSCMDRM    	(SNAOLEDB_DDM_ERROR_START-124) 
#define SNAOLEDB_DDM_TRGNSPRM    	(SNAOLEDB_DDM_ERROR_START-125) 
#define SNAOLEDB_DDM_UPDCSRRM    	(SNAOLEDB_DDM_ERROR_START-126) 
#define SNAOLEDB_DDM_UPDINTRM    	(SNAOLEDB_DDM_ERROR_START-127) 
#define SNAOLEDB_DDM_USRATTRM    	(SNAOLEDB_DDM_ERROR_START-128) 
#define SNAOLEDB_DDM_VALNSPRM    	(SNAOLEDB_DDM_ERROR_START-129) 
#define SNAOLEDB_DDM_DFTRECRM       (SNAOLEDB_DDM_ERROR_START-130)      /* -386 */
#define SNAOLEDB_DDM_STGCNFRM       (SNAOLEDB_DDM_ERROR_START-131)

/*
    SNAOLEDB Communications Error Codes.
    Refer to Microsoft SNA Server SDK Documentation: APPC Programmer's Guide.
    Some error codes are related to TCP/IP communications.
*/ 
#define SNAOLEDB_COMM_ERROR_START                   -512
#define SNAOLEDB_COMM_PARAMETER_CHECK               (SNAOLEDB_COMM_ERROR_START)         /* APPC Errors: */
#define SNAOLEDB_COMM_BAD_TP_ID                     (SNAOLEDB_COMM_ERROR_START-1)
#define SNAOLEDB_COMM_BAD_CONV_ID                   (SNAOLEDB_COMM_ERROR_START-2)
#define SNAOLEDB_COMM_BAD_LU_ALIAS                  (SNAOLEDB_COMM_ERROR_START-3)
#define SNAOLEDB_COMM_INVALID_DATA_SEGMENT          (SNAOLEDB_COMM_ERROR_START-4)
#define SNAOLEDB_COMM_BAD_CONV_TYPE                 (SNAOLEDB_COMM_ERROR_START-5)
#define SNAOLEDB_COMM_BAD_SYNC_LEVEL                (SNAOLEDB_COMM_ERROR_START-6)
#define SNAOLEDB_COMM_BAD_SECURITY                  (SNAOLEDB_COMM_ERROR_START-7)
#define SNAOLEDB_COMM_BAD_RETURN_CONTROL            (SNAOLEDB_COMM_ERROR_START-8)       /* -520 */
#define SNAOLEDB_COMM_PIP_LEN_INCORRECT             (SNAOLEDB_COMM_ERROR_START-9)
#define SNAOLEDB_COMM_NO_USE_OF_SNASVCMG            (SNAOLEDB_COMM_ERROR_START-10)
#define SNAOLEDB_COMM_UNKNOWN_PARTNER_MODE          (SNAOLEDB_COMM_ERROR_START-11)
#define SNAOLEDB_COMM_CONFIRM_ON_SYNC_LEVEL_NONE    (SNAOLEDB_COMM_ERROR_START-12)
#define SNAOLEDB_COMM_DEALLOC_BAD_TYPE              (SNAOLEDB_COMM_ERROR_START-13)
#define SNAOLEDB_COMM_DEALLOC_LOG_LL_WRONG          (SNAOLEDB_COMM_ERROR_START-14)
#define SNAOLEDB_COMM_P_TO_R_INVALID_TYPE           (SNAOLEDB_COMM_ERROR_START-15)
#define SNAOLEDB_COMM_RCV_AND_WAIT_BAD_FILL         (SNAOLEDB_COMM_ERROR_START-16)
#define SNAOLEDB_COMM_RCV_IMMD_BAD_FILL             (SNAOLEDB_COMM_ERROR_START-17)
#define SNAOLEDB_COMM_RCV_AND_POST_BAD_FILL         (SNAOLEDB_COMM_ERROR_START-18)      /* -530 */
#define SNAOLEDB_COMM_INVALID_SEMAPHORE_HANDLE      (SNAOLEDB_COMM_ERROR_START-19)
#define SNAOLEDB_COMM_BAD_RETURN_STATUS_WITH_DATA   (SNAOLEDB_COMM_ERROR_START-20)
#define SNAOLEDB_COMM_BAD_LL                        (SNAOLEDB_COMM_ERROR_START-21)
#define SNAOLEDB_COMM_SEND_DATA_INVALID_TYPE        (SNAOLEDB_COMM_ERROR_START-22)
#define SNAOLEDB_COMM_INVALID_SESSION_ID            (SNAOLEDB_COMM_ERROR_START-23)
#define SNAOLEDB_COMM_SEND_DATA_CONFIRM_SYNC_NONE   (SNAOLEDB_COMM_ERROR_START-24)
#define SNAOLEDB_COMM_BAD_PARTNER_LU_ALIAS          (SNAOLEDB_COMM_ERROR_START-25) 
#define SNAOLEDB_COMM_SEND_ERROR_LOG_LL_WRONG       (SNAOLEDB_COMM_ERROR_START-26)
#define SNAOLEDB_COMM_SEND_ERROR_BAD_TYPE           (SNAOLEDB_COMM_ERROR_START-27) 
#define SNAOLEDB_COMM_BAD_ERROR_DIRECTION           (SNAOLEDB_COMM_ERROR_START-28)      /* -540 */
#define SNAOLEDB_COMM_TOO_MANY_TPS                  (SNAOLEDB_COMM_ERROR_START-29) 
#define SNAOLEDB_COMM_BAD_TYPE                      (SNAOLEDB_COMM_ERROR_START-30) 
#define SNAOLEDB_COMM_UNDEFINED_TP_NAME             (SNAOLEDB_COMM_ERROR_START-31) 

#define SNAOLEDB_COMM_STATE_CHECK                   (SNAOLEDB_COMM_ERROR_START-32)
#define SNAOLEDB_COMM_CONFIRM_BAD_STATE             (SNAOLEDB_COMM_ERROR_START-33)
#define SNAOLEDB_COMM_CONFIRM_NOT_LL_BDY            (SNAOLEDB_COMM_ERROR_START-34)
#define SNAOLEDB_COMM_CONFIRMED_BAD_STATE           (SNAOLEDB_COMM_ERROR_START-35)
#define SNAOLEDB_COMM_DEALLOC_FLUSH_BAD_STATE       (SNAOLEDB_COMM_ERROR_START-36)
#define SNAOLEDB_COMM_DEALLOC_CONFIRM_BAD_STATE     (SNAOLEDB_COMM_ERROR_START-37)
#define SNAOLEDB_COMM_DEALLOC_NOT_LL_BDY            (SNAOLEDB_COMM_ERROR_START-38)      /* -550 */
#define SNAOLEDB_COMM_FLUSH_NOT_SEND_STATE          (SNAOLEDB_COMM_ERROR_START-39)
#define SNAOLEDB_COMM_P_TO_R_NOT_LL_BDY             (SNAOLEDB_COMM_ERROR_START-40)
#define SNAOLEDB_COMM_P_TO_R_NOT_SEND_STATE         (SNAOLEDB_COMM_ERROR_START-41)
#define SNAOLEDB_COMM_RCV_AND_WAIT_BAD_STATE        (SNAOLEDB_COMM_ERROR_START-42)
#define SNAOLEDB_COMM_RCV_AND_WAIT_NOT_LL_BDY       (SNAOLEDB_COMM_ERROR_START-43)
#define SNAOLEDB_COMM_RCV_IMMD_BAD_STATE            (SNAOLEDB_COMM_ERROR_START-44)
#define SNAOLEDB_COMM_RCV_AND_POST_BAD_STATE        (SNAOLEDB_COMM_ERROR_START-45)
#define SNAOLEDB_COMM_RCV_AND_POST_NOT_LL_BDY       (SNAOLEDB_COMM_ERROR_START-46)
#define SNAOLEDB_COMM_R_T_S_BAD_STATE               (SNAOLEDB_COMM_ERROR_START-47)
#define SNAOLEDB_COMM_SEND_DATA_NOT_SEND_STATE      (SNAOLEDB_COMM_ERROR_START-48)      /* -560 */
#define SNAOLEDB_COMM_SEND_DATA_NOT_LL_BDY          (SNAOLEDB_COMM_ERROR_START-49)
#define SNAOLEDB_COMM_ATTACH_MANAGER_INACTIVE       (SNAOLEDB_COMM_ERROR_START-50)
#define SNAOLEDB_COMM_ALLOCATE_NOT_PENDING          (SNAOLEDB_COMM_ERROR_START-51)
#define SNAOLEDB_COMM_INVALID_PROCESS               (SNAOLEDB_COMM_ERROR_START-52)

#define SNAOLEDB_COMM_ALLOCATION_ERROR              (SNAOLEDB_COMM_ERROR_START-53)
#define SNAOLEDB_COMM_ALLOCATION_FAILURE_NO_RETRY   (SNAOLEDB_COMM_ERROR_START-54)
#define SNAOLEDB_COMM_ALLOCATION_FAILURE_RETRY      (SNAOLEDB_COMM_ERROR_START-55)
#define SNAOLEDB_COMM_SECURITY_NOT_VALID            (SNAOLEDB_COMM_ERROR_START-56)
#define SNAOLEDB_COMM_TRANS_PGM_NOT_AVAIL_RETRY     (SNAOLEDB_COMM_ERROR_START-57)
#define SNAOLEDB_COMM_TRANS_PGM_NOT_AVAIL_NO_RETRY  (SNAOLEDB_COMM_ERROR_START-58)      /* -570 */
#define SNAOLEDB_COMM_TP_NAME_NOT_RECOGNIZED        (SNAOLEDB_COMM_ERROR_START-59)
#define SNAOLEDB_COMM_PIP_NOT_ALLOWED               (SNAOLEDB_COMM_ERROR_START-60)
#define SNAOLEDB_COMM_PIP_NOT_SPECIFIED_CORRECTLY   (SNAOLEDB_COMM_ERROR_START-61)
#define SNAOLEDB_COMM_CONVERSATION_TYPE_MISMATCH    (SNAOLEDB_COMM_ERROR_START-62)
#define SNAOLEDB_COMM_SYNC_LEVEL_NOT_SUPPORTED      (SNAOLEDB_COMM_ERROR_START-63)

#define SNAOLEDB_COMM_DEALLOC_ABEND                 (SNAOLEDB_COMM_ERROR_START-64)
#define SNAOLEDB_COMM_DEALLOC_ABEND_PROG            (SNAOLEDB_COMM_ERROR_START-65)
#define SNAOLEDB_COMM_DEALLOC_ABEND_SVC             (SNAOLEDB_COMM_ERROR_START-66)
#define SNAOLEDB_COMM_DEALLOC_ABEND_TIMER           (SNAOLEDB_COMM_ERROR_START-67)
#define SNAOLEDB_COMM_DEALLOC_NORMAL                (SNAOLEDB_COMM_ERROR_START-68)      /* -580 */
#define SNAOLEDB_COMM_PROG_ERROR_NO_TRUNC           (SNAOLEDB_COMM_ERROR_START-69)
#define SNAOLEDB_COMM_PROG_ERROR_TRUNC              (SNAOLEDB_COMM_ERROR_START-70)
#define SNAOLEDB_COMM_PROG_ERROR_PURGING            (SNAOLEDB_COMM_ERROR_START-71)
#define SNAOLEDB_COMM_CONV_FAILURE_RETRY            (SNAOLEDB_COMM_ERROR_START-72)
#define SNAOLEDB_COMM_CONV_FAILURE_NO_RETRY         (SNAOLEDB_COMM_ERROR_START-73)
#define SNAOLEDB_COMM_SVC_ERROR_NO_TRUNC            (SNAOLEDB_COMM_ERROR_START-74)
#define SNAOLEDB_COMM_SVC_ERROR_TRUNC               (SNAOLEDB_COMM_ERROR_START-75)
#define SNAOLEDB_COMM_SVC_ERROR_PURGING             (SNAOLEDB_COMM_ERROR_START-76)
#define SNAOLEDB_COMM_UNSUCCESSFUL                  (SNAOLEDB_COMM_ERROR_START-77)
#define SNAOLEDB_COMM_CONVERSATION_TYPE_MIXED       (SNAOLEDB_COMM_ERROR_START-78)      /* -590 */
#define SNAOLEDB_COMM_CANCELLED                     (SNAOLEDB_COMM_ERROR_START-79)
#define SNAOLEDB_COMM_SECURITY_REQ_NOT_SUPPORTED    (SNAOLEDB_COMM_ERROR_START-80)
#define SNAOLEDB_COMM_TP_BUSY                       (SNAOLEDB_COMM_ERROR_START-81)      
#define SNAOLEDB_COMM_COMM_SUBSYSTEM_ABENDED        (SNAOLEDB_COMM_ERROR_START-82)      
#define SNAOLEDB_COMM_COMM_SUBSYSTEM_NOT_LOADED     (SNAOLEDB_COMM_ERROR_START-83)      
#define SNAOLEDB_COMM_CONV_BUSY                     (SNAOLEDB_COMM_ERROR_START-84)     
#define SNAOLEDB_COMM_THREAD_BLOCKING               (SNAOLEDB_COMM_ERROR_START-85)     
#define SNAOLEDB_COMM_INVALID_VERB_SEGMENT          (SNAOLEDB_COMM_ERROR_START-86)      
#define SNAOLEDB_COMM_UNEXPECTED_DOS_ERROR          (SNAOLEDB_COMM_ERROR_START-87)      
#define SNAOLEDB_COMM_STACK_TOO_SMALL               (SNAOLEDB_COMM_ERROR_START-88)      /* -600 */
#define SNAOLEDB_COMM_INVALID_VERB                  (SNAOLEDB_COMM_ERROR_START-89)
#define SNAOLEDB_COMM_HOST_NAMERESOLV_FAILED        (SNAOLEDB_COMM_ERROR_START-90)      /* TCP/IP Errors: */
#define SNAOLEDB_COMM_HOST_CONNECT_FAILED           (SNAOLEDB_COMM_ERROR_START-91)
#define SNAOLEDB_COMM_SOCKET_ALLOC_FAILED           (SNAOLEDB_COMM_ERROR_START-92)

#endif  /* #ifndef __SNAOLEDB_h__ */