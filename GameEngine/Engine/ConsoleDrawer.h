#pragma once

#define SNAKE_HEAD char(21)
#define SNAKE_BODY char(219)
#define FRUIT '@'

class ConsoleDrawer
{
	int height = 0;
	int initHeight = 3;
	int width = 0;
	char* screen = nullptr;

	ConsoleDrawer();

public:
	void ResetScreen(char character);
	ConsoleDrawer(int height, int width);
	~ConsoleDrawer();

	void Start();
	void Draw();
	void UpdateDraw(int n);

	void DrawAtPos(char character, int h, int w);
	void DrawAtPos(const char* string, int h, int w);

	void DrawBoard(int n);
	void DrawPoints(int headerHeight, int points, int record);

	void DrawGameOver();

	int GetInitHeight();

	void DrawSnake(int y, int x, int s);
	void DrawEmpty(int y, int x, int s);
	void DrawFruit(int y, int x);
};