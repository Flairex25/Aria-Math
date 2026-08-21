//==========
#pragma once
//=====================
#include "DarkEdif.hpp"
//=====================
#include <cmath>
#include <tchar.h>
#include <vector>
//================
class Vector2 {
private:
	const TCHAR* ID = _T("[EMPTY]");
	float x = 0;
	float y = 0;
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
};
//==========================================================================================================
namespace TwoDVectors {
	void AddToArray(const TCHAR* ID);
	Vector2* GetFromArray(const TCHAR* ID);
	void RemoveFromArray(const TCHAR* ID);
	void Delete();
}
//==========================================================================================================
