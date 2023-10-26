#include "WallStretching.h"

WallStretching::WallStretching(int Width, int Height): Maze(Width, Height)
{
	cell temp = {0,0};
	for (int h = 0; h < Height_; h++)
	{
		for (int w = 0; w < Width_; w++)
		{
			if (w >= 1 && w < Width_ - 1 && h >= 1 && h < Height_ - 1)//�O�ǂ���Ȃ���
				if (w % 2 == 0 && h % 2 == 0)//�����ʒu�������烊�X�g�ɒǉ�
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
	while (evenPosList.size())//���X�g�̒��g��0�ɂȂ�܂�
	{
		int randomValue = rand() % evenPosList.size();
		processingCell = evenPosList[randomValue];
		evenPosList.erase(evenPosList.begin() + randomValue);//�v�f���폜
		int x = processingCell.xPos;
		int y = processingCell.yPos;
		if (MapTable[x][y] == FLOOR)
		{
			currentWallCells.clear();
			ExtendWall(x, y);
		}
	}
}

//�J�n�n�_���w��
//�����_���ɂP�}�X�L�΂�
//CurrentWallCells�ɐL�΂����ʒu��ǉ�
//����CurrentWallCells�ɂԂ�������,��܂����ǂ��čĒ��I

//�����̍ċN������������stafck over flow���� 
void WallStretching::ExtendWall(int x, int y)
{
	vector<int>directions;

	//���̃u���b�N��FLOOR���H���̎��̃u���b�N�͐L�΂��Ă�Œ��̂���H
	if (MapTable[x][y - 1] == FLOOR && !IsCurrentWall(x, y - 2))//��
		directions.push_back(Up);

	if (MapTable[x][y + 1] == FLOOR && !IsCurrentWall(x, y + 2))//��
		directions.push_back(Down);

	if (MapTable[x + 1][y] == FLOOR && !IsCurrentWall(x + 2, y))//�E
		directions.push_back(Right);

	if (MapTable[x - 1][y] == FLOOR && !IsCurrentWall(x - 2, y))//��
		directions.push_back(Left);

	// �����_���ɐL�΂�(2�}�X)
	if (directions.size() > 0)
	{
		// �ǂ��쐬(���̒n�_����ǂ�L�΂�)
		SetWall(x, y);

		// �L�΂��悪�ʘH�̏ꍇ�͊g���𑱂���
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
			// �����̕ǂɐڑ��ł��Ă��Ȃ��ꍇ�͊g�����s
			ExtendWall(x, y);

		}
	}	
		else
		{
			// ���ׂČ��݊g�����̕ǂɂԂ���ꍇ�A�o�b�N���čĊJ
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
	if (x % 2 == 0 && y % 2 == 0)//�����������烊�X�g�ɒǉ�
	{
		tempCell = { x,y };
	}
		currentWallCells.push_back(tempCell);
}