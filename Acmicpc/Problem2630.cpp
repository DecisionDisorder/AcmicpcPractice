#include <iostream>

using namespace std;

void split(int **paper, int size, int row, int col, int& blueCount, int& whiteCount)
{
	if (size > 1)
	{
		bool bAllSame = true;
		int z = paper[row][col];
		for (int i = row; i < row + size; i++)
		{
			for (int j = col; j < col + size; j++)
			{
				if (paper[i][j] != z)
				{
					bAllSame = false;
					break;
				}
			}
			if(!bAllSame)
				break;
		}

		if (bAllSame)
		{
			if (paper[row][col])
				blueCount++;
			else
				whiteCount++;
		}
		else
		{
			int half = size / 2;
			split(paper, half, row, col, blueCount, whiteCount);
			split(paper, half, row + half, col, blueCount, whiteCount);
			split(paper, half, row, col + half, blueCount, whiteCount);
			split(paper, half, row + half, col + half, blueCount, whiteCount);
		}
	}
	else
	{
		if(paper[row][col])
			blueCount++;
		else
			whiteCount++;
	}
}

int main()
{
	int size, blueCount = 0, whiteCount = 0;
	int** paper;
	cin >> size;
	
	paper = new int*[size];
	for (int i = 0; i < size; i++)
	{
		paper[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			cin >> paper[i][j];
		}
	}

	split(paper, size, 0, 0, blueCount, whiteCount);

	cout << whiteCount << endl << blueCount << endl;

	return 0;
}