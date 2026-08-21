//===================
#include "Common.hpp"
#include "AriaMath\StringArrays.hpp"
//===================================
#include <cmath>
#include <tchar.h>
#include <vector>
//============================
StringArray emptyArr;
//=========================================
std::vector<StringArray> arrArray;
//==================================================
void StringArrays::AddToArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID already exists in array
	for (int i = 0; i < arrArray.size(); i++) {
		StringArray* currentArray = &arrArray[i];
		const TCHAR* currentID = currentArray->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return;
		}
	}

	//Add new object to array
	arrArray.emplace_back();
	StringArray* newArray = &arrArray.back();
	newArray->SetID(ID);
	return;
}
//==========================================================================================================
StringArray* StringArrays::GetFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return &emptyArr;
	}

	//Check if ID exists in array
	for (int i = 0; i < arrArray.size(); i++) {
		StringArray* currentArray = &arrArray[i];
		const TCHAR* currentID = currentArray->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return currentArray;
		}
	}

	return &emptyArr;
}
//==========================================================================================================
void StringArrays::RemoveFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID exists in array
	for (int i = 0; i < arrArray.size(); i++) {
		StringArray* currentArray = &arrArray[i];
		const TCHAR* currentID = currentArray->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			arrArray.erase(arrArray.begin() + i);
		}
	}
}
//==========================================================================================================
void StringArrays::Delete() {
	std::vector<StringArray>().swap(arrArray);
}
//==========================================================================================================
