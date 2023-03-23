#include "InputManager.h"
#include <iostream>

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

void InputManager::Start()
{
}
void InputManager::Update()
{
}

char InputManager::ReturnInput()
{
	if (GetKeyState(UP_KEY) & 0x8000)
	{
		//return GetKeyState('W');
		return UP_KEY;
	}

	if (GetKeyState(DOWN_KEY) & 0x8000)
	{
		//return GetKeyState('W');
		return DOWN_KEY;
	}

	if (GetKeyState(LEFT_KEY) & 0x8000)
	{
		//return GetKeyState('W');
		return LEFT_KEY;
	}

	if (GetKeyState(RIGHT_KEY) & 0x8000)
	{
		//return GetKeyState('W');
		return RIGHT_KEY;
	}
}
