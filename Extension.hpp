#pragma once
#include "DarkEdif.hpp"
//AriaMath Files
#include "AriaMath\Math.hpp"
#include "AriaMath\BagRandomizer.hpp"
#include "AriaMath\DeltaTime.hpp"
#include "AriaMath\Vector2.hpp"
#include "AriaMath\Vector3.hpp"
#include "AriaMath\Functions.hpp"
#include "AriaMath\IntArrays.hpp"
#include "AriaMath\FloatArrays.hpp"
#include "AriaMath\StringArrays.hpp"
#include "AriaMath\AriaTime.hpp"
#include "AriaMath\AriaStrings.hpp"
#include "AriaMath\AriaColors.hpp"

class Extension final
{
public:
	// ======================================
	// Required variables + functions
	// Variables here must not be moved or swapped around or it can cause future issues
	// ======================================
	RunHeader* rhPtr;
	RunObjectMultiPlatPtr rdPtr;
#ifdef __ANDROID__
	global<jobject> javaExtPtr;
#elif defined(__APPLE__)
	void* const objCExtPtr;
#endif

	Edif::Runtime Runtime;

	static const int MinimumBuild = 254;
	static const int Version = 1;

	// Warning: OEFLAGS/OEPREFS cannot be freely modified when you have used them in MFAs.
	static constexpr OEFLAGS OEFLAGS = OEFLAGS::NONE;
	static constexpr OEPREFS OEPREFS = OEPREFS::NONE;
	// If OEFLAGS::WINDOW_PROC (otherwise you can delete)
	// static constexpr int WindowProcPriority = 100;
	// If OEFLAGS::TEXT (otherwise you can delete)
	// static constexpr TextCapacity TextCapacity = TextCapacity::None;

#ifdef _WIN32
	Extension(RunObject* const rdPtr, const EDITDATA* const edPtr, const CreateObjectInfo* const cobPtr);
#elif defined(__ANDROID__)
	Extension(const EDITDATA* const edPtr, const jobject javaExtPtr, const CreateObjectInfo* const cobPtr);
#else
	Extension(const EDITDATA* const edPtr, void* const objCExtPtr, const CreateObjectInfo* const cobPtr);
#endif
	~Extension();

	// ======================================
	// Extension data
	// ======================================

	// To add items to the Fusion Debugger, just uncomment this line.
	DarkEdif::FusionDebugger FusionDebugger;
	// After enabling it, you run FusionDebugger.AddItemToDebugger() inside Extension's constructor
	// As an example:
	std::tstring exampleDebuggerTextItem;


	/*  Add any data you want to store in your extension to this class
		(eg. what you'd normally store in rdPtr in old SDKs).

		Unlike rdPtr, you can store real C++ objects with constructors
		and destructors, without having to call them manually or store
		a pointer.
	*/

	std::vector<const TCHAR**> tcharStorage;

	const TCHAR* currentFunctionID = _T("");
	const TCHAR* currentIntArrayLoopID = _T("");
	const TCHAR* currentFloatArrayLoopID = _T("");
	const TCHAR* currentStringArrayLoopID = _T("");


	/*  Add your actions, conditions and expressions as real class member
		functions here. The arguments (and return type for expressions) must
		match EXACTLY what you defined in the JSON.

		Remember to link the actions, conditions and expressions to their
		numeric IDs in the class constructor (Extension.cpp)
	*/

	//=======================================================================================================================================================================================================
	//Actions
	//===================
	//Time Formatting
	void aFormatTimeString(int timeValue);
	//===================
	//Randomization
	void aCreateBagRandomizer(const TCHAR* ID);
	void aResetBagRandomizer(const TCHAR* ID);
	void aDeleteBagRandomizer(const TCHAR* ID);
	void aAddValueToBagRandomizer(const TCHAR* ID, int value);
	void aRemoveIndexFromBagRandomizer(const TCHAR* ID, int index);
	//===================
	//DeltaTime/Ticks
	void aEnableTicks();
	void aDisableTicks();
	void aCalculateDeltaTime(int timer);
	void aSetDeltaTimeBase(int deltaTimeBase);
	void aSetGameSpeed(float gameSpeed);
	void aPauseGameSpeed();
	void aResumeGameSpeed();
	void aSetTickRate(int tickRate);
	void aSetOldTimer(int oldTimer);
	//===================
	//Function Parameters
	void aSetFunctionIntegerParameter(const TCHAR* functionID, const TCHAR* paramID, int value);
	void aSetFunctionFloatParameter(const TCHAR* functionID, const TCHAR* paramID, float value);
	void aSetFunctionStringParameter(const TCHAR* functionID, const TCHAR* paramID, const TCHAR* value);
	//Function Returns
	void aSetFunctionIntegerReturn(const TCHAR* functionID, int value);
	void aSetFunctionFloatReturn(const TCHAR* functionID, float value);
	void aSetFunctionStringReturn(const TCHAR* functionID, const TCHAR* value);
	//Functions
	void aCallFunction(const TCHAR* functionID, int deleteParams);
	void aCallFunctionLoop(const TCHAR* functionID, int repetitions, int deleteParams);
	void aCallFunctionImmediate(const TCHAR* functionID, int deleteParams, const TCHAR* param1, const TCHAR* param2, const TCHAR* param3, const TCHAR* param4, const TCHAR* param5);
	void aResumeFunctionLoop(const TCHAR* ID, int deleteParams);
	void aStopFunctionLoop(const TCHAR* ID);
	void aSetFunctionLoopIndex(const TCHAR* ID, int index);
	//===================
	//Integer Arrays
	void aCreateIntegerArray(const TCHAR* arrayID);
	void aDeleteIntegerArray(const TCHAR* arrayID);
	void aSetIntegerArrayElement(const TCHAR* arrayID, int index, int value);
	void aDeleteIntegerArrayElement(const TCHAR* arrayID, int index);
	void aSortIntegerArrayAscending(const TCHAR* arrayID);
	void aSortIntegerArrayDescending(const TCHAR* arrayID);
	void aLoopThroughIntegerArray(const TCHAR* arrayID);
	void aLoopThroughIntegerArrayReverse(const TCHAR* arrayID);
	void aSetIntegerArrayLoopID(const TCHAR* arrayID, const TCHAR* loopID);
	void aParseStringToIntArray(const TCHAR* arrayID, const TCHAR* str, const TCHAR* delimiters);
	void aResumeIntegerArrayLoop(const TCHAR* arrayID);
	void aStopIntegerArrayLoop(const TCHAR* arrayID);
	void aSetIntegerArrayLoopIndex(const TCHAR* arrayID, int index);
	//Float Arrays
	void aCreateFloatArray(const TCHAR* arrayID);
	void aDeleteFloatArray(const TCHAR* arrayID);
	void aSetFloatArrayElement(const TCHAR* arrayID, int index, float value);
	void aDeleteFloatArrayElement(const TCHAR* arrayID, int index);
	void aSortFloatArrayAscending(const TCHAR* arrayID);
	void aSortFloatArrayDescending(const TCHAR* arrayID);
	void aLoopThroughFloatArray(const TCHAR* arrayID);
	void aLoopThroughFloatArrayReverse(const TCHAR* arrayID);
	void aSetFloatArrayLoopID(const TCHAR* arrayID, const TCHAR* loopID);
	void aParseStringToFloatArray(const TCHAR* arrayID, const TCHAR* str, const TCHAR* delimiters);
	void aResumeFloatArrayLoop(const TCHAR* arrayID);
	void aStopFloatArrayLoop(const TCHAR* arrayID);
	void aSetFloatArrayLoopIndex(const TCHAR* arrayID, int index);
	//String Arrays
	void aCreateStringArray(const TCHAR* arrayID);
	void aDeleteStringArray(const TCHAR* arrayID);
	void aSetStringArrayElement(const TCHAR* arrayID, int index, const TCHAR* value);
	void aDeleteStringArrayElement(const TCHAR* arrayID, int index);
	void aSortStringArrayLengthAscending(const TCHAR* arrayID);
	void aSortStringArrayLengthDescending(const TCHAR* arrayID);
	void aSortStringArrayAlphabeticalAscending(const TCHAR* arrayID);
	void aSortStringArrayAlphabeticalDescending(const TCHAR* arrayID);
	void aLoopThroughStringArray(const TCHAR* arrayID);
	void aLoopThroughStringArrayReverse(const TCHAR* arrayID);
	void aSetStringArrayLoopID(const TCHAR* arrayID, const TCHAR* loopID);
	void aParseStringToStringArray(const TCHAR* arrayID, const TCHAR* str, const TCHAR* delimiters);
	void aResumeStringArrayLoop(const TCHAR* arrayID);
	void aStopStringArrayLoop(const TCHAR* arrayID);
	void aSetStringArrayLoopIndex(const TCHAR* arrayID, int index);
	//===================
	//2D Vectors
	void aCreateVector2(const TCHAR* vectorID, float xValue, float yValue);
	void aDeleteVector2(const TCHAR* vectorID);
	void aSetVector2X(const TCHAR* vectorID, float value);
	void aSetVector2Y(const TCHAR* vectorID, float value);
	void aScaleVector2(const TCHAR* vectorID, float scalar, const TCHAR* newVectorID);
	void aUnitVector2(const TCHAR* vectorID, const TCHAR* newVectorID);
	void aAddVector2(const TCHAR* vectorID1, const TCHAR* vectorID2, const TCHAR* newVectorID);
	void aSubtractVector2(const TCHAR* vectorID1, const TCHAR* vectorID2, const TCHAR* newVectorID);
	void aMultiplyVector2(const TCHAR* vectorID1, const TCHAR* vectorID2, const TCHAR* newVectorID);
	void aDivideVector2(const TCHAR* vectorID1, const TCHAR* vectorID2, const TCHAR* newVectorID);
	void aLerpVector2(const TCHAR* vectorID1, const TCHAR* vectorID2, float lerpAmount, const TCHAR* newVectorID);
	//3D Vectors
	void aCreateVector3(const TCHAR* vectorID, float xValue, float yValue, float zValue);
	void aDeleteVector3(const TCHAR* vectorID);
	void aSetVector3X(const TCHAR* vectorID, float value);
	void aSetVector3Y(const TCHAR* vectorID, float value);
	void aSetVector3Z(const TCHAR* vectorID, float value);
	void aScaleVector3(const TCHAR* vectorID, float scalar, const TCHAR* newVectorID);
	void aUnitVector3(const TCHAR* vectorID, const TCHAR* newVectorID);
	void aAddVector3(const TCHAR* vectorID1, const TCHAR* vectorID2, const TCHAR* newVectorID);
	void aSubtractVector3(const TCHAR* vectorID1, const TCHAR* vectorID2, const TCHAR* newVectorID);
	void aMultiplyVector3(const TCHAR* vectorID1, const TCHAR* vectorID2, const TCHAR* newVectorID);
	void aDivideVector3(const TCHAR* vectorID1, const TCHAR* vectorID2, const TCHAR* newVectorID);
	void aLerpVector3(const TCHAR* vectorID1, const TCHAR* vectorID2, float lerpAmount, const TCHAR* newVectorID);
	//=======================================================================================================================================================================================================
	//Conditions
	//===================
	//DeltaTime/Tick
	bool cOnTick();
	bool cIsGameSpeedPaused();
	bool cOnGameSpeedPaused();
	bool cOnGameSpeedResumed();
	bool cOnGameSpeedChanged();
	//===================
	//Functions
	bool cOnFunction(const TCHAR* functionID);
	bool cFunctionLoopIndexEquals(const TCHAR* functionID, int loopIndex);
	//===================
	//Integer Arrays
	bool cOnIntegerArrayLoop(const TCHAR* arrayID);
	bool cIntegerArrayLoopIDEquals(const TCHAR* arrayID, const TCHAR* loopID);
	bool cCurrentIntegerArrayIndexEquals(const TCHAR* arrayID, int index);
	bool cCurrentIntegerArrayValueEquals(const TCHAR* arrayID, int value);
	bool cValueExistsInIntegerArray(const TCHAR* arrayID, int value);
	//Float Arrays
	bool cOnFloatArrayLoop(const TCHAR* arrayID);
	bool cFloatArrayLoopIDEquals(const TCHAR* arrayID, const TCHAR* loopID);
	bool cCurrentFloatArrayIndexEquals(const TCHAR* arrayID, int index);
	bool cCurrentFloatArrayValueEquals(const TCHAR* arrayID, float value);
	bool cValueExistsInFloatArray(const TCHAR* arrayID, float value);
	//String Arrays
	bool cOnStringArrayLoop(const TCHAR* arrayID);
	bool cStringArrayLoopIDEquals(const TCHAR* arrayID, const TCHAR* loopID);
	bool cCurrentStringArrayIndexEquals(const TCHAR* arrayID, int index);
	bool cCurrentStringArrayValueEquals(const TCHAR* arrayID, const TCHAR* value);
	bool cValueExistsInStringArray(const TCHAR* arrayID, const TCHAR* value);
	//===================
	//Runtime
	bool cIsRunningInEditor();
	bool cIsRunningInSubApplication();
	//=======================================================================================================================================================================================================
	//Expressions
	//===================
	//Constants
	float eConstE();
	float eConstPi();
	float eConstTau();
	float eConstPhi();
	float eConstGamma();
	float eConstRoot2();
	float eConstRoot3();
	//===================
	//Exponents
	float eExpE(float power);
	float eExp10(float power);
	float eExp2(float power);
	float eExpB(float power, float base);
	//Logs
	float eLogE(float argument);
	float eLog10(float argument);
	float eLog2(float argument);
	float eLogB(float argument, float base);
	//===================
	//Roots
	float eRoot2(float value);
	float eRoot3(float value);
	float eRootN(float value, float radical);
	float eRootInv(float value, float radical);
	//===================
	//Angles
	float eToRadians(int angle);
	float eToDegrees(float angle);
	//Trig Functions
	float eSinR(float angle);
	float eSinD(int angle);
	float eCosR(float angle);
	float eCosD(int angle);
	float eTanR(float angle);
	float eTanD(int angle);
	//Reciprocal Trig Functions
	float eCscR(float angle);
	float eCscD(int angle);
	float eSecR(float angle);
	float eSecD(int angle);
	float eCotR(float angle);
	float eCotD(int angle);
	//Hyperbolic Trig Functions
	float ehSinR(float angle);
	float ehSinD(int angle);
	float ehCosR(float angle);
	float ehCosD(int angle);
	float ehTanR(float angle);
	float ehTanD(int angle);
	//Inverse Trig Functions
	float eSinInv(float ratio);
	float eCosInv(float ratio);
	float eTanInv(float ratio);
	//Inverse Reciprocal Trig Functions
	float eCscInv(float ratio);
	float eSecInv(float ratio);
	float eCotInv(float ratio);
	//Inverse Hyperbolic Trig Functions
	float ehSinInv(float ratio);
	float ehCosInv(float ratio);
	float ehTanInv(float ratio);
	//===================
	//Factorials
	int eFactorialI(int input);
	float eFactorialF(float input);
	//===================
	//Operations
	//Clamps
	int eClampI(int input, int min, int max);
	float eClampF(float input, float min, float max);
	int eMinI(int valueA, int valueB);
	float eMinF(float valueA, float valueB);
	int eMaxI(int valueA, int valueB);
	float eMaxF(float valueA, float valueB);
	//Rounding
	int eRound(float input);
	float eRoundTo(float input, int decimal);
	int eFloor(float input);
	float eFloorTo(float input, int decimal);
	int eCeil(float input);
	float eCeilTo(float input, int decimal);
	//Other
	int eAbsI(int input);
	float eAbsF(float input);
	int eSign(int input);
	int eModI(int input, int divisor);
	float eModF(float input, float divisor);
	int eDivI(int input, int divisor);
	int eDivF(float input, float divisor);
	int eRemI(int valueA, int valueB);
	float eRemF(float valueA, float valueB);
	//===================
	//Comparisons
	int eCompEq(float valueA, float valueB);
	int eCompDiff(float valueA, float valueB);
	int eCompGreater(float valueA, float valueB);
	int eCompGreaterEq(float valueA, float valueB);
	int eCompLess(float valueA, float valueB);
	int eCompLessEq(float valueA, float valueB);
	//===================
	//Linear Interpolation
	float eLerp(float valueA, float valueB, float valueT);
	float eLerpSmooth(float valueA, float valueB, float valueT, float deltaTime);
	float ePointSlope(float x0, float x1, float y0, float y1, float valueT);
	//===================
	//Easing
	float eEaseConstant(float valueA, float valueB, float valueT, float jumpPoint);
	float eEaseLinear(float valueA, float valueB, float valueT);
	float eEaseQuadratic(float valueA, float valueB, float valueT, const TCHAR* direction);
	float eEaseCubic(float valueA, float valueB, float valueT, const TCHAR* direction);
	float eEaseQuartic(float valueA, float valueB, float valueT, const TCHAR* direction);
	float eEasePolynomial(float valueA, float valueB, float valueT, const TCHAR* direction, int exponent);
	float eEaseExponential(float valueA, float valueB, float valueT, const TCHAR* direction, float base, float growth);
	float eEaseSine(float valueA, float valueB, float valueT, const TCHAR* direction);
	float eEaseCircular(float valueA, float valueB, float valueT, const TCHAR* direction);
	float eEaseBack(float valueA, float valueB, float valueT, const TCHAR* direction, float overshoot);
	float eEaseBounce(float valueA, float valueB, float valueT, const TCHAR* direction, float damping, float frequency);
	float eEaseElastic(float valueA, float valueB, float valueT, const TCHAR* direction, float damping, float frequency);
	//===================
	//Kill Timer Equations
	float eExponentialDecayFormula(float minAI, float maxAI, float timerA, float timerB, float valueT);
	float eSquareRootDecayFormula(float minAI, float maxAI, float timerA, float timerB, float valueT);
	//===================
	//Colors
	int eFromRGB(int r, int g, int b);
	int eFromHSV(int h, float s, float v);
	int eFromHEX(const TCHAR* hex);
	//Get RGB
	int eGetRed(int color);
	int eGetGreen(int color);
	int eGetBlue(int color);
	//Get HSV
	int eGetHue(int color);
	float eGetSaturation(int color);
	float eGetBrightness(int color);
	//Get HEX
	const TCHAR* aGetHex(int color);
	//===================
	//Other
	float eErf(float value);
	//===================
	//Boolean
	int eToBoolean(int value);
	int eNOT(int value);
	int eAND(int valueA, int valueB);
	int eNAND(int valueA, int valueB);
	int eOR(int valueA, int valueB);
	int eNOR(int valueA, int valueB);
	int eXOR(int valueA, int valueB);
	int eXNOR(int valueA, int valueB);
	int eImplies(int valueA, int valueB);
	int eNImplies(int valueA, int valueB);
	//===================
	//Bitwise
	int eBitshiftR(int value, int shiftAmount);
	int eBitshiftL(int value, int shiftAmount);
	int eBitwiseNOT(int value);
	int eBitwiseAND(int valueA, int valueB);
	int eBitwiseNAND(int valueA, int valueB);
	int eBitwiseOR(int valueA, int valueB);
	int eBitwiseNOR(int valueA, int valueB);
	int eBitwiseXOR(int valueA, int valueB);
	int eBitwiseXNOR(int valueA, int valueB);
	int eBitwiseImplies(int valueA, int valueB);
	int eBitwiseNImplies(int valueA, int valueB);
	int eTwosComplement(int value);
	//===================
	//Time
	int eTimeHours();
	int eTimeMinutes();
	int eTimeSeconds();
	int eTimeMilliseconds();
	const TCHAR* eTimeHours$();
	const TCHAR* eTimeMinutes$();
	const TCHAR* eTimeSeconds$();
	const TCHAR* eTimeMilliseconds$();
	const TCHAR* eTimeString$();
	int eCurrentMonth();
	int eCurrentDay();
	int eCurrentYear();
	const TCHAR* eCurrentDate$();
	int eCurrentHours();
	int eCurrentMinutes();
	int eCurrentSeconds();
	const TCHAR* eCurrentTime$();
	//===================
	//Randomization
	int eRandom0(int value);
	int eRandom1(int value);
	int eRRandomI(int valueA, int valueB);
	float eRRandomF(float valueA, float valueB);
	int eRandomizerIndex(const TCHAR* ID, int index);
	int eRandomizerValue(const TCHAR* ID);
	//===================
	//Delta Time/Ticks
	float eDeltaTimeF();
	float eDeltaTimeS();
	float eGameSpeed();
	int eDeltaTimeBase();
	int eTickRate();
	int eOldTimer();
	//===================
	//Functions
	int eFunctionIntParam(const TCHAR* functionID, const TCHAR* paramID);
	float eFunctionFloatParam(const TCHAR* functionID, const TCHAR* paramID);
	const TCHAR* eFunctionStringParam(const TCHAR* functionID, const TCHAR* paramID);
	int eFunctionIntReturn(const TCHAR* functionID);
	float eFunctionFloatReturn(const TCHAR* functionID);
	const TCHAR* eFunctionStringReturn(const TCHAR* functionID);
	int eFunctionLoopIndex(const TCHAR* functionID);
	const TCHAR* eToFunctionParam(const TCHAR* paramID, const TCHAR* paramType, const TCHAR* paramValue);
	//===================
	//IntArrays
	int eIntArrayValue(const TCHAR* arrayID, int index);
	int eIntArrayLoopIndex(const TCHAR* arrayID);
	int eIntArrayValueAtLoopIndex(const TCHAR* arrayID);
	int eIntArraySize(const TCHAR* arrayID);
	const TCHAR* eIntArrayLoopID(const TCHAR* arrayID);
	const TCHAR* ePrintIntArray(const TCHAR* arrayID);
	//FloatArrays
	float eFloatArrayValue(const TCHAR* arrayID, int index);
	int eFloatArrayLoopIndex(const TCHAR* arrayID);
	float eFloatArrayValueAtLoopIndex(const TCHAR* arrayID);
	int eFloatArraySize(const TCHAR* arrayID);
	const TCHAR* eFloatArrayLoopID(const TCHAR* arrayID);
	const TCHAR* ePrintFloatArray(const TCHAR* arrayID);
	//StringArrays
	const TCHAR* eStringArrayValue(const TCHAR* arrayID, int index);
	int eStringArrayLoopIndex(const TCHAR* arrayID);
	const TCHAR* eStringArrayValueAtLoopIndex(const TCHAR* arrayID);
	int eStringArraySize(const TCHAR* arrayID);
	const TCHAR* eStringArrayLoopID(const TCHAR* arrayID);
	const TCHAR* ePrintStringArray(const TCHAR* arrayID);
	//===================
	//Vector2
	float eVect2(const TCHAR* ID, const TCHAR* dimension);
	float eVect2x(const TCHAR* ID);
	float eVect2y(const TCHAR* ID);
	float eVect2M(const TCHAR* ID);
	float eVect2Dot(const TCHAR* ID1, const TCHAR* ID2);
	//Vector3
	float eVect3(const TCHAR* ID, const TCHAR* dimension);
	float eVect3x(const TCHAR* ID);
	float eVect3y(const TCHAR* ID);
	float eVect3z(const TCHAR* ID);
	float eVect3M(const TCHAR* ID);
	float eVect3Dot(const TCHAR* ID1, const TCHAR* ID2);
	//=======================================================================================================================================================================================================

	// Runs every tick of Fusion's runtime, can be toggled off and back on
	REFLAG Handle();

#if TEXT_OEFLAG_EXTENSION
	// Extension text struct. Required for text exts.
	DarkEdif::FontInfoMultiPlat font;
	void OnFontChanged(bool colorEdit, DarkEdif::Rect* rc);
#endif
#if DARKEDIF_DISPLAY_TYPE == DARKEDIF_DISPLAY_SIMPLE
	// Extension display surface ptr. Required for simple display exts.
	DarkEdif::Surface * surf = nullptr;
#elif DARKEDIF_DISPLAY_TYPE == DARKEDIF_DISPLAY_MANUAL
	void Display();
	void GetZoneInfos();
	DarkEdif::Surface * GetDisplaySurface();
	DarkEdif::CollisionMask * GetCollisionMask(std::uint32_t flags);
#endif

	// These are called if there's no function linked to an ID
	void UnlinkedAction(int ID);
	long UnlinkedCondition(int ID);
	long UnlinkedExpression(int ID);

#if PAUSABLE_EXTENSION
	// Called when Fusion runtime is pausing - not just the F3 pause dialog
	void FusionRuntimePaused();
	// Called when Fusion runtime is resuming after a pause
	void FusionRuntimeContinued();
#endif // PAUSABLE_EXTENSION
};
