#include "WallStretching.h"

WallStretching::WallStretching(int Width, int Height): Maze(Width, Height)
{
	Float2Pos temp = {0,0};
	for (int h = 0; h < Height_; h++)
	{
		for (int w = 0; w < Width_; w++)
		{
			if (w >= 1 && w < Width_ - 1 && h >= 1 && h < Height_ - 1)//�O�ǂ���Ȃ���
				if (w % 2 == 0 && h % 2 == 0)//�����ʒu�������烊�X�g�ɒǉ�
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
	while (evenPosList.size())//���X�g�̒��g��0�ɂȂ�܂�
	{
		int randomValue = rand() % evenPosList.size();
		processingCell = evenPosList[randomValue];
		evenPosList.erase(evenPosList.begin() + randomValue);//�v�f���폜

		if (MapTable[processingCell.xPos][processingCell.yPos] == FLOOR)
		{
			CurrentWallCells.clear();

		}

	}
	
	
}

//�J�n�n�_���w��
//�����_���ɂP�}�X�L�΂�
//CurrentWallCells�ɐL�΂����ʒu��ǉ�
//����CurrentWallCells�ɂԂ�������,��܂����ǂ��čĒ��I
void WallStretching::ExtendedWall(int x, int y)
{

}
