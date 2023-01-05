#pragma once
#include "Definitions.h"

class CElement
{
private:
	CElement* mpNext;
	EItem mData;
public:
	CElement(EItem data);
	EItem getData();
	CElement* getNext();
	void setNext(CElement* pNew);

};