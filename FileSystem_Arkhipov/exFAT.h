#pragma once
#include "FileSystemClass.h"

typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_Name[8];
	BYTE Padding2[61];
	ULONGLONG  SectorsTotal;
	DWORD FAT_StartSector;
	DWORD FAT_Size;
	DWORD FirstDataSector;
	ULONGLONG  ClustersTotal;
	DWORD RootDirCluster;
	BYTE SectorFactor;
	BYTE ClusterFactor;

} ExFAT_BootRecord;

class Work_with_exFAT : public FileSystemClass
{
public:
	Work_with_exFAT(BYTE * BufferRecord, HANDLE fileHandle);
	virtual bool ReadClusters(ULONGLONG startCluster, DWORD numberOfClusters, BYTE *outBuffer);
	~Work_with_exFAT();
};