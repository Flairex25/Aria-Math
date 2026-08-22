//==========
#pragma once
//=====================
#include "DarkEdif.hpp"
//=====================
#include <cmath>
#include <tchar.h>
#include <vector>
//================
class Vector3 {
private:
	const TCHAR* ID = _T("[EMPTY]");
	float x = 0;
	float y = 0;
	float z = 0;
public:
	//Getters
	const TCHAR* GetID() {
		return this->ID;
	}
	float GetX() {
		return this->x;
	}
	float GetY() {
		return this->y;
	}
	float GetZ() {
		return this->z;
	}
	//Setters
	void SetID(const TCHAR* ID) {
		this->ID = ID;
	}
	void SetX(float x) {
		this->x = x;
	}
	void SetY(float y) {
		this->y = y;
	}
	void SetZ(float z) {
		this->z = z;
	}
};
//==========================================================================================================
namespace ThreeDVectors {
	void AddToArray(const TCHAR* ID);
	Vector3* GetFromArray(const TCHAR* ID);
	void RemoveFromArray(const TCHAR* ID);
	void Delete();
	std::vector<Vector3> Get();
	void Set(std::vector<Vector3> newList);
}
//==========================================================================================================
