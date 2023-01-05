#pragma once
#include "Definitions.h"
class CLinkedListEItem;
class CGame
{
private:
	CLinkedListEItem* mNorthItems;
	CLinkedListEItem* mSouthItems;
	ERiverBank mFarmerLocation;
public:
	CGame();
	void displayBanks();
	void displayInstructions();
	~CGame();
	bool isWon();
	bool isLost(CLinkedListEItem& withoutFarmer);
	bool isPlaying();
	void transportItem(CLinkedListEItem& fromBank, CLinkedListEItem& toBank);
	void Reset();
	void Play();
	
};

