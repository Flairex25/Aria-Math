//===================
#include "Common.hpp"
#include "AriaMath\IntArrays.hpp"
//===================================
#include <cmath>
#include <tchar.h>
#include <vector>
//============================
IntArray emptyArr;
//=========================================
std::vector<IntArray> arrArray;
//==================================================
void IntegerArrays::AddToArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID already exists in array
	for (int i = 0; i < arrArray.size(); i++) {
		IntArray* currentArray = &arrArray[i];
		const TCHAR* currentID = currentArray->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return;
		}
	}

	//Add new object to array
	arrArray.emplace_back();
	IntArray* newArray = &arrArray.back();
	newArray->SetID(ID);
	return;
}
//==========================================================================================================
IntArray* IntegerArrays::GetFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return &emptyArr;
	}

	//Check if ID exists in array
	for (int i = 0; i < arrArray.size(); i++) {
		IntArray* currentArray = &arrArray[i];
		const TCHAR* currentID = currentArray->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return currentArray;
		}
	}

	return &emptyArr;
}
//==========================================================================================================
void IntegerArrays::RemoveFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID exists in array
	for (int i = 0; i < arrArray.size(); i++) {
		IntArray* currentArray = &arrArray[i];
		const TCHAR* currentID = currentArray->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			arrArray.erase(arrArray.begin() + i);
		}
	}
}
//==========================================================================================================
void IntegerArrays::Delete() {
	std::vector<IntArray>().swap(arrArray);
}
//==========================================================================================================
