//===================
#include "Common.hpp"
#include "AriaMath\Functions.hpp"
//===================================
#include <cmath>
#include <tchar.h>
#include <vector>
//============================
AriaFunction emptyFunction;
//=========================================
std::vector<AriaFunction> functionArray;
//==================================================
void Functions::AddToArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID already exists in array
	for (int i = 0; i < functionArray.size(); i++) {
		AriaFunction* currentFunction = &functionArray[i];
		const TCHAR* currentID = currentFunction->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return;
		}
	}

	//Add new object to array
	functionArray.emplace_back();
	AriaFunction* newArray = &functionArray.back();
	newArray->SetID(ID);
	return;
}
//==========================================================================================================
AriaFunction* Functions::GetFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		emptyFunction.DeleteAllParams();
		return &emptyFunction;
	}

	//Check if ID exists in array
	for (int i = 0; i < functionArray.size(); i++) {
		AriaFunction* currentFunction = &functionArray[i];
		const TCHAR* currentID = currentFunction->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return currentFunction;
		}
	}

	emptyFunction.DeleteAllParams();
	return &emptyFunction;
}
//==========================================================================================================
void Functions::RemoveFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID exists in array
	for (int i = 0; i < functionArray.size(); i++) {
		AriaFunction* currentFunction = &functionArray[i];
		const TCHAR* currentID = currentFunction->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			functionArray.erase(functionArray.begin() + i);
		}
	}
}
//==========================================================================================================
void Functions::Delete() {
	std::vector<AriaFunction>().swap(functionArray);
}
//==========================================================================================================
std::vector<AriaFunction> Functions::Get() {
	return functionArray;
}
//==========================================================================================================
void Functions::Set(std::vector<AriaFunction> newList) {
	newList.swap(functionArray);
}
//==========================================================================================================
