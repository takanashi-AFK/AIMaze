#include "MazeBar.h"


void MazeBar::Initialize(int _Width, int _Height)
{

	vector<vector<int>> MapTable(_Width, vector<int>(_Height, 0));
	for (int h = 1;h < _Height; h++)
	{
		cout << endl;
		for (int w = 1; w < _Width; w++)
		{
			if (w == 1 || w == _Width-1)
				MapTable[w][h] = 1;
			else
				MapTable[w][h] = 0;

			cout << MapTable[w][h];
		}
	}
}
