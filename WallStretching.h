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

