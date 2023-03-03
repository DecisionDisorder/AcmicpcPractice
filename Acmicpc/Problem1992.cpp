#include <iostream>
#include <string>
using namespace std;

void divide(int** qtree, int size, int row, int col, string& result)
{
	if (size == 1)
	{
		result.append(to_string(qtree[row][col]));
		return;
	}

	bool allSame = true;
	for (int i = row; i < row + size; i++)
	{
		for (int j = col; j < col + size; j++)
		{
			if (qtree[row][col] != qtree[i][j])
			{
				result.append("(");
				allSame = false;
				break;
			}
		}
		if(!allSame)
			break;
	}
	if (allSame)
	{
		result.append(to_string(qtree[row][col]));
	}
	else
	{
		int half = size / 2;
		divide(qtree, half, row, col, result);
		divide(qtree, half, row, col + half, result);
		divide(qtree, half, row + half, col, result);
		divide(qtree, half, row + half, col + half, result);
		result.append(")");
	}
}

int main()
{
	string result = "";
	int size;
	scanf("%d", &size);

	int** quadtree = new int*[size];

	for (int i = 0; i < size; i++)
	{
		quadtree[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			scanf("%1d", &quadtree[i][j]);
		}
	}

	divide(quadtree, size, 0, 0, result);

	cout << result << endl;

	return 0;
}