#include<iostream>
#include<string>
#include<vector>
#include"MazeBar.h"
#include"Maze.h"

using namespace std;
const int MAPWIDTH = 15;
const int MAPHEIGHT = 15;

int main()
{
	srand(time(NULL));

	MazeBar* bar = new MazeBar(MAPWIDTH, MAPHEIGHT);
	bar->MazeInitialize();
	bar->BarInitialize();
	bar->KnockDownThePole();
	bar->PrintMaze();
	delete bar;
}