//==========
#pragma once
//=====================
#include "DarkEdif.hpp"
//=====================
#include <cmath>
#include <tchar.h>
#include <vector>
//================
class StringArray {
private:
	const TCHAR* ID = _T("[EMPTY]");
	const TCHAR* LoopID = _tcsdup(_T(""));
	std::vector<const TCHAR*> arr;
	int loopIndex = 0;
	int loopAmount = 0;
	bool isPaused = false;
	bool isReverse = false;
public:
	//Getters
	const TCHAR* GetID() {
		return this->ID;
	}
	const TCHAR* GetLoopID() {
		return this->LoopID;
	}
	std::vector<const TCHAR*> GetArray() {
		return this->arr;
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
	bool IsReverse() {
		return this->isReverse;
	}
	//Setters
	void SetID(const TCHAR* ID) {
		this->ID = ID;
	}
	void SetLoopID(const TCHAR* LoopID) {
		free((void*)this->LoopID);
		this->LoopID = LoopID;
	}
	void SetArray(std::vector<const TCHAR*> arr) {
		this->arr = arr;
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
	void SetIsReverse(bool isReverse) {
		this->isReverse = isReverse;
	}
	//Destructor
	~StringArray() {
		for (const TCHAR* str : this->GetArray()) {
			free((void*)str);
		}
	}
};
//==========================================================================================================
namespace StringArrays {
	void AddToArray(const TCHAR* ID);
	StringArray* GetFromArray(const TCHAR* ID);
	void RemoveFromArray(const TCHAR* ID);
	void Delete();
	std::vector<StringArray> Get();
	void Set(std::vector<StringArray> newList);
};
//==========================================================================================================
