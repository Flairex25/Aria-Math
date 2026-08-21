//===================
#include "Common.hpp"
#include "AriaMath\BagRandomizer.hpp"
//===================================
#include <cmath>
#include <tchar.h>
#include <vector>
//============================
BagRandomizer emptyRandomizer;
//=========================================
std::vector<BagRandomizer> randomizerArray;
//==================================================
void BagRandomization::AddToArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID already exists in array
	for (int i = 0; i < randomizerArray.size(); i++) {
		BagRandomizer* currentRandomizer = &randomizerArray[i];
		const TCHAR* currentID = currentRandomizer->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return;
		}
	}

	//Add new object to array
	randomizerArray.emplace_back();
	BagRandomizer* newRandomizer = &randomizerArray.back();
	newRandomizer->SetID(ID);
	return;
}
//==========================================================================================================
BagRandomizer* BagRandomization::GetFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return &emptyRandomizer;
	}

	//Check if ID exists in array
	for (int i = 0; i < randomizerArray.size(); i++) {
		BagRandomizer* currentRandomizer = &randomizerArray[i];
		const TCHAR* currentID = currentRandomizer->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return currentRandomizer;
		}
	}

	return &emptyRandomizer;
}
//==========================================================================================================
void BagRandomization::RemoveFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID exists in array
	for (int i = 0; i < randomizerArray.size(); i++) {
		BagRandomizer* currentRandomizer = &randomizerArray[i];
		const TCHAR* currentID = currentRandomizer->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			randomizerArray.erase(randomizerArray.begin() + i);
		}
	}
}
//==========================================================================================================
void BagRandomization::Delete() {
	std::vector<BagRandomizer>().swap(randomizerArray);
}
//==========================================================================================================
