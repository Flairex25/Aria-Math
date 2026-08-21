//==========
#pragma once
//=====================
#include "DarkEdif.hpp"
//=====================
#include <cmath>
#include <tchar.h>
#include <vector>
//================
namespace AriaTime {
	//
	void FormatTime(int timeMS);
	//
	int GetHoursValue();
	int GetMinutesValue();
	int GetSecondsValue();
	int GetMillisecondsValue();
	//
	const TCHAR* GetHoursValue$();
	const TCHAR* GetMinutesValue$();
	const TCHAR* GetSecondsValue$();
	const TCHAR* GetMillisecondsValue$();
	//
	const TCHAR* GetTimeString();
	//
	int GetCurrentDay();
	int GetCurrentMonth();
	int GetCurrentYear();
	const TCHAR* GetCurrentDate();
	//
	int GetCurrentHours();
	int GetCurrentMinutes();
	int GetCurrentSeconds();
	const TCHAR* GetCurrentTimeString();
	//
};
//================
