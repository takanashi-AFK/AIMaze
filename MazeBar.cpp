#include "MazeBar.h"
MazeBar::MazeBar(int Width, int Height):Maze(Width,Height)
{
}

void MazeBar::BarInitialize()
{
	for (int h = 0; h < Height_; h++)
	{	
		for (int w = 0; w < Width_; w++)
		{
			if (w % 2 == 0 && h % 2 == 0)
				SetBrock(h, w);
		}
	}
}
;

void MazeBar::KnockDownThePole()
{
	//�_�̃|�W�V���������
	//���̈ʒu����㉺���E4�_���
	//������ԏゾ������->�����_����4�_����ē|��
	//����ȊO���������ȊO��3�_����Ă����ɓ|��
	//�����|���悪���łɕǂ������炻���ȊO�ɓ|��
}


