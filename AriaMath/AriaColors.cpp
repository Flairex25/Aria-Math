#include "Common.hpp"
#include "AriaMath\AriaColors.hpp"
//==================================================================================
#include <cmath>
#include <tchar.h>
#include <algorithm>
//==================================================================================
int AriaColors::GetRGB(int r, int g, int b) {
	r = Math::ClampI(r, 0, 0xFF);
	g = Math::ClampI(g, 0, 0xFF);
	b = Math::ClampI(b, 0, 0xFF);
	return (b << 16) + (g << 8) + (r);
}
//==================================================================================
int AriaColors::GetRed(int rgbValue) {
	rgbValue = Math::ClampI(rgbValue, 0, 0xFFFFFF);
	return (rgbValue & 0xFF);
}
int AriaColors::GetGreen(int rgbValue) {
	//Clamp between 0,16777215
	return ((rgbValue & (0xFF << 8)) >> 8);
}
int AriaColors::GetBlue(int rgbValue) {
	//Clamp between 0,16777215
	return ((rgbValue & (0xFF << 16)) >> 16);
}
//==================================================================================
int AriaColors::GetHSV(int hue, float saturation, float value) {

	hue = Math::AbsI(hue % 360);
	saturation = Math::ClampF(saturation, 0.0f, 100.0f);
	value = Math::ClampF(value, 0.0f, 100.0f);

	//Convert s and v to double
	double S = static_cast<double>(saturation / 100.0f);
	double V = static_cast<double>(value / 100.0f);

	//Grayscale Case
	if (S == 0.0) {
		value = static_cast<int>(V * 255.0);
		return AriaColors::GetRGB(value, value, value);
	}

	//Find hue sector
	double H = static_cast<double>(hue / 60.0);
	int sector = static_cast<int>(Math::FloorI(H));
	double fraction = H - sector;

	double p = V * (1.0 - S);
	double q = V * (1.0 - S * fraction);
	double t = V * (1.0 - S * (1.0 - fraction));

	//Declare r, g, b
	double r = 0.0;
	double g = 0.0;
	double b = 0.0;

	//Sector Switch Statement
	switch (sector) {
	case 0:
		r = V; g = t; b = p;
		break;

	case 1:
		r = q; g = V; b = p;
		break;

	case 2:
		r = p; g = V; b = t;
		break;

	case 3:
		r = p; g = q; b = V;
		break;

	case 4:
		r = t; g = p; b = V;
		break;

	default: // sector 5, including h == 360
		r = V; g = p; b = q;
		break;
	}

	return GetRGB(static_cast<int>(r * 255.0), static_cast<int>(g * 255.0), static_cast<int>(b * 255.0));
}
//==================================================================================
int AriaColors::GetHEX(const TCHAR* hex) {
	const unsigned long valueFromStr = _tcstoul(hex, nullptr, 16);

	int r = Math::ClampI(static_cast<int>((valueFromStr >> 16) & 0xFF), 0, 0xFF);
	int g = Math::ClampI(static_cast<int>((valueFromStr >> 8) & 0xFF), 0, 0xFF);
	int b = Math::ClampI(static_cast<int>((valueFromStr) & 0xFF), 0, 0xFF);

	return AriaColors::GetRGB(r, g, b);
}
//==================================================================================
void AriaColors::RGBtoHSV(int r, int g, int b, int* hue, float* saturation, float* value) {

	r = Math::ClampI(r, 0, 0xFF);
	g = Math::ClampI(g, 0, 0xFF);
	b = Math::ClampI(b, 0, 0xFF);

	//Convert r, g, b to double
	double Red = static_cast<double>(r / 255.0);
	double Green = static_cast<double>(g / 255.0);
	double Blue = static_cast<double>(b / 255.0);

	double maxOfColors = std::max({ Red, Green, Blue });
	double minOfColors = std::min({ Red, Green, Blue });
	double differenceMinMax = maxOfColors - minOfColors;

	//Set value
	*value = static_cast<float>(maxOfColors * 100.0);

	// Set saturation
	if (maxOfColors == 0.0) {
		*saturation = 0.0f;
	}
	else {
		*saturation = static_cast<float>((differenceMinMax / maxOfColors) * 100.0);
	}

	//Set Hue
	if (differenceMinMax == 0.0) {
		*hue = 0;
	}
	else if (maxOfColors == Red) {
		*hue = static_cast<int>(60.0 * std::fmod((Green - Blue) / differenceMinMax, 6.0));
	}
	else if (maxOfColors == Green) {
		*hue = static_cast<int>(60.0 * (((Blue - Red) / differenceMinMax) + 2.0));
	}
	else {
		*hue = static_cast<int>(60.0 * (((Red - Green) / differenceMinMax) + 4.0));
	}

	if (*hue < 0.0)
		*hue += 360.0;
}
//==================================================================================
const TCHAR* AriaColors::RGBtoHEX(int r, int g, int b) {

	r = Math::ClampI(r, 0, 0xFF);
	g = Math::ClampI(g, 0, 0xFF);
	b = Math::ClampI(b, 0, 0xFF);

	static TCHAR hex[9];

	_stprintf_s(hex, _countof(hex), _T("0x%02X%02X%02X"), r, g, b);

	return hex;
}
//==================================================================================
