//===================
#include "Common.hpp"
#include "AriaMath\Vector2.hpp"
//===================================
#include <cmath>
#include <tchar.h>
#include <vector>
//============================
Vector2 emptyVector2;
//=========================================
std::vector<Vector2> vector2Array;
//==================================================
void TwoDVectors::AddToArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID already exists in array
	for (int i = 0; i < vector2Array.size(); i++) {
		Vector2* currentVector2 = &vector2Array[i];
		const TCHAR* currentID = currentVector2->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return;
		}
	}

	//Add new object to array
	vector2Array.emplace_back();
	Vector2* newVector2 = &vector2Array.back();
	newVector2->SetID(ID);
	return;
}
//==========================================================================================================
Vector2* TwoDVectors::GetFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return &emptyVector2;
	}

	//Check if ID exists in array
	for (int i = 0; i < vector2Array.size(); i++) {
		Vector2* currentVector2 = &vector2Array[i];
		const TCHAR* currentID = currentVector2->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return currentVector2;
		}
	}

	return &emptyVector2;
}
//==========================================================================================================
void TwoDVectors::RemoveFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID exists in array
	for (int i = 0; i < vector2Array.size(); i++) {
		Vector2* currentVector2 = &vector2Array[i];
		const TCHAR* currentID = currentVector2->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			vector2Array.erase(vector2Array.begin() + i);
		}
	}
}
//==========================================================================================================
void TwoDVectors::Delete() {
	std::vector<Vector2>().swap(vector2Array);
}
//==========================================================================================================
std::vector<Vector2> TwoDVectors::Get() {
	return vector2Array;
}
//==========================================================================================================
void TwoDVectors::Set(std::vector<Vector2> newList) {
	newList.swap(vector2Array);
}
//==========================================================================================================
