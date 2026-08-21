//==========
#pragma once
//=====================
#include "DarkEdif.hpp"
//=====================
#include <cmath>
#include <tchar.h>
#include <vector>
//=====================
namespace AriaStrings {
	//
	std::vector<const TCHAR*>& ParseString(const TCHAR* string, const TCHAR* delimiters);
	//
	int ToInt(const TCHAR* string);
	float ToFloat(const TCHAR* string);
	//
};
//=====================
