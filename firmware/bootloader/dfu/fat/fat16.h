/*!
 * \file fat16.h
 *
 * \brief 
 *
 *
 * \date Jun 15, 2011
 * \author Dan Riedler
 *
 */
#ifndef _FAT16_H_
#define _FAT16_H_

/*-----------------------------------------------------------------------------
 Includes
------------------------------------------------------------------------------*/
#include "bootloader.h"


/*-----------------------------------------------------------------------------
 Defines
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 Macros
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 Typedefs
------------------------------------------------------------------------------*/
PUBLIC typedef enum
{
	FAT16_MEDIA_DES_REMOVABLE	= 0xF0,
	FAT16_MEDIA_DES_FIXED_DISK 	= 0xF8
} FAT16_MediaDescriptor;


// refer to: http://en.wikipedia.org/wiki/File_Allocation_Table#Boot_Sector
// http://staff.washington.edu/dittrich/misc/fatgen103.pdf
// http://www.beginningtoseethelight.org/fat16/
#pragma pack(push, 1)
PUBLIC typedef struct
{
	uint8 JumpInstruct[3];
	uint8 OEMName[8];
	uint16 BytesPerSector;
	uint8 SectorsPerCluster;
	uint16 ReservedSectorCount;
	uint8 NumFats;
	uint16 MaxRootEntries;
	uint16 TotalSectors;
	FAT16_MediaDescriptor MediaDescriptor;
	uint16 SectorsPerFat;
	uint16 SectorsPerTrack;
	uint16 NumOfHeads;
	uint32 NumHiddenSectors;
	uint32 TotalSectors2;
	uint8 PhysicalDriveNumber;
	uint8 CurrentHead;
	uint8 ExtendedBootSig;
	uint32 SerialNumber;
	uint8 VolumeLabel[11];
	uint8 FatType[8];
	uint8 BootCode[448];
	uint16 BootSectorSig;
} FAT16_BootSectorInfo;
#pragma pack(pop)
#define FAT16_BOOT_SECTOR_SIZE sizeof(FAT16_BootSectorInfo)

PUBLIC typedef uint16 FAT16_FatEntry;
#define FAT16_FAT_ENTRY_SIZE sizeof(FAT16_FatEntry)

PUBLIC typedef enum
{
	FAT16_ENTRY_FREE_CLUSTER		= 0x0000,
	FAT16_ENTRY_FIRST_CLUSTER		= 0x0001,
	FAT16_ENTRY_RESERVED0			= 0xFFF0,
	FAT16_ENTRY_RESERVED1			= 0xFFF1,
	FAT16_ENTRY_RESERVED2			= 0xFFF2,
	FAT16_ENTRY_RESERVED3			= 0xFFF3,
	FAT16_ENTRY_RESERVED4			= 0xFFF4,
	FAT16_ENTRY_RESERVED5			= 0xFFF5,
	FAT16_ENTRY_RESERVED6			= 0xFFF6,
	FAT16_ENTRY_BAD_SECTOR			= 0xFFF7,
	FAT16_ENTRY_LAST_CLUSTER		= 0xFFFF
} FAT16_FatSpecialEntry;


PUBLIC typedef enum
{
	FAT16_FILE_ATTR_READ_ONLY 		= (1 << 0),
	FAT16_FILE_ATTR_HIDDEN			= (1 << 1),
	FAT16_FILE_ATTR_SYSTEM			= (1 << 2),
	FAT16_FILE_ATTR_VOLUME_LABEL	= (1 << 3),
	FAT16_FILE_ATTR_SUB_DIR			= (1 << 4),
	FAT16_FILE_ATTR_ARCHIVE			= (1 << 5),
	FAT16_FILE_ATTR_DEVICE			= (1 << 6),
	FAT16_FILE_ATTR_UNUSED			= (1 << 7)
} FAT16_FileAttributes;

// refer to: http://en.wikipedia.org/wiki/File_Allocation_Table#Directory_Table
#pragma pack(push, 1)
PUBLIC typedef struct
{
	uint8 Filename[8];
	uint8 Extension[3];
	uint8 Attributes;
	uint8 Reserved;
	uint8 CreationTimeMs;
	uint16 CreationTime;
	uint16 CreationDate;
	uint16 LastAccessDate;
	uint16 EaIndex;
	uint16 LastModifyTime;
	uint16 LastModifyDate;
	uint16 StartOfFile;
	uint32 FileSize;
} FAT16_DirectoryEntryInfo;
#pragma pack(pop)
#define FAT16_DIRECTORY_ENTRY_SIZE sizeof(FAT16_DirectoryEntryInfo)

/*-----------------------------------------------------------------------------
 Exported Function Prototypes
------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
 External Data Members
------------------------------------------------------------------------------*/



#endif /* _FAT16_H_ */
