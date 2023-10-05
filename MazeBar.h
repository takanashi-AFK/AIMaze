#pragma once
#include "Maze.h"
using namespace std;

class  MazeBar: public Maze
{
public:
	MazeBar(int Width,int Height);
	void BarInitialize();
	void KnockDownThePole();
};

