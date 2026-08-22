//==========
#pragma once
//=====================
#include "DarkEdif.hpp"
//=====================
#include <cmath>
#include <tchar.h>
#include <vector>
//================
class IntParameter {
private:
	const TCHAR* ID = _T("[EMPTY]");
	int value = 0;
public:
	//Getters
	const TCHAR* GetID() { return this->ID; }
	int GetValue() { return this->value; }
	//Setters
	void SetID(const TCHAR* ID) { this->ID = ID; }
	void SetValue(int value) { this->value = value; }
};
class FloatParameter {
private:
	const TCHAR* ID = _T("[EMPTY]");
	float value = 0.0f;
public:
	//Getters
	const TCHAR* GetID() { return this->ID; }
	float GetValue() { return this->value; }
	//Setters
	void SetID(const TCHAR* ID) { this->ID = ID; }
	void SetValue(int value) { this->value = value; }
};
class StringParameter {
private:
	const TCHAR* ID = _T("[EMPTY]");
	const TCHAR* value = _T("");
public:
	//Getters
	const TCHAR* GetID() { return this->ID; }
	const TCHAR* GetValue() { return this->value; }
	//Setters
	void SetID(const TCHAR* ID) { this->ID = ID; }
	void SetValue(const TCHAR* value) { this->value = value; }
};
//================
//================
class AriaFunction {
private:
	const TCHAR* ID = _T("[EMPTY]");
	std::vector<IntParameter> intParams;
	std::vector<FloatParameter> floatParams;
	std::vector<StringParameter> stringParams;
	int loopIndex = 0;
	int loopAmount = 0;
	bool isPaused = false;
	int intReturn = 0;
	float floatReturn = 0.0f;
	const TCHAR* stringReturn = _T("");
public:
	//Getters
	const TCHAR* GetID() {
		return this->ID;
	}
	int GetLoopIndex() {
		return this->loopIndex;
	}
	int GetLoopAmount() {
		return this->loopAmount;
	}
	bool IsPaused() {
		return this->isPaused;
	}
	int GetIntReturn() {
		return this->intReturn;
	}
	float GetFloatReturn() {
		return this->floatReturn;
	}
	const TCHAR* GetStringReturn() {
		return this->stringReturn;
	}
	//Setters
	void SetID(const TCHAR* ID) {
		this->ID = ID;
	}
	void SetLoopIndex(int loopIndex) {
		this->loopIndex = loopIndex;
	}
	void SetLoopAmount(int loopAmount) {
		this->loopAmount = loopAmount;
	}
	void SetIsPaused(bool isPaused) {
		this->isPaused = isPaused;
	}
	void SetIntReturn(int intReturn) {
		this->intReturn = intReturn;
	}
	void SetFloatReturn(float floatReturn) {
		this->floatReturn = floatReturn;
	}
	void SetStringReturn(const TCHAR* stringReturn) {
		this->stringReturn = stringReturn;
	}
	//Get Params
	IntParameter* GetIntParam(const TCHAR* ID) {
		IntParameter emptyIntParam;
		if (_tcscmp(ID, _T("")) == 0) { return &emptyIntParam; }
		for (int i = 0; i < this->intParams.size(); i++) {
			IntParameter* currentParam = &this->intParams[i];
			if (_tcscmp(ID, currentParam->GetID()) == 0) { return currentParam; }
		}
		return &emptyIntParam;
	}
	FloatParameter* GetFloatParam(const TCHAR* ID) {
		FloatParameter emptyFloatParam;
		if (_tcscmp(ID, _T("")) == 0) { return &emptyFloatParam; }
		for (int i = 0; i < this->floatParams.size(); i++) {
			FloatParameter* currentParam = &this->floatParams[i];
			if (_tcscmp(ID, currentParam->GetID()) == 0) { return currentParam; }
		}
		return &emptyFloatParam;
	}
	StringParameter* GetStringParam(const TCHAR* ID) {
		StringParameter emptyStringParam;
		if (_tcscmp(ID, _T("")) == 0) { return &emptyStringParam; }
		for (int i = 0; i < this->stringParams.size(); i++) {
			StringParameter* currentParam = &this->stringParams[i];
			if (_tcscmp(ID, currentParam->GetID()) == 0) { return currentParam; }
		}
		return &emptyStringParam;
	}
	//Set Params
	void SetIntParam(const TCHAR* ID, int value) {
		if (_tcscmp(ID, _T("")) == 0) { return; }
		for (int i = 0; i < this->intParams.size(); i++) {
			IntParameter* currentParam = &this->intParams[i];
			if (_tcscmp(ID, currentParam->GetID()) == 0) {
				currentParam->SetValue(value);
				return;
			}
		}
		this->intParams.emplace_back();
		IntParameter* newParam = &this->intParams.back();
		newParam->SetID(ID);
		newParam->SetValue(value);
	}
	void SetFloatParam(const TCHAR* ID, float value) {
		if (_tcscmp(ID, _T("")) == 0) { return; }
		for (int i = 0; i < this->floatParams.size(); i++) {
			FloatParameter* currentParam = &this->floatParams[i];
			if (_tcscmp(ID, currentParam->GetID()) == 0) {
				currentParam->SetValue(value);
				return;
			}
		}
		this->floatParams.emplace_back();
		FloatParameter* newParam = &this->floatParams.back();
		newParam->SetID(ID);
		newParam->SetValue(value);
	}
	void SetStringParam(const TCHAR* ID, const TCHAR* value) {
		if (_tcscmp(ID, _T("")) == 0) { return; }
		for (int i = 0; i < this->stringParams.size(); i++) {
			StringParameter* currentParam = &this->stringParams[i];
			if (_tcscmp(ID, currentParam->GetID()) == 0) {
				currentParam->SetValue(_tcsdup(value));
				return;
			}
		}
		this->stringParams.emplace_back();
		StringParameter* newParam = &this->stringParams.back();
		newParam->SetID(ID);
		newParam->SetValue(_tcsdup(value));
	}
	//Delete Params
	void DeleteIntParam(const TCHAR* ID) {
		if (_tcscmp(ID, _T("")) == 0) { return; }
		for (int i = 0; i < this->intParams.size(); i++) {
			IntParameter* currentParam = &this->intParams[i];
			if (_tcscmp(ID, currentParam->GetID()) == 0) {
				this->intParams.erase(this->intParams.begin()+i);
				return;
			}
		}
	}
	void DeleteFloatParam(const TCHAR* ID) {
		if (_tcscmp(ID, _T("")) == 0) { return; }
		for (int i = 0; i < this->floatParams.size(); i++) {
			FloatParameter* currentParam = &this->floatParams[i];
			if (_tcscmp(ID, currentParam->GetID()) == 0) {
				this->floatParams.erase(this->floatParams.begin() + i);
				return;
			}
		}
	}
	void DeleteStringParam(const TCHAR* ID) {
		if (_tcscmp(ID, _T("")) == 0) { return; }
		for (int i = 0; i < this->stringParams.size(); i++) {
			StringParameter* currentParam = &this->stringParams[i];
			if (_tcscmp(ID, currentParam->GetID()) == 0) {
				free((void*)currentParam->GetValue());
				this->stringParams.erase(this->stringParams.begin() + i);
				return;
			}
		}
	}
	void DeleteAllParams() {

		for (StringParameter currentParam : this->stringParams) {
			free((void*)currentParam.GetValue());
		}

		std::vector<IntParameter>().swap(this->intParams);
		std::vector<FloatParameter>().swap(this->floatParams);
		std::vector<StringParameter>().swap(this->stringParams);
	}
};
//==========================================================================================================
namespace Functions {
	void AddToArray(const TCHAR* ID);
	AriaFunction* GetFromArray(const TCHAR* ID);
	void RemoveFromArray(const TCHAR* ID);
	void Delete();
	std::vector<AriaFunction> Get();
	void Set(std::vector<AriaFunction> newList);
}
//==========================================================================================================
