#include <iostream>
#include <vector>

using namespace std;

int GetMax(int* list, int size)
{
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if(max < list[i])
			max = list[i];
	}
	return max;
}

int GetMaxTShape(int** paper, int n, int m, int row, int col)
{
	int count[4] = { 0, };
	if(row + 1 < n && col + 2 < m)
		count[0] = paper[row][col] + paper[row][col + 1] + paper[row][col + 2] + paper[row + 1][col + 1];
	if (row + 1 < n && col + 1 < m && col - 1 >= 0)
		count[1] = paper[row][col] + paper[row + 1][col + 1] + paper[row + 1][col - 1] + paper[row + 1][col];
	if (row + 2 < n && col - 1 >= 0)
		count[2] = paper[row][col] + paper[row + 1][col] + paper[row + 2][col] + paper[row + 1][col - 1];
	if (row + 2 < n && col + 1 < m)
		count[3] = paper[row][col] + paper[row + 1][col] + paper[row + 2][col] + paper[row + 1][col + 1];

	return GetMax(count, 4);
}

int GetMaxSShape(int** paper, int n, int m, int row, int col)
{
	int count[4] = {0,};
	if (row + 1 < n && col + 2 < m)
		count[0] = paper[row][col] + paper[row][col + 1] + paper[row + 1][col + 1] + paper[row + 1][col + 2];
	if (row + 1 < n && col + 1 < m && col - 1 >= 0)
		count[1] = paper[row][col] + paper[row][col + 1] + paper[row + 1][col] + paper[row + 1][col - 1];
	if (row + 2 < n && col + 1 < m)
		count[2] = paper[row][col] + paper[row + 1][col] + paper[row + 1][col + 1] + paper[row + 2][col + 1];
	if (row + 2 < n && col - 1 >= 0)
		count[3] = paper[row][col] + paper[row + 1][col] + paper[row + 1][col - 1] + paper[row + 2][col - 1];

	return GetMax(count, 4);
}

int GetMaxLShape(int** paper, int n, int m, int row, int col)
{
	int count[8] = {0,};
	if (row + 2 < n && col + 1 < m)
		count[0] = paper[row][col] + paper[row + 1][col] + paper[row + 2][col] + paper[row + 2][col + 1];
	if (row + 2 < n && col - 1 >= 0)
		count[1] = paper[row][col] + paper[row + 1][col] + paper[row + 2][col] + paper[row + 2][col - 1];
	if (row + 2 < n && col - 1 >= 0)
		count[2] = paper[row][col] + paper[row + 1][col] + paper[row + 2][col] + paper[row][col - 1];
	if (row + 2 < n && col + 1 < m)
		count[3] = paper[row][col] + paper[row + 1][col] + paper[row + 2][col] + paper[row][col + 1];
	if (row + 1 < n && col - 2 >= 0)
		count[4] = paper[row][col] + paper[row + 1][col] + paper[row][col - 1] + paper[row][col - 2];
	if (row + 1 < n && col + 2 < m)
		count[5] = paper[row][col] + paper[row + 1][col] + paper[row][col + 1] + paper[row][col + 2];
	if (row + 1 < n && col - 2 >= 0)
		count[6] = paper[row][col] + paper[row + 1][col] + paper[row + 1][col - 1] + paper[row + 1][col - 2];
	if (row + 1 < n && col + 2 < m)
		count[7] = paper[row][col] + paper[row + 1][col] + paper[row + 1][col + 1] + paper[row + 1][col + 2];


	return GetMax(count, 8);
}

int GetMaxBoxShape(int** paper, int n, int m, int row, int col)
{
	int count = 0;
	if (row + 1 < n && col + 1 < m)
	{
		count = paper[row][col] + paper[row + 1][col] + paper[row][col + 1] + paper[row + 1][col + 1];
	}

	return count;
}

int GetMaxLinearShape(int** paper, int n, int m, int row, int col)
{
	int count[2] = {0, 0};
	if (row + 3 < n)
	{
		for(int i = 0; i < 4; i++)
			count[0] += paper[row + i][col];
	}
	if (col + 3 < m)
	{
		for (int i = 0; i < 4; i++)
			count[1] += paper[row][col + i];
	}

	return GetMax(count, 2);
}

int main()
{
	int n, m;
	vector<int> countList;
	scanf("%d %d", &n, &m);

	int** paper = new int*[n];
	for (int i = 0; i < n; i++)
	{
		paper[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &paper[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			countList.push_back(GetMaxLinearShape(paper, n, m, i, j));
			countList.push_back(GetMaxBoxShape(paper, n, m, i, j));
			countList.push_back(GetMaxLShape(paper, n, m, i, j));
			countList.push_back(GetMaxSShape(paper, n, m, i, j));
			countList.push_back(GetMaxTShape(paper, n, m, i, j));
		}
	}
	
	printf("%d\n", GetMax(&countList[0], countList.size()));

	return 0;
}