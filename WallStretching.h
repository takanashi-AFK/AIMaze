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
	/// 壁を伸ばす
	/// </summary>
	/// <param name="x">壁を置きたいX座標</param>
	/// <param name="y">壁を置きたいY座標</param>
	void ExtendedWall(int x, int y);

	vector<Float2Pos> evenPosList;
	vector<Float2Pos> CurrentWallCells;


	Float2Pos processingCell;


};

