#include "Maze.h"


Maze::Maze(int _Width, int _Height)
{
	MapTable = vector<vector<int>>(_Height, vector<int>(_Width, 0));
	Width_ = _Width;
	Height_ = _Height;
}
void Maze::SetBlock(int _Height, int _Width)
{
	MapTable[_Height][_Width] = WALL;
}



void Maze::PrintMaze()
{
	for (int h = 0; h < Height_; h++)
	{
		cout << endl;
		for (int w = 0; w < Width_; w++)
		{
			if (MapTable[h][w] == WALL)
				cout << "¡";
			else if (MapTable[h][w] == FLOOR)
				cout << " ";
		}
	}
}


void Maze::MazeInitialize()
{
	for (int h = 0; h < Height_; h++)
	{
		for (int w = 0; w < Width_; w++)
		{
			if (w == 0 || w == Width_ - 1 || h == 0 || h == Height_ - 1)
				SetBlock(h,w);
		}
	}
}

bool Maze::IsWall(int w, int h)
{
	if (MapTable[w][h] == WALL)
		return true;
	return false;
}


