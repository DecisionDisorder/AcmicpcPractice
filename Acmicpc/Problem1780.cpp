#include <iostream>

using namespace std;

int counts[3] {0,};

void divide(int **paper, int row, int col, int size, const int entireSize)
{
	if (row < entireSize && col < entireSize)
	{
		if (size > 1)
		{
			int std = paper[row][col];
			bool passed = true;
			for (int i = row; i < row + size; i++)
			{
				for (int j = col; j < col + size; j++)
				{
					if (paper[i][j] != std)
					{
						passed = false;
						break;
					}
				}

				if(!passed)
					break;
			}

			if (passed)
			{
				counts[std + 1]++;
			}
			else
			{
				int decreasedSize = size / 3;
				divide(paper, row,						col,				decreasedSize ,entireSize);
				divide(paper, row + decreasedSize,		col,				decreasedSize, entireSize);
				divide(paper, row + decreasedSize * 2,	col,				decreasedSize, entireSize);
				divide(paper, row,						col + decreasedSize, decreasedSize, entireSize);
				divide(paper, row + decreasedSize,		col + decreasedSize, decreasedSize, entireSize);
				divide(paper, row + decreasedSize * 2,	col + decreasedSize, decreasedSize, entireSize);
				divide(paper, row,						col + decreasedSize * 2, decreasedSize, entireSize);
				divide(paper, row + decreasedSize,		col + decreasedSize * 2, decreasedSize, entireSize);
				divide(paper, row + decreasedSize * 2,	col + decreasedSize * 2, decreasedSize, entireSize);
			}
		}
		else
			counts[paper[row][col] + 1]++;
	}
}

int main()
{
	int size;
	cin >> size;

	int** paper = new int*[size];
	for (int i = 0; i < size; i++)
	{
		paper[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			cin >> paper[i][j];
		}
	}

	divide(paper, 0, 0, size, size);

	cout << counts[0] << endl << counts[1] << endl << counts[2] << endl;
	
	return 0;
}