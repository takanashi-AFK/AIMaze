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
}
;

void MazeBar::KnockDownThePole()
{
	//棒のポジションを取る
	//その位置から上下左右4点取る
	//もし一番上だったら->ランダムで4点取って倒す
	//それ以外だったら上以外の3点取ってそこに倒す
	//もし倒す先がすでに壁だったらそこ以外に倒す
}


