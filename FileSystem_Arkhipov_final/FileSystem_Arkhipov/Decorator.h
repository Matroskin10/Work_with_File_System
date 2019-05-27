#pragma once
#include "Iterator.h"

class DecoratorClass : public IteratorClass
{
protected:
	IteratorClass * iterator;
	DWORD StepForDecorator;
public:
	DecoratorClass(IteratorClass * iterator, DWORD step);
	void First();
	void Next();
	bool IsDone();
	BYTE * GetCurrent();
	~DecoratorClass();
};