#pragma once
#include <windows.h>

class FileSystemClass
{
protected:
	HANDLE FileHandle;
	BYTE OEM_Name[8];
	DWORD BytesPerSector;
	DWORD SectorsPerCluster;
	DWORD BytesPerCluster;
	DWORD TotalClusters;
	DWORD TotalSectors;
public:
	FileSystemClass();
	BYTE * GetOEM_Name();
	DWORD GetTotalClusters() const;
	DWORD GetBytesPerCluster() const;
	DWORD GetBytesPerSector() const;
	DWORD GetTotalSectors() const;
	DWORD GetSectorsPerCluster() const;
	virtual bool ReadClusters(ULONGLONG startCluster, DWORD numberOfClusters, BYTE *outBuffer) = 0;
	~FileSystemClass();
	void CloseDisk();
};