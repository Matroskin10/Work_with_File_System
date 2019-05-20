#include "pch.h"
#include "FAT32.h"
#include <string>
#include <iostream>

Work_with_FAT32::Work_with_FAT32(BYTE * BufferRecord, HANDLE fileHandle)
{
	FAT32_BootRecord * pBootRecord = (FAT32_BootRecord *)BufferRecord;
	memcpy(OEM_Name, pBootRecord->OEM_Name, sizeof(OEM_Name));
	BytesPerSector = *((WORD*)pBootRecord->bytesPerSector);
	SectorsPerCluster = pBootRecord->sectorsPerCluster;
	BytesPerCluster = SectorsPerCluster * BytesPerSector;
	TotalSectors = pBootRecord->SectorsTotal;
	TotalClusters = TotalSectors / SectorsPerCluster;
	FileHandle = fileHandle;
}

bool Work_with_FAT32::ReadClusters(ULONGLONG startCluster, DWORD numberOfClusters, BYTE * outBuffer)
{
	DWORD bytesToRead;
	DWORD bytesRead;
	LARGE_INTEGER clusterOffset;
	clusterOffset.QuadPart = startCluster * BytesPerCluster;
	bytesToRead = numberOfClusters * BytesPerCluster;
	unsigned long currentPosition = SetFilePointer(
		FileHandle,
		clusterOffset.LowPart,
		&clusterOffset.HighPart,
		FILE_BEGIN
		// Точка в файле, относительно которой необходимо позиционироваться 
		//(FILE_BEGIN, FILE_CURRENT, FILE_END)
	);

	if (currentPosition != clusterOffset.LowPart)
	{
		std::cout << "Error: Impossible to define border!" << std::endl;
		exit(GetLastError());
	}

	bool readResult = ReadFile(
		FileHandle,
		outBuffer,
		bytesToRead,
		&bytesRead,
		NULL
	);
	int i = 0;
	while (i != bytesToRead) {
		int check = int(*outBuffer);
		switch (check)
		{
		case 0:
			std::cout << "00 ";
			break;
		case 1:
			std::cout << "01 ";
			break;
		case 2:
			std::cout << "02 ";
			break;
		case 3:
			std::cout << "03 ";
			break;
		case 4:
			std::cout << "04 ";
			break;
		case 5:
			std::cout << "05 ";
			break;
		case 6:
			std::cout << "06 ";
			break;
		case 7:
			std::cout << "07 ";
			break;
		case 8:
			std::cout << "08 ";
			break;
		case 9:
			std::cout << "09 ";
			break;
		case 10:
			std::cout << "0a ";
			break;
		case 11:
			std::cout << "0b ";
			break;
		case 12:
			std::cout << "0c ";
			break;
		case 13:
			std::cout << "0d ";
			break;
		case 14:
			std::cout << "0e ";
			break;
		case 15:
			std::cout << "0f ";
			break;
		default:
			std::cout << std::hex << DWORD(*outBuffer) << " ";
			break;
		}
		outBuffer++;
		i++;
		if (i % 16 == 0)
		{
			std::cout << std::endl;
		}
	}
}

Work_with_FAT32::~Work_with_FAT32()
{

}
