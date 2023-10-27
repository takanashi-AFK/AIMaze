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
	/*
	int mode = 0;
	cin >> mode;

	switch (mode)
	{
	case 0:
		MazeBar * bar = new MazeBar(MAPWIDTH, MAPHEIGHT);
		bar->MazeInitialize();
		bar->BarInitialize();
		bar->PrintMaze();
		delete bar;
		break;
	case 1:
		WallStretching* wst = new WallStretching(MAPWIDTH, MAPHEIGHT);
	wst->MazeInitialize();
	wst->CreateWallStretching();
	wst->PrintMaze();
	delete wst;
		break;
	case 2:
		break;
	}
	*/

	//MazeBar* bar = new MazeBar(MAPWIDTH, MAPHEIGHT);
	//bar->MazeInitialize();
	//bar->BarInitialize();
	//bar->PrintMaze();
	//delete bar;

	/*WallStretching* wst = new WallStretching(MAPWIDTH, MAPHEIGHT);
	wst->MazeInitialize();
	wst->CreateWallStretching();
	wst->PrintMaze();
	delete wst;*/
	MazeDig *dig = new MazeDig(MAPWIDTH, MAPHEIGHT);
	dig->CreateMaze();
	dig->PrintMaze();
	delete dig;


}