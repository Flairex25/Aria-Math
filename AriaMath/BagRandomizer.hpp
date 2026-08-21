//==========
#pragma once
//=====================
#include "DarkEdif.hpp"
//=====================
#include <cmath>
#include <tchar.h>
#include <vector>
//================
class BagRandomizer
{
private:
	const TCHAR* ID = _T("[EMPTY]");
	std::vector<int> bagArray;
	std::vector<int> bufferArray;
public:
	//Getters
	const TCHAR* GetID() {
		return this->ID;
	}
	int GetFromBag(int index) {
		if ((index < 0) || (index >= this->bagArray.size())) {
			return 0;
		}
		return this->bagArray[index];
	}
	int GetFromBuffer(int index) {
		if ((index < 0) || (index >= this->bufferArray.size())) {
			return 0;
		}
		return this->bufferArray[index];
	}
	//Setters
	void SetID(const TCHAR* ID) {
		this->ID = ID;
	}
	//Bag Methods
	void AddToBag(int value) {
		this->Reset();
		this->bagArray.emplace_back();
		this->bufferArray.emplace_back();
		this->bagArray.back() = value;
		this->bufferArray.back() = value;
	}
	void RemoveFromBag(int index) {
		if ((index < 0) || (index >= this->bagArray.size())) {
			return;
		}
		this->Reset();
		this->bagArray.erase(this->bagArray.begin() + index);
		this->bufferArray.erase(this->bufferArray.begin() + index);
	}
	int GetRandomValue() {
		if (this->bagArray.size() == 0) {
			return 0;
		}

		if (this->bufferArray.size() == 0) {
			this->Reset();
		}

		int randomIndex = Math::RRandomI(0, this->bufferArray.size() - 1);
		int randomValue = this->bufferArray[randomIndex];

		this->bufferArray.erase(this->bufferArray.begin() + randomIndex);

		return randomValue;
	}
	//Reset Randomizer
	void Reset() {
		for (int i = 0; i < this->bagArray.size(); i++) {
			if (i >= this->bufferArray.size()) {
				bufferArray.emplace_back();
			}
			this->bufferArray[i] = this->bagArray[i];
		}
		return;
	}
};
//==========================================================================================================
namespace BagRandomization {
	void AddToArray(const TCHAR* ID);
	BagRandomizer* GetFromArray(const TCHAR* ID);
	void RemoveFromArray(const TCHAR* ID);
	void Delete();
}
//==========================================================================================================
