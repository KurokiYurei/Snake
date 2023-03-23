#pragma once
#include "GameLogic.h"
#include "ConsoleDrawer.h"
#include "TimeManager.h"
#include "InputManager.h"


class GameEngine
{
	TimeManager* timeManager;
	GameLogic* logicManager;
	ConsoleDrawer* drawManager;
	InputManager* inputManager;

public:
	GameEngine(int frameRate, int height, int width);
	~GameEngine();

	void Start();
	void MainLoop();
	void Update(float deltaTime); // delta time == elapsed time
	void Draw();

	GameLogic* GetLogic();
};

