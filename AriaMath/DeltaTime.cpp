#include "Common.hpp"
#include "AriaMath\DeltaTime.hpp"
#include <cmath>
#include <iostream>
//========================================================================
const int MAX_TIMER_DIFFERENCE = 30;
//========================================================================
float deltaTime = 1.0f;
float gameSpeed = 1.0f;
float oldGameSpeed = gameSpeed;
int oldTimer = 0;
int oldTimerBuffer = 0;
int timeScale = 60;
int deltaTimeLimit = 30;

bool gameSpeedUpdateFlag = false;

bool isPaused = false;
//========================================================================
//Getters
float DeltaTime::GetDeltaTimeF() {
	return deltaTime * gameSpeed;
}
float DeltaTime::GetDeltaTimeS() {
	return (1.0f / (deltaTime * timeScale)) * gameSpeed;
}
float DeltaTime::GetGameSpeed() {
	return gameSpeed;
}
int DeltaTime::GetOldTimer() {
	return oldTimer;
}
int DeltaTime::GetTimeScale() {
	return timeScale;
}
int DeltaTime::GetDeltaTimeLimit() {
	return deltaTimeLimit;
}
bool DeltaTime::GetIsGamePaused() {
	return isPaused;
}
bool DeltaTime::GetGameSpeedUpdateFlag() {
	bool result = gameSpeedUpdateFlag;
	gameSpeedUpdateFlag = false;
	return result;
}
//========================================================================
//Setters
void DeltaTime::SetDeltaTime(float dt) {
	deltaTime = fmax(0.0f, dt);

	if (deltaTime >= deltaTimeLimit) {
		deltaTime = 0.0f;
	}
}
float DeltaTime::SetGameSpeed(float gs) {
	gameSpeed = fmax(0.0, gs);
	isPaused = (gameSpeed == 0.0f);

	gameSpeedUpdateFlag = (oldGameSpeed != gameSpeed);

	float result = oldGameSpeed;
	oldGameSpeed = gameSpeed;

	return result;
}
void DeltaTime::SetOldTimer(int ot) {
	oldTimer = (int)fmax(0.0f, ot);
	oldTimerBuffer = oldTimer;
}
void DeltaTime::SetTimeScale(int ts) {
	timeScale = (int)fmax(1.0f, ts);
}
void DeltaTime::SetDeltaTimeLimit(int dtl) {
	deltaTimeLimit = (int)fmax(1.0f, dtl);
}
//========================================================================
//Calculate Delta Time
void DeltaTime::CalculateDeltaTime(int timer) {
	oldTimer = oldTimerBuffer;
	DeltaTime::SetDeltaTime((timer - oldTimer) * ((float)timeScale / 1000.0f));
	oldTimerBuffer = timer;
}
//========================================================================
