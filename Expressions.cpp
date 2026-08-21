#include "Common.hpp"
#include <cmath>
#include <strsafe.h>

//=======================================================================================================================================================================================================
//Constants
float Extension::eConstE() { return Math::e; }
float Extension::eConstPi() { return Math::pi; }
float Extension::eConstTau() { return Math::tau; }
float Extension::eConstPhi() { return Math::phi; }
float Extension::eConstGamma() { return Math::gamma; }
float Extension::eConstRoot2() { return Math::root2; }
float Extension::eConstRoot3() { return Math::root3; }
//=======================================================================================================================================================================================================
//Exponents
float Extension::eExpE(float power) { return Math::Exp_e(power); }
float Extension::eExp10(float power) { return Math::Exp_b(power, 10.0f); }
float Extension::eExp2(float power) { return Math::Exp_b(power, 2.0f); }
float Extension::eExpB(float power, float base) { return Math::Exp_b(power, base); }
//Logs
float Extension::eLogE(float argument) { return Math::Log_e(argument); }
float Extension::eLog10(float argument) { return Math::Log_b(argument, 10.0f); }
float Extension::eLog2(float argument) { return Math::Log_b(argument, 2.0f); }
float Extension::eLogB(float argument, float base) { return Math::Log_b(argument, base); }
//=======================================================================================================================================================================================================
//Roots
float Extension::eRoot2(float value) { return Math::Root2(value); }
float Extension::eRoot3(float value) { return Math::RootN(value, 3.0f); }
float Extension::eRootN(float value, float radical) { return Math::RootN(value, radical); }
float Extension::eRootInv(float value, float radical) { return (1.0f / Math::RootN(value, radical)); }
//=======================================================================================================================================================================================================
//Angles
float Extension::eToRadians(int angle) { return Math::ToRadians(angle); }
float Extension::eToDegrees(float angle) { return Math::ToDegrees(angle); }
//Trig Functions
float Extension::eSinR(float angle) { return sinf(angle); }
float Extension::eSinD(int angle) { return sinf(Math::ToRadians(angle)); }
float Extension::eCosR(float angle) { return cosf(angle); }
float Extension::eCosD(int angle) { return cosf(Math::ToRadians(angle)); }
float Extension::eTanR(float angle) { return tanf(angle); }
float Extension::eTanD(int angle) { return tanf(Math::ToRadians(angle)); }
//Reciprocal Trig Functions
float Extension::eCscR(float angle) { return 1.0f / sinf(angle); }
float Extension::eCscD(int angle) { return 1.0f / sinf(Math::ToRadians(angle)); }
float Extension::eSecR(float angle) { return 1.0f / cosf(angle); }
float Extension::eSecD(int angle) { return 1.0f / cosf(Math::ToRadians(angle)); }
float Extension::eCotR(float angle) { return 1.0f / tanf(angle); }
float Extension::eCotD(int angle) { return 1.0f / tanf(Math::ToRadians(angle)); }
//Hyperbolic Trig Functions
float Extension::ehSinR(float angle) { return sinh(angle); }
float Extension::ehSinD(int angle) { return sinh(Math::ToRadians(angle)); }
float Extension::ehCosR(float angle) { return sinh(angle); }
float Extension::ehCosD(int angle) { return sinh(Math::ToRadians(angle)); }
float Extension::ehTanR(float angle) { return sinh(angle); }
float Extension::ehTanD(int angle) { return sinh(Math::ToRadians(angle)); }
//Inverse Trig Functions
float Extension::eSinInv(float ratio) { return asin(ratio); }
float Extension::eCosInv(float ratio) { return acos(ratio); }
float Extension::eTanInv(float ratio) { return atan(ratio); }
//Inverse Reciprocal Trig Functions
float Extension::eCscInv(float ratio) { return asin(1.0f/ratio); }
float Extension::eSecInv(float ratio) { return acos(1.0f/ratio); }
float Extension::eCotInv(float ratio) { return atan(1.0f/ratio); }
//Inverse Hyperbolic Trig Functions
float Extension::ehSinInv(float ratio) { return asinh(ratio); }
float Extension::ehCosInv(float ratio) { return acosh(ratio); }
float Extension::ehTanInv(float ratio) { return atanh(ratio); }
//=======================================================================================================================================================================================================
//Factorials
int Extension::eFactorialI(int input) { return Math::FactorialI(input); }
float Extension::eFactorialF(float input) { return Math::FactorialF(input); }
//=======================================================================================================================================================================================================
//Operations
int Extension::eClampI(int input, int min, int max) { return Math::ClampI(input, min, max); }
float Extension::eClampF(float input, float min, float max) { return Math::ClampF(input, min, max); }
int Extension::eMinI(int valueA, int valueB) { return Math::MinI(valueA, valueB); }
float Extension::eMinF(float valueA, float valueB) { return Math::MinF(valueA, valueB); }
int Extension::eMaxI(int valueA, int valueB) { return Math::MaxI(valueA, valueB); }
float Extension::eMaxF(float valueA, float valueB) { return Math::MaxF(valueA, valueB); }
//Rounding
int Extension::eRound(float input) { return Math::RoundI(input); }
float Extension::eRoundTo(float input, int decimal) { return Math::RoundF(input, decimal); }
int Extension::eFloor(float input) { return Math::FloorI(input); }
float Extension::eFloorTo(float input, int decimal) { return Math::FloorF(input, decimal); }
int Extension::eCeil(float input) { return Math::CeilI(input); }
float Extension::eCeilTo(float input, int decimal) { return Math::CeilF(input, decimal); }
//Other
int Extension::eAbsI(int input) { return Math::AbsI(input); }
float Extension::eAbsF(float input) { return Math::AbsF(input); }
int Extension::eSign(int input) { return Math::Sign(input); }
int Extension::eModI(int input, int divisor) { return Math::ModI(input, divisor); }
float Extension::eModF(float input, float divisor) { return Math::ModF(input, divisor); }
int Extension::eDivI(int input, int divisor) { return Math::FloorI(input / divisor); }
int Extension::eDivF(float input, float divisor) { return Math::FloorI(input / divisor); }
int Extension::eRemI(int valueA, int valueB) { return valueA % valueB; }
float Extension::eRemF(float valueA, float valueB) { return fmodf(valueA, valueB); }
//=======================================================================================================================================================================================================
//Comparisons
int Extension::eCompEq(float valueA, float valueB) { return (valueA == valueB); }
int Extension::eCompDiff(float valueA, float valueB) { return (valueA != valueB); }
int Extension::eCompGreater(float valueA, float valueB) { return (valueA > valueB); }
int Extension::eCompGreaterEq(float valueA, float valueB) { return (valueA >= valueB); }
int Extension::eCompLess(float valueA, float valueB) { return (valueA < valueB); }
int Extension::eCompLessEq(float valueA, float valueB) { return (valueA <= valueB); }
//=======================================================================================================================================================================================================
//Linear Interpolation
float Extension::eLerp(float valueA, float valueB, float valueT) { return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Linear, Math::EasingDirection::InOut); }
float Extension::eLerpSmooth(float valueA, float valueB, float valueT, float deltaTime) { return Math::Ease(valueA, valueB, powf(1.0f - valueT, deltaTime), Math::EasingStyle::Linear, Math::EasingDirection::InOut); }
float Extension::ePointSlope(float x0, float x1, float y0, float y1, float valueT) { return (y1 - y0)/(x1 - x0) * (valueT - x0) + y0; }
//=======================================================================================================================================================================================================
//Easing

const TCHAR* DIR_IN = _T("IN");
const TCHAR* DIR_OUT = _T("OUT");
const TCHAR* DIR_IN_OUT = _T("INOUT");

float Extension::eEaseConstant(float valueA, float valueB, float valueT, float jumpPoint) {
	return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Constant, Math::EasingDirection::InOut);
}

float Extension::eEaseLinear(float valueA, float valueB, float valueT) {
	return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Linear, Math::EasingDirection::InOut);
}
float Extension::eEaseQuadratic(float valueA, float valueB, float valueT, const TCHAR* direction) {
	if (Math::UnsCompTCHAR(direction, DIR_IN) == 0) {
		//Easing In
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Polynomial, Math::EasingDirection::In, 2.0f);
	}
	else if (Math::UnsCompTCHAR(direction, DIR_OUT) == 0) {
		//Easing Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Polynomial, Math::EasingDirection::Out, 2.0f);
	}
	else {
		//Easing In Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Polynomial, Math::EasingDirection::InOut, 2.0f);
	}
}
float Extension::eEaseCubic(float valueA, float valueB, float valueT, const TCHAR* direction) {
	if (Math::UnsCompTCHAR(direction, DIR_IN) == 0) {
		//Easing In
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Polynomial, Math::EasingDirection::In, 3.0f);
	}
	else if (Math::UnsCompTCHAR(direction, DIR_OUT) == 0) {
		//Easing Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Polynomial, Math::EasingDirection::Out, 3.0f);
	}
	else {
		//Easing In Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Polynomial, Math::EasingDirection::InOut, 3.0f);
	}
}
float Extension::eEaseQuartic(float valueA, float valueB, float valueT, const TCHAR* direction) {
	if (Math::UnsCompTCHAR(direction, DIR_IN) == 0) {
		//Easing In
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Polynomial, Math::EasingDirection::In, 4.0f);
	}
	else if (Math::UnsCompTCHAR(direction, DIR_OUT) == 0) {
		//Easing Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Polynomial, Math::EasingDirection::Out, 4.0f);
	}
	else {
		//Easing In Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Polynomial, Math::EasingDirection::InOut, 4.0f);
	}
}
float Extension::eEasePolynomial(float valueA, float valueB, float valueT, const TCHAR* direction, int exponent) {
	if (Math::UnsCompTCHAR(direction, DIR_IN) == 0) {
		//Easing In
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Polynomial, Math::EasingDirection::In, exponent);
	}
	else if (Math::UnsCompTCHAR(direction, DIR_OUT) == 0) {
		//Easing Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Polynomial, Math::EasingDirection::Out, exponent);
	}
	else {
		//Easing In Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Polynomial, Math::EasingDirection::InOut, exponent);
	}
}
float Extension::eEaseExponential(float valueA, float valueB, float valueT, const TCHAR* direction, float base, float growth) {
	if (Math::UnsCompTCHAR(direction, DIR_IN) == 0) {
		//Easing In
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Exponential, Math::EasingDirection::In, base, growth);
	}
	else if (Math::UnsCompTCHAR(direction, DIR_OUT) == 0) {
		//Easing Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Exponential, Math::EasingDirection::Out, base, growth);
	}
	else {
		//Easing In Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Exponential, Math::EasingDirection::InOut, base, growth);
	}
}
float Extension::eEaseSine(float valueA, float valueB, float valueT, const TCHAR* direction) {
	if (Math::UnsCompTCHAR(direction, DIR_IN) == 0) {
		//Easing In
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Sine, Math::EasingDirection::In);
	}
	else if (Math::UnsCompTCHAR(direction, DIR_OUT) == 0) {
		//Easing Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Sine, Math::EasingDirection::Out);
	}
	else {
		//Easing In Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Sine, Math::EasingDirection::InOut);
	}
}
float Extension::eEaseCircular(float valueA, float valueB, float valueT, const TCHAR* direction) {
	if (Math::UnsCompTCHAR(direction, DIR_IN) == 0) {
		//Easing In
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Circular, Math::EasingDirection::In);
	}
	else if (Math::UnsCompTCHAR(direction, DIR_OUT) == 0) {
		//Easing Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Circular, Math::EasingDirection::Out);
	}
	else {
		//Easing In Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Circular, Math::EasingDirection::InOut);
	}
}
float Extension::eEaseBack(float valueA, float valueB, float valueT, const TCHAR* direction, float overshoot) {
	if (Math::UnsCompTCHAR(direction, DIR_IN) == 0) {
		//Easing In
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Back, Math::EasingDirection::In, overshoot);
	}
	else if (Math::UnsCompTCHAR(direction, DIR_OUT) == 0) {
		//Easing Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Back, Math::EasingDirection::Out, overshoot);
	}
	else {
		//Easing In Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Back, Math::EasingDirection::InOut, overshoot);
	}
}
float Extension::eEaseBounce(float valueA, float valueB, float valueT, const TCHAR* direction, float damping, float frequency) {
	if (Math::UnsCompTCHAR(direction, DIR_IN) == 0) {
		//Easing In
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Bounce, Math::EasingDirection::In, damping, frequency);
	}
	else if (Math::UnsCompTCHAR(direction, DIR_OUT) == 0) {
		//Easing Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Bounce, Math::EasingDirection::Out, damping, frequency);
	}
	else {
		//Easing In Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Bounce, Math::EasingDirection::InOut, damping, frequency);
	}
}
float Extension::eEaseElastic(float valueA, float valueB, float valueT, const TCHAR* direction, float damping, float frequency) {
	if (Math::UnsCompTCHAR(direction, DIR_IN) == 0) {
		//Easing In
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Elastic, Math::EasingDirection::In, damping, frequency);
	}
	else if (Math::UnsCompTCHAR(direction, DIR_OUT) == 0) {
		//Easing Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Elastic, Math::EasingDirection::Out, damping, frequency);
	}
	else {
		//Easing In Out
		return Math::Ease(valueA, valueB, valueT, Math::EasingStyle::Elastic, Math::EasingDirection::InOut, damping, frequency);
	}
}
//=======================================================================================================================================================================================================
//Kill Timer Equations
float Extension::eExponentialDecayFormula(float minAI, float maxAI, float timerA, float timerB, float valueT) { return Math::ExpDecay(minAI, maxAI, timerA, timerB, valueT); }
float Extension::eSquareRootDecayFormula(float minAI, float maxAI, float timerA, float timerB, float valueT) { return Math::SqrtDecay(minAI, maxAI, timerA, timerB, valueT); }
//=======================================================================================================================================================================================================
//Colors
int Extension::eFromRGB(int r, int g, int b) { return AriaColors::GetRGB(r, g, b); }
int Extension::eFromHSV(int h, float s, float v) { return AriaColors::GetHSV(h, s, v); }
int Extension::eFromHEX(const TCHAR* hex) { return AriaColors::GetHEX(hex); }
//Get RGB
int Extension::eGetRed(int color) { return AriaColors::GetRed(color); }
int Extension::eGetGreen(int color) { return AriaColors::GetGreen(color); }
int Extension::eGetBlue(int color) { return AriaColors::GetBlue(color); }
//Get HSV
int Extension::eGetHue(int color) {
	int h = 0;
	float s = 0;
	float v = 0;
	AriaColors::RGBtoHSV(AriaColors::GetRed(color), AriaColors::GetGreen(color), AriaColors::GetBlue(color), &h, &s, &v);
	return h;
}
float Extension::eGetSaturation(int color) {
	int h = 0;
	float s = 0;
	float v = 0;
	AriaColors::RGBtoHSV(AriaColors::GetRed(color), AriaColors::GetGreen(color), AriaColors::GetBlue(color), &h, &s, &v);
	return s;
}
float Extension::eGetBrightness(int color) {
	int h = 0;
	float s = 0;
	float v = 0;
	AriaColors::RGBtoHSV(AriaColors::GetRed(color), AriaColors::GetGreen(color), AriaColors::GetBlue(color), &h, &s, &v);
	return v;
}
//Get HEX
const TCHAR* Extension::aGetHex(int color) {
	return AriaColors::RGBtoHEX(AriaColors::GetRed(color), AriaColors::GetGreen(color), AriaColors::GetBlue(color));
}
//=======================================================================================================================================================================================================
//Other
float Extension::eErf(float value) { return std::erf(value); }
//=======================================================================================================================================================================================================
//Boolean
int Extension::eToBoolean(int value) {
	return Math::ToBoolean(value);
}
int Extension::eNOT(int value) {
	return Math::NOT(value);
}
int Extension::eAND(int valueA, int valueB) {
	valueA = Math::ToBoolean(valueA);
	valueB = Math::ToBoolean(valueB);
	return Math::ToBoolean((valueA == 1) && (valueB == 1));
}
int Extension::eNAND(int valueA, int valueB) {
	valueA = Math::ToBoolean(valueA);
	valueB = Math::ToBoolean(valueB);
	return Math::NOT((valueA==1) && (valueB==1));
}
int Extension::eOR(int valueA, int valueB) {
	valueA = Math::ToBoolean(valueA);
	valueB = Math::ToBoolean(valueB);
	return Math::ToBoolean((valueA == 1) || (valueB == 1));
}
int Extension::eNOR(int valueA, int valueB) {
	valueA = Math::ToBoolean(valueA);
	valueB = Math::ToBoolean(valueB);
	return Math::NOT((valueA == 1) || (valueB == 1));
}
int Extension::eXOR(int valueA, int valueB) {
	valueA = Math::ToBoolean(valueA);
	valueB = Math::ToBoolean(valueB);
	return Math::ToBoolean((valueA + valueB)%2);
}
int Extension::eXNOR(int valueA, int valueB) {
	valueA = Math::ToBoolean(valueA);
	valueB = Math::ToBoolean(valueB);
	return Math::NOT((valueA + valueB) % 2);
}
int Extension::eImplies(int valueA, int valueB) {
	valueA = Math::ToBoolean(valueA);
	valueB = Math::ToBoolean(valueB);
	return Math::MinI(Math::NOT(valueA) + valueB, 1);
}
int Extension::eNImplies(int valueA, int valueB) {
	valueA = Math::ToBoolean(valueA);
	valueB = Math::ToBoolean(valueB);
	return Math::NOT(Math::MinI(Math::NOT(valueA) + valueB, 1));
}
//=======================================================================================================================================================================================================
//Bitwise
const int MAX_BITSHIFT = 32;

int Extension::eBitshiftR(int value, int shiftAmount) { return value >> Math::ClampI(shiftAmount,0,MAX_BITSHIFT); }
int Extension::eBitshiftL(int value, int shiftAmount) { return value << Math::ClampI(shiftAmount, 0, MAX_BITSHIFT); }
int Extension::eBitwiseNOT(int value) { return ~value; }
int Extension::eBitwiseAND(int valueA, int valueB) { return valueA & valueB; }
int Extension::eBitwiseNAND(int valueA, int valueB) { return ~(valueA & valueB); }
int Extension::eBitwiseOR(int valueA, int valueB) { return valueA | valueB; }
int Extension::eBitwiseNOR(int valueA, int valueB) { return ~(valueA | valueB); }
int Extension::eBitwiseXOR(int valueA, int valueB) { return valueA ^ valueB; }
int Extension::eBitwiseXNOR(int valueA, int valueB) { return ~(valueA ^ valueB); }
int Extension::eBitwiseImplies(int valueA, int valueB) { return ~valueA | valueB; }
int Extension::eBitwiseNImplies(int valueA, int valueB) { return ~(~valueA | valueB); }
int Extension::eTwosComplement(int value) { return ~value + 1; }
//=======================================================================================================================================================================================================
//Time
int Extension::eTimeHours() { return AriaTime::GetHoursValue(); }
int Extension::eTimeMinutes() { return AriaTime::GetMinutesValue(); }
int Extension::eTimeSeconds() { return AriaTime::GetSecondsValue(); }
int Extension::eTimeMilliseconds() { return AriaTime::GetMillisecondsValue(); }
const TCHAR* Extension::eTimeHours$() { return AriaTime::GetHoursValue$(); }
const TCHAR* Extension::eTimeMinutes$() { return AriaTime::GetMinutesValue$(); }
const TCHAR* Extension::eTimeSeconds$() { return AriaTime::GetSecondsValue$(); }
const TCHAR* Extension::eTimeMilliseconds$() { return AriaTime::GetMillisecondsValue$(); }
const TCHAR* Extension::eTimeString$() { return AriaTime::GetTimeString(); }
int Extension::eCurrentMonth() { return AriaTime::GetCurrentMonth(); }
int Extension::eCurrentDay() { return AriaTime::GetCurrentDay(); }
int Extension::eCurrentYear() { return AriaTime::GetCurrentYear(); }
const TCHAR* Extension::eCurrentDate$() { return AriaTime::GetCurrentDate(); }
int Extension::eCurrentHours() { return AriaTime::GetCurrentHours(); }
int Extension::eCurrentMinutes() { return AriaTime::GetCurrentMinutes(); }
int Extension::eCurrentSeconds() { return AriaTime::GetCurrentSeconds(); }
const TCHAR* Extension::eCurrentTime$() { return AriaTime::GetCurrentTimeString(); }
//=======================================================================================================================================================================================================
//Randomization
int Extension::eRandom0(int value) { return Math::RRandomI(0, Math::MaxI(value - 1, 0)); }
int Extension::eRandom1(int value) { return Math::RRandomI(1, Math::MaxI(value, 1)); }
int Extension::eRRandomI(int valueA, int valueB) { return Math::RRandomI(valueA, valueB); }
float Extension::eRRandomF(float valueA, float valueB) { return Math::RRandomF(valueA, valueB); }
int Extension::eRandomizerIndex(const TCHAR* ID, int index) { return BagRandomization::GetFromArray(ID)->GetFromBag(index); }
int Extension::eRandomizerValue(const TCHAR* ID) { return BagRandomization::GetFromArray(ID)->GetRandomValue(); }
//=======================================================================================================================================================================================================
//Delta Time/Ticks
float Extension::eDeltaTimeF() { return DeltaTime::GetDeltaTimeF(); }
float Extension::eDeltaTimeS() { return DeltaTime::GetDeltaTimeS(); }
float Extension::eGameSpeed() { return DeltaTime::GetGameSpeed(); }
int Extension::eDeltaTimeBase() { return DeltaTime::GetTimeScale(); }
int Extension::eTickRate() { return 0; }
int Extension::eOldTimer() { return DeltaTime::GetOldTimer(); }
//=======================================================================================================================================================================================================
//Functions
int Extension::eFunctionIntParam(const TCHAR* functionID, const TCHAR* paramID) { return Functions::GetFromArray(functionID)->GetIntParam(paramID)->GetValue(); }
float Extension::eFunctionFloatParam(const TCHAR* functionID, const TCHAR* paramID) { return Functions::GetFromArray(functionID)->GetFloatParam(paramID)->GetValue(); }
const TCHAR* Extension::eFunctionStringParam(const TCHAR* functionID, const TCHAR* paramID) { return Functions::GetFromArray(functionID)->GetStringParam(paramID)->GetValue(); }
int Extension::eFunctionIntReturn(const TCHAR* functionID) { return Functions::GetFromArray(functionID)->GetIntReturn(); }
float Extension::eFunctionFloatReturn(const TCHAR* functionID) { return Functions::GetFromArray(functionID)->GetFloatReturn(); }
const TCHAR* Extension::eFunctionStringReturn(const TCHAR* functionID) { return Functions::GetFromArray(functionID)->GetStringReturn(); }
int Extension::eFunctionLoopIndex(const TCHAR* functionID) { return Functions::GetFromArray(functionID)->GetLoopIndex(); }
const TCHAR* Extension::eToFunctionParam(const TCHAR* paramID, const TCHAR* paramType, const TCHAR* paramValue) {

	size_t len = _tcslen(paramID) + _tcslen(paramType) + _tcslen(paramValue) + 3;

	TCHAR* result = new TCHAR[len];

	_stprintf_s(result, len, _T("%s-%s-%s"), paramID, paramType, paramValue);

	return _tcsdup(result);
};
//=======================================================================================================================================================================================================
//IntArrays
int Extension::eIntArrayValue(const TCHAR* arrayID, int index) {
	IntArray* currentArray = IntegerArrays::GetFromArray(arrayID);
	std::vector<int> arr = currentArray->GetArray();
	if (arr.size() == 0) { return 0; }
	if (index >= arr.size()) { return 0; }
	index = Math::MaxI(index, 0);
	return arr[index];
}
int Extension::eIntArrayLoopIndex(const TCHAR* arrayID) { return IntegerArrays::GetFromArray(arrayID)->GetLoopIndex(); }
int Extension::eIntArrayValueAtLoopIndex(const TCHAR* arrayID) {
	IntArray* currentArray = IntegerArrays::GetFromArray(arrayID);
	std::vector<int> arr = currentArray->GetArray();
	if (arr.size() == 0) { return 0; }
	return arr[currentArray->GetLoopIndex()];
}
int Extension::eIntArraySize(const TCHAR* arrayID) { return IntegerArrays::GetFromArray(arrayID)->GetArray().size(); }
const TCHAR* Extension::eIntArrayLoopID(const TCHAR* arrayID) { return IntegerArrays::GetFromArray(arrayID)->GetLoopID(); }
const TCHAR* Extension::ePrintIntArray(const TCHAR* arrayID) {
	std::vector<int> arr = IntegerArrays::GetFromArray(arrayID)->GetArray();
	static std::basic_string<TCHAR> result;
	std::basic_ostringstream<TCHAR> stream;
	stream << _T("{ ");
	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (i > 0) {
			stream << _T(", ");
		}
		stream << arr[i];
	}
	stream << _T(" }");
	result = stream.str();
	return result.c_str();
}
//FloatArrays
float Extension::eFloatArrayValue(const TCHAR* arrayID, int index) {
	FloatArray* currentArray = FloatArrays::GetFromArray(arrayID);
	std::vector<float> arr = currentArray->GetArray();
	if (arr.size() == 0) { return 0; }
	if (index >= arr.size()) { return 0; }
	index = Math::MaxI(index, 0);
	return arr[index];
}
int Extension::eFloatArrayLoopIndex(const TCHAR* arrayID) { return FloatArrays::GetFromArray(arrayID)->GetLoopIndex(); }
float Extension::eFloatArrayValueAtLoopIndex(const TCHAR* arrayID) {
	FloatArray* currentArray = FloatArrays::GetFromArray(arrayID);
	std::vector<float> arr = currentArray->GetArray();
	if (arr.size() == 0) { return 0; }
	return arr[currentArray->GetLoopIndex()];
}
int Extension::eFloatArraySize(const TCHAR* arrayID) { return FloatArrays::GetFromArray(arrayID)->GetArray().size(); }
const TCHAR* Extension::eFloatArrayLoopID(const TCHAR* arrayID) { return FloatArrays::GetFromArray(arrayID)->GetLoopID(); }
const TCHAR* Extension::ePrintFloatArray(const TCHAR* arrayID) {
	std::vector<float> arr = FloatArrays::GetFromArray(arrayID)->GetArray();
	static std::basic_string<TCHAR> result;
	std::basic_ostringstream<TCHAR> stream;
	stream << _T("{ ");
	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (i > 0) {
			stream << _T(", ");
		}
		stream << arr[i];
	}
	stream << _T(" }");
	result = stream.str();
	return result.c_str();
}
//StringArrays
const TCHAR* Extension::eStringArrayValue(const TCHAR* arrayID, int index) {
	StringArray* currentArray = StringArrays::GetFromArray(arrayID);
	std::vector<const TCHAR*> arr = currentArray->GetArray();
	if (arr.size() == 0) { return 0; }
	if (index >= arr.size()) { return 0; }
	index = Math::MaxI(index, 0);
	return arr[index];
}
int Extension::eStringArrayLoopIndex(const TCHAR* arrayID) { return StringArrays::GetFromArray(arrayID)->GetLoopIndex(); }
const TCHAR* Extension::eStringArrayValueAtLoopIndex(const TCHAR* arrayID) {
	StringArray* currentArray = StringArrays::GetFromArray(arrayID);
	std::vector<const TCHAR*> arr = currentArray->GetArray();
	if (arr.size() == 0) { return 0; }
	return arr[currentArray->GetLoopIndex()];
}
int Extension::eStringArraySize(const TCHAR* arrayID) { return StringArrays::GetFromArray(arrayID)->GetArray().size(); }
const TCHAR* Extension::eStringArrayLoopID(const TCHAR* arrayID) { return StringArrays::GetFromArray(arrayID)->GetLoopID(); }
const TCHAR* Extension::ePrintStringArray(const TCHAR* arrayID) {
	std::vector<const TCHAR*> arr = StringArrays::GetFromArray(arrayID)->GetArray();
	static std::basic_string<TCHAR> result;
	result = _T("{ ");
	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (i > 0) {
			result += _T(", ");
		}
		result += arr[i];
	}
	result += _T(" }");
	return result.c_str();
}
//=======================================================================================================================================================================================================
//Vector2
float Extension::eVect2(const TCHAR* ID, const TCHAR* dimension) {
	Vector2* currentVector = TwoDVectors::GetFromArray(ID);
	float result = currentVector->GetX();
	if (Math::UnsCompTCHAR(ID, _T("Y")) == 0) {
		result = currentVector->GetY();
	}
	return result;
}
float Extension::eVect2x(const TCHAR* ID) { return TwoDVectors::GetFromArray(ID)->GetX(); }
float Extension::eVect2y(const TCHAR* ID) { return TwoDVectors::GetFromArray(ID)->GetY(); }
float Extension::eVect2M(const TCHAR* ID) {
	Vector2* currentVector = TwoDVectors::GetFromArray(ID);
	float x = currentVector->GetX();
	float y = currentVector->GetY();
	return sqrtf(x * x + y * y);
}
float Extension::eVect2Dot(const TCHAR* ID1, const TCHAR* ID2) {
	Vector2* currentVector1 = TwoDVectors::GetFromArray(ID1);
	Vector2* currentVector2 = TwoDVectors::GetFromArray(ID2);
	float x1 = currentVector1->GetX();
	float y1 = currentVector1->GetY();
	float x2 = currentVector2->GetX();
	float y2 = currentVector2->GetY();
	return (x1 * x2 + y1 * y2);
}
//Vector3
float Extension::eVect3(const TCHAR* ID, const TCHAR* dimension) {
	Vector3* currentVector = ThreeDVectors::GetFromArray(ID);
	float result = currentVector->GetX();
	if (Math::UnsCompTCHAR(ID, _T("Y")) == 0) {
		result = currentVector->GetY();
	}
	else if (Math::UnsCompTCHAR(ID, _T("Z")) == 0) {
		result = currentVector->GetZ();
	}
	return result;
}
float Extension::eVect3x(const TCHAR* ID) { return ThreeDVectors::GetFromArray(ID)->GetX(); }
float Extension::eVect3y(const TCHAR* ID) { return ThreeDVectors::GetFromArray(ID)->GetY(); }
float Extension::eVect3z(const TCHAR* ID) { return ThreeDVectors::GetFromArray(ID)->GetZ(); }
float Extension::eVect3M(const TCHAR* ID) {
	Vector3* currentVector = ThreeDVectors::GetFromArray(ID);
	float x = currentVector->GetX();
	float y = currentVector->GetY();
	float z = currentVector->GetZ();
	return sqrtf(x * x + y * y + z * z);
}
float Extension::eVect3Dot(const TCHAR* ID1, const TCHAR* ID2) {
	Vector3* currentVector1 = ThreeDVectors::GetFromArray(ID1);
	Vector3* currentVector2 = ThreeDVectors::GetFromArray(ID2);
	float x1 = currentVector1->GetX();
	float y1 = currentVector1->GetY();
	float z1 = currentVector1->GetZ();
	float x2 = currentVector2->GetX();
	float y2 = currentVector2->GetY();
	float z2 = currentVector2->GetZ();
	return (x1 * x2 + y1 * y2 + z1 * z2);
}
//=======================================================================================================================================================================================================
