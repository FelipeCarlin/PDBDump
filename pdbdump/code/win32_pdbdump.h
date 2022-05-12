#if !defined(WIN32_PDBDUMP_H)
/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Felipe Carlin $
   $Notice: Copyright © 2022 Felipe Carlin $
   ======================================================================== */

typedef enum tpi_stream_version
{
    TPI_V40 = 19950410,
    TPI_V41 = 19951122,
    TPI_V50 = 19961031,
    TPI_V70 = 19990903,
    TPI_V80 = 20040203,
} tpi_stream_version;

typedef struct tpi_stream_header
{
    tpi_stream_version Version;
    uint32 HeaderSize;
    uint32 TypeIndexBegin;
    uint32 TypeIndexEnd;
    uint32 TypeRecordBytes;
    
    uint16 HashStreamIndex;
    uint16 HashAuxStreamIndex;
    uint32 HashKeySize;
    uint32 NumHashBuckets;
    
    int32 HashValueBufferOffset;
    uint32 HashValueBufferLength;
    
    int32 IndexOffsetBufferOffset;
    uint32 IndexOffsetBufferLength;
    
    int32 HashAdjBufferOffset;
    uint32 HashAdjBufferLength;
} tpi_stream_header;

typedef enum leaf_record_type
{
#if 0
    LF_MODIFIER_16t         = 0x00000001,
    LF_POINTER_16t          = 0x00000002,
    LF_ARRAY_16t            = 0x00000003,
    LF_CLASS_16t            = 0x00000004,
    LF_STRUCTURE_16t        = 0x00000005,
    LF_UNION_16t            = 0x00000006,
    LF_ENUM_16t             = 0x00000007,
    LF_PROCEDURE_16t        = 0x00000008,
    LF_MFUNCTION_16t        = 0x00000009,
    LF_VTSHAPE              = 0x0000000A,
    LF_COBOL0_16t           = 0x0000000B,
    LF_COBOL1               = 0x0000000C,
    LF_BARRAY_16t           = 0x0000000D,
    LF_LABEL                = 0x0000000E,
    LF_NULL                 = 0x0000000F,
    LF_NOTTRAN              = 0x00000010,
    LF_DIMARRAY_16t         = 0x00000011,
    LF_VFTPATH_16t          = 0x00000012,
    LF_PRECOMP_16t          = 0x00000013,
    LF_ENDPRECOMP           = 0x00000014,
    LF_OEM_16t              = 0x00000015,
    LF_TYPESERVER_ST        = 0x00000016,
    LF_SKIP_16t             = 0x00000200,
    LF_ARGLIST_16t          = 0x00000201,
    LF_DEFARG_16t           = 0x00000202,
    LF_LIST                 = 0x00000203,
    LF_FIELDLIST_16t        = 0x00000204,
    LF_DERIVED_16t          = 0x00000205,
    LF_BITFIELD_16t         = 0x00000206,
    LF_METHODLIST_16t       = 0x00000207,
    LF_DIMCONU_16t          = 0x00000208,
    LF_DIMCONLU_16t         = 0x00000209,
    LF_DIMVARU_16t          = 0x0000020A,
    LF_DIMVARLU_16t         = 0x0000020B,
    LF_REFSYM               = 0x0000020C,
    LF_BCLASS_16t           = 0x00000400,
    LF_VBCLASS_16t          = 0x00000401,
    LF_IVBCLASS_16t         = 0x00000402,
    LF_ENUMERATE_ST         = 0x00000403,
    LF_FRIENDFCN_16t        = 0x00000404,
    LF_INDEX_16t            = 0x00000405,
    LF_MEMBER_16t           = 0x00000406,
    LF_STMEMBER_16t         = 0x00000407,
    LF_METHOD_16t           = 0x00000408,
    LF_NESTTYPE_16t         = 0x00000409,
    LF_VFUNCTAB_16t         = 0x0000040A,
    LF_FRIENDCLS_16t        = 0x0000040B,
    LF_ONEMETHOD_16t        = 0x0000040C,
    LF_VFUNCOFF_16t         = 0x0000040D,
    LF_TI16_MAX             = 0x00001000,
    LF_MODIFIER             = 0x00001001,
    LF_POINTER              = 0x00001002,
    LF_ARRAY_ST             = 0x00001003,
    LF_CLASS_ST             = 0x00001004,
    LF_STRUCTURE_ST         = 0x00001005,
    LF_UNION_ST             = 0x00001006,
    LF_ENUM_ST              = 0x00001007,
    LF_PROCEDURE            = 0x00001008,
    LF_MFUNCTION            = 0x00001009,
    LF_COBOL0               = 0x0000100A,
    LF_BARRAY               = 0x0000100B,
    LF_DIMARRAY_ST          = 0x0000100C,
    LF_VFTPATH              = 0x0000100D,
    LF_PRECOMP_ST           = 0x0000100E,
    LF_OEM                  = 0x0000100F,
    LF_ALIAS_ST             = 0x00001010,
    LF_OEM2                 = 0x00001011,
    LF_SKIP                 = 0x00001200,
    LF_ARGLIST              = 0x00001201,
    LF_DEFARG_ST            = 0x00001202,
    LF_FIELDLIST            = 0x00001203,
    LF_DERIVED              = 0x00001204,
    LF_BITFIELD             = 0x00001205,
    LF_METHODLIST           = 0x00001206,
    LF_DIMCONU              = 0x00001207,
    LF_DIMCONLU             = 0x00001208,
    LF_DIMVARU              = 0x00001209,
    LF_DIMVARLU             = 0x0000120A,
    LF_BCLASS               = 0x00001400,
    LF_VBCLASS              = 0x00001401,
    LF_IVBCLASS             = 0x00001402,
    LF_FRIENDFCN_ST         = 0x00001403,
    LF_INDEX                = 0x00001404,
    LF_MEMBER_ST            = 0x00001405,
    LF_STMEMBER_ST          = 0x00001406,
    LF_METHOD_ST            = 0x00001407,
    LF_NESTTYPE_ST          = 0x00001408,
    LF_VFUNCTAB             = 0x00001409,
    LF_FRIENDCLS            = 0x0000140A,
    LF_ONEMETHOD_ST         = 0x0000140B,
    LF_VFUNCOFF             = 0x0000140C,
    LF_NESTTYPEEX_ST        = 0x0000140D,
    LF_MEMBERMODIFY_ST      = 0x0000140E,
    LF_MANAGED_ST           = 0x0000140F,
    LF_ST_MAX               = 0x00001500,
    LF_TYPESERVER           = 0x00001501,
    LF_ENUMERATE            = 0x00001502,
    LF_ARRAY                = 0x00001503,
    LF_CLASS                = 0x00001504,
    LF_STRUCTURE            = 0x00001505,
    LF_UNION                = 0x00001506,
    LF_ENUM                 = 0x00001507,
    LF_DIMARRAY             = 0x00001508,
    LF_PRECOMP              = 0x00001509,
    LF_ALIAS                = 0x0000150A,
    LF_DEFARG               = 0x0000150B,
    LF_FRIENDFCN            = 0x0000150C,
    LF_MEMBER               = 0x0000150D,
    LF_STMEMBER             = 0x0000150E,
    LF_METHOD               = 0x0000150F,
    LF_NESTTYPE             = 0x00001510,
    LF_ONEMETHOD            = 0x00001511,
    LF_NESTTYPEEX           = 0x00001512,
    LF_MEMBERMODIFY         = 0x00001513,
    LF_MANAGED              = 0x00001514,
    LF_TYPESERVER2          = 0x00001515,
    LF_CHAR                 = 0x00008000,
    LF_SHORT                = 0x00008001,
    LF_USHORT               = 0x00008002,
    LF_LONG                 = 0x00008003,
    LF_ULONG                = 0x00008004,
    LF_REAL32               = 0x00008005,
    LF_REAL64               = 0x00008006,
    LF_REAL80               = 0x00008007,
    LF_REAL128              = 0x00008008,
    LF_QUADWORD             = 0x00008009,
    LF_UQUADWORD            = 0x0000800A,
    LF_REAL48               = 0x0000800B,
    LF_COMPLEX32            = 0x0000800C,
    LF_COMPLEX64            = 0x0000800D,
    LF_COMPLEX80            = 0x0000800E,
    LF_COMPLEX128           = 0x0000800F,
    LF_VARSTRING            = 0x00008010,
    LF_OCTWORD              = 0x00008017,
    LF_UOCTWORD             = 0x00008018,
    LF_DECIMAL              = 0x00008019,
    LF_DATE                 = 0x0000801A,
    LF_UTF8STRING           = 0x0000801B,
    LF_PAD0                 = 0x000000F0,
    LF_PAD1                 = 0x000000F1,
    LF_PAD2                 = 0x000000F2,
    LF_PAD3                 = 0x000000F3,
    LF_PAD4                 = 0x000000F4,
    LF_PAD5                 = 0x000000F5,
    LF_PAD6                 = 0x000000F6,
    LF_PAD7                 = 0x000000F7,
    LF_PAD8                 = 0x000000F8,
    LF_PAD9                 = 0x000000F9,
    LF_PAD10                = 0x000000FA,
    LF_PAD11                = 0x000000FB,
    LF_PAD12                = 0x000000FC,
    LF_PAD13                = 0x000000FD,
    LF_PAD14                = 0x000000FE,
    LF_PAD15                = 0x000000FF
#endif


    LF_MODIFIER_16t     = 0x0001,
    LF_POINTER_16t      = 0x0002,
    LF_ARRAY_16t        = 0x0003,
    LF_CLASS_16t        = 0x0004,
    LF_STRUCTURE_16t    = 0x0005,
    LF_UNION_16t        = 0x0006,
    LF_ENUM_16t         = 0x0007,
    LF_PROCEDURE_16t    = 0x0008,
    LF_MFUNCTION_16t    = 0x0009,
    LF_VTSHAPE          = 0x000a,
    LF_COBOL0_16t       = 0x000b,
    LF_COBOL1           = 0x000c,
    LF_BARRAY_16t       = 0x000d,
    LF_LABEL            = 0x000e,
    LF_NULL             = 0x000f,
    LF_NOTTRAN          = 0x0010,
    LF_DIMARRAY_16t     = 0x0011,
    LF_VFTPATH_16t      = 0x0012,
    LF_PRECOMP_16t      = 0x0013,       // not referenced from symbol
    LF_ENDPRECOMP       = 0x0014,       // not referenced from symbol
    LF_OEM_16t          = 0x0015,       // oem definable type string
    LF_TYPESERVER_ST    = 0x0016,       // not referenced from symbol

    // leaf indices starting records but referenced only from type records

    LF_SKIP_16t         = 0x0200,
    LF_ARGLIST_16t      = 0x0201,
    LF_DEFARG_16t       = 0x0202,
    LF_LIST             = 0x0203,
    LF_FIELDLIST_16t    = 0x0204,
    LF_DERIVED_16t      = 0x0205,
    LF_BITFIELD_16t     = 0x0206,
    LF_METHODLIST_16t   = 0x0207,
    LF_DIMCONU_16t      = 0x0208,
    LF_DIMCONLU_16t     = 0x0209,
    LF_DIMVARU_16t      = 0x020a,
    LF_DIMVARLU_16t     = 0x020b,
    LF_REFSYM           = 0x020c,

    LF_BCLASS_16t       = 0x0400,
    LF_VBCLASS_16t      = 0x0401,
    LF_IVBCLASS_16t     = 0x0402,
    LF_ENUMERATE_ST     = 0x0403,
    LF_FRIENDFCN_16t    = 0x0404,
    LF_INDEX_16t        = 0x0405,
    LF_MEMBER_16t       = 0x0406,
    LF_STMEMBER_16t     = 0x0407,
    LF_METHOD_16t       = 0x0408,
    LF_NESTTYPE_16t     = 0x0409,
    LF_VFUNCTAB_16t     = 0x040a,
    LF_FRIENDCLS_16t    = 0x040b,
    LF_ONEMETHOD_16t    = 0x040c,
    LF_VFUNCOFF_16t     = 0x040d,

// 32-bit type index versions of leaves, all have the 0x1000 bit set
//
    LF_TI16_MAX         = 0x1000,

    LF_MODIFIER         = 0x1001,
    LF_POINTER          = 0x1002,
    LF_ARRAY_ST         = 0x1003,
    LF_CLASS_ST         = 0x1004,
    LF_STRUCTURE_ST     = 0x1005,
    LF_UNION_ST         = 0x1006,
    LF_ENUM_ST          = 0x1007,
    LF_PROCEDURE        = 0x1008,
    LF_MFUNCTION        = 0x1009,
    LF_COBOL0           = 0x100a,
    LF_BARRAY           = 0x100b,
    LF_DIMARRAY_ST      = 0x100c,
    LF_VFTPATH          = 0x100d,
    LF_PRECOMP_ST       = 0x100e,       // not referenced from symbol
    LF_OEM              = 0x100f,       // oem definable type string
    LF_ALIAS_ST         = 0x1010,       // alias (typedef) type
    LF_OEM2             = 0x1011,       // oem definable type string

    // leaf indices starting records but referenced only from type records

    LF_SKIP             = 0x1200,
    LF_ARGLIST          = 0x1201,
    LF_DEFARG_ST        = 0x1202,
    LF_FIELDLIST        = 0x1203,
    LF_DERIVED          = 0x1204,
    LF_BITFIELD         = 0x1205,
    LF_METHODLIST       = 0x1206,
    LF_DIMCONU          = 0x1207,
    LF_DIMCONLU         = 0x1208,
    LF_DIMVARU          = 0x1209,
    LF_DIMVARLU         = 0x120a,

    LF_BCLASS           = 0x1400,
    LF_VBCLASS          = 0x1401,
    LF_IVBCLASS         = 0x1402,
    LF_FRIENDFCN_ST     = 0x1403,
    LF_INDEX            = 0x1404,
    LF_MEMBER_ST        = 0x1405,
    LF_STMEMBER_ST      = 0x1406,
    LF_METHOD_ST        = 0x1407,
    LF_NESTTYPE_ST      = 0x1408,
    LF_VFUNCTAB         = 0x1409,
    LF_FRIENDCLS        = 0x140a,
    LF_ONEMETHOD_ST     = 0x140b,
    LF_VFUNCOFF         = 0x140c,
    LF_NESTTYPEEX_ST    = 0x140d,
    LF_MEMBERMODIFY_ST  = 0x140e,
    LF_MANAGED_ST       = 0x140f,

    // Types w/ SZ names

    LF_ST_MAX           = 0x1500,

    LF_TYPESERVER       = 0x1501,       // not referenced from symbol
    LF_ENUMERATE        = 0x1502,
    LF_ARRAY            = 0x1503,
    LF_CLASS            = 0x1504,
    LF_STRUCTURE        = 0x1505,
    LF_UNION            = 0x1506,
    LF_ENUM             = 0x1507,
    LF_DIMARRAY         = 0x1508,
    LF_PRECOMP          = 0x1509,       // not referenced from symbol
    LF_ALIAS            = 0x150a,       // alias (typedef) type
    LF_DEFARG           = 0x150b,
    LF_FRIENDFCN        = 0x150c,
    LF_MEMBER           = 0x150d,
    LF_STMEMBER         = 0x150e,
    LF_METHOD           = 0x150f,
    LF_NESTTYPE         = 0x1510,
    LF_ONEMETHOD        = 0x1511,
    LF_NESTTYPEEX       = 0x1512,
    LF_MEMBERMODIFY     = 0x1513,
    LF_MANAGED          = 0x1514,
    LF_TYPESERVER2      = 0x1515,

    LF_STRIDED_ARRAY    = 0x1516,    // same as LF_ARRAY, but with stride between adjacent elements
    LF_HLSL             = 0x1517,
    LF_MODIFIER_EX      = 0x1518,
    LF_INTERFACE        = 0x1519,
    LF_BINTERFACE       = 0x151a,
    LF_VECTOR           = 0x151b,
    LF_MATRIX           = 0x151c,

    LF_VFTABLE          = 0x151d,      // a virtual function table
    LF_ENDOFLEAFRECORD  = LF_VFTABLE,

    LF_TYPE_LAST,                    // one greater than the last type record
    LF_TYPE_MAX         = LF_TYPE_LAST - 1,

    LF_FUNC_ID          = 0x1601,    // global func ID
    LF_MFUNC_ID         = 0x1602,    // member func ID
    LF_BUILDINFO        = 0x1603,    // build info: tool, version, command line, src/pdb file
    LF_SUBSTR_LIST      = 0x1604,    // similar to LF_ARGLIST, for list of sub strings
    LF_STRING_ID        = 0x1605,    // string ID

    LF_UDT_SRC_LINE     = 0x1606,    // source and line on where an UDT is defined
                                     // only generated by compiler

    LF_UDT_MOD_SRC_LINE = 0x1607,    // module, source and line on where an UDT is defined
                                     // only generated by linker

    LF_ID_LAST,                      // one greater than the last ID record
    LF_ID_MAX           = LF_ID_LAST - 1,

    LF_NUMERIC          = 0x8000,
    LF_CHAR             = 0x8000,
    LF_SHORT            = 0x8001,
    LF_USHORT           = 0x8002,
    LF_LONG             = 0x8003,
    LF_ULONG            = 0x8004,
    LF_REAL32           = 0x8005,
    LF_REAL64           = 0x8006,
    LF_REAL80           = 0x8007,
    LF_REAL128          = 0x8008,
    LF_QUADWORD         = 0x8009,
    LF_UQUADWORD        = 0x800a,
    LF_REAL48           = 0x800b,
    LF_COMPLEX32        = 0x800c,
    LF_COMPLEX64        = 0x800d,
    LF_COMPLEX80        = 0x800e,
    LF_COMPLEX128       = 0x800f,
    LF_VARSTRING        = 0x8010,

    LF_OCTWORD          = 0x8017,
    LF_UOCTWORD         = 0x8018,

    LF_DECIMAL          = 0x8019,
    LF_DATE             = 0x801a,
    LF_UTF8STRING       = 0x801b,

    LF_REAL16           = 0x801c,
    
    LF_PAD0             = 0xf0,
    LF_PAD1             = 0xf1,
    LF_PAD2             = 0xf2,
    LF_PAD3             = 0xf3,
    LF_PAD4             = 0xf4,
    LF_PAD5             = 0xf5,
    LF_PAD6             = 0xf6,
    LF_PAD7             = 0xf7,
    LF_PAD8             = 0xf8,
    LF_PAD9             = 0xf9,
    LF_PAD10            = 0xfa,
    LF_PAD11            = 0xfb,
    LF_PAD12            = 0xfc,
    LF_PAD13            = 0xfd,
    LF_PAD14            = 0xfe,
    LF_PAD15            = 0xff,
} leaf_record_type;

typedef struct name_table
{
    uint32 Identifier;
    char *Name;
} name_table;

#define TABLE_END 0xffff

name_table LeafRecordNames[] =
{
#if 0
    {LF_MODIFIER_16t, "LF_MODIFIER_16t"},
    {LF_POINTER_16t, "LF_POINTER_16t"},
    {LF_ARRAY_16t, "LF_ARRAY_16t"},
    {LF_CLASS_16t, "LF_CLASS_16t"},
    {LF_STRUCTURE_16t, "LF_STRUCTURE_16t"},
    {LF_UNION_16t, "LF_UNION_16t"},
    {LF_ENUM_16t, "LF_ENUM_16t"},
    {LF_PROCEDURE_16t, "LF_PROCEDURE_16t"},
    {LF_MFUNCTION_16t, "LF_MFUNCTION_16t"},
    {LF_VTSHAPE, "LF_VTSHAPE"},
    {LF_COBOL0_16t, "LF_COBOL0_16t"},
    {LF_COBOL1, "LF_COBOL1"},
    {LF_BARRAY_16t, "LF_BARRAY_16t"},
    {LF_LABEL, "LF_LABEL"},
    {LF_NULL, "LF_NULL"},
    {LF_NOTTRAN, "LF_NOTTRAN"},
    {LF_DIMARRAY_16t, "LF_DIMARRAY_16t"},
    {LF_VFTPATH_16t, "LF_VFTPATH_16t"},
    {LF_PRECOMP_16t, "LF_PRECOMP_16t"},
    {LF_ENDPRECOMP, "LF_ENDPRECOMP"},
    {LF_OEM_16t, "LF_OEM_16t"},
    {LF_TYPESERVER_ST, "LF_TYPESERVER_ST"},
    {LF_SKIP_16t, "LF_SKIP_16t"},
    {LF_ARGLIST_16t, "LF_ARGLIST_16t"},
    {LF_DEFARG_16t, "LF_DEFARG_16t"},
    {LF_LIST, "LF_LIST"},
    {LF_FIELDLIST_16t, "LF_FIELDLIST_16t"},
    {LF_DERIVED_16t, "LF_DERIVED_16t"},
    {LF_BITFIELD_16t, "LF_BITFIELD_16t"},
    {LF_METHODLIST_16t, "LF_METHODLIST_16t"},
    {LF_DIMCONU_16t, "LF_DIMCONU_16t"},
    {LF_DIMCONLU_16t, "LF_DIMCONLU_16t"},
    {LF_DIMVARU_16t, "LF_DIMVARU_16t"},
    {LF_DIMVARLU_16t, "LF_DIMVARLU_16t"},
    {LF_REFSYM, "LF_REFSYM"},
    {LF_BCLASS_16t, "LF_BCLASS_16t"},
    {LF_VBCLASS_16t, "LF_VBCLASS_16t"},
    {LF_IVBCLASS_16t, "LF_IVBCLASS_16t"},
    {LF_ENUMERATE_ST, "LF_ENUMERATE_ST"},
    {LF_FRIENDFCN_16t, "LF_FRIENDFCN_16t"},
    {LF_INDEX_16t, "LF_INDEX_16t"},
    {LF_MEMBER_16t, "LF_MEMBER_16t"},
    {LF_STMEMBER_16t, "LF_STMEMBER_16t"},
    {LF_METHOD_16t, "LF_METHOD_16t"},
    {LF_NESTTYPE_16t, "LF_NESTTYPE_16t"},
    {LF_VFUNCTAB_16t, "LF_VFUNCTAB_16t"},
    {LF_FRIENDCLS_16t, "LF_FRIENDCLS_16t"},
    {LF_ONEMETHOD_16t, "LF_ONEMETHOD_16t"},
    {LF_VFUNCOFF_16t, "LF_VFUNCOFF_16t"},
    {LF_TI16_MAX, "LF_TI16_MAX"},
    {LF_MODIFIER, "LF_MODIFIER"},
    {LF_POINTER, "LF_POINTER"},
    {LF_ARRAY_ST, "LF_ARRAY_ST"},
    {LF_CLASS_ST, "LF_CLASS_ST"},
    {LF_STRUCTURE_ST, "LF_STRUCTURE_ST"},
    {LF_UNION_ST, "LF_UNION_ST"},
    {LF_ENUM_ST, "LF_ENUM_ST"},
    {LF_PROCEDURE, "LF_PROCEDURE"},
    {LF_MFUNCTION, "LF_MFUNCTION"},
    {LF_COBOL0, "LF_COBOL0"},
    {LF_BARRAY, "LF_BARRAY"},
    {LF_DIMARRAY_ST, "LF_DIMARRAY_ST"},
    {LF_VFTPATH, "LF_VFTPATH"},
    {LF_PRECOMP_ST, "LF_PRECOMP_ST"},
    {LF_OEM, "LF_OEM"},
    {LF_ALIAS_ST, "LF_ALIAS_ST"},
    {LF_OEM2, "LF_OEM2"},
    {LF_SKIP, "LF_SKIP"},
    {LF_ARGLIST, "LF_ARGLIST"},
    {LF_DEFARG_ST, "LF_DEFARG_ST"},
    {LF_FIELDLIST, "LF_FIELDLIST"},
    {LF_DERIVED, "LF_DERIVED"},
    {LF_BITFIELD, "LF_BITFIELD"},
    {LF_METHODLIST, "LF_METHODLIST"},
    {LF_DIMCONU, "LF_DIMCONU"},
    {LF_DIMCONLU, "LF_DIMCONLU"},
    {LF_DIMVARU, "LF_DIMVARU"},
    {LF_DIMVARLU, "LF_DIMVARLU"},
    {LF_BCLASS, "LF_BCLASS"},
    {LF_VBCLASS, "LF_VBCLASS"},
    {LF_IVBCLASS, "LF_IVBCLASS"},
    {LF_FRIENDFCN_ST, "LF_FRIENDFCN_ST"},
    {LF_INDEX, "LF_INDEX"},
    {LF_MEMBER_ST, "LF_MEMBER_ST"},
    {LF_STMEMBER_ST, "LF_STMEMBER_ST"},
    {LF_METHOD_ST, "LF_METHOD_ST"},
    {LF_NESTTYPE_ST, "LF_NESTTYPE_ST"},
    {LF_VFUNCTAB, "LF_VFUNCTAB"},
    {LF_FRIENDCLS, "LF_FRIENDCLS"},
    {LF_ONEMETHOD_ST, "LF_ONEMETHOD_ST"},
    {LF_VFUNCOFF, "LF_VFUNCOFF"},
    {LF_NESTTYPEEX_ST, "LF_NESTTYPEEX_ST"},
    {LF_MEMBERMODIFY_ST, "LF_MEMBERMODIFY_ST"},
    {LF_MANAGED_ST, "LF_MANAGED_ST"},
    {LF_ST_MAX, "LF_ST_MAX"},
    {LF_TYPESERVER, "LF_TYPESERVER"},
    {LF_ENUMERATE, "LF_ENUMERATE"},
    {LF_ARRAY, "LF_ARRAY"},
    {LF_CLASS, "LF_CLASS"},
    {LF_STRUCTURE, "LF_STRUCTURE"},
    {LF_UNION, "LF_UNION"},
    {LF_ENUM, "LF_ENUM"},
    {LF_DIMARRAY, "LF_DIMARRAY"},
    {LF_PRECOMP, "LF_PRECOMP"},
    {LF_ALIAS, "LF_ALIAS"},
    {LF_DEFARG, "LF_DEFARG"},
    {LF_FRIENDFCN, "LF_FRIENDFCN"},
    {LF_MEMBER, "LF_MEMBER"},
    {LF_STMEMBER, "LF_STMEMBER"},
    {LF_METHOD, "LF_METHOD"},
    {LF_NESTTYPE, "LF_NESTTYPE"},
    {LF_ONEMETHOD, "LF_ONEMETHOD"},
    {LF_NESTTYPEEX, "LF_NESTTYPEEX"},
    {LF_MEMBERMODIFY, "LF_MEMBERMODIFY"},
    {LF_MANAGED, "LF_MANAGED"},
    {LF_TYPESERVER2, "LF_TYPESERVER2"},
    {LF_CHAR, "LF_CHAR"},
    {LF_SHORT, "LF_SHORT"},
    {LF_USHORT, "LF_USHORT"},
    {LF_LONG, "LF_LONG"},
    {LF_ULONG, "LF_ULONG"},
    {LF_REAL32, "LF_REAL32"},
    {LF_REAL64, "LF_REAL64"},
    {LF_REAL80, "LF_REAL80"},
    {LF_REAL128, "LF_REAL128"},
    {LF_QUADWORD, "LF_QUADWORD"},
    {LF_UQUADWORD, "LF_UQUADWORD"},
    {LF_REAL48, "LF_REAL48"},
    {LF_COMPLEX32, "LF_COMPLEX32"},
    {LF_COMPLEX64, "LF_COMPLEX64"},
    {LF_COMPLEX80, "LF_COMPLEX80"},
    {LF_COMPLEX128, "LF_COMPLEX128"},
    {LF_VARSTRING, "LF_VARSTRING"},
    {LF_OCTWORD, "LF_OCTWORD"},
    {LF_UOCTWORD, "LF_UOCTWORD"},
    {LF_DECIMAL, "LF_DECIMAL"},
    {LF_DATE, "LF_DATE"},
    {LF_UTF8STRING, "LF_UTF8STRING"},
    
    {LF_PAD0, "LF_PAD0"},
    {LF_PAD1, "LF_PAD1"},
    {LF_PAD2, "LF_PAD2"},
    {LF_PAD3, "LF_PAD3"},
    {LF_PAD4, "LF_PAD4"},
    {LF_PAD5, "LF_PAD5"},
    {LF_PAD6, "LF_PAD6"},
    {LF_PAD7, "LF_PAD7"},
    {LF_PAD8, "LF_PAD8"},
    {LF_PAD9, "LF_PAD9"},
    {LF_PAD10, "LF_PAD10"},
    {LF_PAD11, "LF_PAD11"},
    {LF_PAD12, "LF_PAD12"},
    {LF_PAD13, "LF_PAD13"},
    {LF_PAD14, "LF_PAD14"},
    {LF_PAD15, "LF_PAD15"},
#endif

    
    {LF_MODIFIER_16t, "LF_MODIFIER_16t"},
    {LF_POINTER_16t, "LF_POINTER_16t"},
    {LF_ARRAY_16t, "LF_ARRAY_16t"},
    {LF_CLASS_16t, "LF_CLASS_16t"},
    {LF_STRUCTURE_16t, "LF_STRUCTURE_16t"},
    {LF_UNION_16t, "LF_UNION_16t"},
    {LF_ENUM_16t, "LF_ENUM_16t"},
    {LF_PROCEDURE_16t, "LF_PROCEDURE_16t"},
    {LF_MFUNCTION_16t, "LF_MFUNCTION_16t"},
    {LF_VTSHAPE, "LF_VTSHAPE"},
    {LF_COBOL0_16t, "LF_COBOL0_16t"},
    {LF_COBOL1, "LF_COBOL1"},
    {LF_BARRAY_16t, "LF_BARRAY_16t"},
    {LF_LABEL, "LF_LABEL"},
    {LF_NULL, "LF_NULL"},
    {LF_NOTTRAN, "LF_NOTTRAN"},
    {LF_DIMARRAY_16t, "LF_DIMARRAY_16t"},
    {LF_VFTPATH_16t, "LF_VFTPATH_16t"},
    {LF_PRECOMP_16t, "LF_PRECOMP_16t"},
    {LF_ENDPRECOMP, "LF_ENDPRECOMP"},
    {LF_OEM_16t, "LF_OEM_16t"},
    {LF_TYPESERVER_ST, "LF_TYPESERVER_ST"},

    // leaf indices starting records but referenced only from type records

    {LF_SKIP_16t, "LF_SKIP_16t"},
    {LF_ARGLIST_16t, "LF_ARGLIST_16t"},
    {LF_DEFARG_16t, "LF_DEFARG_16t"},
    {LF_LIST, "LF_LIST"},
    {LF_FIELDLIST_16t, "LF_FIELDLIST_16t"},
    {LF_DERIVED_16t, "LF_DERIVED_16t"},
    {LF_BITFIELD_16t, "LF_BITFIELD_16t"},
    {LF_METHODLIST_16t, "LF_METHODLIST_16t"},
    {LF_DIMCONU_16t, "LF_DIMCONU_16t"},
    {LF_DIMCONLU_16t, "LF_DIMCONLU_16t"},
    {LF_DIMVARU_16t, "LF_DIMVARU_16t"},
    {LF_DIMVARLU_16t, "LF_DIMVARLU_16t"},
    {LF_REFSYM, "LF_REFSYM"},

    {LF_BCLASS_16t, "LF_BCLASS_16t"},
    {LF_VBCLASS_16t, "LF_VBCLASS_16t"},
    {LF_IVBCLASS_16t, "LF_IVBCLASS_16t"},
    {LF_ENUMERATE_ST, "LF_ENUMERATE_ST"},
    {LF_FRIENDFCN_16t, "LF_FRIENDFCN_16t"},
    {LF_INDEX_16t, "LF_INDEX_16t"},
    {LF_MEMBER_16t, "LF_MEMBER_16t"},
    {LF_STMEMBER_16t, "LF_STMEMBER_16t"},
    {LF_METHOD_16t, "LF_METHOD_16t"},
    {LF_NESTTYPE_16t, "LF_NESTTYPE_16t"},
    {LF_VFUNCTAB_16t, "LF_VFUNCTAB_16t"},
    {LF_FRIENDCLS_16t, "LF_FRIENDCLS_16t"},
    {LF_ONEMETHOD_16t, "LF_ONEMETHOD_16t"},
    {LF_VFUNCOFF_16t, "LF_VFUNCOFF_16t"},

// 32-bit type index versions of leaves, all have the 0x1000 bit set
//
    {LF_TI16_MAX, "LF_TI16_MAX"},

    {LF_MODIFIER, "LF_MODIFIER"},
    {LF_POINTER, "LF_POINTER"},
    {LF_ARRAY_ST, "LF_ARRAY_ST"},
    {LF_CLASS_ST, "LF_CLASS_ST"},
    {LF_STRUCTURE_ST, "LF_STRUCTURE_ST"},
    {LF_UNION_ST, "LF_UNION_ST"},
    {LF_ENUM_ST, "LF_ENUM_ST"},
    {LF_PROCEDURE, "LF_PROCEDURE"},
    {LF_MFUNCTION, "LF_MFUNCTION"},
    {LF_COBOL0, "LF_COBOL0"},
    {LF_BARRAY, "LF_BARRAY"},
    {LF_DIMARRAY_ST, "LF_DIMARRAY_ST"},
    {LF_VFTPATH, "LF_VFTPATH"},
    {LF_PRECOMP_ST, "LF_PRECOMP_ST"},
    {LF_OEM, "LF_OEM"},
    {LF_ALIAS_ST, "LF_ALIAS_ST"},
    {LF_OEM2, "LF_OEM2"},

    // leaf indices starting records but referenced only from type records

    {LF_SKIP, "LF_SKIP"},
    {LF_ARGLIST, "LF_ARGLIST"},
    {LF_DEFARG_ST, "LF_DEFARG_ST"},
    {LF_FIELDLIST, "LF_FIELDLIST"},
    {LF_DERIVED, "LF_DERIVED"},
    {LF_BITFIELD, "LF_BITFIELD"},
    {LF_METHODLIST, "LF_METHODLIST"},
    {LF_DIMCONU, "LF_DIMCONU"},
    {LF_DIMCONLU, "LF_DIMCONLU"},
    {LF_DIMVARU, "LF_DIMVARU"},
    {LF_DIMVARLU, "LF_DIMVARLU"},

    {LF_BCLASS, "LF_BCLASS"},
    {LF_VBCLASS, "LF_VBCLASS"},
    {LF_IVBCLASS, "LF_IVBCLASS"},
    {LF_FRIENDFCN_ST, "LF_FRIENDFCN_ST"},
    {LF_INDEX, "LF_INDEX"},
    {LF_MEMBER_ST, "LF_MEMBER_ST"},
    {LF_STMEMBER_ST, "LF_STMEMBER_ST"},
    {LF_METHOD_ST, "LF_METHOD_ST"},
    {LF_NESTTYPE_ST, "LF_NESTTYPE_ST"},
    {LF_VFUNCTAB, "LF_VFUNCTAB"},
    {LF_FRIENDCLS, "LF_FRIENDCLS"},
    {LF_ONEMETHOD_ST, "LF_ONEMETHOD_ST"},
    {LF_VFUNCOFF, "LF_VFUNCOFF"},
    {LF_NESTTYPEEX_ST, "LF_NESTTYPEEX_ST"},
    {LF_MEMBERMODIFY_ST, "LF_MEMBERMODIFY_ST"},
    {LF_MANAGED_ST, "LF_MANAGED_ST"},

    // Types w/ SZ names

    {LF_ST_MAX, "LF_ST_MAX"},

    {LF_TYPESERVER, "LF_TYPESERVER"},
    {LF_ENUMERATE, "LF_ENUMERATE"},
    {LF_ARRAY, "LF_ARRAY"},
    {LF_CLASS, "LF_CLASS"},
    {LF_STRUCTURE, "LF_STRUCTURE"},
    {LF_UNION, "LF_UNION"},
    {LF_ENUM, "LF_ENUM"},
    {LF_DIMARRAY, "LF_DIMARRAY"},
    {LF_PRECOMP, "LF_PRECOMP"},
    {LF_ALIAS, "LF_ALIAS"},
    {LF_DEFARG, "LF_DEFARG"},
    {LF_FRIENDFCN, "LF_FRIENDFCN"},
    {LF_MEMBER, "LF_MEMBER"},
    {LF_STMEMBER, "LF_STMEMBER"},
    {LF_METHOD, "LF_METHOD"},
    {LF_NESTTYPE, "LF_NESTTYPE"},
    {LF_ONEMETHOD, "LF_ONEMETHOD"},
    {LF_NESTTYPEEX, "LF_NESTTYPEEX"},
    {LF_MEMBERMODIFY, "LF_MEMBERMODIFY"},
    {LF_MANAGED, "LF_MANAGED"},
    {LF_TYPESERVER2, "LF_TYPESERVER2"},

    {LF_STRIDED_ARRAY, "LF_STRIDED_ARRAY"},
    {LF_HLSL, "LF_HLSL"},
    {LF_MODIFIER_EX, "LF_MODIFIER_EX"},
    {LF_INTERFACE, "LF_INTERFACE"},
    {LF_BINTERFACE, "LF_BINTERFACE"},
    {LF_VECTOR, "LF_VECTOR"},
    {LF_MATRIX, "LF_MATRIX"},

    {LF_VFTABLE, "LF_VFTABLE"},
    {LF_ENDOFLEAFRECORD, "LF_ENDOFLEAFRECORD"},

    {LF_TYPE_LAST, "LF_TYPE_LAST"},
    {LF_TYPE_MAX, "LF_TYPE_MAX"},

    {LF_FUNC_ID, "LF_FUNC_ID"},
    {LF_MFUNC_ID, "LF_MFUNC_ID"},
    {LF_BUILDINFO, "LF_BUILDINFO"},
    {LF_SUBSTR_LIST, "LF_SUBSTR_LIST"},
    {LF_STRING_ID, "LF_STRING_ID"},

    {LF_UDT_SRC_LINE, "LF_UDT_SRC_LINE"},
                                 

    {LF_UDT_MOD_SRC_LINE, "LF_UDT_MOD_SRC_LINE"},
                                 

    {LF_ID_LAST, "LF_ID_LAST"},                  
    {LF_ID_MAX, "LF_ID_MAX"},

    {LF_NUMERIC, "LF_NUMERIC"},
    {LF_CHAR, "LF_CHAR"},
    {LF_SHORT, "LF_SHORT"},
    {LF_USHORT, "LF_USHORT"},
    {LF_LONG, "LF_LONG"},
    {LF_ULONG, "LF_ULONG"},
    {LF_REAL32, "LF_REAL32"},
    {LF_REAL64, "LF_REAL64"},
    {LF_REAL80, "LF_REAL80"},
    {LF_REAL128, "LF_REAL128"},
    {LF_QUADWORD, "LF_QUADWORD"},
    {LF_UQUADWORD, "LF_UQUADWORD"},
    {LF_REAL48, "LF_REAL48"},
    {LF_COMPLEX32, "LF_COMPLEX32"},
    {LF_COMPLEX64, "LF_COMPLEX64"},
    {LF_COMPLEX80, "LF_COMPLEX80"},
    {LF_COMPLEX128, "LF_COMPLEX128"},
    {LF_VARSTRING, "LF_VARSTRING"},

    {LF_OCTWORD, "LF_OCTWORD"},
    {LF_UOCTWORD, "LF_UOCTWORD"},

    {LF_DECIMAL, "LF_DECIMAL"},
    {LF_DATE, "LF_DATE"},
    {LF_UTF8STRING, "LF_UTF8STRING"},

    {LF_REAL16, "LF_REAL16"},
    
    {LF_PAD0, "LF_PAD0"},
    {LF_PAD1, "LF_PAD1"},
    {LF_PAD2, "LF_PAD2"},
    {LF_PAD3, "LF_PAD3"},
    {LF_PAD4, "LF_PAD4"},
    {LF_PAD5, "LF_PAD5"},
    {LF_PAD6, "LF_PAD6"},
    {LF_PAD7, "LF_PAD7"},
    {LF_PAD8, "LF_PAD8"},
    {LF_PAD9, "LF_PAD9"},
    {LF_PAD10, "LF_PAD10"},
    {LF_PAD11, "LF_PAD11"},
    {LF_PAD12, "LF_PAD12"},
    {LF_PAD13, "LF_PAD13"},
    {LF_PAD14, "LF_PAD14"},
    {LF_PAD15, "LF_PAD15"},
    
    {TABLE_END, " "},
};

//  Leaf Records
//

#pragma pack(push, 1)

typedef struct class_field_attributes
{
    uint16 Access             :2;     // access protection CV_access_t
    uint16 MethodProperties   :3;     // method properties CV_methodprop_t
    uint16 PseudoFunc         :1;     // compiler generated fcn and does not exist
    uint16 NoInherit          :1;     // true if class cannot be inherited
    uint16 NoConstruct        :1;     // true if class cannot be constructed
    uint16 CompilerGener      :1;     // compiler generated fcn and does exist
    uint16 Sealed             :1;     // true if method cannot be overridden
    uint16 Unused             :6;     // unused
} class_field_attributes;

typedef struct leaf_record_properties
{
    uint16 Packed             :1;     // true if structure is packed
    uint16 Constructor        :1;     // true if constructors or destructors present
    uint16 OverlodedOperators :1;     // true if overloaded operators present
    uint16 IsNested           :1;     // true if this is a nested class
    uint16 ClassNested        :1;     // true if this class contains nested types
    uint16 OverloadedAssign   :1;     // true if overloaded assignment (=)
    uint16 OpcastMethods      :1;     // true if casting methods
    uint16 ForwardReference   :1;     // true if forward reference (incomplete defn)
    uint16 Scoped             :1;     // scoped definition
    uint16 HasUniqueName      :1;   // true if there is a decorated name following the regular name
    uint16 Sealed             :1;     // true if class cannot be used as a base class
    uint16 Hfa                :2;     // CV_HFA_e
    uint16 IntrinsicType      :1;     // true if class is an intrinsic type (e.g. __m128d)
    uint16 Mocom              :2;     // CV_MOCOM_UDT_e
} leaf_record_properties;

typedef struct leaf_record_header
{
    uint16 Length;    // Record length, not including this 2 byte field.
    uint16 Kind;      // Record kind enum.
} leaf_record_header;

//

typedef struct leaf_record_struct
{
    leaf_record_header Header;

    uint16 Count;

    leaf_record_properties Properties;
    
    uint32 FieldList;
    uint32 Derived;
    uint32 VShape;

    uint16 StructSize;
    char Name[];
} leaf_record_struct;

typedef struct leaf_record_substruct_header
{
    uint16 Kind;
} leaf_record_substruct_header;
typedef struct leaf_record_substruct_member
{
    leaf_record_substruct_header Header;
    
    class_field_attributes FieldAttributes;
    
    uint32 Index;
    uint16 Offset;
    
    char Name[];
} leaf_record_substruct_member;
typedef struct leaf_record_substruct_enumerate
{
    leaf_record_substruct_header Header;
    
    class_field_attributes FieldAttributes;
    
    uint16 EnumValue;
    
    char Name[];
} leaf_record_substruct_enumerate;

typedef struct leaf_record_function_id
{
    leaf_record_substruct_header Header;

    uint16 Unused;
    
    uint32 ScopeId;    // parent scope of the ID, 0 if global
    uint32 Type;       // function type
    
    char Name[];
} leaf_record_function_id;

//
typedef enum simple_type_kind
{
    None = 0x0000,          // uncharacterized type (no type)
    Void = 0x0003,          // void
    NotTranslated = 0x0007, // type not translated by cvpack
    HResult = 0x0008,       // OLE/COM HRESULT

    SignedCharacter = 0x0010,   // 8 bit signed
    UnsignedCharacter = 0x0020, // 8 bit unsigned
    NarrowCharacter = 0x0070,   // really a char
    WideCharacter = 0x0071,     // wide char
    Character16 = 0x007a,       // char16_t
    Character32 = 0x007b,       // char32_t
    Character8 = 0x007c,        // char8_t

    SByte = 0x0068,       // 8 bit signed int
    Byte = 0x0069,        // 8 bit unsigned int
    Int16Short = 0x0011,  // 16 bit signed
    UInt16Short = 0x0021, // 16 bit unsigned
    Int16 = 0x0072,       // 16 bit signed int
    UInt16 = 0x0073,      // 16 bit unsigned int
    Int32Long = 0x0012,   // 32 bit signed
    UInt32Long = 0x0022,  // 32 bit unsigned
    Int32 = 0x0074,       // 32 bit signed int
    UInt32 = 0x0075,      // 32 bit unsigned int
    Int64Quad = 0x0013,   // 64 bit signed
    UInt64Quad = 0x0023,  // 64 bit unsigned
    Int64 = 0x0076,       // 64 bit signed int
    UInt64 = 0x0077,      // 64 bit unsigned int
    Int128Oct = 0x0014,   // 128 bit signed int
    UInt128Oct = 0x0024,  // 128 bit unsigned int
    Int128 = 0x0078,      // 128 bit signed int
    UInt128 = 0x0079,     // 128 bit unsigned int

    Float16 = 0x0046,                 // 16 bit real
    Float32 = 0x0040,                 // 32 bit real
    Float32PartialPrecision = 0x0045, // 32 bit PP real
    Float48 = 0x0044,                 // 48 bit real
    Float64 = 0x0041,                 // 64 bit real
    Float80 = 0x0042,                 // 80 bit real
    Float128 = 0x0043,                // 128 bit real

    Complex16 = 0x0056,                 // 16 bit complex
    Complex32 = 0x0050,                 // 32 bit complex
    Complex32PartialPrecision = 0x0055, // 32 bit PP complex
    Complex48 = 0x0054,                 // 48 bit complex
    Complex64 = 0x0051,                 // 64 bit complex
    Complex80 = 0x0052,                 // 80 bit complex
    Complex128 = 0x0053,                // 128 bit complex

    Boolean8 = 0x0030,   // 8 bit boolean
    Boolean16 = 0x0031,  // 16 bit boolean
    Boolean32 = 0x0032,  // 32 bit boolean
    Boolean64 = 0x0033,  // 64 bit boolean
    Boolean128 = 0x0034, // 128 bit boolean
} simple_type_kind;

name_table SimpleTypeNames[] = 
{
    {None, "None"},
    {Void, "void"},
    {NotTranslated, "NotTranslated"},
    {HResult, "HResult"},

    {SignedCharacter, "signed char"},
    {UnsignedCharacter, "unsigned char"},
    {NarrowCharacter, "char"},
    {WideCharacter, "wchar"},
    {Character16, "char16"},
    {Character32, "char32"},
    {Character8, "char8"},

    {SByte, "signed byte"},
    {Byte, "byte"},
    {Int16Short, "int16 short"},
    {UInt16Short, "uint16 short"},
    {Int16, "int16"},
    {UInt16, "uint16"},
    {Int32Long, "int32 long"},
    {UInt32Long, "int32 long"},
    {Int32, "int32"},
    {UInt32, "uint32"},
    {Int64Quad, "int64 quad"},
    {UInt64Quad, "uint64 quad"},
    {Int64, "int64"},
    {UInt64, "uint64"},
    {Int128Oct, "int128 oct"},
    {UInt128Oct, "uint128 oct"},
    {Int128, "int128"},
    {UInt128, "uint128"},
    
    {Float16, "real16"},
    {Float32, "real32"},
    {Float32PartialPrecision, "real32 PartialPrecision"},
    {Float48, "real48"},
    {Float64, "real64"},
    {Float80, "real80"},
    {Float128, "real128"},

    {Complex16, "complex16"},
    {Complex32, "complex32"},
    {Complex32PartialPrecision, "complex32 PartialPrecision"},
    {Complex48, "complex48"},
    {Complex64, "complex64"},
    {Complex80, "complex80"},
    {Complex128, "complex128"},

    {Boolean8, "bool8"},
    {Boolean16, "bool16"},
    {Boolean32, "bool32"},
    {Boolean64, "bool64"},
    {Boolean128, "bool128"},

    {TABLE_END, ""},
};

typedef enum simple_type_mode
{
    Direct = 0,        // Not a pointer
    
    NearPointer = 1,   // Near pointer
    FarPointer = 2,    // Far pointer
    HugePointer = 3,   // Huge pointer
    NearPointer32 = 4, // 32 bit near pointer
    FarPointer32 = 5,  // 32 bit far pointer
    NearPointer64 = 6, // 64 bit near pointer
    NearPointer128 = 7 // 128 bit near pointer
} simple_type_mode;

typedef struct type_index
{
    simple_type_kind Kind   :8;
    simple_type_mode Mode   :4;
    uint32 Unused :20;
} type_index;
//

typedef struct leaf_record_field
{
    leaf_record_header Header;

    char Data[];
    
} leaf_record_field;

#pragma pack(pop)

//

typedef enum dbi_stream_version
{
    DBI_VC41 = 930803,
    DBI_V50 = 19960307,
    DBI_V60 = 19970606,
    DBI_V70 = 19990903,
    DBI_V110 = 20091201
} dbi_stream_version;

typedef struct dbi_stream_header
{
    int32 VersionSignature;
    dbi_stream_version VersionHeader;
    uint32 Age;
    
    uint16 GlobalStreamIndex;

    struct
    {
        uint16 MinorVersion : 8;
        uint16 MajorVersion : 7;
        uint16 NewVersionFormat : 1;
    } BuildNumber;
    
    uint16 PublicStreamIndex;
    uint16 PdbDllVersion;
    uint16 SymRecordStream;
    uint16 PdbDllRbld;

    int32 ModInfoSize;
    int32 SectionContributionSize;
    int32 SectionMapSize;
    int32 SourceInfoSize;
    int32 TypeServerMapSize;

    uint32 MFCTypeServerIndex;

    int32 OptionalDbgHeaderSize;
    int32 ECSubstreamSize;

    struct
    {
        uint16 WasIncrementallyLinked : 1;
        uint16 ArePrivateSymbolsStripped : 1;
        uint16 HasConflictingTypes : 1;
        uint16 Reserved : 13;
    } Flags;

    
    uint16 Machine;
    uint32 Padding;

    // Extended
} dbi_stream_header;

typedef struct module_info
{
    uint32 Opened;
    
    struct
    {
        uint16 Section;
        char Padding1[2];
        int32 Offset;
        int32 Size;
        uint32 Characteristics;
        uint16 ModuleIndex;
        char Padding2[2];
        uint32 DataCRC;
        uint32 RelocCRC;
    } SectionContribution;
    
    uint16 Flags;
    
    uint16 ModuleSymbolStream;
    
    uint32 CodeViewSymbolsSize;
    uint32 C11CodeViewLinesSize;
    uint32 C13CodeViewLinesSize;
    
    uint16 SourceFileCount;
    
    char Padding[2];
    uint32 Offsets;
    
    uint32 SourceFileNameIndex;
    uint32 PdbFilePathNameIndex;
    
    char ModuleName[];
} module_info;

#define WIN32_PDBDUMP_H
#endif
