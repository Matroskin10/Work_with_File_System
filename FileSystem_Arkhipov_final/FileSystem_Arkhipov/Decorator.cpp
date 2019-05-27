#include "Decorator.h"

DecoratorClass::DecoratorClass(IteratorClass * iterator, DWORD step)
{
	this->iterator = iterator;
	this->StepForDecorator = step;
}

void DecoratorClass::First()
{
	this->iterator->First();
}

void DecoratorClass::Next()
{
	for (DWORD i = 0; i < StepForDecorator; i++)
	{
		this->iterator->Next();
	}
}

bool DecoratorClass::IsDone()
{
	if (this->fs_i->GetTotalClusters()-this->clusterOffset >= StepForDecorator)
	{
		return false;
	}
	return true;
}

BYTE * DecoratorClass::GetCurrent()
{
	return this->iterator->GetCurrent();
}

DecoratorClass::~DecoratorClass()
{
}
