#include "CLinkedListEItem.h"
#include "CElementEItem.h"
#include<iostream>
using namespace std;


// Constructor. Set the head pointer to 0
CLinkedListEItem::CLinkedListEItem()
{
	mpHead = nullptr;
}

// Destructor. Clean up the linked list.
CLinkedListEItem::~CLinkedListEItem()
{
	CElement* prior; // stores previous
	while (mpHead != nullptr)	  // 0 at the end of the list.
	{
		prior = mpHead;            // store previous
		mpHead = mpHead->getNext(); // advance head
		delete prior;              // destroy previous
	}
}

// Push the given data on to the front of the linked list.
// 'head' is updated.
void CLinkedListEItem::pushFront(EItem data)
{
	// allocate memory for new element
	CElement* pTemp = new CElement(data);
	pTemp->setNext(mpHead); // temp in front of
	// the old head of the list
	mpHead = pTemp; // head updated
}

// Pop the front of the linked list.
// Deletes the first element (if one exists). 
// 'head' is updated to point at the new front.
void CLinkedListEItem::popFront()
{
	CElement* pOldHead = mpHead; // store old head
	if (mpHead != nullptr)    // if list has at least one elem
	{
		mpHead = mpHead->getNext();
		delete pOldHead;
	}
}


// Returns the first element on the linked list.
// If empty then exit with an error message.
EItem CLinkedListEItem::getFront()
{
	if (mpHead != nullptr) // check list has at least one link
	{
		return mpHead->getData();
	}
	// only reached if the linked list is empty
	cout << "ERROR: list is empty" << endl;
	system("pause");
	exit(0);
}


// Display each of the items on the linked list
void CLinkedListEItem::printList()
{
	CElement* pCurr = mpHead; // can't use 'head' else 
	// we'd lose track of the
	// list start

	cout << "\n";

	while (pCurr != nullptr)  // 0 at end of the list.
	{
		EItem eval = pCurr->getData();

		switch (eval)
		{
			case fox:
			{
				cout << "fox ";
				break;
			};

			case chicken:
			{
				cout << "chicken ";
				break;
			};

			case grain:
			{
				cout << "grain ";
				break;
			};
		}
		
		pCurr = pCurr->getNext();
	}
	cout << "\n";
}

bool CLinkedListEItem::isInList(EItem target)
{
	CElement* pCurr = mpHead;

	while (pCurr != nullptr)  // 0 at end of the list.
	{
		if (pCurr->getData() == target)
		{
			return true;
		}

		pCurr = pCurr->getNext();
	}

	return false;
}

int CLinkedListEItem::count()
{
	CElement* pCurr = mpHead;

	int counter = 0;

	while (pCurr != nullptr)
	{
		counter++;
		pCurr = pCurr->getNext();
	}

	return counter;
}

bool CLinkedListEItem::removeElement(EItem target)
{
	if (mpHead == nullptr) //List is empty
	{
		return false;
	}

	else if ((mpHead->getNext() == nullptr) && (mpHead->getData() == target)) //List has one element
	{
		delete mpHead;
		mpHead = nullptr;
		return true;
	}
	else //List has multiple elements
	{
		if (mpHead->getData() == target)
		{
			CElement* pTmp = mpHead->getNext();
			delete mpHead;
			mpHead = pTmp;
			pTmp = nullptr;
			return true;
		}

		CElement* pPrior = nullptr; // stores previous
		CElement* pCurr = mpHead; // stores current

		while (pCurr != nullptr)	  // 0 at the end of the list.
		{
			pPrior = pCurr;            // store previous
			pCurr = pCurr->getNext(); // advance pCurr

			if (pCurr->getData() == target) //once target is found, we set the prior element's pointer to the one after the one that will be removed
			{
				pPrior->setNext(pCurr->getNext());
				delete pCurr; //target element gets removed with all the bells and whistles
				pPrior = nullptr;
				pCurr = nullptr;
				return true;
			}
		}

		return false;
	}



}

void CLinkedListEItem::copyList(CLinkedListEItem* newList)
{
	if (mpHead == nullptr) //List is empty
	{
		cout << "List to be copied is empty.\n\n";
	}
	else //List is not empty
	{

		newList->pushFront(mpHead->getData());

		CElement* pTmp = mpHead;

		while (pTmp->getNext() != nullptr)
		{
			newList->pushFront(pTmp->getData());
			pTmp = pTmp->getNext();

		}

		pTmp = nullptr;

	}
}





