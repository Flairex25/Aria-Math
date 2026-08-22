//===================
#include "Common.hpp"
#include "AriaMath\FloatArrays.hpp"
//===================================
#include <cmath>
#include <tchar.h>
#include <vector>
//============================
FloatArray emptyArr;
//=========================================
std::vector<FloatArray> arrArray;
//==================================================
void FloatArrays::AddToArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID already exists in array
	for (int i = 0; i < arrArray.size(); i++) {
		FloatArray* currentArray = &arrArray[i];
		const TCHAR* currentID = currentArray->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return;
		}
	}

	//Add new object to array
	arrArray.emplace_back();
	FloatArray* newArray = &arrArray.back();
	newArray->SetID(ID);
	return;
}
//==========================================================================================================
FloatArray* FloatArrays::GetFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		emptyArr.SetArray(std::vector<float>());
		return &emptyArr;
	}

	//Check if ID exists in array
	for (int i = 0; i < arrArray.size(); i++) {
		FloatArray* currentArray = &arrArray[i];
		const TCHAR* currentID = currentArray->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return currentArray;
		}
	}

	emptyArr.SetArray(std::vector<float>());
	return &emptyArr;
}
//==========================================================================================================
void FloatArrays::RemoveFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID exists in array
	for (int i = 0; i < arrArray.size(); i++) {
		FloatArray* currentArray = &arrArray[i];
		const TCHAR* currentID = currentArray->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			arrArray.erase(arrArray.begin() + i);
		}
	}
}
//==========================================================================================================
void FloatArrays::Delete() {
	std::vector<FloatArray>().swap(arrArray);
}
//==========================================================================================================
std::vector<FloatArray> FloatArrays::Get() {
	return arrArray;
}
//==========================================================================================================
void FloatArrays::Set(std::vector<FloatArray> newList) {
	newList.swap(arrArray);
}
//==========================================================================================================
