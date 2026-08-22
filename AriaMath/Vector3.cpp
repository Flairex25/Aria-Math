//===================
#include "Common.hpp"
#include "AriaMath\Vector3.hpp"
//===================================
#include <cmath>
#include <tchar.h>
#include <vector>
//============================
Vector3 emptyVector3;
//=========================================
std::vector<Vector3> vector3Array;
//==================================================
void ThreeDVectors::AddToArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID already exists in array
	for (int i = 0; i < vector3Array.size(); i++) {
		Vector3* currentVector3 = &vector3Array[i];
		const TCHAR* currentID = currentVector3->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return;
		}
	}

	//Add new object to array
	vector3Array.emplace_back();
	Vector3* newVector3 = &vector3Array.back();
	newVector3->SetID(ID);
	return;
}
//==========================================================================================================
Vector3* ThreeDVectors::GetFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return &emptyVector3;
	}

	//Check if ID exists in array
	for (int i = 0; i < vector3Array.size(); i++) {
		Vector3* currentVector3 = &vector3Array[i];
		const TCHAR* currentID = currentVector3->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return currentVector3;
		}
	}

	return &emptyVector3;
}
//==========================================================================================================
void ThreeDVectors::RemoveFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID exists in array
	for (int i = 0; i < vector3Array.size(); i++) {
		Vector3* currentVector3 = &vector3Array[i];
		const TCHAR* currentID = currentVector3->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			vector3Array.erase(vector3Array.begin() + i);
		}
	}
}
//==========================================================================================================
void ThreeDVectors::Delete() {
	std::vector<Vector3>().swap(vector3Array);
}
//==========================================================================================================
std::vector<Vector3> ThreeDVectors::Get() {
	return vector3Array;
}
//==========================================================================================================
void ThreeDVectors::Set(std::vector<Vector3> newList) {
	newList.swap(vector3Array);
}
//==========================================================================================================
