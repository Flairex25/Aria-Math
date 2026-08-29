#include "Common.hpp"
#include <vector>

//=======================================================================================================================================================================================================
//Time Formatting

void Extension::aFormatTimeString(int timeValue) { AriaTime::FormatTime(timeValue); }

//=======================================================================================================================================================================================================
//Randomization

void Extension::aSetRandomSeed(int randomSeed) {
	Math::SetRandomSeed(randomSeed);
}
//=====================================================
void Extension::aCreateBagRandomizer(const TCHAR* ID) {
	BagRandomization::RemoveFromArray(ID);
	BagRandomization::AddToArray(ID);
}

void Extension::aResetBagRandomizer(const TCHAR* ID) {
	BagRandomization::GetFromArray(ID)->Reset();
}

void Extension::aDeleteBagRandomizer(const TCHAR* ID) {
	BagRandomization::RemoveFromArray(ID);
}
//=====================================================
void Extension::aAddValueToBagRandomizer(const TCHAR* ID, int value) {
	BagRandomization::GetFromArray(ID)->AddToBag(value);
}

void Extension::aRemoveIndexFromBagRandomizer(const TCHAR* ID, int index) {
	BagRandomization::GetFromArray(ID)->RemoveFromBag(index);
}

//=======================================================================================================================================================================================================
//DeltaTime/Ticks

float prePauseGameSpeed = DeltaTime::GetGameSpeed();

void Extension::aEnableTicks() {

}

void Extension::aDisableTicks() {

}

void Extension::aCalculateDeltaTime(int timer) {
	DeltaTime::CalculateDeltaTime(timer);
}

void Extension::aSetDeltaTimeBase(int deltaTimeBase) {
	DeltaTime::SetTimeScale(deltaTimeBase);
}

void Extension::aSetGameSpeed(float gameSpeed) {
	float oldGameSpeed = DeltaTime::SetGameSpeed(gameSpeed);

	if (DeltaTime::GetGameSpeedUpdateFlag()) {

		//Generate On GamePaused
		if (DeltaTime::GetGameSpeed() == 0) {
			prePauseGameSpeed = oldGameSpeed;
			Runtime.GenerateEvent(2);
		}
		//Generate On Game Resumed
		if (oldGameSpeed == 0) {
			Runtime.GenerateEvent(3);
		}
		//Generate OnGameSpeedChanged
		Runtime.GenerateEvent(4);
	}
}

void Extension::aPauseGameSpeed() {
	DeltaTime::SetGameSpeed(0.0f);
}

void Extension::aResumeGameSpeed() {
	DeltaTime::SetGameSpeed(prePauseGameSpeed);
}

void Extension::aSetTickRate(int tickRate) {

}

void Extension::aSetOldTimer(int oldTimer) {
	DeltaTime::SetOldTimer(oldTimer);
}

//=======================================================================================================================================================================================================
//Function Parameters

void Extension::aSetFunctionIntegerParameter(const TCHAR* functionID, const TCHAR* paramID, int paramValue) {
	Functions::AddToArray(functionID);
	AriaFunction* currentFucntion = Functions::GetFromArray(functionID);
	currentFucntion->SetIntParam(paramID, paramValue);
}

void Extension::aSetFunctionFloatParameter(const TCHAR* functionID, const TCHAR* paramID, float paramValue) {
	Functions::AddToArray(functionID);
	AriaFunction* currentFucntion = Functions::GetFromArray(functionID);
	currentFucntion->SetFloatParam(paramID, paramValue);
}

void Extension::aSetFunctionStringParameter(const TCHAR* functionID, const TCHAR* paramID, const TCHAR* paramValue) {
	Functions::AddToArray(functionID);
	AriaFunction* currentFucntion = Functions::GetFromArray(functionID);
	currentFucntion->SetStringParam(paramID, paramValue);
}

//Function Returns

void Extension::aSetFunctionIntegerReturn(const TCHAR* functionID, int returnValue) {
	Functions::AddToArray(functionID);
	AriaFunction* currentFunction = Functions::GetFromArray(functionID);
	currentFunction->SetIntReturn(returnValue);
}

void Extension::aSetFunctionFloatReturn(const TCHAR* functionID, float returnValue) {
	Functions::AddToArray(functionID);
	AriaFunction* currentFunction = Functions::GetFromArray(functionID);
	currentFunction->SetFloatReturn(returnValue);
}

void Extension::aSetFunctionStringReturn(const TCHAR* functionID, const TCHAR* returnValue) {
	Functions::AddToArray(functionID);
	AriaFunction* currentFunction = Functions::GetFromArray(functionID);
	currentFunction->SetStringReturn(returnValue);
}

//Functions

void SetFunctionParam(const TCHAR* functionID, const TCHAR* formattedParam) {
	if (!formattedParam || !*formattedParam) { return; }
	if (_tcscmp(formattedParam, _T("")) == 0) { return; }
	std::vector<const TCHAR*>& paramArr = AriaStrings::ParseString(formattedParam, _T("-"));
	const TCHAR* paramID = _T("");
	const TCHAR* paramType = _T("");
	const TCHAR* paramValue = _T("");
	if (paramArr.size() > 0) { paramID = paramArr[0]; }
	if (paramArr.size() > 1) { paramType = paramArr[1]; }
	if (paramArr.size() > 2) { paramValue = paramArr[2]; }
	LOGI(paramID);
	LOGI(_T("\n"));
	LOGI(paramType);
	LOGI(_T("\n"));
	if ((Math::UnsCompTCHAR(paramType, _T("int")) == 0) || (Math::UnsCompTCHAR(paramType, _T("integer")) == 0)) {

		TCHAR buffer[32];
		_stprintf_s(buffer, _countof(buffer), TEXT("%d"), AriaStrings::ToInt(paramValue));
		LOGI(buffer);
		LOGI(_T("\n"));
		Functions::GetFromArray(functionID)->SetIntParam(paramID, AriaStrings::ToInt(paramValue));
	}
	if ((Math::UnsCompTCHAR(paramType, _T("flt")) == 0) || (Math::UnsCompTCHAR(paramType, _T("float")) == 0)) {

		TCHAR buffer[32];
		_stprintf_s(buffer, _countof(buffer), TEXT("%f"), AriaStrings::ToFloat(paramValue));
		LOGI(buffer);
		LOGI(_T("\n"));
		Functions::GetFromArray(functionID)->SetFloatParam(paramID, AriaStrings::ToFloat(paramValue));
	}
	if ((Math::UnsCompTCHAR(paramType, _T("str")) == 0) || (Math::UnsCompTCHAR(paramType, _T("string")) == 0)) {
		LOGI(paramValue);
		LOGI(_T("\n"));
		Functions::GetFromArray(functionID)->SetStringParam(paramID, paramValue);
	}
}

void Extension::aCallFunction(const TCHAR* functionID, int deleteParams) {
	Functions::AddToArray(functionID);
	AriaFunction* currentFunction = Functions::GetFromArray(functionID);
	currentFunctionID = functionID;
	Runtime.GenerateEvent(5);
	if (deleteParams != 0) {
		currentFunction->DeleteAllParams();
	}
}

void Extension::aCallFunctionLoop(const TCHAR* functionID, int repetitions, int deleteParams) {
	repetitions = Math::MaxI(repetitions, 1);
	AriaFunction* currentFunction = Functions::GetFromArray(functionID);
	currentFunction->SetLoopIndex(0);
	currentFunction->SetLoopAmount(repetitions);
	currentFunction->SetIsPaused(false);
	for (int i = 0; i < currentFunction->GetLoopAmount() && !currentFunction->IsPaused(); i++) {
		currentFunction = Functions::GetFromArray(functionID);
		currentFunctionID = functionID;
		currentFunction->SetLoopIndex(i);
		Runtime.GenerateEvent(5);
	}
	if (!currentFunction->IsPaused()) {
		currentFunction = Functions::GetFromArray(functionID);
		currentFunction->SetLoopIndex(0);
		currentFunction->SetLoopAmount(0);
	}
	if (!currentFunction->IsPaused() && (deleteParams != 0)) {
		currentFunction->DeleteAllParams();
		Functions::RemoveFromArray(functionID);
	}
}

void Extension::aCallFunctionImmediate(const TCHAR* functionID, int deleteParams, const TCHAR* param1, const TCHAR* param2, const TCHAR* param3, const TCHAR* param4, const TCHAR* param5) {
	Functions::AddToArray(functionID);
	AriaFunction* currentFunction = Functions::GetFromArray(functionID);

	SetFunctionParam(functionID, param1);
	SetFunctionParam(functionID, param2);
	SetFunctionParam(functionID, param3);
	SetFunctionParam(functionID, param4);
	SetFunctionParam(functionID, param5);

	currentFunctionID = functionID;
	Runtime.GenerateEvent(5);
	if (deleteParams != 0) {
		currentFunction->DeleteAllParams();
		Functions::RemoveFromArray(functionID);
	}
}

void Extension::aResumeFunctionLoop(const TCHAR* functionID, int deleteParams) {
	AriaFunction* currentFunction = Functions::GetFromArray(functionID);
	currentFunction->SetIsPaused(false);
	if ((currentFunction->GetLoopAmount() == 0) || (currentFunction->GetLoopIndex() >= currentFunction->GetLoopAmount())) {
		return;
	}
	for (int i = currentFunction->GetLoopIndex()+1; i < currentFunction->GetLoopAmount() && !currentFunction->IsPaused(); i++) {
		currentFunction = Functions::GetFromArray(functionID);
		currentFunctionID = functionID;
		currentFunction->SetLoopIndex(i);
		Runtime.GenerateEvent(5);
	}
	if (!currentFunction->IsPaused()) {
		currentFunction = Functions::GetFromArray(functionID);
		currentFunction->SetLoopIndex(0);
		currentFunction->SetLoopAmount(0);
	}
	if (!currentFunction->IsPaused() && (deleteParams != 0)) {
		currentFunction->DeleteAllParams();
		Functions::RemoveFromArray(functionID);
	}
}

void Extension::aStopFunctionLoop(const TCHAR* functionID) {
	AriaFunction* currentFunction = Functions::GetFromArray(functionID);
	currentFunction->SetIsPaused(true);
}

void Extension::aSetFunctionLoopIndex(const TCHAR* functionID, int loopIndex) {
	AriaFunction* currentFunction = Functions::GetFromArray(functionID);
	currentFunction->SetLoopIndex(Math::ClampI(loopIndex,0,currentFunction->GetLoopAmount()));
}

//=======================================================================================================================================================================================================
//Integer Arrays

void Extension::aCreateIntegerArray(const TCHAR* ID) {
	IntegerArrays::AddToArray(ID);
}

void Extension::aDeleteIntegerArray(const TCHAR* ID) {
	IntegerArrays::RemoveFromArray(ID);
}

void Extension::aSetIntegerArrayElement(const TCHAR* ID, int index, int value) {
	//IntegerArrays::AddToArray(ID);
	index = Math::MaxI(index, 0);
	for (int i = 0; i <= index; i++) {
		IntArray* currentArray = IntegerArrays::GetFromArray(ID);
		std::vector<int> arr = currentArray->GetArray();
		if (i >= arr.size()) {
			arr.emplace_back();
			arr[i] = 0;
			currentArray->SetArray(arr);
		}
	}
	IntArray* currentArray = IntegerArrays::GetFromArray(ID);
	std::vector<int> arr = currentArray->GetArray();
	arr[index] = value;
	currentArray->SetArray(arr);
}

void Extension::aDeleteIntegerArrayElement(const TCHAR* ID, int index) {
	IntArray* currentArray = IntegerArrays::GetFromArray(ID);
	std::vector<int> arr = currentArray->GetArray();
	if (arr.size() == 0) { return; }
	if (index < 0 || index >= arr.size()) { return; }
	arr.erase(arr.begin() + index);
	currentArray->SetArray(arr);
}

void Extension::aSortIntegerArrayAscending(const TCHAR* ID) {
	IntArray* currentArray = IntegerArrays::GetFromArray(ID);
	std::vector<int> arr = currentArray->GetArray();
	std::sort(arr.begin(), arr.end());
	currentArray->SetArray(arr);
}

void Extension::aSortIntegerArrayDescending(const TCHAR* ID) {
	IntArray* currentArray = IntegerArrays::GetFromArray(ID);
	std::vector<int> arr = currentArray->GetArray();
	std::sort(arr.begin(), arr.end(), std::greater<int>());
	currentArray->SetArray(arr);
}

void Extension::aLoopThroughIntegerArray(const TCHAR* ID) {
	IntArray* currentArray = IntegerArrays::GetFromArray(ID);
	std::vector<int> arr = currentArray->GetArray();
	if (arr.size() == 0) { return; }
	currentArray->SetIsReverse(false);
	currentArray->SetIsPaused(false);
	currentArray->SetLoopAmount(arr.size());
	currentArray->SetLoopIndex(0);
	for (int i = currentArray->GetLoopIndex(); i < currentArray->GetArray().size() && !currentArray->IsPaused(); i++) {
		currentArray = IntegerArrays::GetFromArray(ID);
		currentIntArrayLoopID = ID;
		currentArray->SetLoopIndex(i);
		Runtime.GenerateEvent(7);
	}
	if (!currentArray->IsPaused()) {
		currentArray = IntegerArrays::GetFromArray(ID);
		currentArray->SetLoopIndex(0);
		currentArray->SetLoopAmount(0);
	}
}

void Extension::aLoopThroughIntegerArrayReverse(const TCHAR* ID) {
	IntArray* currentArray = IntegerArrays::GetFromArray(ID);
	std::vector<int> arr = currentArray->GetArray();
	if (arr.size() == 0) { return; }
	currentArray->SetIsReverse(true);
	currentArray->SetIsPaused(false);
	currentArray->SetLoopAmount(arr.size());
	currentArray->SetLoopIndex(currentArray->GetLoopAmount() - 1);
	for (int i = currentArray->GetLoopIndex(); i >= 0 && !currentArray->IsPaused(); i--) {
		currentArray = IntegerArrays::GetFromArray(ID);
		currentIntArrayLoopID = ID;
		currentArray->SetLoopIndex(i);
		if (i < currentArray->GetArray().size()) {
			Runtime.GenerateEvent(7);
		}
	}
	if (!currentArray->IsPaused()) {
		currentArray = IntegerArrays::GetFromArray(ID);
		currentArray->SetLoopIndex(0);
		currentArray->SetLoopAmount(0);
	}
}

void Extension::aSetIntegerArrayLoopID(const TCHAR* arrayID, const TCHAR* loopID) {
	IntegerArrays::GetFromArray(arrayID)->SetLoopID(_tcsdup(loopID));
}

void Extension::aParseStringToIntArray(const TCHAR* arrayID, const TCHAR* str, const TCHAR* delimiters) {
	IntArray* currentArray = IntegerArrays::GetFromArray(arrayID);
	currentArray->SetIsPaused(true);
	currentArray->SetLoopAmount(0);
	currentArray->SetLoopIndex(0);
	std::vector<int> arr;
	std::vector<const TCHAR*>& splitString = AriaStrings::ParseString(str, delimiters);
	if (splitString.size() == 0) { return; }
	for (int i = 0; i < splitString.size(); i++) {
		arr.push_back(AriaStrings::ToInt(splitString[i]));
	}
	currentArray->SetArray(arr);
}

void Extension::aResumeIntegerArrayLoop(const TCHAR* ID) {
	IntArray* currentArray = IntegerArrays::GetFromArray(ID);
	std::vector<int> arr = currentArray->GetArray();
	currentArray->SetIsPaused(false);
	if (arr.size() == 0) { return; }
	if ((currentArray->GetLoopAmount() == 0) || (currentArray->GetLoopIndex() >= currentArray->GetLoopAmount())) {
		return;
	}
	if (!currentArray->IsReverse()) {
		for (int i = currentArray->GetLoopIndex(); i < currentArray->GetArray().size() && !currentArray->IsPaused(); i++) {
			currentArray = IntegerArrays::GetFromArray(ID);
			currentArray->SetLoopAmount(currentArray->GetArray().size());
			currentIntArrayLoopID = ID;
			currentArray->SetLoopIndex(i);
			Runtime.GenerateEvent(7);
		}
	}
	else {
		for (int i = currentArray->GetLoopIndex() - 1; i >= 0 && !currentArray->IsPaused(); i--) {
			currentArray = IntegerArrays::GetFromArray(ID);
			currentIntArrayLoopID = ID;
			currentArray->SetLoopIndex(i);
			if (i < currentArray->GetArray().size()) {
				Runtime.GenerateEvent(7);
			}
		}
	}
	if (!currentArray->IsPaused()) {
		currentArray = IntegerArrays::GetFromArray(ID);
		currentArray->SetLoopIndex(0);
		currentArray->SetLoopAmount(0);
	}
}

void Extension::aStopIntegerArrayLoop(const TCHAR* ID) {
	IntArray* currentArray = IntegerArrays::GetFromArray(ID);
	currentArray->SetIsPaused(true);
}

void Extension::aSetIntegerArrayLoopIndex(const TCHAR* ID, int loopIndex) {
	IntArray* currentArray = IntegerArrays::GetFromArray(ID);
	currentArray->SetLoopIndex(Math::ClampI(loopIndex, 0, currentArray->GetLoopAmount()));
}

//Float Arrays

void Extension::aCreateFloatArray(const TCHAR* ID) {
	FloatArrays::AddToArray(ID);
}

void Extension::aDeleteFloatArray(const TCHAR* ID) {
	FloatArrays::RemoveFromArray(ID);
}

void Extension::aSetFloatArrayElement(const TCHAR* ID, int index, float value) {
	//FloatArrays::AddToArray(ID);
	index = Math::MaxI(index, 0);
	for (int i = 0; i <= index; i++) {
		FloatArray* currentArray = FloatArrays::GetFromArray(ID);
		std::vector<float> arr = currentArray->GetArray();
		if (i >= arr.size()) {
			arr.emplace_back();
			arr[i] = 0.0f;
			currentArray->SetArray(arr);
		}
	}
	FloatArray* currentArray = FloatArrays::GetFromArray(ID);
	std::vector<float> arr = currentArray->GetArray();
	arr[index] = value;
	currentArray->SetArray(arr);
}

void Extension::aDeleteFloatArrayElement(const TCHAR* ID, int index) {
	FloatArray* currentArray = FloatArrays::GetFromArray(ID);
	std::vector<float> arr = currentArray->GetArray();
	if (arr.size() == 0) { return; }
	if (index < 0 || index >= arr.size()) { return; }
	arr.erase(arr.begin() + index);
	currentArray->SetArray(arr);
}

void Extension::aSortFloatArrayAscending(const TCHAR* ID) {
	FloatArray* currentArray = FloatArrays::GetFromArray(ID);
	std::vector<float> arr = currentArray->GetArray();
	std::sort(arr.begin(), arr.end());
	currentArray->SetArray(arr);
}

void Extension::aSortFloatArrayDescending(const TCHAR* ID) {
	FloatArray* currentArray = FloatArrays::GetFromArray(ID);
	std::vector<float> arr = currentArray->GetArray();
	std::sort(arr.begin(), arr.end(), std::greater<int>());
	currentArray->SetArray(arr);
}

void Extension::aLoopThroughFloatArray(const TCHAR* ID) {
	FloatArray* currentArray = FloatArrays::GetFromArray(ID);
	std::vector<float> arr = currentArray->GetArray();
	if (arr.size() == 0) { return; }
	currentArray->SetIsReverse(false);
	currentArray->SetIsPaused(false);
	currentArray->SetLoopAmount(arr.size());
	currentArray->SetLoopIndex(0);
	for (int i = currentArray->GetLoopIndex(); i < currentArray->GetArray().size() && !currentArray->IsPaused(); i++) {
		currentArray = FloatArrays::GetFromArray(ID);
		currentFloatArrayLoopID = ID;
		currentArray->SetLoopIndex(i);
		Runtime.GenerateEvent(12);
	}
	if (!currentArray->IsPaused()) {
		currentArray = FloatArrays::GetFromArray(ID);
		currentArray->SetLoopIndex(0);
		currentArray->SetLoopAmount(0);
	}
}

void Extension::aLoopThroughFloatArrayReverse(const TCHAR* ID) {
	FloatArray* currentArray = FloatArrays::GetFromArray(ID);
	std::vector<float> arr = currentArray->GetArray();
	if (arr.size() == 0) { return; }
	currentArray->SetIsReverse(true);
	currentArray->SetIsPaused(false);
	currentArray->SetLoopAmount(arr.size());
	currentArray->SetLoopIndex(currentArray->GetLoopAmount() - 1);
	for (int i = currentArray->GetLoopIndex(); i >= 0 && !currentArray->IsPaused(); i--) {
		currentArray = FloatArrays::GetFromArray(ID);
		currentFloatArrayLoopID = ID;
		currentArray->SetLoopIndex(i);
		if (i < currentArray->GetArray().size()) {
			Runtime.GenerateEvent(12);
		}
	}
	if (!currentArray->IsPaused()) {
		currentArray = FloatArrays::GetFromArray(ID);
		currentArray->SetLoopIndex(0);
		currentArray->SetLoopAmount(0);
	}
}

void Extension::aSetFloatArrayLoopID(const TCHAR* arrayID, const TCHAR* loopID) {
	FloatArrays::GetFromArray(arrayID)->SetLoopID(_tcsdup(loopID));
}

void Extension::aParseStringToFloatArray(const TCHAR* arrayID, const TCHAR* str, const TCHAR* delimiters) {
	FloatArray* currentArray = FloatArrays::GetFromArray(arrayID);
	currentArray->SetIsPaused(true);
	currentArray->SetLoopAmount(0);
	currentArray->SetLoopIndex(0);
	std::vector<float> arr;
	std::vector<const TCHAR*>& splitString = AriaStrings::ParseString(str, delimiters);
	if (splitString.size() == 0) { return; }
	for (int i = 0; i < splitString.size(); i++) {
		arr.push_back(AriaStrings::ToFloat(splitString[i]));
	}
	currentArray->SetArray(arr);
}

void Extension::aResumeFloatArrayLoop(const TCHAR* ID) {
	FloatArray* currentArray = FloatArrays::GetFromArray(ID);
	std::vector<float> arr = currentArray->GetArray();
	currentArray->SetIsPaused(false);
	if (arr.size() == 0) { return; }
	if ((currentArray->GetLoopAmount() == 0) || (currentArray->GetLoopIndex() >= currentArray->GetLoopAmount())) {
		return;
	}
	if (!currentArray->IsReverse()) {
		for (int i = currentArray->GetLoopIndex(); i < currentArray->GetArray().size() && !currentArray->IsPaused(); i++) {
			currentArray = FloatArrays::GetFromArray(ID);
			currentFloatArrayLoopID = ID;
			currentArray->SetLoopIndex(i);
			Runtime.GenerateEvent(12);
		}
	}
	else {
		for (int i = currentArray->GetLoopIndex() - 1; i >= 0 && !currentArray->IsPaused(); i--) {
			currentArray = FloatArrays::GetFromArray(ID);
			currentFloatArrayLoopID = ID;
			currentArray->SetLoopIndex(i);
			if (i < currentArray->GetArray().size()) {
				Runtime.GenerateEvent(12);
			}
		}
	}
	if (!currentArray->IsPaused()) {
		currentArray = FloatArrays::GetFromArray(ID);
		currentArray->SetLoopIndex(0);
		currentArray->SetLoopAmount(0);
	}
}

void Extension::aStopFloatArrayLoop(const TCHAR* ID) {
	FloatArray* currentArray = FloatArrays::GetFromArray(ID);
	currentArray->SetIsPaused(true);
}

void Extension::aSetFloatArrayLoopIndex(const TCHAR* ID, int loopIndex) {
	FloatArray* currentArray = FloatArrays::GetFromArray(ID);
	currentArray->SetLoopIndex(Math::ClampI(loopIndex, 0, currentArray->GetLoopAmount()));
}

//String Arrays

void Extension::aCreateStringArray(const TCHAR* ID) {
	StringArrays::AddToArray(ID);
}

void Extension::aDeleteStringArray(const TCHAR* ID) {
	StringArrays::RemoveFromArray(ID);
}

void Extension::aSetStringArrayElement(const TCHAR* ID, int index, const TCHAR* value) {
	//StringArrays::AddToArray(ID);
	index = Math::MaxI(index, 0);
	for (int i = 0; i <= index; i++) {
		StringArray* currentArray = StringArrays::GetFromArray(ID);
		std::vector<const TCHAR*> arr = currentArray->GetArray();
		if (i >= arr.size()) {
			arr.emplace_back();
			arr[i] = _tcsdup(_T(""));
			currentArray->SetArray(arr);
		}
	}
	StringArray* currentArray = StringArrays::GetFromArray(ID);
	std::vector<const TCHAR*> arr = currentArray->GetArray();
	arr[index] = _tcsdup(value);
	currentArray->SetArray(arr);
}

void Extension::aDeleteStringArrayElement(const TCHAR* ID, int index) {
	StringArray* currentArray = StringArrays::GetFromArray(ID);
	std::vector<const TCHAR*> arr = currentArray->GetArray();
	if (arr.size() == 0) { return; }
	if (index < 0 || index >= arr.size()) { return; }
	free((void*)arr[index]);
	arr.erase(arr.begin() + index);
	currentArray->SetArray(arr);
}

void Extension::aSortStringArrayLengthAscending(const TCHAR* ID) {
	StringArray* currentArray = StringArrays::GetFromArray(ID);
	std::vector<const TCHAR*> arr = currentArray->GetArray();
	std::sort(arr.begin(), arr.end(),
		[](const TCHAR* a, const TCHAR* b) {
			return _tcslen(a) < _tcslen(b);
		}
	);
	currentArray->SetArray(arr);
}

void Extension::aSortStringArrayLengthDescending(const TCHAR* ID) {
	StringArray* currentArray = StringArrays::GetFromArray(ID);
	std::vector<const TCHAR*> arr = currentArray->GetArray();
	std::sort(arr.begin(), arr.end(),
		[](const TCHAR* a, const TCHAR* b) {
			return _tcslen(a) > _tcslen(b);
		}
	);
	currentArray->SetArray(arr);
}

void Extension::aSortStringArrayAlphabeticalAscending(const TCHAR* ID) {
	StringArray* currentArray = StringArrays::GetFromArray(ID);
	std::vector<const TCHAR*> arr = currentArray->GetArray();
	std::sort(arr.begin(), arr.end(),
		[](const TCHAR* a, const TCHAR* b) {
			return _tcscmp(a,b) < 0;
		}
	);
	currentArray->SetArray(arr);
}

void Extension::aSortStringArrayAlphabeticalDescending(const TCHAR* ID) {
	StringArray* currentArray = StringArrays::GetFromArray(ID);
	std::vector<const TCHAR*> arr = currentArray->GetArray();
	std::sort(arr.begin(), arr.end(),
		[](const TCHAR* a, const TCHAR* b) {
			return _tcscmp(a, b) > 0;
		}
	);
	currentArray->SetArray(arr);
}

void Extension::aLoopThroughStringArray(const TCHAR* ID) {
	StringArray* currentArray = StringArrays::GetFromArray(ID);
	std::vector<const TCHAR*> arr = currentArray->GetArray();
	if (arr.size() == 0) { return; }
	currentArray->SetIsReverse(false);
	currentArray->SetIsPaused(false);
	currentArray->SetLoopAmount(arr.size());
	currentArray->SetLoopIndex(0);
	for (int i = currentArray->GetLoopIndex(); i < currentArray->GetArray().size() && !currentArray->IsPaused(); i++) {
		currentArray = StringArrays::GetFromArray(ID);
		currentStringArrayLoopID = ID;
		currentArray->SetLoopIndex(i);
		Runtime.GenerateEvent(17);
	}
	if (!currentArray->IsPaused()) {
		currentArray = StringArrays::GetFromArray(ID);
		currentArray->SetLoopIndex(0);
		currentArray->SetLoopAmount(0);
	}
}

void Extension::aLoopThroughStringArrayReverse(const TCHAR* ID) {
	StringArray* currentArray = StringArrays::GetFromArray(ID);
	std::vector<const TCHAR*> arr = currentArray->GetArray();
	if (arr.size() == 0) { return; }
	currentArray->SetIsReverse(true);
	currentArray->SetIsPaused(false);
	currentArray->SetLoopAmount(arr.size());
	currentArray->SetLoopIndex(currentArray->GetLoopAmount() - 1);
	for (int i = currentArray->GetLoopIndex(); i >= 0 && !currentArray->IsPaused(); i--) {
		currentArray = StringArrays::GetFromArray(ID);
		currentStringArrayLoopID = ID;
		currentArray->SetLoopIndex(i);
		if (i < currentArray->GetArray().size()) {
			Runtime.GenerateEvent(17);
		}
	}
	if (!currentArray->IsPaused()) {
		currentArray = StringArrays::GetFromArray(ID);
		currentArray->SetLoopIndex(0);
		currentArray->SetLoopAmount(0);
	}
}

void Extension::aSetStringArrayLoopID(const TCHAR* arrayID, const TCHAR* loopID) {
	StringArrays::GetFromArray(arrayID)->SetLoopID(_tcsdup(loopID));
}

void Extension::aParseStringToStringArray(const TCHAR* arrayID, const TCHAR* str, const TCHAR* delimiters) {
	StringArray* currentArray = StringArrays::GetFromArray(arrayID);
	LOGI(arrayID);
	currentArray->SetIsPaused(true);
	currentArray->SetLoopAmount(0);
	currentArray->SetLoopIndex(0);
	std::vector<const TCHAR*> arr = currentArray->GetArray();
	for (const TCHAR* str : arr) {
		free((void*)str);
	}
	std::vector<const TCHAR*>().swap(arr);
	std::vector<const TCHAR*>& splitString = AriaStrings::ParseString(str, delimiters);
	if (splitString.size() == 0) { return; }
	for (int i = 0; i < splitString.size(); i++) {
		arr.push_back(_tcsdup(splitString[i]));
	}
	currentArray->SetArray(arr);
}

void Extension::aResumeStringArrayLoop(const TCHAR* ID) {
	StringArray* currentArray = StringArrays::GetFromArray(ID);
	std::vector<const TCHAR*> arr = currentArray->GetArray();
	currentArray->SetIsPaused(false);
	if (arr.size() == 0) { return; }
	if ((currentArray->GetLoopAmount() == 0) || (currentArray->GetLoopIndex() >= currentArray->GetLoopAmount())) {
		return;
	}
	if (!currentArray->IsReverse()) {
		for (int i = currentArray->GetLoopIndex(); i < currentArray->GetArray().size() && !currentArray->IsPaused(); i++) {
			currentArray = StringArrays::GetFromArray(ID);
			currentStringArrayLoopID = ID;
			currentArray->SetLoopIndex(i);
			Runtime.GenerateEvent(17);
		}
	}
	else {
		for (int i = currentArray->GetLoopIndex() - 1; i >= 0 && !currentArray->IsPaused(); i--) {
			currentArray = StringArrays::GetFromArray(ID);
			currentStringArrayLoopID = ID;
			currentArray->SetLoopIndex(i);
			if (i < currentArray->GetArray().size()) {
				Runtime.GenerateEvent(17);
			}
		}
	}
	if (!currentArray->IsPaused()) {
		currentArray = StringArrays::GetFromArray(ID);
		currentArray->SetLoopIndex(0);
		currentArray->SetLoopAmount(0);
	}
}

void Extension::aStopStringArrayLoop(const TCHAR* ID) {

}

void Extension::aSetStringArrayLoopIndex(const TCHAR* ID, int loopIndex) {

}

//=======================================================================================================================================================================================================
//Vector2

void Extension::aCreateVector2(const TCHAR* vectorID, float valueX, float valueY) {
	TwoDVectors::AddToArray(vectorID);
	Vector2* newVector = TwoDVectors::GetFromArray(vectorID);
	newVector->SetX(valueX);
	newVector->SetY(valueY);
}

void Extension::aDeleteVector2(const TCHAR* vectorID) {
	TwoDVectors::RemoveFromArray(vectorID);
}

void Extension::aSetVector2X(const TCHAR* vectorID, float value) {
	TwoDVectors::AddToArray(vectorID);
	Vector2* currentVector = TwoDVectors::GetFromArray(vectorID);
	currentVector->SetX(value);
}

void Extension::aSetVector2Y(const TCHAR* vectorID, float value) {
	TwoDVectors::AddToArray(vectorID);
	Vector2* currentVector = TwoDVectors::GetFromArray(vectorID);
	currentVector->SetY(value);
}

void Extension::aScaleVector2(const TCHAR* vectorID, float scalar, const TCHAR* newVectorID) {
	TwoDVectors::AddToArray(newVectorID);
	Vector2* currentVector = TwoDVectors::GetFromArray(vectorID);
	Vector2* newVector = TwoDVectors::GetFromArray(newVectorID);
	newVector->SetX(currentVector->GetX() * scalar);
	newVector->SetY(currentVector->GetY() * scalar);
}

void Extension::aUnitVector2(const TCHAR* vectorID, const TCHAR* newVectorID) {
	TwoDVectors::AddToArray(newVectorID);
	Vector2* currentVector = TwoDVectors::GetFromArray(vectorID);
	Vector2* newVector = TwoDVectors::GetFromArray(newVectorID);

	float x = currentVector->GetX();
	float y = currentVector->GetY();
	float magnitude = sqrtf(x * x + y * y);

	x /= magnitude;
	y /= magnitude;

	if (magnitude > 0) {
		newVector->SetX(x);
		newVector->SetY(y);
	}
	else
	{
		newVector->SetX(0.0f);
		newVector->SetY(0.0f);
	}
}

void Extension::aAddVector2(const TCHAR* vectorID1, const TCHAR* vectorID2, const TCHAR* newVectorID) {
	TwoDVectors::AddToArray(newVectorID);
	Vector2* currentVector1 = TwoDVectors::GetFromArray(vectorID1);
	Vector2* currentVector2 = TwoDVectors::GetFromArray(vectorID2);
	Vector2* newVector = TwoDVectors::GetFromArray(newVectorID);

	float x1 = currentVector1->GetX();
	float y1 = currentVector1->GetY();
	float x2 = currentVector2->GetX();
	float y2 = currentVector2->GetY();

	newVector->SetX(x1 + x2);
	newVector->SetY(y1 + y2);
}

void Extension::aSubtractVector2(const TCHAR* vectorID1, const TCHAR* vectorID2, const TCHAR* newVectorID) {
	TwoDVectors::AddToArray(newVectorID);
	Vector2* currentVector1 = TwoDVectors::GetFromArray(vectorID1);
	Vector2* currentVector2 = TwoDVectors::GetFromArray(vectorID2);
	Vector2* newVector = TwoDVectors::GetFromArray(newVectorID);

	float x1 = currentVector1->GetX();
	float y1 = currentVector1->GetY();
	float x2 = currentVector2->GetX();
	float y2 = currentVector2->GetY();

	newVector->SetX(x1 - x2);
	newVector->SetY(y1 - y2);
}

void Extension::aMultiplyVector2(const TCHAR* vectorID1, const TCHAR* vectorID2, const TCHAR* newVectorID) {
	TwoDVectors::AddToArray(newVectorID);
	Vector2* currentVector1 = TwoDVectors::GetFromArray(vectorID1);
	Vector2* currentVector2 = TwoDVectors::GetFromArray(vectorID2);
	Vector2* newVector = TwoDVectors::GetFromArray(newVectorID);

	float x1 = currentVector1->GetX();
	float y1 = currentVector1->GetY();
	float x2 = currentVector2->GetX();
	float y2 = currentVector2->GetY();

	newVector->SetX(x1 * x2);
	newVector->SetY(y1 * y2);
}

void Extension::aDivideVector2(const TCHAR* vectorID1, const TCHAR* vectorID2, const TCHAR* newVectorID) {
	TwoDVectors::AddToArray(newVectorID);
	Vector2* currentVector1 = TwoDVectors::GetFromArray(vectorID1);
	Vector2* currentVector2 = TwoDVectors::GetFromArray(vectorID2);
	Vector2* newVector = TwoDVectors::GetFromArray(newVectorID);

	float x1 = currentVector1->GetX();
	float y1 = currentVector1->GetY();
	float x2 = currentVector2->GetX();
	float y2 = currentVector2->GetY();

	if (x2 > 0) {
		newVector->SetX(x1 / x2);
	}
	else {
		newVector->SetX(0);
	}
	if (y2 > 0) {
		newVector->SetY(y1 / y2);
	}
	else {
		newVector->SetY(0);
	}
}

void Extension::aLerpVector2(const TCHAR* vectorID1, const TCHAR* vectorID2, float lerpAmount, const TCHAR* newVectorID) {
	TwoDVectors::AddToArray(newVectorID);
	Vector2* currentVector1 = TwoDVectors::GetFromArray(vectorID1);
	Vector2* currentVector2 = TwoDVectors::GetFromArray(vectorID2);
	Vector2* newVector = TwoDVectors::GetFromArray(newVectorID);

	float x1 = currentVector1->GetX();
	float y1 = currentVector1->GetY();
	float x2 = currentVector2->GetX();
	float y2 = currentVector2->GetY();

	newVector->SetX(x1 + (x2 - x1) * lerpAmount);
	newVector->SetY(y1 + (y2 - y1) * lerpAmount);
}

//Vector3

void Extension::aCreateVector3(const TCHAR* vectorID, float valueX, float valueY, float valueZ) {
	ThreeDVectors::AddToArray(vectorID);
	Vector3* newVector = ThreeDVectors::GetFromArray(vectorID);
	newVector->SetX(valueX);
	newVector->SetY(valueY);
	newVector->SetZ(valueZ);
}

void Extension::aDeleteVector3(const TCHAR* vectorID) {
	ThreeDVectors::RemoveFromArray(vectorID);
}

void Extension::aSetVector3X(const TCHAR* vectorID, float value) {
	ThreeDVectors::AddToArray(vectorID);
	Vector3* currentVector = ThreeDVectors::GetFromArray(vectorID);
	currentVector->SetX(value);
}

void Extension::aSetVector3Y(const TCHAR* vectorID, float value) {
	ThreeDVectors::AddToArray(vectorID);
	Vector3* currentVector = ThreeDVectors::GetFromArray(vectorID);
	currentVector->SetY(value);
}

void Extension::aSetVector3Z(const TCHAR* vectorID, float value) {
	ThreeDVectors::AddToArray(vectorID);
	Vector3* currentVector = ThreeDVectors::GetFromArray(vectorID);
	currentVector->SetZ(value);
}

void Extension::aScaleVector3(const TCHAR* vectorID, float scalar, const TCHAR* newVectorID) {
	ThreeDVectors::AddToArray(newVectorID);
	Vector3* currentVector = ThreeDVectors::GetFromArray(vectorID);
	Vector3* newVector = ThreeDVectors::GetFromArray(newVectorID);
	newVector->SetX(currentVector->GetX() * scalar);
	newVector->SetY(currentVector->GetY() * scalar);
	newVector->SetZ(currentVector->GetZ() * scalar);
}

void Extension::aUnitVector3(const TCHAR* vectorID, const TCHAR* newVectorID) {
	ThreeDVectors::AddToArray(newVectorID);
	Vector3* currentVector = ThreeDVectors::GetFromArray(vectorID);
	Vector3* newVector = ThreeDVectors::GetFromArray(newVectorID);

	float x = currentVector->GetX();
	float y = currentVector->GetY();
	float z = currentVector->GetZ();
	float magnitude = sqrtf(x * x + y * y + z * z);

	x /= magnitude;
	y /= magnitude;
	z /= magnitude;

	if (magnitude > 0) {
		newVector->SetX(x);
		newVector->SetY(y);
		newVector->SetZ(z);
	}
	else
	{
		newVector->SetX(0.0f);
		newVector->SetY(0.0f);
		newVector->SetZ(0.0f);
	}
}

void Extension::aAddVector3(const TCHAR* vectorID1, const TCHAR* vectorID2, const TCHAR* newVectorID) {
	ThreeDVectors::AddToArray(newVectorID);
	Vector3* currentVector1 = ThreeDVectors::GetFromArray(vectorID1);
	Vector3* currentVector2 = ThreeDVectors::GetFromArray(vectorID2);
	Vector3* newVector = ThreeDVectors::GetFromArray(newVectorID);

	float x1 = currentVector1->GetX();
	float y1 = currentVector1->GetY();
	float z1 = currentVector1->GetZ();
	float x2 = currentVector2->GetX();
	float y2 = currentVector2->GetY();
	float z2 = currentVector2->GetZ();

	newVector->SetX(x1 + x2);
	newVector->SetY(y1 + y2);
	newVector->SetZ(z1 + z2);
}

void Extension::aSubtractVector3(const TCHAR* vectorID1, const TCHAR* vectorID2, const TCHAR* newVectorID) {
	ThreeDVectors::AddToArray(newVectorID);
	Vector3* currentVector1 = ThreeDVectors::GetFromArray(vectorID1);
	Vector3* currentVector2 = ThreeDVectors::GetFromArray(vectorID2);
	Vector3* newVector = ThreeDVectors::GetFromArray(newVectorID);

	float x1 = currentVector1->GetX();
	float y1 = currentVector1->GetY();
	float z1 = currentVector1->GetZ();
	float x2 = currentVector2->GetX();
	float y2 = currentVector2->GetY();
	float z2 = currentVector2->GetZ();

	newVector->SetX(x1 - x2);
	newVector->SetY(y1 - y2);
	newVector->SetZ(z1 - z2);
}

void Extension::aMultiplyVector3(const TCHAR* vectorID1, const TCHAR* vectorID2, const TCHAR* newVectorID) {
	ThreeDVectors::AddToArray(newVectorID);
	Vector3* currentVector1 = ThreeDVectors::GetFromArray(vectorID1);
	Vector3* currentVector2 = ThreeDVectors::GetFromArray(vectorID2);
	Vector3* newVector = ThreeDVectors::GetFromArray(newVectorID);

	float x1 = currentVector1->GetX();
	float y1 = currentVector1->GetY();
	float z1 = currentVector1->GetZ();
	float x2 = currentVector2->GetX();
	float y2 = currentVector2->GetY();
	float z2 = currentVector2->GetZ();

	newVector->SetX(x1 * x2);
	newVector->SetY(y1 * y2);
	newVector->SetZ(z1 * z2);
}

void Extension::aDivideVector3(const TCHAR* vectorID1, const TCHAR* vectorID2, const TCHAR* newVectorID) {
	ThreeDVectors::AddToArray(newVectorID);
	Vector3* currentVector1 = ThreeDVectors::GetFromArray(vectorID1);
	Vector3* currentVector2 = ThreeDVectors::GetFromArray(vectorID2);
	Vector3* newVector = ThreeDVectors::GetFromArray(newVectorID);

	float x1 = currentVector1->GetX();
	float y1 = currentVector1->GetY();
	float z1 = currentVector1->GetZ();
	float x2 = currentVector2->GetX();
	float y2 = currentVector2->GetY();
	float z2 = currentVector2->GetZ();

	newVector->SetX(x1 / x2);
	newVector->SetY(y1 / y2);
	newVector->SetZ(z1 / z2);
}

void Extension::aLerpVector3(const TCHAR* vectorID1, const TCHAR* vectorID2, float lerpAmount, const TCHAR* newVectorID) {
	ThreeDVectors::AddToArray(newVectorID);
	Vector3* currentVector1 = ThreeDVectors::GetFromArray(vectorID1);
	Vector3* currentVector2 = ThreeDVectors::GetFromArray(vectorID2);
	Vector3* newVector = ThreeDVectors::GetFromArray(newVectorID);

	float x1 = currentVector1->GetX();
	float y1 = currentVector1->GetY();
	float z1 = currentVector1->GetZ();
	float x2 = currentVector2->GetX();
	float y2 = currentVector2->GetY();
	float z2 = currentVector2->GetZ();

	newVector->SetX(x1 + (x2 - x1) * lerpAmount);
	newVector->SetY(y1 + (y2 - y1) * lerpAmount);
	newVector->SetZ(z1 + (z2 - z1) * lerpAmount);
}

//=======================================================================================================================================================================================================
