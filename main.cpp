#include<iostream>
#include<string>
#include<vector>
#include"MazeBar.h"
#include"Maze.h"
#include"WallStretching.h"
#include "MazeDig.h"
using namespace std;
const int MAPWIDTH  = 51;
const int MAPHEIGHT = 51;

int main()
{
	srand(time(NULL));
	
	WallStretching* wst = new WallStretching(MAPWIDTH, MAPHEIGHT);
	MazeBar * bar = new MazeBar(MAPWIDTH, MAPHEIGHT);
	MazeDig *dig = new MazeDig(MAPWIDTH, MAPHEIGHT);
	int mode = 0;
	cin >> mode;

	switch (mode)
	{
	case 0:
		bar->MazeInitialize();
		bar->BarInitialize();
		bar->PrintMaze();
		break;
	case 1:
		wst->MazeInitialize();
		wst->CreateWallStretching();
		wst->PrintMaze();
		break;
	case 2:
		dig->CreateMaze();
		dig->PrintMaze();
		break;
	}
	

		delete wst;
		delete dig;	
		delete bar;
	
	


}