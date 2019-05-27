#include "FileSystemClass.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <wchar.h>

using namespace std;

FileSystemClass::FileSystemClass()
{
	FileHandle = NULL;
	OEM_Name[8] = 0;
	BytesPerSector = 0;
	SectorsPerCluster = 0;
	BytesPerCluster = 0;
	TotalClusters = 0;
	TotalSectors = 0;
}

BYTE * FileSystemClass::GetOEM_Name()
{
	return OEM_Name;
}

DWORD FileSystemClass::GetTotalClusters() const
{
	return TotalClusters;
}

DWORD FileSystemClass::GetBytesPerCluster() const
{
	return BytesPerCluster;
}

DWORD FileSystemClass::GetTotalSectors() const
{
	return TotalSectors;
}

DWORD FileSystemClass::GetBytesPerSector() const
{
	return BytesPerSector;
}

DWORD FileSystemClass::GetSectorsPerCluster() const
{
	return SectorsPerCluster;
}

FileSystemClass::~FileSystemClass()
{
}

void FileSystemClass::CloseDisk()
{
	CloseHandle(FileHandle);
}