#include "CreateFileSystem.h"
#include <iostream>
#include <windows.h>
#include "FileSystem_Arkhipov.h"
#include "Iterator.h"
#include "Decorator.h"

using namespace std;

int main()
{
	CreateFileSystemClass FS_C;
	ULONGLONG desiredOffset;
	DWORD stepCluster;
	BYTE Buffer[2048];
	FS_C.Handle();
	FS_C.GetFirstSector(Buffer);
	HANDLE handle = FS_C.GetHandle();
	FileSystemClass * pFS = FS_C.CreateFileSystem(Buffer, handle);
	//Для FAT32
	string str_FAT = string((char*)pFS->GetOEM_Name());
	if (str_FAT == "MSDOS5.0") {
		std::cout << "OEM name: FAT32" << std::endl;
		std::cout << "Bytes per sector: " << pFS->GetBytesPerSector() << std::endl;
		std::cout << "Total sectors: " << pFS->GetTotalSectors() << std::endl;
		std::cout << "Sectors per cluster: " << pFS->GetSectorsPerCluster() << std::endl;
		std::cout << "Bytes per cluster: " << pFS->GetBytesPerCluster() << std::endl;
		std::cout << "Total clusters: " << pFS->GetTotalClusters() << std::endl;
		std::cout << "Enter step of cluster: ";
		std::cin >> stepCluster;
		IteratorClass Iterator = IteratorClass(pFS);
		DecoratorClass Decorator = DecoratorClass(&Iterator, stepCluster);
		Decorator.First();
		Decorator.Next();
		Decorator.GetCurrent();
	}
	//Для остальных ФС
	else {
		std::cout << "OEM name: " << pFS->GetOEM_Name() << std::endl;
		std::cout << "Bytes per sector: " << pFS->GetBytesPerSector() << std::endl;
		std::cout << "Total sectors: " << pFS->GetTotalSectors() << std::endl;
		std::cout << "Sectors per cluster: " << pFS->GetSectorsPerCluster() << std::endl;
		std::cout << "Bytes per cluster: " << pFS->GetBytesPerCluster() << std::endl;
		std::cout << "Total clusters: " << pFS->GetTotalClusters() << std::endl;
		std::cout << "Enter step of cluster: ";
		std::cin >> stepCluster;
		IteratorClass Iterator = IteratorClass(pFS);
		DecoratorClass Decorator = DecoratorClass(&Iterator, stepCluster);
		Decorator.First();
		Decorator.Next();
		Decorator.GetCurrent();
	}
	system("pause");
	return 0;
}

