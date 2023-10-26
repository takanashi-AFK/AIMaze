#include "MazeDig.h"

MazeDig::MazeDig()
{
    width_ = 0;
    height_ = 0;
}

MazeDig::MazeDig(int width, int height): Maze(width, height)
{
    width_ = width;
    height_ = height;

    // �S�Ă�ǂŖ��߂�
         // ���@��J�n���(x,y�Ƃ��ɋ���)���W��ێ����Ă���
    for (int y = 0; y < height_; y++)
    {
        for (int x = 0; x < width_; x++)
        {
            if (x == 0 || y == 0 || x == width_ - 1 || y == height_ - 1)
            {
                MapTable[x][y] = FLOOR;  // �O�ǂ͔���̈גʘH�ɂ��Ă���(�Ō�ɖ߂�)
            }
            else
            {
                if (width_ % 2 == 1 && height_ % 2 == 1)
                    StartCells.push_back({x,y});
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
    if(StartCells.size()!=0)
    int random = rand() % StartCells.size();

    while (true)
    {
        // �@��i�߂邱�Ƃ��ł�������̃��X�g���쐬
        vector<int>direction;
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
        SetFloor(x, y);
        // �@��i�߂���ꍇ�̓����_���ɕ��������߂Č@��i�߂�
        int dirIndex = rand()% direction.size();
        // ���܂��������ɐ�2�}�X����ʘH�Ƃ���
        switch (direction[dirIndex])
        {
        case Up:
            SetFloor(x, --y);
            SetFloor(x, --y);
            break;
        case Right:
            SetFloor(++x, y);
            SetFloor(++x, y);
            break;
        case Down:
            SetFloor(x, ++y);
            SetFloor(x, ++y);
            break;
        case Left:
            SetFloor(--x, y);
            SetFloor(--x, y);
            break;
        }
    }

    // �ǂ��ɂ��@��i�߂��Ȃ��ꍇ�A���@��J�n�����W����@��Ȃ���
          // �����W�����݂��Ȃ��Ƃ��A���@�芮��
    cell startPos = GetStartCell();
    if (startPos.xPos != 0||startPos.yPos != 0)
    {
        Dig(startPos.xPos, startPos.yPos);
    }

}

void MazeDig::CreateMaze()
{

   
    //���񂽂炩�񂽂猊�@�肵��
    Dig(1, 1);

    // �O�ǂ�߂�
    for (int y = 0; y < height_; y++)
    {
        for (int x = 0; x < width_; x++)
        {
            if (x == 0 || y == 0 || x == width_ - 1 || y == height_ - 1)
            {
                MapTable[x][y] = WALL;
            }
        }
    }
}

void MazeDig::SetFloor(int x, int y)
{
    MapTable[x][y] = FLOOR;
    if (x % 2 == 1 && y % 2 == 1)
    {
        // ���@������W
       StartCells.push_back({ x, y });
    }
}

cell MazeDig::GetStartCell()
{
    if (StartCells.size() == 0) return {0,0};

    // �����_���ɊJ�n���W���擾����
    int index = rand() % StartCells.size();
    cell Start = StartCells[index];
    StartCells.erase(StartCells.begin()+index);

    return Start;
}
