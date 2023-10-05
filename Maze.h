#pragma once
#include<vector>
#include<iostream>
using namespace std;
const int  WALL = 1;
const int FLOOR = 0;

class Maze
{
	public:
	Maze() {};
	Maze(int _Width, int _Height);

	int Width_ = 0;
	int Height_ = 0;

	std::vector<std::vector<int>> MapTable;
	void SetBrock(int _Width, int _Height);
	void PrintMaze();
	void MazeInitialize();
	void VectorInitialize(int _Width, int _Height);

};

