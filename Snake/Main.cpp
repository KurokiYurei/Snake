#include <iostream>
#include "GameEngine.h"

int main()
{
	GameEngine* gameEngine = new GameEngine(10, 25, 110); //10FPS //20 height //100 width
	gameEngine->Start();
}