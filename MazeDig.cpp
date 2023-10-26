#include "MazeDig.h"

MazeDig::MazeDig()
{
}

MazeDig::MazeDig(int width, int height): Maze(width, height)
{
    // �S�Ă�ǂŖ��߂�
           // ���@��J�n���(x,y�Ƃ��ɋ���)���W��ێ����Ă���
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (x == 0 || y == 0 || x == width - 1 || y == height - 1)
            {
                MapTable[x][y] = FLOOR;  // �O�ǂ͔���̈גʘH�ɂ��Ă���(�Ō�ɖ߂�)
            }
            else
            {
                MapTable[x][y] = WALL;
            }
        }
    }
    //���񂽂炩�񂽂猊�@�肵��

      // �O�ǂ�߂�
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (x == 0 || y == 0 || x ==width - 1 || y ==height - 1)
            {
                MapTable[x][y] = WALL;
            }
        }
    }
}

MazeDig::~MazeDig()
{
}

void MazeDig::Dig(int x, int y)
{
    int random = rand() % StartCells.size();

    while (true)
    {
        // �@��i�߂邱�Ƃ��ł�������̃��X�g���쐬
        list<int>direction;
        if (MapTable[x][y - 1] == WALL && MapTable[x][y - 2] == WALL)
            direction.push_back(Up);
        if (MapTable[x + 1][ y] == WALL && MapTable[x + 2][ y] == WALL)
            direction.push_back(Right);
        if (MapTable[x][ y + 1] == WALL && MapTable[x][ y + 2] == WALL)
            direction.push_back(Down);
        if (MapTable[x - 1][y] == WALL && MapTable[x - 2][y] == WALL)
            direction.push_back(Left);

        // �@��i�߂��Ȃ��ꍇ�A���[�v�𔲂���
        if (direction.size() == 0) break;

        // �w����W��ʘH�Ƃ����@������W����폜
        SetPath(x, y);
        // �@��i�߂���ꍇ�̓����_���ɕ��������߂Č@��i�߂�
        var dirIndex = rnd.Next(direction.Count);
        // ���܂��������ɐ�2�}�X����ʘH�Ƃ���
        switch (direction[dirIndex])
        {
        case Up:
            SetPath(x, --y);
            SetPath(x, --y);
            break;
        case Right:
            SetPath(++x, y);
            SetPath(++x, y);
            break;
        case Down:
            SetPath(x, ++y);
            SetPath(x, ++y);
            break;
        case Left:
            SetPath(--x, y);
            SetPath(--x, y);
            break;
        }
    }
}

void MazeDig::SetFloor(int x, int y)
{
    MapTable[x][y] = FLOOR;
    if (x % 2 == 1 && y % 2 == 1)
    {
        // ���@������W
        StartCells.push_back()
    }
}
