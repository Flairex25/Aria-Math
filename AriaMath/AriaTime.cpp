//===================
#include "Common.hpp"
#include "AriaMath\AriaTime.hpp"
//===================================
#include <cmath>
#include <tchar.h>
#include <vector>
#include <ctime>
//============================
int timeHours = 0;
int timeMinutes = 0;
int timeSeconds = 0;
int timeMilliseconds = 0;
//============================
void AriaTime::FormatTime(int timeValue) {
	timeMilliseconds = timeValue % 1000;
	timeSeconds = (timeValue / 1000) % 60;
	timeMinutes = ((timeValue / 1000) / 60) % 60;
	timeHours = ((timeValue / 1000) / 60) / 60;
}
//============================
int AriaTime::GetHoursValue() { return timeHours; }
int AriaTime::GetMinutesValue() { return timeMinutes; }
int AriaTime::GetSecondsValue() { return timeSeconds; }
int AriaTime::GetMillisecondsValue() { return timeMilliseconds; }
//============================

const TCHAR* IntToString(int value)
{
	static TCHAR buffer[32];
	_stprintf_s(buffer, _T("%d"), value);
	return buffer;
}

const TCHAR* CombineStrings(const TCHAR* first, const TCHAR* second)
{
	static TCHAR buffer[1024];

	_tcscpy_s(buffer, first);
	_tcscat_s(buffer, second);

	return buffer;
}

const TCHAR* AriaTime::GetHoursValue$() {
	return IntToString(timeHours);
}
const TCHAR* AriaTime::GetMinutesValue$() {
	const TCHAR* returnStr = IntToString(timeMinutes);
	if (timeMinutes < 10) {
		return CombineStrings(_T("0"), returnStr);
	}
	else {
		return returnStr;
	}
}
const TCHAR* AriaTime::GetSecondsValue$() {
	const TCHAR* returnStr = IntToString(timeSeconds);
	if (timeSeconds < 10) {
		return CombineStrings(_T("0"), returnStr);
	}
	else {
		return returnStr;
	}
}
const TCHAR* AriaTime::GetMillisecondsValue$() {
	const TCHAR* returnStr = IntToString(timeMilliseconds);
	if (timeMilliseconds < 10) {
		return CombineStrings(_T("00"), returnStr);
	}
	else if (timeMilliseconds < 100) {
		return CombineStrings(_T("0"), returnStr);
	}
	else {
		return returnStr;
	}
}
const TCHAR* AriaTime::GetTimeString() {
	static TCHAR buffer[64];

	_stprintf_s(
		buffer,
		_countof(buffer),
		_T("%d:%02d:%02d.%03d"),
		timeHours,
		timeMinutes,
		timeSeconds,
		timeMilliseconds
	);

	return buffer;
}
//============================
int AriaTime::GetCurrentDay() {
	std::time_t now = std::time(nullptr);
	std::tm* localTime = std::localtime(&now);

	return localTime->tm_mday;
}
int AriaTime::GetCurrentMonth() {
	std::time_t now = std::time(nullptr);
	std::tm* localTime = std::localtime(&now);

	return localTime->tm_mon + 1;
}
int AriaTime::GetCurrentYear() {
	std::time_t now = std::time(nullptr);
	std::tm* localTime = std::localtime(&now);

	return localTime->tm_year + 1900;
}
const TCHAR* AriaTime::GetCurrentDate()
{
	static TCHAR buffer[32];

	_stprintf_s(
		buffer,
		_countof(buffer),
		_T("%02d/%02d/%04d"),
		AriaTime::GetCurrentMonth(),
		AriaTime::GetCurrentDay(),
		AriaTime::GetCurrentYear()
	);

	return buffer;
}
//============================
int AriaTime::GetCurrentHours() {
	std::time_t now = std::time(nullptr);
	std::tm* localTime = std::localtime(&now);

	return localTime->tm_hour;
}
int AriaTime::GetCurrentMinutes() {
	std::time_t now = std::time(nullptr);
	std::tm* localTime = std::localtime(&now);

	return localTime->tm_min;
}
int AriaTime::GetCurrentSeconds() {
	std::time_t now = std::time(nullptr);
	std::tm* localTime = std::localtime(&now);

	return localTime->tm_sec;
}
const TCHAR* AriaTime::GetCurrentTimeString()
{
	static TCHAR buffer[32];

	std::time_t now = std::time(nullptr);
	std::tm* localTime = std::localtime(&now);

	_stprintf_s(
		buffer,
		_countof(buffer),
		_T("%02d:%02d:%02d"),
		localTime->tm_hour,
		localTime->tm_min,
		localTime->tm_sec
	);

	return buffer;
}
//============================
