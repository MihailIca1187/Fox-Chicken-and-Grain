#include "CElementEItem.h"

// Constructor. An Element cannot be created
// unless it has data.
CElement::CElement(EItem data)
{
	mData = data;
}

// Get the data item from an element.
EItem CElement::getData()
{
	return mData;
}

// Set the 'next' pointer of an Element
void CElement::setNext(CElement* pNew)
{
	mpNext = pNew;
}

// Get the 'next' pointer of an Element.
CElement* CElement::getNext()
{
	return mpNext;
}