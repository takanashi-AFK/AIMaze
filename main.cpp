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

	MazeBar* bar = new MazeBar(MAPWIDTH, MAPHEIGHT);
	bar->MazeInitialize();
	bar->BarInitialize();
	bar->PrintMaze();
	delete bar;
}