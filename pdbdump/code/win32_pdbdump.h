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
} leaf_record_type;

typedef struct name_table
{
    uint32 Identifier;
    char *Name;
} name_table;

#define TABLE_END 0xffff

name_table LeafRecordNames[] =
{
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

typedef struct leaf_record_substruct
{
    uint16 Kind;
} leaf_record_substruct;
typedef struct leaf_record_substruct_member
{
    leaf_record_substruct Header;
    
    class_field_attributes FieldAttributes;
    uint32 Index;
    uint32 Offset;
} leaf_record_substruct_member;

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
} dbi_stream_header;

typedef struct module_info
{
    uint32 Unused1;

    struct SectionContribEntry
    {
        uint16 Section;
        char Padding1[2];
        int32 Offset;
        int32 Size;
        uint32 Characteristics;
        uint16 ModuleIndex;
        char Padding2[2];
        uint32 DataCrc;
        uint32 RelocCrc;
    } SectionContr;

    uint16 Flags;
    uint16 ModuleSymStream;
    uint32 SymByteSize;
    uint32 C11ByteSize;
    uint32 C13ByteSize;
    uint16 SourceFileCount;
    char Padding[2];
    uint32 Unused2;
    uint32 SourceFileNameIndex;
    uint32 PdbFilePathNameIndex;
} module_info;

#define WIN32_PDBDUMP_H
#endif
