#pragma once
#include<vector>
#include<iostream>
using namespace std;
const int  WALL = 1;
const int FLOOR = 0;

struct cell
{
	cell() {};
	cell(int x, int y) { x = xPos; y = yPos; }
	int xPos = 0;
	int yPos = 0;
};

enum Direction
{
	Up = 0,
	Right = 1,
	Down = 2,
	Left = 3
};


class Maze
{
	public:
	Maze() {};
	Maze(int _Width, int _Height);
	~Maze();

	int Width_ = 0;
	int Height_ = 0;

	std::vector<std::vector<int>> MapTable;
	void SetBlock(int _Width, int _Height);
	//void SetBrock(std::vector<std::vector<int>> _MapTable);
	void PrintMaze();
	void MazeInitialize();
	bool IsWall(int w , int h);
};

