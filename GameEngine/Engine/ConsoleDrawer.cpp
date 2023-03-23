#include "ConsoleDrawer.h"
#include <iostream>
#include <sstream>

ConsoleDrawer::ConsoleDrawer()
{

}

ConsoleDrawer::ConsoleDrawer(int height, int width) : height(height), width(width)
{
	screen = new char[height * width];
}

ConsoleDrawer::~ConsoleDrawer()
{
	delete[] screen;
}

void ConsoleDrawer::Start()
{
	int headerHeight = initHeight;
	ResetScreen(' ');

	//DrawPoints(headerHeight, 0, 0);
	DrawBoard(headerHeight);
	UpdateDraw(headerHeight);
}

void ConsoleDrawer::Draw()
{
	system("cls");
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
			std::cout << screen[h * width + w];

		std::cout << std::endl;
	}
}
void ConsoleDrawer::UpdateDraw(int initHeight)
{
	Draw();
}

void ConsoleDrawer::DrawAtPos(char character, int h, int w)
{
	screen[h * width + w] = character;
}

void ConsoleDrawer::DrawAtPos(const char* string, int h, int w)
{
	int i = 0;

	while (string[i] != '\0' && i < (height * width) - h * width + w + i)
	{
		char* pointer = &(screen[h * width + w + i]);
		*pointer = string[i];
		i++;
	}
}

void ConsoleDrawer::ResetScreen(char character)
{
	for (int i = 0; i < height * width; i++)
	{
		screen[i] = character;
	}
}

void ConsoleDrawer::DrawBoard(int initHeight)
{

	for (int h = initHeight; h < height; h++)
	{
		DrawAtPos(char(204), initHeight, 0); //Cantonada dreta

		for (int w = 0; w < width; w++)
		{
			DrawAtPos(char(186), h + initHeight, 0); //Columna esquerra

			if (h == initHeight || (h + 1) == height)
			{
				if (h == initHeight)
					DrawAtPos(char(205), h, w); //Barra superior
				else
					DrawAtPos(char(205), h, w); //Barra inferior

				if ((w + 1) == width && h == initHeight)
					DrawAtPos(char(185), h, w); //Cantonada superior esquerra

				if ((h + 1) == height && (w + 1) == width)
					DrawAtPos(char(188), h, w); //Cantonada inferior esquerra
			}
			else if (w == 0 || (w + 1) == width)
				DrawAtPos(char(186), h, w);
			else
			{
				DrawAtPos(' ', h, w);
			}

		}
		DrawAtPos(char(200), height - 1, 0);
	}
}

void ConsoleDrawer::DrawPoints(int headerHeight, int points, int record)
{
	std::string stringPoints = "PUNTUATION: " + std::to_string(points);
	std::string stringRecord = "RECORD: " + std::to_string(record);

	for (int h = 0; h < headerHeight; h++)
	{
		DrawAtPos(char(201), 0, 0);

		for (int w = 0; w < width; w++)
		{
			DrawAtPos(char(186), h + 1, 0);

			if (h == 0 || (h + 1) == height)
			{
				DrawAtPos(char(205), h, w); //Fila superior
				DrawAtPos(char(205), h + 2, w); //Fila inferior
			}
			else if ((w + 1) == width)
			{
				if (h == headerHeight / 2)
				{
					DrawAtPos(char(186), h, w);
				}
				DrawAtPos(char(185), h + 1, w);
			}
			else if (w == 0 && (h + 1) == headerHeight)
			{
				DrawAtPos(char(204), h, w);
			}
			else if (w == width / 20 && h == headerHeight / 2)
			{
				DrawAtPos(stringPoints.c_str(), h, w);
			}
			else if (w == width - 20 && h == headerHeight / 2)
			{
				DrawAtPos(stringRecord.c_str(), h, w);
			}
		}
	}
	DrawAtPos(char(187), 0, width - 1);
}

void ConsoleDrawer::DrawSnake(int y, int x, int size)
{
	for (int i = 0; i < size; i++)
	{
		DrawAtPos(SNAKE_BODY, y, x);
		//DrawAtPos('0', y, x);
	}
}

void ConsoleDrawer::DrawEmpty(int y, int x, int size)
{
	for (int i = 0; i < size; i++)
	{
		DrawAtPos(' ', y, x);
	}
}

void ConsoleDrawer::DrawFruit(int y, int x)
{
	DrawAtPos(FRUIT, y, x);
}


void ConsoleDrawer::DrawGameOver()
{
	ResetScreen(' ');
	DrawAtPos("GAME OVER", height / 2, width / 2);
}

int ConsoleDrawer::GetInitHeight()
{
	return initHeight;
}