#pragma once
#include<vector>
#include<list>
#include"Maze.h"
using std::vector;
using std::list;

struct cell
{
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


class MazeDig:public Maze
{
public:
	MazeDig();
	MazeDig(int Width, int Height);
	~MazeDig();

	void Dig(int x, int y);

private:
	vector <cell> StartCells;
	void SetFloor(int x, int y);


};

