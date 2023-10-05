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
	MazeBar* bar = new MazeBar(MAPWIDTH, MAPHEIGHT);
	bar->MazeInitialize();
	bar->BarInitialize();
	bar->PrintMaze();
	delete bar;
}