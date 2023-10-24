#pragma once
#include "Maze.h"
#include<vector>
#include <algorithm>

struct Float2Pos
{
	int xPos = 0;
	int yPos = 0;
};
class WallStretching : public Maze
{
private:
	WallStretching(int Width, int Height);
	void CreateWallStretching();
	/// <summary>
	/// �ǂ�L�΂�
	/// </summary>
	/// <param name="x">�ǂ�u������X���W</param>
	/// <param name="y">�ǂ�u������Y���W</param>
	void ExtendedWall(int x, int y);

	vector<Float2Pos> evenPosList;
	vector<Float2Pos> CurrentWallCells;


	Float2Pos processingCell;


};

