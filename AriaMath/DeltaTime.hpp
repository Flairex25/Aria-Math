#pragma once
#include "DarkEdif.hpp"
#include <cmath>

namespace DeltaTime {
	//Getters
	float GetDeltaTimeF();
	float GetDeltaTimeS();
	float GetGameSpeed();
	int GetOldTimer();
	int GetTimeScale();
	int GetDeltaTimeLimit();
	bool GetIsGamePaused();
	bool GetGameSpeedUpdateFlag();
	//Setters
	void SetDeltaTime(float dt);
	float SetGameSpeed(float gs);
	void SetOldTimer(int ot);
	void SetTimeScale(int ts);
	void SetDeltaTimeLimit(int dtl);
	//Methods
	void CalculateDeltaTime(int timer);
};
