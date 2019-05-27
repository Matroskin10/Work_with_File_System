#pragma once
#include "FileSystemClass.h"

typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_Name[8];
	BYTE bytesPerSector[2];
	BYTE sectorsPerCluster;
	BYTE Padding2[26];
	ULONGLONG SectorsTotal;

} NTFS_BootRecord;


class Work_with_NTFS : public FileSystemClass
{
public:
	Work_with_NTFS(BYTE * BufferRecord, HANDLE fileHandle);
	virtual bool ReadClusters(ULONGLONG startCluster, DWORD numberOfClusters, BYTE *outBuffer);
	~Work_with_NTFS();
};