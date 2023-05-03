#include <iostream>
#include <vector>
using namespace std;

int r, c;
char board[20][21];

int dfs(int row, int col, int depth, vector<bool>& visited);

void visit(int row, int col, int depth, int& max_length, vector<bool>& visited)
{
	if (!visited[board[row][col] - 'A'])
	{
		visited[board[row][col] - 'A'] = true;
		int res = dfs(row, col, depth + 1, visited);
		max_length = max(res, max_length);
		visited[board[row][col] - 'A'] = false;
	}
}

int dfs(int row, int col, int depth, vector<bool>& visited)
{
	int max_length = depth;
	if (row > 0)
		visit(row - 1, col, depth, max_length, visited);
	if (row < r - 1)
		visit(row + 1, col, depth, max_length, visited);
	if (col > 0)
		visit(row, col - 1, depth, max_length, visited);
	if (col < c - 1)
		visit(row, col + 1, depth, max_length, visited);

	return max_length;
}

int solve()
{
	vector<bool> visited;
	visited.resize(26, false);
	visited[board[0][0] - 'A'] = true;
	return dfs(0, 0, 1, visited);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		cin >> board[i];
	}

	cout << solve() << endl;

	return 0;
}