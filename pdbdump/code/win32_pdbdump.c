/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Felipe Carlin $
   $Notice: Copyright © 2021 Felipe Carlin $
   ======================================================================== */

#include <stdint.h>

typedef int64_t int64;
typedef int32_t int32;
typedef int16_t int16;
typedef int8_t int8;

typedef uint64_t uint64;
typedef uint32_t uint32;
typedef uint16_t uint16;
typedef uint8_t uint8;

typedef float real32;
typedef double real64;

typedef uint32 bool32;

#define internal static
#define local_persist static
#define global_variable static

#define true 1
#define false 0

#include <stdio.h>
#include <windows.h>

#define Assert(X) if(!(X)) {*(int *)0 = 0;}

#define ArrayCount(A) (sizeof(A) / sizeof((A)[0]))

typedef struct loaded_file
{
    char *Name;
    
    void *Memory;
    uint32 Size;
} loaded_file;

inline uint32
SafeTruncateUInt64(uint64 Value)
{
    // TODO(felipe): Defines for maximum values.
    Assert(Value <= 0xFFFFFFFF);
    uint32 Result = (uint32)Value;
    return Result;
}

internal loaded_file
Win32ReadEntireFile(char *Filename)
{
    loaded_file Result = {0};
    
    bool32 Failed = false;
    
    HANDLE FileHandle = CreateFileA(Filename, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
    if(FileHandle != INVALID_HANDLE_VALUE)
    {
        LARGE_INTEGER FileSize;
        if(GetFileSizeEx(FileHandle, &FileSize))
        {
            uint32 FileSize32 = SafeTruncateUInt64(FileSize.QuadPart);
            Result.Memory = VirtualAlloc(0, FileSize32, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE);
            if(Result.Memory)
            {
                DWORD BytesRead;
                if(ReadFile(FileHandle, Result.Memory, FileSize32, &BytesRead, 0) &&
                   (FileSize32 == BytesRead))
                {
                    // NOTE(felipe): File read succesfully.
                    Result.Name = Filename;
                    Result.Size = FileSize32;
                }
                else
                {
                    // TODO(felipe): Logging.
                    VirtualFree(Result.Memory, 0, MEM_RELEASE);
                    Result.Memory = 0;
                }
            }
            else
            {
                Failed = true;
                // TODO(felipe): Logging.
            }
        }
        else
        {
            Failed = true;
            // TODO(felipe): Logging.
        }

        CloseHandle(FileHandle);
    }
    else
    {
        Failed = true;
        // TODO(felipe): Logging.
    }

    if(Failed)
    {
//        Error(State, "cannot open %s: %s", Filename);
        fprintf(stderr, "cannot open: %s\n", Filename);
    }

    return Result;
}

internal void
AssertError(uint32 Condition, char *Error)
{
    if(!Condition)
    {
        printf(Error);
        exit(1);
    }
}

internal uint32
Ceil(real32 Value)
{
    uint32 Result = (uint32)Value;
    if(Result != Value)
    {
        Result += 1;
    }

    return Result;
}

typedef struct guid
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} guid;

typedef struct super_block
{
    char FileMagic[32];
    uint32 BlockSize;
    uint32 FreeBlockMapBlock;
    uint32 NumberOfBlocks;
    uint32 NumberOfDirectoryBytes;
    uint32 Unknown;
    uint32 BlockMapIndex;
} super_block;

typedef struct stream_directory
{
    uint32 NumberOfStreams;
    uint32 StreamSizes[1];
} stream_directory;

typedef enum pdb_stream_version
{
    VC2 = 19941610,
    VC4 = 19950623,
    VC41 = 19950814,
    VC50 = 19960307,
    VC98 = 19970604,
    VC70Dep = 19990604,
    VC70 = 20000404,
    VC80 = 20030901,
    VC110 = 20091201,
    VC140 = 20140508,
} pdb_stream_version;

typedef struct bit_vector
{
    uint32 WordCount;
    uint32 Words[1];
} bit_vector;

typedef struct pdb_stream_header
{
    pdb_stream_version Version;
    uint32 Signature;
    uint32 Age;
    guid UniqueId;
} pdb_stream_header;

typedef struct pdb_file
{
    uint8 *Memory;
    
    super_block *SuperBlock;
    stream_directory *StreamDirectory;
} pdb_file;

internal uint8 *
PDBGetBlock(pdb_file *PDB, uint32 BlockIndex)
{
    Assert(BlockIndex < PDB->SuperBlock->NumberOfBlocks);
    uint8 *Result = PDB->Memory + PDB->SuperBlock->BlockSize*BlockIndex;
    
    return Result;
}

internal void *
PDBGetIndexedStream(pdb_file *PDB, uint32 StreamIndex)
{
    uint32 PDBStreamSize = PDB->StreamDirectory->StreamSizes[StreamIndex];
    uint32 PDBStreamBlockCount = Ceil((real32)PDBStreamSize/PDB->SuperBlock->BlockSize);
    uint32 RoundedPDBStreamSize = PDBStreamBlockCount*PDB->SuperBlock->BlockSize;
        
    uint8 *Stream = malloc(RoundedPDBStreamSize);
        
    uint32 *StreamDirectoryStreams = PDB->StreamDirectory->StreamSizes + PDB->StreamDirectory->NumberOfStreams;
    uint32 *PDBStreamBlocks = StreamDirectoryStreams;
    for(uint32 Index = 0;
        Index < StreamIndex;
        ++Index)
    {
        uint32 StreamSize = Ceil((real32)PDB->StreamDirectory->StreamSizes[Index]/PDB->SuperBlock->BlockSize);
        PDBStreamBlocks += StreamSize;
    }
        
    for(uint32 BlockIndex = 0;
        BlockIndex < PDBStreamBlockCount;
        ++BlockIndex)
    {
        uint8 *CurrentBlockSource = PDBGetBlock(PDB, *(PDBStreamBlocks + BlockIndex));
        uint8 *CurrentBlockDestination = Stream + BlockIndex*PDB->SuperBlock->BlockSize;

        for(uint32 Index = 0;
            Index < PDB->SuperBlock->BlockSize;
            ++Index)
        {
            CurrentBlockDestination[Index] = CurrentBlockSource[Index];
        }
    }

    return Stream;
}

#include "win32_pdbdump.h"

int main(int ArgC, char *ArgV[])
{
    char *FileMagic = "Microsoft C / C++ MSF 7.00\\r\\n\x1a\x44\x53\x00\x00\x00";
    
    if(ArgC == 2)
    {   
        loaded_file File = Win32ReadEntireFile(ArgV[1]);
        super_block *SuperBlock = (super_block *)File.Memory;

        pdb_file PDB = {0};
        PDB.Memory = File.Memory;
        PDB.SuperBlock = SuperBlock;
        
        // NOTE(felipe): Check file signature.
        bool32 FileIsValid = true;
        for(uint32 Index = 0;
            Index < ArrayCount(FileMagic);
            ++Index)
        {
            if(SuperBlock->FileMagic[Index] != FileMagic[Index])
            {
                FileIsValid = false;
                break;
            }
        }
        
        AssertError((SuperBlock->BlockSize == 512) || (SuperBlock->BlockSize == 1024) || (SuperBlock->BlockSize == 2048) || (SuperBlock->BlockSize == 4096),
                    "Invalid SuperBlock BlockSize\n");
        AssertError((SuperBlock->FreeBlockMapBlock == 1) || (SuperBlock->FreeBlockMapBlock == 2),
                    "Invalid SuperBlock FreeBlockMapBlock\n");
        AssertError((SuperBlock->BlockSize * SuperBlock->NumberOfBlocks) == File.Size,
                    "Invalid number of blocks\n");
        
        printf("%s\n", File.Name);
        
        printf("\tBlockSize: %d\n\tFreeBlockMapBlock: %d\n\tNumber of Blocks: %d\n\tNumber of Directory Bytes: %d\n\tBlockMapIndex: %d\n",
               SuperBlock->BlockSize, SuperBlock->FreeBlockMapBlock,
               SuperBlock->NumberOfBlocks, SuperBlock->NumberOfDirectoryBytes,
               SuperBlock->BlockMapIndex);

        // NOTE(felipe): Stream Directory.
        uint32 DirectoryBlockCount = Ceil((real32)SuperBlock->NumberOfDirectoryBytes / SuperBlock->BlockSize);
        uint32 *StreamDirectoryBlocks = (uint32 *)PDBGetBlock(&PDB, SuperBlock->BlockMapIndex);
        uint8 *StreamDirectory = malloc(SuperBlock->BlockSize*DirectoryBlockCount);
        
        for(uint32 BlockIndex = 0;
            BlockIndex < DirectoryBlockCount;
            ++BlockIndex)
        {
            uint8 *CurrentBlockSource = PDBGetBlock(&PDB, StreamDirectoryBlocks[BlockIndex]);
            uint8 *CurrentBlockDestination = StreamDirectory + BlockIndex*SuperBlock->BlockSize;
            
            for(uint32 Index = 0;
                Index < SuperBlock->BlockSize;
                ++Index)
            {
                CurrentBlockDestination[Index] = CurrentBlockSource[Index];
            }
        }
        
        PDB.StreamDirectory = (stream_directory *)StreamDirectory;
        
        printf("\nNumber of streams: %d\n", PDB.StreamDirectory->NumberOfStreams);

        printf("\tOld Directory: %.8d bytes\n", PDB.StreamDirectory->StreamSizes[0]);
        printf("\tPDB Stream:    %.8d bytes\n", PDB.StreamDirectory->StreamSizes[1]);
        printf("\tTPI Stream:    %.8d bytes\n", PDB.StreamDirectory->StreamSizes[2]);
        printf("\tDBI Stream:    %.8d bytes\n", PDB.StreamDirectory->StreamSizes[3]);
        printf("\tIPI Stream:    %.8d bytes\n", PDB.StreamDirectory->StreamSizes[4]);

        
        // NOTE(felipe): PDB Stream
        pdb_stream_header *PDBStreamHeader = (pdb_stream_header *)PDBGetIndexedStream(&PDB, 1);

        uint32 *StringEntrySize = (uint32 *)(PDBStreamHeader + 1);
        char *StringEntry = (char *)(StringEntrySize + 1);

        uint32 *StringTableSize = (uint32 *)(StringEntry + *StringEntrySize);
        uint32 *StringTableCapacity = (uint32 *)(StringTableSize + 1);
        
        bit_vector *PresentBit = (bit_vector *)(StringTableCapacity + 1);
        bit_vector *DeletedBit = (bit_vector *)((uint32 *)PresentBit + PresentBit->WordCount + 1);

        typedef struct bucket
        {
            uint32 Key;
            uint32 Value;
        } bucket;

        bucket *Buckets = (bucket *)((uint32 *)DeletedBit + DeletedBit->WordCount + 1);

        guid Guid = PDBStreamHeader->UniqueId;
        
        printf("\nPDB Stream:\n");
        printf("\tVersion: %d\n\tSignature: %d\n\tAge: %d\n\tGUID: Guid = {%08lX-%04hX-%04hX-%02hhX%02hhX-%02hhX%02hhX%02hhX%02hhX%02hhX%02hhX}\n\n",
               PDBStreamHeader->Version, PDBStreamHeader->Signature, PDBStreamHeader->Age,
               Guid.Data1, Guid.Data2, Guid.Data3, 
               Guid.Data4[0], Guid.Data4[1], Guid.Data4[2], Guid.Data4[3],
               Guid.Data4[4], Guid.Data4[5], Guid.Data4[6], Guid.Data4[7]);

        for(uint32 Index = 0;
            Index < (*StringTableCapacity/2);
            ++Index)
        {
            printf("\t  %d. ", Index);
            
            uint32 Word = PresentBit->Words[Index/32];
            if(Word & (Index % 32))
            {
                char *StreamName = StringEntry + Buckets[Index].Key;
                printf("Present     %s -> %d\n", StreamName, Buckets[Index].Value);
//                Buckets[Index];
            }
            else
            {
                printf("Not present\n");
            }
        }

        // NOTE(felipe): TPI Stream
//        pdb_stream_header *PDBStreamHeader = (pdb_stream_header *)PDBGetIndexedStream(&PDB, 2);

        // NOTE(felipe): DBI Stream
        dbi_stream_header *DBIStreamHeader = (dbi_stream_header *)PDBGetIndexedStream(&PDB, 3);
        module_info *Module = (module_info *)(DBIStreamHeader + 1);
        char *ModuleName = (char *)(Module + 1);
        
        //
        //
        
        int HB = 69;
    }
    else
    {
        printf("Usage: pdbdump <filename>\n");
    }
    
    return 0;
}
