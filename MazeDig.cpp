#include "MazeDig.h"

MazeDig::MazeDig()
{
}

MazeDig::MazeDig(int width, int height): Maze(width, height)
{
    // 全てを壁で埋める
           // 穴掘り開始候補(x,yともに偶数)座標を保持しておく
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (x == 0 || y == 0 || x == width - 1 || y == height - 1)
            {
                MapTable[x][y] = FLOOR;  // 外壁は判定の為通路にしておく(最後に戻す)
            }
            else
            {
                MapTable[x][y] = WALL;
            }
        }
    }
    //うんたらかんたら穴掘りして

      // 外壁を戻す
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
        // 掘り進めることができる方向のリストを作成
        list<int>direction;
        if (MapTable[x][y - 1] == WALL && MapTable[x][y - 2] == WALL)
            direction.push_back(Up);
        if (MapTable[x + 1][ y] == WALL && MapTable[x + 2][ y] == WALL)
            direction.push_back(Right);
        if (MapTable[x][ y + 1] == WALL && MapTable[x][ y + 2] == WALL)
            direction.push_back(Down);
        if (MapTable[x - 1][y] == WALL && MapTable[x - 2][y] == WALL)
            direction.push_back(Left);

        // 掘り進められない場合、ループを抜ける
        if (direction.size() == 0) break;

        // 指定座標を通路とし穴掘り候補座標から削除
        SetPath(x, y);
        // 掘り進められる場合はランダムに方向を決めて掘り進める
        var dirIndex = rnd.Next(direction.Count);
        // 決まった方向に先2マス分を通路とする
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
        // 穴掘り候補座標
        StartCells.push_back()
    }
}
