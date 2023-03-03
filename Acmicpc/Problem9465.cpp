#include <iostream>
#define ROW 2
using namespace std;

int max(int a, int b) { return a >= b ? a : b; }

int main()
{
	int testcase, columnSize;
	scanf("%d", &testcase);


	for (int t = 0; t < testcase; t++)
	{
		int** stickers = new int*[ROW];
		int** dp = new int* [ROW];
		int totalScore = 0;
		scanf("%d", &columnSize);

		for (int i = 0; i < ROW; i++)
		{
			stickers[i] = new int[columnSize];
			dp[i] = new int[columnSize];
			for (int j = 0; j < columnSize; j++)
			{
				scanf("%d", &stickers[i][j]);
				dp[i][j] = 0;
			}
		}

		dp[0][0] = stickers[0][0];
		dp[1][0] = stickers[1][0];

		if (columnSize >= 2)
		{
			dp[0][1] = dp[1][0] + stickers[0][1];
			dp[1][1] = dp[0][0] + stickers[1][1];
		}

		for (int i = 2; i < columnSize; i++)
		{
			dp[0][i] = stickers[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = stickers[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}
		
		printf("%d\n", max(dp[0][columnSize - 1], dp[1][columnSize - 1]));
	}
}