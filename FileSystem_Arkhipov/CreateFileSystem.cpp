#include "pch.h"
#include "CreateFileSystem.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <wchar.h>

CreateFileSystemClass::CreateFileSystemClass()
{
	FileHandle = NULL;
}

bool CreateFileSystemClass::Handle()
{
	std::wstring fileNameFirst;
	std::wcout << "Enter name logical disk (in format: \\\\.\\<name logical disk>:): " << std::endl;
	std::wcin >> fileNameFirst;
	WCHAR * fileName = &fileNameFirst[0];

	FileHandle = CreateFileW(
		fileName, // Имя файла (WCHAR*)
		GENERIC_READ,	  // Режим доступа
		FILE_SHARE_READ | FILE_SHARE_WRITE, // Режим совместной работы
		NULL, // Атрибуты безопасности
		OPEN_EXISTING, // Способ открытия
		FILE_ATTRIBUTE_NORMAL, // Флаги и атрибуты
		NULL // Описатель (идентификатор) файла шаблона с правами доступа GENERIC_READ.
	);

	if (FileHandle == INVALID_HANDLE_VALUE) {
		std::cout << "Error: File system not defined or unable to open disk!" << std::endl;
		exit(GetLastError());
	}
	else {
		return 0;
	}
}

HANDLE CreateFileSystemClass::GetHandle()
{
	return FileHandle;
}

void CreateFileSystemClass::GetFirstSector(BYTE* tempBuffer)
{
	DWORD bytesRead;
	bool readResult = ReadFile(
		FileHandle,
		tempBuffer,
		512,
		&bytesRead,
		NULL
	);

	if (!readResult) {
		std::cout << "Error read first sector!" << std::endl;
		exit(GetLastError());
	}

}

FileSystemClass * CreateFileSystemClass::CreateFileSystem(BYTE * buffer, HANDLE FileHandle)
{
	OEM_Record * pBootRecord = (OEM_Record*)buffer;
	std::string OEM((char*)pBootRecord->OEM_Name, 8);

	if (OEM == "NTFS    ") {
		return new Work_with_NTFS(buffer, FileHandle);
	}
	else if (OEM == "EXFAT   ") {
		return new Work_with_exFAT(buffer, FileHandle);
	}
	else if (OEM == "MSDOS5.0") {
		return new Work_with_FAT32(buffer, FileHandle);
	}
	else {
		std::cout << "Unknown file system!" << std::endl;
		return false;
	}
}

CreateFileSystemClass::~CreateFileSystemClass()
{
}
