// Pong.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>

#define P1_UP 72
#define P1_DOWN 80
#define P2_UP 119
#define P2_DOWN 115

using namespace std;

const int rows = 24;
const int columns = 79;

class Ball
{
public:
	int x_position;
	int y_position;
	string direction;

	void setPosition(int temp_x_position, int temp_y_position)
	{
		x_position = temp_x_position;
		y_position = temp_y_position;
	}

	void setDirection(string temp_direction)
	{
		direction = temp_direction;
	}
};

class Paddle
{
public:
	int x_position;
	int y_position;
	int length;
	int score;

	void setPosition(int temp_x_position, int temp_y_position)
	{
		x_position = temp_x_position;
		y_position = temp_y_position;
	}

	void setLength(int temp_length)
	{
		length = temp_length;
	}
	
};

class Gameboard
{
public:
	char board[rows][columns];
	Ball ball;
	Paddle player_one;
	Paddle player_two;

	void initializeBoard()
	{
		clearBoard();
		createBorders();
		createBall();
		createPaddles();
	}

	void clearBoard()
	{
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				board[i][j] = ' ';
			}
		}
	}

	void createBorders()
	{
		for(int i = 0; i < columns; ++i)
		{
			board[0][i] = '#';
			board[rows - 1][i] = '#';
		}
	//	for(int i = 0; i < rows; ++i)
	//	{
	//		board[i][0] = '#';
	//		board[i][columns - 1] = '#';
	//	}
	}

	void printBoard()
	{
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < columns; j++)
			{
				cout << board[i][j];
			}
			cout << endl;
		}
	}

	void createBall()
	{
		ball.setPosition(rows/2, columns/2);
		ball.setDirection("SW");

		board[ball.x_position][ball.y_position] = 'O';
	}

	void moveBall()
	{
		string direction = ball.direction;
		if (checkBallX() && checkBallY())
		{
			if (direction == "NE")
			{
				board[ball.x_position--][ball.y_position++] = ' ';
				board[ball.x_position][ball.y_position] = 'O';
			}
			else if (direction == "NW")
			{
				board[ball.x_position--][ball.y_position--] = ' ';
				board[ball.x_position][ball.y_position] = 'O';
			}
			else if (direction == "SE")
			{
				board[ball.x_position++][ball.y_position++] = ' ';
				board[ball.x_position][ball.y_position] = 'O';
			}
			else if (direction == "SW")
			{
				board[ball.x_position++][ball.y_position--] = ' ';
				board[ball.x_position][ball.y_position] = 'O';
			}
		}
		else if (checkBallX())
		{
			if (direction == "NE")
			{
				if (player_one.x_position <= ball.x_position && ball.x_position < player_one.x_position + player_one.length)
				{
					ball.direction = "NW";
					board[ball.x_position--][ball.y_position--] = ' ';
					board[ball.x_position][ball.y_position] = 'O';
				}
				else
				{
					board[ball.x_position][ball.y_position] = ' ';
					resetGame();
				}
			}
			else if (direction == "NW")
			{
				if (player_two.x_position <= ball.x_position && ball.x_position < player_two.x_position + player_two.length)
				{
					ball.direction = "NE";
					board[ball.x_position--][ball.y_position++] = ' ';
					board[ball.x_position][ball.y_position] = 'O';
				}
				else
				{
					board[ball.x_position][ball.y_position] = ' ';
					resetGame();
				}
			}
			else if (direction == "SE")
			{
				if (player_one.x_position <= ball.x_position && ball.x_position < player_one.x_position + player_one.length)
				{
					ball.direction = "SW";
					board[ball.x_position++][ball.y_position--] = ' ';
					board[ball.x_position][ball.y_position] = 'O';
				}
				else
				{
					board[ball.x_position][ball.y_position] = ' ';
					resetGame();
				}
			}
			else if (direction == "SW")
			{
				if (player_two.x_position <= ball.x_position && ball.x_position < player_two.x_position + player_two.length)
				{
					ball.direction = "SE";
					board[ball.x_position++][ball.y_position++] = ' ';
					board[ball.x_position][ball.y_position] = 'O';
				}
				else
				{
					board[ball.x_position][ball.y_position] = ' ';
					resetGame();
				}
			}
		}
		else if (checkBallY())
		{
			if (direction == "NE")
			{
				ball.direction = "SE";
				board[ball.x_position++][ball.y_position++] = ' ';
				board[ball.x_position][ball.y_position] = 'O';
			}
			else if (direction == "NW")
			{
				ball.direction = "SW";
				board[ball.x_position++][ball.y_position--] = ' ';
				board[ball.x_position][ball.y_position] = 'O';
			}
			else if (direction == "SE")
			{
				ball.direction = "NE";
				board[ball.x_position--][ball.y_position++] = ' ';
				board[ball.x_position][ball.y_position] = 'O';
			}
			else if (direction == "SW")
			{
				ball.direction = "NW";
				board[ball.x_position--][ball.y_position--] = ' ';
				board[ball.x_position][ball.y_position] = 'O';
			}
		}
		else
		{
			if (direction == "NE")
			{
				direction = "SW";
				board[ball.x_position++][ball.y_position--] = ' ';
				board[ball.x_position][ball.y_position] = 'O';
			}
			else if (direction == "NW")
			{
				ball.direction = "SE";
				board[ball.x_position++][ball.y_position++] = ' ';
				board[ball.x_position][ball.y_position] = 'O';
			}
			else if (direction == "SE")
			{
				ball.direction = "NW";
				board[ball.x_position--][ball.y_position--] = ' ';
				board[ball.x_position][ball.y_position] = 'O';
			}
			else if (direction == "SW")
			{
				ball.direction = "NE";
				board[ball.x_position--][ball.y_position++] = ' ';
				board[ball.x_position][ball.y_position] = 'O';
			}
		}
	}

	bool checkBallX()
	{
		string direction = ball.direction;
		int x_position = ball.x_position;
		bool move = false;
		if (direction == "NE" || direction == "NW")
		{
			if (0 < --x_position)
				move = true;
		}
		else if (direction == "SE" || direction == "SW")
		{
			if (++x_position < rows - 1)
				move = true;
		}
		return move;
	}

	bool checkBallY()
	{
		string direction = ball.direction;
		int y_position = ball.y_position;
		bool move = false;
		if (direction == "NW" || direction == "SW")
		{
			if (0 < --y_position)
				move = true;
		}
		else if (direction == "NE" || direction == "SE")
		{
			if (++y_position < columns - 1)
				move = true;
		}
		
		return move;
	}
	
	void createPaddles()
	{
		player_one.setLength(3);
		player_one.setPosition(rows/2 - 2, columns - 1);
		for(int i = 0; i < player_one.length; i++)
		{
			board[player_one.x_position + i][player_one.y_position] = '|';
		}

		player_two.setLength(3);
		player_two.setPosition(rows/2 - 2, 0);
		for(int i = 0; i < player_two.length; i++)
		{
			board[player_two.x_position + i][player_two.y_position] = '|';
		}
	}

	void movePaddles(int key_pressed)
	{
		if (key_pressed == 72)
		{
			if (0 < player_one.x_position - 1)
			{
				board[--player_one.x_position][player_one.y_position] = '|';
				board[player_one.x_position + player_one.length][player_one.y_position] = ' ';
			}
		}
		else if (key_pressed == 80)
		{
			if (player_one.x_position + player_one.length < rows - 1)
			{
				board[player_one.x_position][player_one.y_position] = ' ';
				board[player_one.x_position++ + player_one.length][player_one.y_position] = '|';
			}
		}
		else if (key_pressed == 119)
		{
			if (0 < player_two.x_position - 1)
			{
				board[--player_two.x_position][player_two.y_position] = '|';
				board[player_two.x_position + player_two.length][player_two.y_position] = ' ';
			}
		}
		else if (key_pressed == 115)
		{
			if (player_two.x_position + player_two.length < rows - 1)
			{
				board[player_two.x_position][player_two.y_position] = ' ';
				board[player_two.x_position++ + player_two.length][player_two.y_position] = '|';
			}
		}
	}

	void resetGame()
	{
		createBall();
		//createPaddles();
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Gameboard board;
	Ball ball;
	int key = 0;
	
	board.initializeBoard();
	board.printBoard();
	
	while(true)
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == 72 || key == 80 || key == 119 || key == 115)
			{
				board.movePaddles(key);
			}
		}
		
		board.moveBall();
		Sleep(100);
		system("cls");
		board.printBoard();
	}

	return 0;
}