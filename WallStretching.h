#pragma once
#include "Maze.h"
#include<vector>
#include <algorithm>

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
class WallStretching : public Maze
{
public:
	WallStretching(int Width, int Height);
	void CreateWallStretching();
private:
	/// <summary>
	/// �ǂ�L�΂�
	/// </summary>
	/// <param name="x">�ǂ�u������X���W</param>
	/// <param name="y">�ǂ�u������Y���W</param>
	void ExtendWall(int x, int y);

	bool IsCurrentWall(int x, int y);

	void SetWall(int x,int y);

	vector<cell> evenPosList;
	vector<cell> currentWallCells;


	cell processingCell;
	cell tempCell = {};



};

