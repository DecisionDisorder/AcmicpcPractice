#include <iostream>
#define INF 9999999

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int **cost = new int*[n];
	int* kevin = new int[n];
	int min = INF, minIndex = 0;

	for (int i = 0; i < n; i++)
	{
		cost[i] = new int[n];
		for (int j = 0; j < n; j++)
			cost[i][j] = INF;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		cost[a - 1][b - 1] = 1;
		cost[b - 1][a - 1] = 1;
	}

	for (int k = 0; k < n; k++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
				if (cost[i][j] > cost[i][k] + cost[k][j])
				{
					cost[i][j] = cost[i][k] + cost[k][j];
					cost[j][i] = cost[i][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		kevin[i] = 0;
		for (int j = 0; j < n; j++)
			kevin[i] += cost[i][j];

		if (min > kevin[i])
		{
			min = kevin[i];
			minIndex = i;
		}
	}

	printf("%d\n", minIndex + 1);

	return 0;
}