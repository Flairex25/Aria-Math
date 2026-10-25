//===================
#include "Common.hpp"
#include "AriaMath\Constants.hpp"
//===================================
#include <cmath>
#include <tchar.h>
#include <vector>
//=====================================================================
//Int Constants
//=====================================================================
IntConst emptyIntConst;
std::vector<IntConst> intConstArray;
//============================
void Constants::ConstInt::AddToArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID already exists in array
	for (int i = 0; i < intConstArray.size(); i++) {
		IntConst* currentConstant = &intConstArray[i];
		const TCHAR* currentID = currentConstant->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return;
		}
	}

	//Add new object to array
	intConstArray.emplace_back();
	IntConst* newConstant = &intConstArray.back();
	newConstant->SetID(ID);
	return;
}
//============================
IntConst* Constants::ConstInt::GetFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		emptyIntConst.SetValue(0);
		return &emptyIntConst;
	}

	//Check if ID exists in array
	for (int i = 0; i < intConstArray.size(); i++) {
		IntConst* currentConstant = &intConstArray[i];
		const TCHAR* currentID = currentConstant->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return currentConstant;
		}
	}

	emptyIntConst.SetValue(0);
	return &emptyIntConst;
}
//============================
void Constants::ConstInt::RemoveFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID exists in array
	for (int i = 0; i < intConstArray.size(); i++) {
		IntConst* currentConstant = &intConstArray[i];
		const TCHAR* currentID = currentConstant->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			intConstArray.erase(intConstArray.begin() + i);
		}
	}
}
//=====================================================================
//Float Constants
//=====================================================================
FloatConst emptyFloatConst;
std::vector<FloatConst> floatConstArray;
//============================
void Constants::ConstFloat::AddToArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID already exists in array
	for (int i = 0; i < floatConstArray.size(); i++) {
		FloatConst* currentConstant = &floatConstArray[i];
		const TCHAR* currentID = currentConstant->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return;
		}
	}

	//Add new object to array
	floatConstArray.emplace_back();
	FloatConst* newConstant = &floatConstArray.back();
	newConstant->SetID(ID);
	return;
}
//============================
FloatConst* Constants::ConstFloat::GetFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		emptyFloatConst.SetValue(0);
		return &emptyFloatConst;
	}

	//Check if ID exists in array
	for (int i = 0; i < floatConstArray.size(); i++) {
		FloatConst* currentConstant = &floatConstArray[i];
		const TCHAR* currentID = currentConstant->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return currentConstant;
		}
	}

	emptyFloatConst.SetValue(0);
	return &emptyFloatConst;
}
//============================
void Constants::ConstFloat::RemoveFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID exists in array
	for (int i = 0; i < floatConstArray.size(); i++) {
		FloatConst* currentConstant = &floatConstArray[i];
		const TCHAR* currentID = currentConstant->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			floatConstArray.erase(floatConstArray.begin() + i);
		}
	}
}
//=====================================================================
//String Constants
//=====================================================================
StrConst emptyStrConst;
std::vector<StrConst> strConstArray;
//============================
void Constants::ConstString::AddToArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID already exists in array
	for (int i = 0; i < strConstArray.size(); i++) {
		StrConst* currentConstant = &strConstArray[i];
		const TCHAR* currentID = currentConstant->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return;
		}
	}

	//Add new object to array
	strConstArray.emplace_back();
	StrConst* newConstant = &strConstArray.back();
	newConstant->SetID(ID);
	return;
}
//============================
StrConst* Constants::ConstString::GetFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		emptyStrConst.SetValue(_T(""));
		return &emptyStrConst;
	}

	//Check if ID exists in array
	for (int i = 0; i < strConstArray.size(); i++) {
		StrConst* currentConstant = &strConstArray[i];
		const TCHAR* currentID = currentConstant->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			return currentConstant;
		}
	}

	emptyStrConst.SetValue(_T(""));
	return &emptyStrConst;
}
//============================
void Constants::ConstString::RemoveFromArray(const TCHAR* ID) {
	//Check if ID is an empty ID
	if (_tcscmp(ID, _T("")) == 0) {
		return;
	}

	//Check if ID exists in array
	for (int i = 0; i < strConstArray.size(); i++) {
		StrConst* currentConstant = &strConstArray[i];
		const TCHAR* currentID = currentConstant->GetID();
		if (_tcscmp(currentID, ID) == 0) {
			strConstArray.erase(strConstArray.begin() + i);
		}
	}
}
//=====================================================================
