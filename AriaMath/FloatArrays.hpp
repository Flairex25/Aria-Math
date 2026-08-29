//==========
#pragma once
//=====================
#include "DarkEdif.hpp"
//=====================
#include <cmath>
#include <tchar.h>
#include <vector>
//================
class FloatArray {
private:
	const TCHAR* ID = _T("[EMPTY]");
	const TCHAR* LoopID = _tcsdup(_T(""));
	std::vector<float> arr;
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
	std::vector<float> GetArray() {
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
	void SetArray(std::vector<float> arr) {
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
};
//==========================================================================================================
namespace FloatArrays {
	void AddToArray(const TCHAR* ID);
	FloatArray* GetFromArray(const TCHAR* ID);
	void RemoveFromArray(const TCHAR* ID);
	void Delete();
	std::vector<FloatArray> Get();
	void Set(std::vector<FloatArray> newList);
};
//==========================================================================================================
