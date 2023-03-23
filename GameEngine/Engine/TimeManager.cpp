#include "TimeManager.h"
#include <iostream>

TimeManager::TimeManager()
{

}

TimeManager::TimeManager(int framesXSecond): timePerFrame(1.0f / (float)framesXSecond)
{
	
}

TimeManager::~TimeManager()
{

}

bool TimeManager::ShouldExecuteNextFrame() const
{
	return elapsedTime >= timePerFrame;
}

void TimeManager::Update()
{
	elapsedTimeClocks = clock() - lastFrameClockTime;
	elapsedTime = (float)elapsedTimeClocks / (float)CLOCKS_PER_SEC;
}

float TimeManager::GetElapsedTime() const
{
	return elapsedTime;
}

void TimeManager::NextFrameExecuted()
{
	lastFrameClockTime = clock();
}
