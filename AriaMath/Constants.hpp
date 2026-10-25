//==========
#pragma once
//=====================
#include "DarkEdif.hpp"
//=====================
#include <cmath>
#include <tchar.h>
#include <vector>
//================
class IntConst {
	//==========
private:
	const TCHAR* ID = _T("");
	int value = NULL;
	//==========
public:
	const TCHAR* GetID() {
		return this->ID;
	}
	void SetID(const TCHAR* ID) {
		this->ID = ID;
	}
	int GetValue() {
		if (this->value == NULL) {
			return 0;
		}
		else {
			return this->value;
		}
	}
	void SetValue(int value) {
		if (this->value == NULL) {
			this->value = value;
		}
	}
	//==========
};
//================
class FloatConst {
	//==========
private:
	const TCHAR* ID = _T("");
	float value = NULL;
	//==========
public:
	const TCHAR* GetID() {
		return this->ID;
	}
	void SetID(const TCHAR* ID) {
		this->ID = ID;
	}
	float GetValue() {
		if (this->value == NULL) {
			return 0.0f;
		}
		else {
			return this->value;
		}
	}
	void SetValue(float value) {
		if (this->value == NULL) {
			this->value = value;
		}
	}
	//==========
};
//================
class StrConst {
	//==========
private:
	const TCHAR* ID = _T("");
	const TCHAR* value = NULL;
	//==========
public:
	const TCHAR* GetID() {
		return this->ID;
	}
	void SetID(const TCHAR* ID) {
		this->ID = ID;
	}
	const TCHAR* GetValue() {
		if (this->value == NULL) {
			return _T("");
		}
		else {
			return this->value;
		}
	}
	void SetValue(const TCHAR* value) {
		if (this->value == NULL) {
			this->value = value;
		}
	}
	//==========
};
//=======================================
namespace Constants {
	struct ConstInt {
		static void AddToArray(const TCHAR* ID);
		static IntConst* GetFromArray(const TCHAR* ID);
		static void RemoveFromArray(const TCHAR* ID);
	};
	struct ConstFloat {
		static void AddToArray(const TCHAR* ID);
		static FloatConst* GetFromArray(const TCHAR* ID);
		static void RemoveFromArray(const TCHAR* ID);
	};
	struct ConstString {
		static void AddToArray(const TCHAR* ID);
		static StrConst* GetFromArray(const TCHAR* ID);
		static void RemoveFromArray(const TCHAR* ID);
	};
};
//=======================================
