#include "GameLogic.h"

GameLogic::GameLogic(int height, int width, ConsoleDrawer* draw, InputManager* input) : height(height), width(width)
{
	logicDrawManager = draw;
	logicInputManager = input;

	snakeCurrentLength = 4;

	for (int i = 0; i < snakeCurrentLength; i++)
	{
		snake.push_back({ ((height - initHeight) / 2) - i, (width / 2) - i });
	}
}

GameLogic::~GameLogic()
{
	//delete this;
}

void GameLogic::Start()
{
	initHeight = logicDrawManager->GetInitHeight();
	points = 0;

	fruitsPos.reserve(maxFruits);

	gameOver = false;
}

void GameLogic::Update(float deltaTime)
{
	std::srand(std::time(nullptr));
	GenerateRandomFruit();
	GetInput();
	CheckCollision();
	EatFruit();
	Draw();

}

void GameLogic::Draw()
{
	//logicDrawManager->DrawSnake(l_y, l_x, snakeCurrentLength);
	DrawPoints();
	DrawSnake();
}

void GameLogic::DrawSnake()
{
	int oldPosX = 0;
	int oldPosY = 0;

	logicDrawManager->DrawEmpty(l_y, l_x, snakeCurrentLength);
	for (int i = 0; i < snake.size(); i++)
	{
		if (i == 0)
		{
			l_y = snake[i].y += dirY;
			l_x = snake[i].x += dirX;

			logicDrawManager->DrawSnake(l_y, l_x, snakeCurrentLength);
		}
		else
		{
			oldPosY = snake.at(i).y;
			oldPosX = snake.at(i).x;

			snake.at(i).y = l_y;
			snake.at(i).x = l_x;

			l_y = oldPosY;
			l_x = oldPosX;
		}
	}
}

void GameLogic::DrawPoints()
{
	logicDrawManager->DrawPoints(initHeight, points, record);
}

void GameLogic::DrawRandomFruit(int h, int w)
{
	for (gameCoords var : fruitsPos)
	{
		logicDrawManager->DrawFruit(var.y, var.x);
	}
}

void GameLogic::GenerateRandomFruit()
{
	if (fruitCounter < maxFruits)
	{
		randHeight = (4 + rand() % (height - 5));
		randWidth = (4 + rand() % (width - 5));

		fruitsPos.push_back({ randHeight, randWidth });
		DrawRandomFruit(randHeight, randWidth);

		fruitCounter++;
	}
}

void GameLogic::GetInput()
{
	if (logicInputManager->ReturnInput() == UP_KEY)
	{
		if (dirX != 0)
		{
			dirY = -1;
			dirX = 0;
		}
	}
	if (logicInputManager->ReturnInput() == DOWN_KEY)
	{
		if (dirX != 0)
		{
			dirY = 1;
			dirX = 0;
		}
	}
	if (logicInputManager->ReturnInput() == LEFT_KEY)
	{
		if (dirY != 0)
		{
			dirY = 0;
			dirX = -1;
		}
	}
	if (logicInputManager->ReturnInput() == RIGHT_KEY)
	{
		if (dirY != 0)
		{
			dirY = 0;
			dirX = 1;
		}
	}
}

void GameLogic::CheckCollision()
{
	for (int i = 0; i < snake.size(); i++)
	{
		if (snake.at(0).y == height - 1 || snake.at(0).y == initHeight + 1)
		{
			logicDrawManager->DrawGameOver();
			gameOver = true;
		}

		if ((snake.at(0).x == width - 1 || snake.at(0).x == 1))
		{
			logicDrawManager->DrawGameOver();
			gameOver = true;
		}

		if (snake.at(i).y == l_y && snake.at(i).x == l_x)
		{
			logicDrawManager->DrawGameOver();
			gameOver = true;
		}
	}
}

void GameLogic::EatFruit()
{
	for (gameCoords fruitPos : fruitsPos)
	{
		if (fruitPos.x == snake.at(0).x && fruitPos.y == snake.at(0).y)
		{
			points += 1;
			record += 1;
			Grow();
			fruitCounter--;
		}
	}
}

void GameLogic::Grow()
{
	snake.push_back({ snake.back().y + 1, snake.back().x + 1 });
}

bool GameLogic::GetGameOver()
{
	return gameOver;
}

void GameLogic::SetGameOver(bool b)
{
	gameOver = b;
}


