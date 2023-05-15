#include <iostream>

using namespace std;

int n, m;
int board[500][500];
int dp[500][500];

int dfs(int row, int col)
{
	int rows[] = { 0, 0, 1, -1 };
	int cols[] = { 1, -1, 0, 0 };

	if (row == m - 1 && col == n - 1)
		return 1;

	if (dp[row][col] != -1)
		return dp[row][col];

	dp[row][col] = 0;

	for (int i = 0; i < 4; i++)
	{
		int nextRow = row + rows[i];
		int nextCol = col + cols[i];

		if ((0 <= nextRow && nextRow < m) && (0 <= nextCol && nextCol < n) && board[nextRow][nextCol] < board[row][col])
		{
			dp[row][col] += dfs(nextRow, nextCol);
		}
	}

	return dp[row][col];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < m; i++)
		fill(dp[i], dp[i] + n, -1);
	
	int res = dfs(0, 0);

 	cout << res << endl;

	return 0;
}