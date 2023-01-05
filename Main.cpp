#include "CGame.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include<iostream>
using namespace std;

string ToLowerMain(string data)
{
	string lowerString;
	for (auto c : data) lowerString += tolower(c);
	return lowerString;
}


int main()
{
	CGame* test1 = new CGame;

	string input = "";
	cout << "\nWould you like to play this amazing game?\n";
	input = ToLowerMain(input);

	do
	{
		test1->Play();


	} while (input == "yes");

	delete test1;

	if (_CrtDumpMemoryLeaks())
	{
		cout << "Memory leak detected!\n\n";
	}
}