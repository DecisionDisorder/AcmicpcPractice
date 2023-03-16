#include <iostream>
#include <queue>

using namespace std;

int** map;
int n, m;

bool checkVirusSpread(int row, int col)
{
	if (0 <= row && row < n && 0 <= col && col < m)
	{
		if (map[row][col] == 0)
			return true;
		else
			return false;
	}
	else
		return false;
}

void virusSpread(queue<pair<int, int>> virusQue)
{
	while (!virusQue.empty())
	{
		int row = virusQue.front().first;
		int col = virusQue.front().second;
		virusQue.pop();

		if (checkVirusSpread(row + 1, col))
		{
			map[row + 1][col] = 3;
			virusQue.push({row + 1, col});
		}
		if (checkVirusSpread(row, col + 1))
		{
			map[row][col + 1] = 3;
			virusQue.push({ row, col + 1 });
		}
		if (checkVirusSpread(row - 1, col))
		{
			map[row - 1][col] = 3;
			virusQue.push({ row - 1, col });
		}
		if (checkVirusSpread(row, col - 1))
		{
			map[row][col - 1] = 3;
			virusQue.push({ row, col - 1 });
		}
	}
}

void print()
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int max = 0;
	cin >> n >> m;
	map = new int* [n];

	queue<pair<int, int>> virusQue;

	for (int i = 0; i < n; i++)
	{
		map[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
				virusQue.push({ i, j });
		}
	}

	for (int a = 0; a < n * m; a++)
	{
		int i1 = a / m, j1 = a % m;
		if (map[i1][j1] > 0)
			continue;
		map[i1][j1] = 1;

		for (int b = a + 1; b < n * m; b++)
		{
			int i2 = b / m, j2 = b % m;
			if (map[i2][j2] > 0)
				continue;
			map[i2][j2] = 1;

			for (int c = 0; c < n * m; c++)
			{
				int i3 = c / m, j3 = c % m;
				if (map[i3][j3] > 0)
					continue;

				map[i3][j3] = 1;

				virusSpread(virusQue);

				int count = 0;
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						if (map[i][j] == 0)
							count++;
						else if (map[i][j] == 3)
							map[i][j] = 0;
					}
				}

				if (max < count)
					max = count;

				map[i3][j3] = 0;
			}
			map[i2][j2] = 0;
		}
		map[i1][j1] = 0;
	}

	cout << max << endl;
	return 0;
}