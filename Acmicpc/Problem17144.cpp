#include <iostream>
#define MAX 50

using namespace std;

struct Point {
	int row;
	int col;
};

int room[MAX][MAX];
int row, col, t;
Point air_cleaners[2];

void spread()
{
	int room_spread[MAX][MAX];
	for (int i = 0; i < row; i++)
		fill(room_spread[i], room_spread[i] + col, 0);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (room[i][j] == -1)
				continue;

			int spreaded = 0;
			int spreading = room[i][j] / 5;
			if (i > 0)
			{
				if (room[i - 1][j] != -1)
				{
					spreaded += spreading;
					room_spread[i - 1][j] += spreading;
				}
				
			}
			if (j > 0)
			{
				if (room[i][j - 1] != -1)
				{
					spreaded += spreading;
					room_spread[i][j - 1] += spreading;
				}
			}
			if (i < row - 1)
			{
				if (room[i + 1][j] != -1)
				{
					spreaded += spreading;
					room_spread[i + 1][j] += spreading;
				}
			}
			if (j < col - 1)
			{
				if (room[i][j + 1] != -1)
				{
					spreaded += spreading;
					room_spread[i][j + 1] += spreading;
				}
			}
			room[i][j] -= spreaded;
		}
	}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (room[i][j] != -1)
				room[i][j] += room_spread[i][j];
}

void air_flow_upper()
{
	int cleaner_row = air_cleaners[0].row;
	int cleaner_col = air_cleaners[0].col;
	for (int r = cleaner_row - 1; r > 0; r--)
		room[r][cleaner_col] = room[r - 1][cleaner_col];
	for (int c = 0; c < col - 1; c++)
		room[0][c] = room[0][c + 1];
	for (int r = 0; r < cleaner_row; r++)
		room[r][col - 1] = room[r + 1][col - 1];
	for (int c = col - 1; c > 1; c--)
		room[cleaner_row][c] = room[cleaner_row][c - 1];
	room[cleaner_row][1] = 0;
}
void air_flow_below()
{
	int cleaner_row = air_cleaners[1].row;
	int cleaner_col = air_cleaners[1].col;
	for (int r = cleaner_row + 1; r < row - 1; r++)
		room[r][cleaner_col] = room[r + 1][cleaner_col];
	for (int c = 0; c < col - 1; c++)
		room[row - 1][c] = room[row - 1][c + 1];
	for (int r = row - 1; r > cleaner_row; r--)
		room[r][col - 1] = room[r - 1][col - 1];
	for (int c = col - 1; c > 1; c--)
		room[cleaner_row][c] = room[cleaner_row][c - 1];
	room[cleaner_row][1] = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cleaner = 0, sum = 0;

	cin >> row >> col >> t;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> room[i][j];
			if (room[i][j] == -1)
				air_cleaners[cleaner++] = { i, j };
		}
	}

	for (int k = 0; k < t; k++)
	{
		spread();
		air_flow_upper();
		air_flow_below();
	}

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (room[i][j] != -1)
				sum += room[i][j];

	cout << sum << endl;

	return 0;
}