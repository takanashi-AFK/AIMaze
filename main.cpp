#include<iostream>
#include<string>
#include<vector>
#include"MazeBar.h"
#include"Maze.h"

using namespace std;
const int MAPWIDTH = 51;
const int MAPHEIGHT =51;

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
		return;
	case 1:
		return;
	case 2:
		return;
	}
	*/
	MazeBar* bar = new MazeBar(MAPWIDTH, MAPHEIGHT);
	bar->MazeInitialize();
	bar->BarInitialize();
	bar->PrintMaze();
	delete bar;
}