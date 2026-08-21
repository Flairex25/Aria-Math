#pragma once
#include "DarkEdif.hpp"
#include <algorithm>
#include <cmath>

//==============================================================================================================================================================
namespace Math {
	//============================================
	//Constants
	//============================================
	const float e = 2.718281828;
	const float pi = 3.141592653;
	const float tau = 6.283185307;
	const float phi = 1.618033988;
	const float gamma = 0.577215664;
	const float root2 = 1.414213562;
	const float root3 = 1.732050807;
	//============================================
	//Operations
	//============================================
	//Exponents
	float Exp_e(float power);
	float Exp_b(float power, float base);
	//Logs
	float Log_e(float argument);
	float Log_b(float argument, float base);
	//Clamps
	int MinI(int valueA, int valueB);
	float MinF(float valueA, float valueB);
	int MaxI(int valueA, int valueB);
	float MaxF(float valueA, float valueB);
	int ClampI(int value, int min, int max);
	float ClampF(float value, float min, float max);
	//Rounding
	int RoundI(float input);
	float RoundF(float input, int decimal);
	int FloorI(float input);
	float FloorF(float input, int decimal);
	int CeilI(float input);
	float CeilF(float input, int decimal);
	//Modulus
	float ModI(int input, int divisor);
	float ModF(float input, float divisor);
	//Absolute Value
	int AbsI(int input);
	int AbsF(float input);
	//Sign
	int Sign(int input);
	//Roots
	float Root2(float value);
	float RootN(float value, float radical);
	//Angles
	float ToRadians(int degrees);
	float ToDegrees(float radians);
	//Factorials
	int FactorialI(int input);
	float FactorialF(float input);
	//Easing
	enum EasingStyle {
		Constant,
		Linear,
		Polynomial,
		Exponential,
		Sine,
		Circular,
		Back,
		Bounce,
		Elastic
	};
	enum EasingDirection {
		In,
		Out,
		InOut
	};
	float Ease(float a, float b, float t, Math::EasingStyle easingStyle, Math::EasingDirection easingDirection, float p1 = 1.0f, float p2 = 1.0f);
	//Kill Timer Functions
	float ExpDecay(float x0, float x1, float y0, float y1, float t);
	float SqrtDecay(float x0, float x1, float y0, float y1, float t);
	//TCHAR Arrays
	void ToLowerTCHAR(TCHAR* input);
	void ToUpperTCHAR(TCHAR* input);
	int CompTCHAR(const TCHAR* arrA, const TCHAR* arrB);
	int UnsCompTCHAR(const TCHAR* arrA, const TCHAR* arrB);
	//Booleans
	int ToBoolean(int input);
	int NOT(int input);
	//Randomization
	void SetSeed();
	int RRandomI(int valueA, int valueB);
	float RRandomF(float valueA, float valueB);
}
//==============================================================================================================================================================
