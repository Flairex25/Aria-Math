#include "Common.hpp"
#include "AriaMath\Math.hpp"
#include <cmath>
#include <tchar.h>
#include <functional>
#include <time.h>

//================================================================================================================
//CONSTANTS
//================================================================================================================
const int MAX_DECIMAL_ACCURACY = 5;
const int RRANDOM_DECIMAL_ACCURACY = 3;
const int MAX_TIMER_DIFFERENCE = 100;
//================================================================================================================
//Exponents
//================================================================================================================
//Exp e
float Math::Exp_e(float power) {
	return exp(power);
}
//Exp b
float Math::Exp_b(float power, float base) {
	return pow(base, power);
}
//================================================================================================================
//Logs
//================================================================================================================
//Log e
float Math::Log_e(float argument) {
	return log(argument);
}
//Log b
float Math::Log_b(float argument, float base) {
	return log(argument) / log(base);
}
//================================================================================================================
//Clamps
//================================================================================================================
//Min Integer
int Math::MinI(int valueA, int valueB) {
	return (valueA <= valueB) ? valueA : valueB;
}
//Min Float
float Math::MinF(float valueA, float valueB) {
	return (valueA <= valueB) ? valueA : valueB;
}
//Max Integer
int Math::MaxI(int valueA, int valueB) {
	return (valueA >= valueB) ? valueA : valueB;
}
//Max Float
float Math::MaxF(float valueA, float valueB) {
	return (valueA >= valueB) ? valueA : valueB;
}
//Clamp Integer
int Math::ClampI(int value, int min, int max) {
	int valMin = min;
	int valMax = max;
	int result = value;
	if (min > max) {
		valMin = max;
		valMax = min;
	}
	result = Math::MinI(result, max);
	result = Math::MaxI(result, min);
	return result;
}
//Clamp Float
float Math::ClampF(float value, float min, float max) {
	float valMin = min;
	float valMax = max;
	float result = value;
	if (min > max) {
		valMin = max;
		valMax = min;
	}
	result = Math::MinF(result, max);
	result = Math::MaxF(result, min);
	return result;
}
//================================================================================================================
//Rounding
//================================================================================================================
int Math::RoundI(float input) {
	return round(input);
}
float Math::RoundF(float input, int decimal) {
	decimal = Math::ClampI(decimal, 0, MAX_DECIMAL_ACCURACY);
	float result = input;
	result = result * pow(10, decimal);
	result = (float)round(result);
	result = result / pow(10, decimal);
	return result;
}
int Math::FloorI(float input) {
	return floor(input);
}
float Math::FloorF(float input, int decimal) {
	decimal = Math::ClampI(decimal, 0, MAX_DECIMAL_ACCURACY);
	float result = input;
	result = result * pow(10, decimal);
	result = (float)floor(result);
	result = result / pow(10, decimal);
	return result;
}
int Math::CeilI(float input) {
	return ceil(input);
}
float Math::CeilF(float input, int decimal) {
	decimal = Math::ClampI(decimal, 0, MAX_DECIMAL_ACCURACY);
	float result = input;
	result = result * pow(10, decimal);
	result = (float)ceil(result);
	result = result / pow(10, decimal);
	return result;
}
//================================================================================================================
//Modulus
//================================================================================================================
float Math::ModI(int input, int divisor)
{
	int result = input % divisor;

	return (input < 0) ? result + divisor : result;
}
float Math::ModF(float input, float divisor)
{
	float remainder = input - Math::FloorI(input);
	int result = fmodf(input, divisor);
	if (result < 0) {
		result += divisor;
	}

	return result + remainder;
}
//================================================================================================================
//Absolute Value
//================================================================================================================
int Math::AbsI(int input) {
	return (std::signbit(input) ? -input : input);
}
int Math::AbsF(float input) {
	return fabs(input);
}
//================================================================================================================
//Sign
//================================================================================================================
int Math::Sign(int input) {
	if (std::signbit(input)) {
		return -1;
	}
	else {
		return 1;
	}
}
//================================================================================================================
//Roots
//================================================================================================================
//Square Root
float Math::Root2(float value) {
	return sqrt(value);
}
//Nth Root
float Math::RootN(float value, float radical) {
	return pow(value, 1.0f/radical);
}
//================================================================================================================
//Angles
//================================================================================================================
float Math::ToRadians(int degrees) {
	degrees = Math::ModI(degrees, 360);
	return (Math::pi * degrees) / 180.0f;
}
float Math::ToDegrees(float radians) {
	radians = (radians * 180.0f) / Math::pi;
	return ModF(radians, 360);
}
//================================================================================================================
//Factorials
//================================================================================================================
int Math::FactorialI(int input) {
	int result = 1;
	input = Math::MaxI(input, 0);

	for (int i = input; i > 0; i--) {
		result *= i;
	}

	return result;
}
float Math::FactorialF(float input) {
	return tgamma(input + 1.0f);
}
//================================================================================================================
//Easing
//================================================================================================================
float Math::Ease(float a, float b, float t, Math::EasingStyle easingStyle, Math::EasingDirection easingDirection, float param1, float param2) {
	//Main function declaration
	std::function<float(float)> function = [=](float n) { return n; };
	//Easing Style Switch Statement
	switch (easingStyle) {
		//Constant
	default:
		return (t < 0.5f) ? a : b;
		//Linear
	case Math::EasingStyle::Linear:
		return a + (b - a) * t;
		//Polynomial
	case Math::EasingStyle::Polynomial:
		if (param1 <= 0.0f) { param1 = 1.0f; }
		function = [=](float n) { return pow(n, param1); };
		break;
		//Exponential
	case Math::EasingStyle::Exponential:
		if (param1 <= 1.0f) { param1 = Math::e; }
		if (param2 <= 0.0f) { param2 = 1.0f; }
		function = [=](float n) { return pow(param1, param2 * n); };
		break;
		//Sine
	case Math::EasingStyle::Sine:
		function = [=](float n) { return sinf(Math::pi / 2.0f * n - Math::pi / 2.0f) + 1; };
		break;
		//Circular
	case Math::EasingStyle::Circular:
		function = [=](float n) { return sqrtf(1.0f - n * n); };
		break;
		//Back
	case Math::EasingStyle::Back:
		param1 = Math::MaxF(0.0f, param1);
		function = [=](float n) { return (param1 + 1.0f) * n * n * n - param1 * n * n; };
		break;
		//Bounce
	case Math::EasingStyle::Bounce:
		if (param1 <= 0.0f) { param1 = 1.0f; }
		if (param2 <= 0.0f) { param2 = 1.0f; }
		function = [=](float n) { return exp(param1 * n) * fabs(cosf(2.0f * Math::pi * param2 * n)); };
		break;
		//Elastic
	case Math::EasingStyle::Elastic:
		if (param1 <= 0.0f) { param1 = 1.0f; }
		if (param2 <= 0.0f) { param2 = 1.0f; }
		function = [=](float n) { return exp(param1 * n) * cosf(2.0f * Math::pi * param2 * n); };
		break;
	}
	//Linear Remapping
	std::function<float(float)> easing = [=](float n) { return a + (b - a) * (function(0) - function(n)) / (function(0) - function(1)); };
	//Easing Direction Switch Statement
	switch (easingDirection) {
		//In
	case Math::EasingDirection::In:
		return easing(t);
		//Out
	case Math::EasingDirection::Out:
		return b - easing(1.0f - t) + a;
		//InOut
	default:
		if (t < 0.5f) {
			return (b - easing(1.0f - 2.0f * t)) / 2.0f + a;
		}
		else {
			return (easing(2.0f * t - 1.0f) + b) / 2.0f;
		}
	}
}
//================================================================================================================
//Kill Timer Formulas
//================================================================================================================
float Math::ExpDecay(float x0, float x1, float y0, float y1, float t) {
	std::function<float(float)> function = [=](float n) { return expf(-2.0f * n); };
	return y0 + (y1 - y0) * ((1.0f - function((t-x0)/(x1-x0))) / (1.0f - function(1.0f)));
}
float Math::SqrtDecay(float x0, float x1, float y0, float y1, float t) {
	std::function<float(float)> function = [=](float n) { return sqrtf(n); };
	return y0 + (y1 - y0) * ((0.0f - function((t - x0) / (x1 - x0))) / (0.0f - 1.0f));
}
//================================================================================================================
//TCHAR Arrays
//================================================================================================================
void Math::ToLowerTCHAR(TCHAR* str) {
	if (!str) { return; }
	for (int i = 0; str[i] != _T('\0'); i++) {
		str[i] = _totlower(str[i]);
	}
}
void Math::ToUpperTCHAR(TCHAR* str) {
	if (!str) { return; }
	for (int i = 0; str[i] != _T('\0'); i++) {
		str[i] = _totupper(str[i]);
	}
}
int Math::CompTCHAR(const TCHAR* arrA, const TCHAR* arrB) {
	TCHAR* a = _tcsdup(arrA);
	TCHAR* b = _tcsdup(arrB);
	int result = _tcscmp(a, b);
	free(a);
	free(b);
	return result;
}
int Math::UnsCompTCHAR(const TCHAR* arrA, const TCHAR* arrB) {
	TCHAR* a = _tcsdup(arrA);
	TCHAR* b = _tcsdup(arrB);
	Math::ToLowerTCHAR(a);
	Math::ToLowerTCHAR(b);
	int result = _tcscmp(a, b);
	free(a);
	free(b);
	return result;
}
//================================================================================================================
//Boolean
//================================================================================================================
int Math::ToBoolean(int input) {
	return (input == 0) ? 0 : 1;
}
int Math::NOT(int input) {
	return !(Math::ToBoolean(input)==1);
}
//================================================================================================================
//Randomization
//================================================================================================================
int	currentTimer = 0;
int randomSeed = 0;

void Math::SetupRNG() {
	randomSeed = 0;
	currentTimer = 0;
}

void Math::SetRandomSeed(int value) {
	randomSeed = value;
	if (value == 0) { return; }
	srand(value);
};

void Math::SetSeed() {
	if (randomSeed != 0) { return; }
	if (time(NULL) - currentTimer > MAX_TIMER_DIFFERENCE) {
		currentTimer = time(NULL);
		srand(currentTimer);
	}
}
int Math::RRandomI(int valueA, int valueB) {
	Math::SetSeed();
	int vA = valueA;
	int vB = valueB;
	if (valueB < valueA) { vA = valueB; vB = valueA; }
	return (rand() % (vB - vA + 1)) + vA;
}
float Math::RRandomF(float valueA, float valueB) {
	Math::SetSeed();
	int vA = valueA;
	int vB = valueB;
	if (valueB < valueA) { vA = valueB; vB = valueA; }
	int result = (rand() % (vB - vA)) + vA;
	int remainder = (rand() % ((int)pow(10, RRANDOM_DECIMAL_ACCURACY) - 1));
	return result + (float)remainder / pow(10, RRANDOM_DECIMAL_ACCURACY);
}
//================================================================================================================
