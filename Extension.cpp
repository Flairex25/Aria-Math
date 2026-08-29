#include "Common.hpp"
#include <iomanip>
using namespace std::chrono_literals;

std::tstring globalKey = _T("AriaMath"s);
bool keepData = false;
///
/// EXTENSION CONSTRUCTOR/DESTRUCTOR
///

#ifdef _WIN32
Extension::Extension(RunObject* const _rdPtr, const EDITDATA* const edPtr, const CreateObjectInfo* const cobPtr) :
	rdPtr(_rdPtr), rhPtr(_rdPtr->get_rHo()->get_AdRunHeader()), Runtime(this), FusionDebugger(this)
#elif defined(__ANDROID__)
Extension::Extension(const EDITDATA* const edPtr, const jobject javaExtPtr, const CreateObjectInfo* const cobPtr) :
	javaExtPtr(javaExtPtr, "Extension::javaExtPtr from Extension ctor"),
	Runtime(this, this->javaExtPtr), FusionDebugger(this)
#else
Extension::Extension(const EDITDATA* const edPtr, void* const objCExtPtr, const CreateObjectInfo* const cobPtr) :
	objCExtPtr(objCExtPtr), Runtime(this, objCExtPtr), FusionDebugger(this)
#endif
{
	/*
		Link all your action/condition/expression functions to their IDs to match the
		IDs in the JSON here
	*/

	//=======================================================================================================================================================================================================
	//Actions
	//===================
	//Time Formatting
	LinkAction(0, aFormatTimeString);
	//===================
	//Randomization
	LinkAction(1, aCreateBagRandomizer);
	LinkAction(2, aResetBagRandomizer);
	LinkAction(3, aDeleteBagRandomizer);
	LinkAction(4, aAddValueToBagRandomizer);
	LinkAction(5, aRemoveIndexFromBagRandomizer);
	//===================
	//DeltaTime/Ticks
	LinkAction(6, aEnableTicks);
	LinkAction(7, aDisableTicks);
	LinkAction(8, aCalculateDeltaTime);
	LinkAction(9, aSetDeltaTimeBase);
	LinkAction(10, aSetGameSpeed);
	LinkAction(11, aPauseGameSpeed);
	LinkAction(12, aResumeGameSpeed);
	LinkAction(13, aSetTickRate);
	LinkAction(14, aSetOldTimer);
	//===================
	//Function Parameters
	LinkAction(15, aSetFunctionIntegerParameter);
	LinkAction(16, aSetFunctionFloatParameter);
	LinkAction(17, aSetFunctionStringParameter);
	//Function Returns
	LinkAction(18, aSetFunctionIntegerReturn);
	LinkAction(19, aSetFunctionFloatReturn);
	LinkAction(20, aSetFunctionStringReturn);
	//Funtions
	LinkAction(21, aCallFunction);
	LinkAction(22, aCallFunctionLoop);
	LinkAction(23, aCallFunctionImmediate);
	LinkAction(24, aResumeFunctionLoop);
	LinkAction(25, aStopFunctionLoop);
	LinkAction(26, aSetFunctionLoopIndex);
	//===================
	//Integer Arrays
	LinkAction(27, aCreateIntegerArray);
	LinkAction(28, aDeleteIntegerArray);
	LinkAction(29, aSetIntegerArrayElement);
	LinkAction(30, aDeleteIntegerArrayElement);
	LinkAction(31, aSortIntegerArrayAscending);
	LinkAction(32, aSortIntegerArrayDescending);
	LinkAction(33, aLoopThroughIntegerArray);
	LinkAction(34, aLoopThroughIntegerArrayReverse);
	LinkAction(35, aSetIntegerArrayLoopID);
	LinkAction(36, aParseStringToIntArray);
	LinkAction(37, aResumeIntegerArrayLoop);
	LinkAction(38, aStopIntegerArrayLoop);
	LinkAction(39, aSetIntegerArrayLoopIndex);
	//Float Arrays
	LinkAction(40, aCreateFloatArray);
	LinkAction(41, aDeleteFloatArray);
	LinkAction(42, aSetFloatArrayElement);
	LinkAction(43, aDeleteFloatArrayElement);
	LinkAction(44, aSortFloatArrayAscending);
	LinkAction(45, aSortFloatArrayDescending);
	LinkAction(46, aLoopThroughFloatArray);
	LinkAction(47, aLoopThroughFloatArrayReverse);
	LinkAction(48, aSetFloatArrayLoopID);
	LinkAction(49, aParseStringToFloatArray);
	LinkAction(50, aResumeFloatArrayLoop);
	LinkAction(51, aStopFloatArrayLoop);
	LinkAction(52, aSetFloatArrayLoopIndex);
	//String Arrays
	LinkAction(53, aCreateStringArray);
	LinkAction(54, aDeleteStringArray);
	LinkAction(55, aSetStringArrayElement);
	LinkAction(56, aDeleteStringArrayElement);
	LinkAction(57, aSortStringArrayLengthAscending);
	LinkAction(58, aSortStringArrayLengthDescending);
	LinkAction(59, aSortStringArrayAlphabeticalAscending);
	LinkAction(60, aSortStringArrayAlphabeticalDescending);
	LinkAction(61, aLoopThroughStringArray);
	LinkAction(62, aLoopThroughStringArrayReverse);
	LinkAction(63, aSetStringArrayLoopID);
	LinkAction(64, aParseStringToStringArray);
	LinkAction(65, aResumeStringArrayLoop);
	LinkAction(66, aStopStringArrayLoop);
	LinkAction(67, aSetStringArrayLoopIndex);
	//===================
	//2D Vectors
	LinkAction(68, aCreateVector2);
	LinkAction(69, aDeleteVector2);
	LinkAction(70, aSetVector2X);
	LinkAction(71, aSetVector2Y);
	LinkAction(72, aScaleVector2);
	LinkAction(73, aUnitVector2);
	LinkAction(74, aAddVector2);
	LinkAction(75, aSubtractVector2);
	LinkAction(76, aMultiplyVector2);
	LinkAction(77, aDivideVector2);
	LinkAction(78, aLerpVector2);
	//3D Vectors
	LinkAction(79, aCreateVector3);
	LinkAction(80, aDeleteVector3);
	LinkAction(81, aSetVector3X);
	LinkAction(82, aSetVector3Y);
	LinkAction(83, aSetVector3Z);
	LinkAction(84, aScaleVector3);
	LinkAction(85, aUnitVector3);
	LinkAction(86, aAddVector3);
	LinkAction(87, aSubtractVector3);
	LinkAction(88, aMultiplyVector3);
	LinkAction(89, aDivideVector3);
	LinkAction(90, aLerpVector3);
	//Randomization
	LinkAction(91, aSetRandomSeed);
	//=======================================================================================================================================================================================================
	//Conditions
	//===================
	//DeltaTime/Ticks
	LinkCondition(0, cOnTick);
	LinkCondition(1, cIsGameSpeedPaused);
	LinkCondition(2, cOnGameSpeedPaused);
	LinkCondition(3, cOnGameSpeedResumed);
	LinkCondition(4, cOnGameSpeedChanged);
	//===================
	//Functions
	LinkCondition(5, cOnFunction);
	LinkCondition(6, cFunctionLoopIndexEquals);
	//===================
	//Integer Arrays
	LinkCondition(7, cOnIntegerArrayLoop);
	LinkCondition(8, cIntegerArrayLoopIDEquals);
	LinkCondition(9, cCurrentIntegerArrayIndexEquals);
	LinkCondition(10, cCurrentIntegerArrayValueEquals);
	LinkCondition(11, cValueExistsInIntegerArray);
	//Float Arrays
	LinkCondition(12, cOnFloatArrayLoop);
	LinkCondition(13, cFloatArrayLoopIDEquals);
	LinkCondition(14, cCurrentFloatArrayIndexEquals);
	LinkCondition(15, cCurrentFloatArrayValueEquals);
	LinkCondition(16, cValueExistsInFloatArray);
	//String Arrays
	LinkCondition(17, cOnStringArrayLoop);
	LinkCondition(18, cStringArrayLoopIDEquals);
	LinkCondition(19, cCurrentStringArrayIndexEquals);
	LinkCondition(20, cCurrentStringArrayValueEquals);
	LinkCondition(21, cValueExistsInStringArray);
	//===================
	//Runtime
	LinkCondition(22, cIsRunningInEditor);
	LinkCondition(23, cIsRunningInSubApplication);
	//=======================================================================================================================================================================================================
	//Expressions
	//===================
	//Constants
	LinkExpression(0, eConstE);
	LinkExpression(1, eConstPi);
	LinkExpression(2, eConstTau);
	LinkExpression(3, eConstPhi);
	LinkExpression(4, eConstGamma);
	LinkExpression(5, eConstRoot2);
	LinkExpression(6, eConstRoot3);
	//===================
	//Exponents
	LinkExpression(7, eExpE);
	LinkExpression(8, eExp10);
	LinkExpression(9, eExp2);
	LinkExpression(10, eExpB);
	//Logs
	LinkExpression(11, eLogE);
	LinkExpression(12, eLog10);
	LinkExpression(13, eLog2);
	LinkExpression(14, eLogB);
	//===================
	//Roots
	LinkExpression(15, eRoot2);
	LinkExpression(16, eRoot3);
	LinkExpression(17, eRootN);
	LinkExpression(18, eRootInv);
	//===================
	//Angles
	LinkExpression(19, eToRadians);
	LinkExpression(20, eToDegrees);
	//Trig Functions
	LinkExpression(21, eSinR);
	LinkExpression(22, eSinD);
	LinkExpression(23, eCosR);
	LinkExpression(24, eCosD);
	LinkExpression(25, eTanR);
	LinkExpression(26, eTanD);
	//Reciprocal Trig Functions
	LinkExpression(27, eCscR);
	LinkExpression(28, eCscD);
	LinkExpression(29, eSecR);
	LinkExpression(30, eSecD);
	LinkExpression(31, eCotR);
	LinkExpression(32, eCotD);
	//Hyperbolic Trig Functions
	LinkExpression(33, ehSinR);
	LinkExpression(34, ehSinD);
	LinkExpression(35, ehCosR);
	LinkExpression(36, ehCosD);
	LinkExpression(37, ehTanR);
	LinkExpression(38, ehTanD);
	//Inverse Trig Functions
	LinkExpression(39, eSinInv);
	LinkExpression(40, eCosInv);
	LinkExpression(41, eTanInv);
	//Inverse Reciprocal Trig Functions
	LinkExpression(42, eCscInv);
	LinkExpression(43, eSecInv);
	LinkExpression(44, eCotInv);
	//Inverse Hyperbolic Trig Functions
	LinkExpression(45, ehSinInv);
	LinkExpression(46, ehCosInv);
	LinkExpression(47, ehTanInv);
	//===================
	//Factorials
	LinkExpression(48, eFactorialI);
	LinkExpression(49, eFactorialF);
	//===================
	//Operations
	LinkExpression(50, eClampI);
	LinkExpression(51, eClampF);
	LinkExpression(52, eMinI);
	LinkExpression(53, eMinF);
	LinkExpression(54, eMaxI);
	LinkExpression(55, eMaxF);
	//Rounding
	LinkExpression(56, eRound);
	LinkExpression(57, eRoundTo);
	LinkExpression(58, eFloor);
	LinkExpression(59, eFloorTo);
	LinkExpression(60, eCeil);
	LinkExpression(61, eCeilTo);
	//Other
	LinkExpression(62, eAbsI);
	LinkExpression(63, eAbsF);
	LinkExpression(64, eSign);
	LinkExpression(65, eModI);
	LinkExpression(66, eModF);
	LinkExpression(67, eDivI);
	LinkExpression(68, eDivF);
	LinkExpression(69, eRemI);
	LinkExpression(70, eRemF);
	//===================
	//Comparisons
	LinkExpression(71, eCompEq);
	LinkExpression(72, eCompDiff);
	LinkExpression(73, eCompGreater);
	LinkExpression(74, eCompGreaterEq);
	LinkExpression(75, eCompLess);
	LinkExpression(76, eCompLessEq);
	//===================
	//Linear Interpolation
	LinkExpression(77, eLerp);
	LinkExpression(78, eLerpSmooth);
	LinkExpression(79, ePointSlope);
	//===================
	//Easing
	LinkExpression(80, eEaseConstant);
	LinkExpression(81, eEaseLinear);
	LinkExpression(82, eEaseQuadratic);
	LinkExpression(83, eEaseCubic);
	LinkExpression(84, eEaseQuartic);
	LinkExpression(85, eEasePolynomial);
	LinkExpression(86, eEaseExponential);
	LinkExpression(87, eEaseSine);
	LinkExpression(88, eEaseCircular);
	LinkExpression(89, eEaseBack);
	LinkExpression(90, eEaseBounce);
	LinkExpression(91, eEaseElastic);
	//===================
	//Kill Timer Equations
	LinkExpression(92, eExponentialDecayFormula);
	LinkExpression(93, eSquareRootDecayFormula);
	//===================
	//Colors
	LinkExpression(94, eFromRGB);
	LinkExpression(95, eFromHSV);
	LinkExpression(96, eFromHEX);
	//Get RGB
	LinkExpression(97, eGetRed);
	LinkExpression(98, eGetBlue);
	LinkExpression(99, eGetGreen);
	//Get HSV
	LinkExpression(100, eGetHue);
	LinkExpression(101, eGetSaturation);
	LinkExpression(102, eGetBrightness);
	//Get HEX
	LinkExpression(103, aGetHex);
	//===================
	//Other
	LinkExpression(104, eErf);
	//===================
	//Boolean
	LinkExpression(105, eToBoolean);
	LinkExpression(106, eNOT);
	LinkExpression(107, eAND);
	LinkExpression(108, eNAND);
	LinkExpression(109, eOR);
	LinkExpression(110, eNOR);
	LinkExpression(111, eXOR);
	LinkExpression(112, eXNOR);
	LinkExpression(113, eImplies);
	LinkExpression(114, eNImplies);
	//===================
	//Bitwise
	LinkExpression(115, eBitshiftR);
	LinkExpression(116, eBitshiftL);
	LinkExpression(117, eBitwiseNOT);
	LinkExpression(118, eBitwiseAND);
	LinkExpression(119, eBitwiseNAND);
	LinkExpression(120, eBitwiseOR);
	LinkExpression(121, eBitwiseNOR);
	LinkExpression(122, eBitwiseXOR);
	LinkExpression(123, eBitwiseXNOR);
	LinkExpression(124, eBitwiseImplies);
	LinkExpression(125, eBitwiseNImplies);
	LinkExpression(126, eTwosComplement);
	//===================
	//Time
	LinkExpression(127, eTimeHours);
	LinkExpression(128, eTimeMinutes);
	LinkExpression(129, eTimeSeconds);
	LinkExpression(130, eTimeMilliseconds);
	LinkExpression(131, eTimeHours$);
	LinkExpression(132, eTimeMinutes$);
	LinkExpression(133, eTimeSeconds$);
	LinkExpression(134, eTimeMilliseconds$);
	LinkExpression(135, eTimeString$);
	LinkExpression(136, eCurrentMonth);
	LinkExpression(137, eCurrentDay);
	LinkExpression(138, eCurrentYear);
	LinkExpression(139, eCurrentDate$);
	LinkExpression(140, eCurrentHours);
	LinkExpression(141, eCurrentMinutes);
	LinkExpression(142, eCurrentSeconds);
	LinkExpression(143, eCurrentTime$);
	//===================
	//Randomization
	LinkExpression(144, eRandom0);
	LinkExpression(145, eRandom1);
	LinkExpression(146, eRRandomI);
	LinkExpression(147, eRRandomF);
	LinkExpression(148, eRandomizerIndex);
	LinkExpression(149, eRandomizerValue);
	//===================
	//Delta Time/Ticks
	LinkExpression(150, eDeltaTimeF);
	LinkExpression(151, eDeltaTimeS);
	LinkExpression(152, eGameSpeed);
	LinkExpression(153, eDeltaTimeBase);
	LinkExpression(154, eTickRate);
	LinkExpression(155, eOldTimer);
	//===================
	//Functions
	LinkExpression(156, eFunctionIntParam);
	LinkExpression(157, eFunctionFloatParam);
	LinkExpression(158, eFunctionStringParam);
	LinkExpression(159, eFunctionIntReturn);
	LinkExpression(160, eFunctionFloatReturn);
	LinkExpression(161, eFunctionStringReturn);
	LinkExpression(162, eFunctionLoopIndex);
	LinkExpression(163, eToFunctionParam);
	//===================
	//IntArrays
	LinkExpression(164, eIntArrayValue);
	LinkExpression(165, eIntArrayLoopIndex);
	LinkExpression(166, eIntArrayValueAtLoopIndex);
	LinkExpression(167, eIntArraySize);
	LinkExpression(168, eIntArrayLoopID);
	LinkExpression(169, ePrintIntArray);
	//FloatArrays
	LinkExpression(170, eFloatArrayValue);
	LinkExpression(171, eFloatArrayLoopIndex);
	LinkExpression(172, eFloatArrayValueAtLoopIndex);
	LinkExpression(173, eFloatArraySize);
	LinkExpression(174, eFloatArrayLoopID);
	LinkExpression(175, ePrintFloatArray);
	//StringArrays
	LinkExpression(176, eStringArrayValue);
	LinkExpression(177, eStringArrayLoopIndex);
	LinkExpression(178, eStringArrayValueAtLoopIndex);
	LinkExpression(179, eStringArraySize);
	LinkExpression(180, eStringArrayLoopID);
	LinkExpression(181, ePrintStringArray);
	//===================
	//Vector2
	LinkExpression(182, eVect2);
	LinkExpression(183, eVect2x);
	LinkExpression(184, eVect2y);
	LinkExpression(185, eVect2M);
	LinkExpression(186, eVect2Dot);
	//Vector3
	LinkExpression(187, eVect3);
	LinkExpression(188, eVect3x);
	LinkExpression(189, eVect3y);
	LinkExpression(190, eVect3z);
	LinkExpression(191, eVect3M);
	LinkExpression(192, eVect3Dot);
	//=======================================================================================================================================================================================================

	/*
		This is where you'd do anything you'd do in CreateRunObject in the original SDK

		It's the only place you'll get access to edPtr at runtime, so you should transfer
		anything from edPtr to the extension class here.

	*/

	// Don't use "this" inside these lambda functions, always ext.
	// There can be nothing in the [] section of the lambda.
	// If you're not sure about lambdas, you can remove this debugger stuff without any side effects;
	// it's just an example of how to use the debugger. You can view it in Fusion itself to see.
	FusionDebugger.AddItemToDebugger(
		// Prefix before debugger value, and initial text; if we pass null for initial text, it uses reader func
		_T("My text is: "sv), exampleDebuggerTextItem.c_str(),
		// reader function for your debug item
		[](Extension* const ext, std::tstring& writeTo) {
			writeTo = ext->exampleDebuggerTextItem;
		},
		// writer function (can be null if you don't want user to be able to edit it in debugger)
		[](Extension* const ext, std::tstring& newText) {
			ext->exampleDebuggerTextItem = newText;
			return true; // accept the changes
		}, 500, NULL
	);

	// Read object DarkEdif properties; you can pass property name, or property index
	// This will work on all platforms the same way.
	// See edPtr->Props functions.
	bool checkboxGlobalData = edPtr->Props.IsPropChecked("Enable Global Data"sv);

	//Setup globals
	keepData = checkboxGlobalData;
	//Setup ext instance vector for globals
	GlobalData* globalPtr = NULL;
	//Read Global Data
	globalPtr = (GlobalData*)Runtime.ReadGlobal((_T("AriaMath"s)).c_str());
	//Create new Global Data if it doesn't exist
	if (globalPtr == NULL && checkboxGlobalData == true) {
		globals = new GlobalData();
		globals->bagRandomizerList = BagRandomization::Get();
		globals->vector2list = TwoDVectors::Get();
		globals->vector3list = ThreeDVectors::Get();
		globals->functionList = Functions::Get();
		globals->intArrayList = IntegerArrays::Get();
		globals->floatArrayList = FloatArrays::Get();
		globals->stringArrayList = StringArrays::Get();
		Runtime.WriteGlobal(globalKey.c_str(), globals);
	}
	else {
		globals = globalPtr;
	}
	if (checkboxGlobalData == true) {
		BagRandomization::Set(globals->bagRandomizerList);
		TwoDVectors::Set(globals->vector2list);
		ThreeDVectors::Set(globals->vector3list);
		Functions::Set(globals->functionList);
		IntegerArrays::Set(globals->intArrayList);
		FloatArrays::Set(globals->floatArrayList);
		StringArrays::Set(globals->stringArrayList);
	}
	//This runs every time a new ext instance is loaded
	//Delete all data
	BagRandomization::Delete();
	TwoDVectors::Delete();
	ThreeDVectors::Delete();
	Functions::Delete();
	IntegerArrays::Delete();
	FloatArrays::Delete();
	StringArrays::Delete();
	Math::SetupRNG();
	LOGI(_T("Extension Instance Created"));


	// These lines do nothing, but prevent the compiler warning the variables are unused
	//(void)checkboxGlobalData;
	//(void)checkboxGlobalData;

#if TEXT_OEFLAG_EXTENSION
	// Copy from edittime data into runtime data
	font.CopyFromEditFont(this, edPtr->font);

	// Set Runtime.fontChangedFunc to trigger a function if the runtime
	// changes your ext's font via the built-in font actions
	Runtime.fontChangedFunc = &Extension::OnFontChanged;
#endif

#if DARKEDIF_DISPLAY_TYPE == DARKEDIF_DISPLAY_SIMPLE
	Runtime.SetSurfaceWithSize(edPtr->objSize.width, edPtr->objSize.height);
	// surf is already constructed
	// To start, let's make the image a solid blue fill
	surf->FillImageWith(DarkEdif::SurfaceFill::Solid(DarkEdif::ColorRGB(0, 0, 127)));
#endif
}

Extension::~Extension()
{
	//Write GlobalData
	if (keepData) {
		globals->bagRandomizerList = BagRandomization::Get();
		globals->vector2list = TwoDVectors::Get();
		globals->vector3list = ThreeDVectors::Get();
		globals->functionList = Functions::Get();
		globals->intArrayList = IntegerArrays::Get();
		globals->floatArrayList = FloatArrays::Get();
		globals->stringArrayList = StringArrays::Get();
		Runtime.WriteGlobal(globalKey.c_str(), globals);
	}
	else {
		BagRandomization::Delete();
		TwoDVectors::Delete();
		ThreeDVectors::Delete();
		Functions::Delete();
		IntegerArrays::Delete();
		FloatArrays::Delete();
		StringArrays::Delete();
	}
}



// Runs every tick of Fusion's runtime, can be toggled off and back on
REFLAG Extension::Handle()
{
	/*	If your extension won't draw to the window, but it still needs
		to do something every Fusion loop, use:
			return REFLAG::NONE;

		If you don't need to do something in Handle anymore, use:
			return REFLAG::ONE_SHOT;
		...you can later re-enable Handle with Runtime.Rehandle(),
		but don't use one-shot with a displaying ext.

		If you're drawing with simple display, use:
			return surf->GetAndResetAltered() ? REFLAG::DISPLAY : REFLAG::NONE;

		If you're drawing manually, use rdPtr->get_roc()->get_changed(),
		and potentially your surfaces GetAndResetAltered(), to decide
		what REFLAG to return.
		DarkEdif expects you to do manual drawing in Extension::Display()
		and other funcs.
	*/

#if DARKEDIF_DISPLAY_TYPE >= DARKEDIF_DISPLAY_SIMPLE
	// Example variables for showing how display can be modified.
	// These values should be in your Extension, not static; this is just a brief demo,
	// to show how to easily time your ext's display changes.
	// Display does not have to be done in Handle, but you do need to return
	// REFLAG::DISPLAY here and/or do rdPtr->get_roc()->set_changed(true) when display is changed.
	static std::chrono::steady_clock clock;
	static decltype(clock)::time_point nextTick;
	static const std::uint32_t colors[] = {
		DarkEdif::ColorRGB(128, 0, 0), DarkEdif::ColorRGB(168, 157, 50),
		DarkEdif::ColorRGB(50, 168, 64), DarkEdif::ColorRGB(50, 54, 168)
	};
	static std::size_t colorIndex = 0;
	if (nextTick < clock.now())
	{
		nextTick = clock.now() + 200ms;
		if (++colorIndex >= std::size(colors))
			colorIndex = 0;
		surf->FillImageWith(DarkEdif::SurfaceFill::Solid(colors[colorIndex]));
	}
	return surf->GetAndResetAltered() ? REFLAG::DISPLAY : REFLAG::NONE;
#endif

	// Will not be called next event tick
	return REFLAG::ONE_SHOT;
}

#if PAUSABLE_EXTENSION
// Called when Fusion runtime is pausing - not just the F3 pause dialog
void Extension::FusionRuntimePaused()
{

}

// Called when Fusion runtime is resuming after a pause
void Extension::FusionRuntimeContinued()
{

}
#endif // PAUSABLE_EXTENSION

#if TEXT_OEFLAG_EXTENSION
/* Triggered when the runtime changes the font name or size via built-in actions
 * @param colorEdit If true, font color was edited. If false, the font typeface was.
 * @param rect		If not null, contains a hint as to what size the object should be.
 *					This is based on differences between original font size and current one.
 *					You can ignore this hint, but it indicates you may want to call
 *					rdPtr->get_roc()->SetSize(). */
void Extension::OnFontChanged(bool colorEdit, DarkEdif::Rect * rect)
{
	// Prevent warnings about unused variables
	(void)colorEdit;
	(void)rect;

	// We could call Runtime.Redraw() to redraw ext immediately,
	// but we'll be patient and wait for next event tick
	rdPtr->get_roc()->set_changed(true);
	Runtime.Rehandle();
}

#endif

#if DARKEDIF_DISPLAY_TYPE == DARKEDIF_DISPLAY_MANUAL

void Extension::Display()
{
	// You should manually draw the surface(s) here.
	// Surface::BlitToFrameWithExtEffects will let you draw with the ext's sprites/X/Y accounted for,
	// but note you should also manage the collision mask in GetCollisionMask().
	// If you have a single surface, and don't want simple drawing, use the GetDisplaySurface().
	//
	//surf->BlitToFrameWithExtEffects(this, Point { x offset, y offset });
}


void Extension::GetZoneInfos()
{
	LOGI(_T("##### Extension::GetZoneInfos() called.\n"));
	// You can safely do nothing here. Some extensions do:
	// rdPtr->get_rHo()->set_ImgWidth()/set_ImgHeight()
	// but it is done automatically in CF2.5, so shouldn't be necessary.
}

DarkEdif::Surface * Extension::GetDisplaySurface()
{
	// Old style MMF2 fade-in/fade-out transistions requires this function,
	// Auto-rendering of Sprite effects (alpha coeff etc) will be applied by returning a surface here.
	// If you have multiple surfaces, you should can return null here and draw them yourself.
	// If you return null here, Display() will be called instead.
	return nullptr;
}
DarkEdif::CollisionMask * Extension::GetCollisionMask(std::uint32_t flags)
{
	// If your ext supports fine collision, you should return the collision mask corresponding to
	// which pixels have collision and which don't. DarkEdif::Surface can generate collision masks,
	// but it can be computationally expensive.
	// If your ext uses only box collision, DE will detect that and never call this function.
	(void)flags;

	return nullptr;
}

#endif // DARKEDIF_DISPLAY_MANUAL

// These are called if there's no function linked to an ID

void Extension::UnlinkedAction(int ID)
{
	DarkEdif::MsgBox::Error(_T("Extension::UnlinkedAction() called"), _T("Running a fallback for action ID %d. Make sure you ran LinkAction()."), ID);
}

long Extension::UnlinkedCondition(int ID)
{
	DarkEdif::MsgBox::Error(_T("Extension::UnlinkedCondition() called"), _T("Running a fallback for condition ID %d. Make sure you ran LinkCondition()."), ID);
	return 0;
}

long Extension::UnlinkedExpression(int ID)
{
	DarkEdif::MsgBox::Error(_T("Extension::UnlinkedExpression() called"), _T("Running a fallback for expression ID %d. Make sure you ran LinkExpression()."), ID);
	// Unlinked A/C/E is fatal error, but try not to return null string and definitely crash it
	if ((std::size_t)ID < Edif::SDK->ExpressionInfos.size() && Edif::SDK->ExpressionInfos[ID]->Flags.ef == ExpReturnType::String)
		return (long)Runtime.CopyString(_T(""));
	return 0;
}
