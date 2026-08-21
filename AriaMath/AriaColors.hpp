#pragma once
//=========================
#include "DarkEdif.hpp"
//=========================
#include <cmath>
#include <tchar.h>
//=========================
namespace AriaColors {
	//
	int GetRGB(int r, int g, int b);
	//
	int GetRed(int rgbValue);
	int GetGreen(int rgbValue);
	int GetBlue(int rgbValue);
	//
	int GetHSV(int hue, float saturation, float value);
	int GetHEX(const TCHAR* hex);
	//
	void RGBtoHSV(int r, int g, int b, int* hue, float* saturation, float* value);
	const TCHAR* RGBtoHEX(int r, int g, int b);
	//
};
//=========================
