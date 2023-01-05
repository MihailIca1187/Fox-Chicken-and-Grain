#include "CGame.h"
#include "CLinkedListEItem.h"
#include<iostream>
using namespace std;

string ToLower(string data)
{
	string lowerString;
	for (auto c : data) lowerString += tolower(c);
	return lowerString;
}

CGame::CGame()
{
	//The game starts with all items on southBank including the farmer
	mFarmerLocation = south;

	mSouthItems = new CLinkedListEItem;
	mNorthItems = new CLinkedListEItem;

	mSouthItems->pushFront(fox);
	mSouthItems->pushFront(chicken);
	mSouthItems->pushFront(grain);
}

void CGame::displayBanks()
{
	mSouthItems->printList();
	mNorthItems->printList();

	int fLocation = mFarmerLocation;

	switch(fLocation)
	{
	case south :
	{
		cout << "\nFarmer is on the South bank \n";
		break;
	};
	case north:
	{
		cout << "\nFarmer is on the North bank \n";
		break;
	};
		
	}
	
}

void CGame::displayInstructions()
{
	cout << "\n\nA particularly stupid farmer must get his fox, chicken and grain safely across a river\n" <<
		"from the southriver bank to the north bank.The farmer makes trips across the river in a little boat, but can only\n" <<
		"take at most one item with him on each trip.If he leaves the fox and the chicken alone together,\n"<<
		"the fox will eat the chicken!If he leaves the chicken alone with the grain, the chicken will eat the\n" <<
		"grain.The player must help the farmer by deciding what he should take with him(or nothing) on\n" <<
		"each trip.Once all three items are on the north bank, the game is won.If anything gets eaten, the\n" <<
		"game is lost.\n\n";
}

CGame::~CGame()
{
	delete mSouthItems;
	delete mNorthItems;
}


bool CGame::isWon()
{
	

	if (mNorthItems->isInList(fox) && mNorthItems->isInList(chicken)
		&& mNorthItems->isInList(grain))
	{
		cout << "\n Congratulations, you have won the game! ";
		return true;
	}
}

bool CGame::isLost(CLinkedListEItem& withoutFarmer)
{
	bool flag = false;

	if (withoutFarmer.isInList(fox) && withoutFarmer.isInList(chicken))
	{
		flag = true;
		cout << "\nFox ate chicken!\nGame is lost!";
	}
	else if (withoutFarmer.isInList(chicken) && withoutFarmer.isInList(grain))
	{
		flag = true;
		cout << "\nChicken ate grain!\nGame is lost!";
	}

	
	return flag;
}


bool CGame::isPlaying()
{
	
	bool lost;
	if (mFarmerLocation == south)
	{
		lost = isLost(*mNorthItems);
	}
	else
	{
		lost = isLost(*mSouthItems);
	}
	bool won = isWon();
	return(!lost && !won);
	

}

void CGame::transportItem(CLinkedListEItem& fromBank, CLinkedListEItem& toBank)
{
	string input = "";
	cout << "\nWhat item do you wish to transport?\n";
	cin >> input;
	input = ToLower(input);

	string again = "no";
	again = ToLower(again);
	
	do
	{
		again = "no";

		if (input == "fox")
		{
			if (fromBank.isInList(fox))
			{
				fromBank.removeElement(fox);
				toBank.pushFront(fox);
				cout << "\nFox has been moved over.\n";
			}
			else
			{
				cout << "\nFox is not on this bank! Would you like to move a different item?\n";
				cin >> again;
				
			}

		}
		else if (input == "chicken")
		{
			if (fromBank.isInList(chicken))
			{
				fromBank.removeElement(chicken);
				toBank.pushFront(chicken);
				cout << "\nChicken has been moved over.\n";
			}
			else
			{
				cout << "\nChicken is not on this bank! Would you like to move a different item?\n";
				cin >> again;
				
			}
			
		}
		else if (input == "grain")
		{
			if (fromBank.isInList(grain))
			{
				fromBank.removeElement(grain);
				toBank.pushFront(grain);
				cout << "\nGrain has been moved over.\n";
			}
			else
			{
				cout << "\nGrain is not on this bank! Would you like to move a different item?\n";
				cin >> again;
				
			}
		}

		again = ToLower(again);

		if(again != "yes" && input != "fox" && input != "chicken" && input != "grain")
		{
			cout << "\nNothing has been transported over except for the farmer.";
		}

		
	} while (again == "yes");
	
	
	if (mFarmerLocation == south)
	{
		mFarmerLocation = north;
	}
	else if (mFarmerLocation == north)
	{
		mFarmerLocation = south;
	}
	

}

void CGame::Play()
{
	Reset();
	displayBanks();
	displayInstructions();

	while (isPlaying())
	{
		if (mFarmerLocation == south)
		{
			transportItem(*mSouthItems, *mNorthItems);
		}

		else if (mFarmerLocation == north)
		{
			transportItem(*mNorthItems, *mSouthItems);
		}
	}
}

void CGame::Reset()
{
	while (mSouthItems->count() != 0)
	{
		mSouthItems->popFront();
	}
	while (mNorthItems->count() != 0)
	{
		mNorthItems->popFront();
	}

	mFarmerLocation = south;

	mSouthItems->pushFront(fox);
	mSouthItems->pushFront(chicken);
	mSouthItems->pushFront(grain);
}






