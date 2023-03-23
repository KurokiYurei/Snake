#pragma once
#include <windows.h>

#define UP_KEY char(0x26)
#define DOWN_KEY char(0x28)
#define LEFT_KEY char(0x25)
#define RIGHT_KEY char(0x27)

class InputManager
{
public:
	InputManager();
	~InputManager();

	void Start();
	void Update();

	char ReturnInput();
};

