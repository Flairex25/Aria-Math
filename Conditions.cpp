#include "Common.hpp"

//=======================================================================================================================================================================================================
//DeltaTime/Ticks

bool Extension::cOnTick() {
	return true;
};

bool Extension::cIsGameSpeedPaused() {
	return true;
};

bool Extension::cOnGameSpeedPaused() {
	return true;
};

bool Extension::cOnGameSpeedResumed() {
	return true;
};

bool Extension::cOnGameSpeedChanged() {
	return true;
};

//=======================================================================================================================================================================================================
//Functions

bool Extension::cOnFunction(const TCHAR* functionID) {
	return (_tcscmp(functionID, currentFunctionID) == 0);
}

bool Extension::cFunctionLoopIndexEquals(const TCHAR* functionID, int loopIndex) {
	int functionLoopIndex = Functions::GetFromArray(functionID)->GetLoopIndex();
	return (loopIndex == functionLoopIndex);
}

//=======================================================================================================================================================================================================
//Integer Arrays

bool Extension::cOnIntegerArrayLoop(const TCHAR* arrayID) {
	if (!arrayID || !*arrayID) { return false; }
	if (!currentIntArrayLoopID || !*currentIntArrayLoopID) { return false; }
	return (_tcscmp(arrayID, currentIntArrayLoopID) == 0);
}

bool Extension::cIntegerArrayLoopIDEquals(const TCHAR* arrayID, const TCHAR* loopID) {
	const TCHAR* currentLoopID = IntegerArrays::GetFromArray(arrayID)->GetLoopID();
	if (!currentLoopID || !*currentLoopID) { return false; }
	if (!loopID || !*loopID) { return false; }
	return (_tcscmp(currentLoopID, loopID) == 0);
}

bool Extension::cCurrentIntegerArrayIndexEquals(const TCHAR* arrayID, int index) {
	int currentLoopIndex = IntegerArrays::GetFromArray(arrayID)->GetLoopIndex();
	return (index == currentLoopIndex);
}

bool Extension::cCurrentIntegerArrayValueEquals(const TCHAR* arrayID, int value) {
	IntArray* currentArray = IntegerArrays::GetFromArray(arrayID);
	std::vector<int> arr = currentArray->GetArray();
	int index = currentArray->GetLoopIndex();
	int currentValue = 0;
	if (index >= 0 && index < arr.size()) {
		currentValue = arr[index];
	}
	return (value == currentValue);
}

bool Extension::cValueExistsInIntegerArray(const TCHAR* arrayID, int value) {
	IntArray* currentArray = IntegerArrays::GetFromArray(arrayID);
	std::vector<int> arr = currentArray->GetArray();
	return std::find(arr.begin(), arr.end(), value) != arr.end();
}

//Float Arrays

bool Extension::cOnFloatArrayLoop(const TCHAR* arrayID) {
	if (!arrayID || !*arrayID) { return false; }
	if (!currentFloatArrayLoopID || !*currentFloatArrayLoopID) { return false; }
	return (_tcscmp(arrayID, currentFloatArrayLoopID) == 0);
}

bool Extension::cFloatArrayLoopIDEquals(const TCHAR* arrayID, const TCHAR* loopID) {
	const TCHAR* currentLoopID = FloatArrays::GetFromArray(arrayID)->GetLoopID();
	if (!currentLoopID || !*currentLoopID) { return false; }
	if (!loopID || !*loopID) { return false; }
	return (_tcscmp(currentLoopID, loopID) == 0);
}

bool Extension::cCurrentFloatArrayIndexEquals(const TCHAR* arrayID, int index) {
	int currentLoopIndex = FloatArrays::GetFromArray(arrayID)->GetLoopIndex();
	return (index == currentLoopIndex);
}

bool Extension::cCurrentFloatArrayValueEquals(const TCHAR* arrayID, float value) {
	FloatArray* currentArray = FloatArrays::GetFromArray(arrayID);
	std::vector<float> arr = currentArray->GetArray();
	int index = currentArray->GetLoopIndex();
	float currentValue = 0;
	if (index >= 0 && index < arr.size()) {
		currentValue = arr[index];
	}
	return (value == currentValue);
}

bool Extension::cValueExistsInFloatArray(const TCHAR* arrayID, float value) {
	FloatArray* currentArray = FloatArrays::GetFromArray(arrayID);
	std::vector<float> arr = currentArray->GetArray();
	return std::find(arr.begin(), arr.end(), value) != arr.end();
}

//String Array

bool Extension::cOnStringArrayLoop(const TCHAR* arrayID) {
	if (!arrayID || !*arrayID) { return false; }
	if (!currentStringArrayLoopID || !*currentStringArrayLoopID) { return false; }
	return (_tcscmp(arrayID, currentStringArrayLoopID) == 0);
}

bool Extension::cStringArrayLoopIDEquals(const TCHAR* arrayID, const TCHAR* loopID) {
	const TCHAR* currentLoopID = StringArrays::GetFromArray(arrayID)->GetLoopID();
	if (!currentLoopID || !*currentLoopID) { return false; }
	if (!loopID || !*loopID) { return false; }
	return (_tcscmp(currentLoopID, loopID) == 0);
}

bool Extension::cCurrentStringArrayIndexEquals(const TCHAR* arrayID, int index) {
	int currentLoopIndex = StringArrays::GetFromArray(arrayID)->GetLoopIndex();
	return (index == currentLoopIndex);
}

bool Extension::cCurrentStringArrayValueEquals(const TCHAR* arrayID, const TCHAR* value) {
	StringArray* currentArray = StringArrays::GetFromArray(arrayID);
	std::vector<const TCHAR*> arr = currentArray->GetArray();
	int index = currentArray->GetLoopIndex();
	const TCHAR* currentValue = 0;
	if (index >= 0 && index < arr.size()) {
		currentValue = arr[index];
	}
	return (value == currentValue);
}

bool Extension::cValueExistsInStringArray(const TCHAR* arrayID, const TCHAR* value) {
	StringArray* currentArray = StringArrays::GetFromArray(arrayID);
	std::vector<const TCHAR*> arr = currentArray->GetArray();
	bool existsInArray = false;
	for (int i = 0; i < arr.size(); i++) {
		currentArray = StringArrays::GetFromArray(arrayID);
		arr = currentArray->GetArray();
		if (_tcscmp(value, arr[i]) == 0) {
			existsInArray = true;
		}
	}
	return existsInArray;
}

//=======================================================================================================================================================================================================
//Runtime

bool Extension::cIsRunningInEditor() {
	return (DarkEdif::RunMode != DarkEdif::MFXRunMode::BuiltEXE);
}

bool Extension::cIsRunningInSubApplication() {
	return (rhPtr->get_App()->get_ParentApp() != nullptr);
}

//=======================================================================================================================================================================================================
