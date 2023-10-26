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

    // 全てを壁で埋める
         // 穴掘り開始候補(x,yともに偶数)座標を保持しておく
    for (int y = 0; y < height_; y++)
    {
        for (int x = 0; x < width_; x++)
        {
            if (x == 0 || y == 0 || x == width_ - 1 || y == height_ - 1)
            {
                MapTable[x][y] = FLOOR;  // 外壁は判定の為通路にしておく(最後に戻す)
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
        // 掘り進めることができる方向のリストを作成
        vector<int>direction;
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
        SetFloor(x, y);
        // 掘り進められる場合はランダムに方向を決めて掘り進める
        int dirIndex = rand()% direction.size();
        // 決まった方向に先2マス分を通路とする
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

    // どこにも掘り進められない場合、穴掘り開始候補座標から掘りなおし
          // 候補座標が存在しないとき、穴掘り完了
    cell startPos = GetStartCell();
    if (startPos.xPos != 0||startPos.yPos != 0)
    {
        Dig(startPos.xPos, startPos.yPos);
    }

}

void MazeDig::CreateMaze()
{

   
    //うんたらかんたら穴掘りして
    Dig(1, 1);

    // 外壁を戻す
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
        // 穴掘り候補座標
       StartCells.push_back({ x, y });
    }
}

cell MazeDig::GetStartCell()
{
    if (StartCells.size() == 0) return {0,0};

    // ランダムに開始座標を取得する
    int index = rand() % StartCells.size();
    cell Start = StartCells[index];
    StartCells.erase(StartCells.begin()+index);

    return Start;
}
