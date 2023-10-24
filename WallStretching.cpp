#include "WallStretching.h"

WallStretching::WallStretching(int Width, int Height): Maze(Width, Height)
{
	Float2Pos temp = {0,0};
	for (int h = 0; h < Height_; h++)
	{
		for (int w = 0; w < Width_; w++)
		{
			if (w >= 1 && w < Width_ - 1 && h >= 1 && h < Height_ - 1)//外壁じゃなくて
				if (w % 2 == 0 && h % 2 == 0)//偶数位置だったらリストに追加
				{
					temp = { w,h};
					evenPosList.push_back(temp);
				}
		}
	}
}

void WallStretching::CreateWallStretching()
{
	int count = 0;
	while (evenPosList.size())//リストの中身が0になるまで
	{
		int randomValue = rand() % evenPosList.size();
		processingCell = evenPosList[randomValue];
		evenPosList.erase(evenPosList.begin() + randomValue);//要素を削除

		if (MapTable[processingCell.xPos][processingCell.yPos] == FLOOR)
		{
			CurrentWallCells.clear();

		}

	}
	
	
}

//開始地点を指定
//ランダムに１マス伸ばす
//CurrentWallCellsに伸ばした位置を追加
//もしCurrentWallCellsにぶつかったら,一ますもどって再抽選
void WallStretching::ExtendedWall(int x, int y)
{

}
