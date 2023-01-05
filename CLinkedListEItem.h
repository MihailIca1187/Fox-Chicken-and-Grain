#pragma once
#include "Definitions.h"
class CElement;

class CLinkedListEItem
{
private:
	CElement* mpHead;
public:
	CLinkedListEItem();
	~CLinkedListEItem();
	void pushFront(EItem data);
	void popFront();
	EItem getFront();
	void printList();
	bool isInList(EItem target);
	int count();
	bool removeElement(EItem target);
	void pushBack(EItem data);
	void copyList(CLinkedListEItem* newList);
	
};

