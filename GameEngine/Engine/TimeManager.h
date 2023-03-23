#pragma once
#include <windows.h>
#include <time.h>

class TimeManager
{
private:
	const float timePerFrame		= 1.0f / 1.0f; //one second
	clock_t elapsedTimeClocks		= 0;
	clock_t lastFrameClockTime		= 0;
	float elapsedTime				= 0.0f;

public:
	TimeManager();
	TimeManager(int framesXSecond);

	~TimeManager();

	bool ShouldExecuteNextFrame() const;
	float GetElapsedTime() const;

	void Update();
	void NextFrameExecuted();
};

