#pragma once
#include <iostream>
#include <random>
#include <vector>
#include "ConsoleDrawer.h"
#include "InputManager.h"
#include <Windows.h>
#include <algorithm>

#define SNAKE_HEAD char(21)
#define SNAKE_BODY char(219)

struct gameCoords
{
	int y;
	int x;
};

class GameLogic
{
	int height = 0;
	int initHeight = 0;
	int width = 0;

	ConsoleDrawer* logicDrawManager;
	InputManager* logicInputManager;

	int points = 0;
	int record = 0;

	int randHeight = 0;
	int randWidth = 0;

	int fruitCounter = 0;
	int maxFruits = 2;

	int l_y;
	int l_x;

	int dirX = 1;
	int dirY = 0;

	int snakeCurrentLength;

	std::vector<gameCoords> snake; //Millor una llista dinamica de ints amb la posicio del snake
	std::vector<gameCoords> fruitsPos;

	bool gameOver;

	GameLogic();
public:
	GameLogic(int height, int width, ConsoleDrawer* d, InputManager* i);
	~GameLogic();

	void Start();
	void Update(float deltaTime);
	void Draw();

	void DrawSnake();
	void DrawPoints();
	void DrawRandomFruit(int h, int w);
	void GenerateRandomFruit();

	void GetInput();

	void CheckCollision();
	void EatFruit();
	void Grow();

	bool GetGameOver();
	void SetGameOver(bool b);
};

