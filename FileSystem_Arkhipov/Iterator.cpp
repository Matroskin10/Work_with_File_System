#include "pch.h"
#include "Iterator.h"

IteratorClass::IteratorClass(FileSystemClass *fs_i)
{
	clusterOffset = 0;
	this->fs_i = fs_i;
}
	
void IteratorClass::First()
{
	clusterOffset = 0;
}


void IteratorClass::Next()
{
	clusterOffset++;
}


bool IteratorClass::IsDone()
{
	if (fs_i->GetTotalClusters() >= clusterOffset) {
		return true;
	}
	else {
		return false;
	}
}

BYTE * IteratorClass::GetCurrent()
{
	BYTE * tempBuffer = new BYTE[fs_i->GetBytesPerCluster()];
	if (fs_i->ReadClusters(clusterOffset, 1, tempBuffer)) {
		return tempBuffer;
	}
	else {
		return 0;
	}
}

IteratorClass::~IteratorClass()
{

}