#pragma once
#include "FileSystemClass.h"
#include "NTFS.h"
#include "exFAT.h"
#include "FAT32.h"

typedef struct
{
	BYTE Padding1[3];
	BYTE OEM_Name[8];
} OEM_Record;

class CreateFileSystemClass
{
protected:
	HANDLE FileHandle;
public:
	CreateFileSystemClass();
	bool Handle();
	void GetFirstSector(BYTE* tempBuffer);
	HANDLE GetHandle();
	static FileSystemClass * CreateFileSystem(BYTE * buffer, HANDLE FileHandle);
	~CreateFileSystemClass();
};
