//===================
#include "AriaMath\AriaStrings.hpp"
//===================================
#include <cmath>
#include <tchar.h>
#include <string>
#include <vector>
//======================================================================
std::basic_string<TCHAR> stringStorage;
std::vector<const TCHAR*> stringArray;
//======================================================================
std::vector<const TCHAR*>& AriaStrings::ParseString(const TCHAR* string, const TCHAR* delimiters) {
	std::vector<const TCHAR*>().swap(stringArray); //Clears the current string array, setting the capacity to 0
	stringStorage = string ? string : _TEXT(""); //Sets the modifyable string to the current string input or an empty string if it doesnt exist

	if (!delimiters || !*delimiters) //If delimiters is empty, place the string into stringArray[0] and return
	{
		if (!stringStorage.empty())
			stringArray.push_back(stringStorage.c_str());

		return stringArray;
	}

	const size_t delimiterLength = _tcslen(delimiters); //Get size of delimiters
	size_t start = 0;

	while (start < stringStorage.length())
	{
		size_t pos = stringStorage.find(delimiters, start); //Find location of next delimiter

		if (pos == std::basic_string<TCHAR>::npos) //Break if no valid position was found
		{
			stringArray.push_back(stringStorage.c_str() + start);
			break;
		}

		stringStorage[pos] = _TEXT('\0'); //Replace delimiter with null terminator
		stringArray.push_back(stringStorage.c_str() + start); //Add string segment to vector

		start = pos + delimiterLength;
	}

	return stringArray;
}
//======================================================================
int AriaStrings::ToInt(const TCHAR* string)
{
	if (!string)
		return 0;

	return static_cast<int>(_tcstol(string, nullptr, 10));
}

float AriaStrings::ToFloat(const TCHAR* string)
{
	if (!string)
		return 0.0f;

	return _tcstof(string, nullptr);
}
//======================================================================
