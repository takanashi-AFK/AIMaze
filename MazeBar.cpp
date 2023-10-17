#include "MazeBar.h"
MazeBar::MazeBar(int Width, int Height):Maze(Width,Height)
{	
}

void MazeBar::BarInitialize()
{
	for (int h = 0; h < Height_; h++)
	{	
		for (int w = 0; w < Width_; w++)
		{
			if (w % 2 == 0 && h % 2 == 0)
				SetBrock(h, w);
		}
	}

	for (int h = 0; h < Height_; h++)
	{
		for (int w = 0; w < Width_; w++)
		{
			//もし棒の位置だったら
			if (w % 2 == 0 && h % 2 == 0)
			{
				if (w >= 1 && w < Width_ - 1 && h >= 1 && h < Height_)
				{
					//一番上だったら
					if (w == 2 && h == 2)
					{
						int randum = rand() % 4;

					}
				}
			}
		}
	}

}
;

void MazeBar::KnockDownThePole()
{
	//棒のポジションを取る
	//その位置から上下左右4点取る
	//もし一番上だったら->ランダムで4点取って倒す
	//それ以外だったら上以外の3点取ってそこに倒す
	//もし倒す先がすでに壁だったらそこ以外に倒す

	//全部見る
	for (int h = 0; h < Height_; h++)
	{
		for (int w = 0; w < Width_; w++)
		{
			//もし棒の位置だったら
			if (w % 2 == 0 && h % 2 == 0)
			{
				if (w >=1 && w < Width_-1 &&h >= 1 && h <Height_)
				{
					//一番上だったら
					if (w == 2 && h == 2)
					{
						int randum = rand() % 4;

					}
				}
			}
		}
	}
}


