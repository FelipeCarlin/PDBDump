#if !defined(WIN32_PDBDUMP_H)
/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Felipe Carlin $
   $Notice: Copyright © 2022 Felipe Carlin $
   ======================================================================== */

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
