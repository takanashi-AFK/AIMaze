#include "WallStretching.h"

WallStretching::WallStretching(int Width, int Height): Maze(Width, Height)
{
	cell temp = {0,0};
	for (int h = 0; h < Height_; h++)
	{
		for (int w = 0; w < Width_; w++)
		{
			if (w >= 1 && w < Width_ - 1 && h >= 1 && h < Height_ - 1)//外壁じゃなくて
				if (w % 2 == 0 && h % 2 == 0)//偶数位置だったらリストに追加
				{
					temp = {w,h};
					evenPosList.push_back(cell(0,0));
				}
		}
	}
}

WallStretching::~WallStretching()
{
	evenPosList.clear();
	currentWallCells.clear();
}

void WallStretching::CreateWallStretching()
{
	while (evenPosList.size())//リストの中身が0になるまで
	{
		int randomValue = rand() % evenPosList.size();
		processingCell = evenPosList[randomValue];
		evenPosList.erase(evenPosList.begin() + randomValue);//要素を削除
		int x = processingCell.xPos;
		int y = processingCell.yPos;
		if (MapTable[x][y] == FLOOR)
		{
			currentWallCells.clear();
			ExtendWall(x, y);
		}
	}
}

//開始地点を指定
//ランダムに１マス伸ばす
//CurrentWallCellsに伸ばした位置を追加
//もしCurrentWallCellsにぶつかったら,一ますもどって再抽選

//ここの再起処理が原因でstafck over flow発生 
void WallStretching::ExtendWall(int x, int y)
{
	vector<int>directions;

	//次のブロックがFLOORか？次の次のブロックは伸ばしてる最中のやつか？
	if (MapTable[x][y - 1] == FLOOR && !IsCurrentWall(x, y - 2))//上
		directions.push_back(Up);

	if (MapTable[x][y + 1] == FLOOR && !IsCurrentWall(x, y + 2))//下
		directions.push_back(Down);

	if (MapTable[x + 1][y] == FLOOR && !IsCurrentWall(x + 2, y))//右
		directions.push_back(Right);

	if (MapTable[x - 1][y] == FLOOR && !IsCurrentWall(x - 2, y))//左
		directions.push_back(Left);

	// ランダムに伸ばす(2マス)
	if (directions.size() > 0)
	{
		// 壁を作成(この地点から壁を伸ばす)
		SetWall(x, y);

		// 伸ばす先が通路の場合は拡張を続ける
		bool isFloor = false;
		int dirIndex = rand() % directions.size();
		switch (directions[dirIndex])
		{
		case Up:
			isFloor = (MapTable[x][y - 2] == FLOOR);
			SetWall(x, --y);
			SetWall(x, --y);
			break;
		case Right:
			isFloor = (MapTable[x + 2][y] == FLOOR);
			SetWall(++x, y);
			SetWall(++x, y);
			break;
		case Down:
			isFloor = (MapTable[x][y + 2] == FLOOR);
			SetWall(x, ++y);
			SetWall(x, ++y);
			break;
		case Left:
			isFloor = (MapTable[x - 2][y] == FLOOR);
			SetWall(--x, y);
			SetWall(--x, y);
			break;
		}
		if (isFloor)
		{
			// 既存の壁に接続できていない場合は拡張続行
			ExtendWall(x, y);

		}
	}	
		else
		{
			// すべて現在拡張中の壁にぶつかる場合、バックして再開
		cell  beforeCell = currentWallCells[sizeof(currentWallCells)-1];
			ExtendWall(beforeCell.xPos, beforeCell.yPos);
		}
}

	bool WallStretching::IsCurrentWall(int x, int y)
	{ 
		if (!currentWallCells.empty())
		for (auto& wall : currentWallCells) {
			if (wall.xPos == x && wall.yPos == y)
				return true;
		}
		return false;
	}
	
void WallStretching::SetWall(int x, int y)
{
	MapTable[x][y] = WALL;
	if (x % 2 == 0 && y % 2 == 0)//偶数だったらリストに追加
	{
		tempCell = { x,y };
	}
		currentWallCells.push_back(tempCell);
}