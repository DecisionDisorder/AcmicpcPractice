#include <iostream>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int** sumArr = new int* [n];

	for (int i = 0; i < n; i++)
	{
		sumArr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			int input;
			scanf("%d", &input);
			if (j == 0)
				sumArr[i][j] = input;
			else
				sumArr[i][j] = sumArr[i][j - 1] + input;
		}
	}

	for (int t = 0; t < m; t++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int sum = 0;

		for (int i = x1 - 1; i < x2; i++)
		{
			if (y1 == 1)
			{
				sum += sumArr[i][y2 - 1];
			}
			else
			{
				sum += sumArr[i][y2 - 1] - sumArr[i][y1 - 2];
			}
		}

		printf("%d\n", sum);
	}
	
	return 0;
}