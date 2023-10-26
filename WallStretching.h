#pragma once
#include "Maze.h"
#include<vector>
#include <algorithm>

class WallStretching : public Maze
{
public:
	WallStretching(int Width, int Height);
	~WallStretching();
	void CreateWallStretching();
private:
	/// <summary>
	/// 壁を伸ばす
	/// </summary>
	/// <param name="x">壁を置きたいX座標</param>
	/// <param name="y">壁を置きたいY座標</param>
	void ExtendWall(int x, int y);

	bool IsCurrentWall(int x, int y);

	void SetWall(int x,int y);

	vector<cell> evenPosList;
	vector<cell> currentWallCells;


	cell processingCell;
	cell tempCell = {};



};

