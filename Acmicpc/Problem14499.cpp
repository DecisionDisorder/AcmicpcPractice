#include <iostream>

using namespace std;

int n, m, dice_col, dice_row, k;
int map[20][20];
int commands[1000];

int dice_horizontal[4];
int dice_vertical[4];

pair<int, int> directions[] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

void MoveDice(int dir)
{
	if ((0 <= dice_row + directions[dir].first && dice_row + directions[dir].first < n) && (0 <= dice_col + directions[dir].second && dice_col + directions[dir].second < m))
	{
		if (dir == 0)
		{
			int tmp = dice_horizontal[0];
			for (int i = 0; i < 3; i++)
				dice_horizontal[i] = dice_horizontal[i + 1];
			dice_horizontal[3] = tmp;
			dice_vertical[3] = dice_horizontal[1];
			dice_vertical[1] = dice_horizontal[3];
		}
		else if (dir == 1)
		{
			int tmp = dice_horizontal[3];
			for (int i = 3; i > 0; i--)
				dice_horizontal[i] = dice_horizontal[i - 1];
			dice_horizontal[0] = tmp;
			dice_vertical[3] = dice_horizontal[1];
			dice_vertical[1] = dice_horizontal[3];
		}
		else if (dir == 2)
		{
			int tmp = dice_vertical[0];
			for (int i = 0; i < 3; i++)
				dice_vertical[i] = dice_vertical[i + 1];
			dice_vertical[3] = tmp;
			dice_horizontal[1] = dice_vertical[3];
			dice_horizontal[3] = dice_vertical[1];
		}
		else
		{
			int tmp = dice_vertical[3];
			for (int i = 3; i > 0; i--)
				dice_vertical[i] = dice_vertical[i - 1];
			dice_vertical[0] = tmp;
			dice_horizontal[1] = dice_vertical[3];
			dice_horizontal[3] = dice_vertical[1];
		}

		dice_row += directions[dir].first;
		dice_col += directions[dir].second;

		if (map[dice_row][dice_col] == 0)
		{
			map[dice_row][dice_col] = dice_vertical[3];
		}
		else
		{
			dice_vertical[3] = map[dice_row][dice_col];
			dice_horizontal[1] = map[dice_row][dice_col];
			map[dice_row][dice_col] = 0;
		}

 		cout << dice_vertical[1] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> dice_row >> dice_col >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		cin >> commands[i];
		commands[i]--;
	}

	for (int i = 0; i < k; i++)
	{
		MoveDice(commands[i]);
	}

	return 0;
}