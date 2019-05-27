#pragma once
#include "FileSystemClass.h"

class IteratorClass 
{
protected:
	ULONGLONG clusterOffset;
	FileSystemClass * fs_i;

public:
	IteratorClass(FileSystemClass * fs_i);
	IteratorClass();
	void First();
	void Next();
	bool IsDone();
	BYTE * GetCurrent();
	~IteratorClass();
	   	 
};