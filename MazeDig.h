#pragma once
#include<vector>
#include<list>
#include"Maze.h"
#include"WallStretching.h"
using std::vector;
using std::list;


class MazeDig:public Maze
{
public:
	MazeDig();
	MazeDig(int Width, int Height);
	~MazeDig();

	void Dig(int x, int y);
	void CreateMaze();

private:
	vector <cell> StartCells;
	vector <cell> currentCells;
	void SetFloor(int x, int y);
	cell GetStartCell();

	cell temp;

	int height_;
	int width_;
};

