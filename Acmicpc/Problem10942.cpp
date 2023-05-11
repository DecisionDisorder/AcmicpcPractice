#include <iostream>

using namespace std;

int n, m;
int arr[2000];
bool dp[2000][2000];

void Pelindrome(int start, int end)
{
	if (arr[start] == arr[end])
	{
		if (dp[start + 1][end - 1])
		{
			dp[start][end] = true;
		}
	}
}

int CheckPelindrome(int start, int end)
{
	return dp[start][end] ? 1 : 0;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
		dp[i][i] = true;

	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = true;
	}

	for (int i = 2; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			Pelindrome(j, j + i);
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int s, e;
		cin >> s >> e;
		cout << CheckPelindrome(s - 1, e - 1) << "\n";
	}


	return 0;
}