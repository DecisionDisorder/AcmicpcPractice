#include <iostream>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main()
{
	int n;
	scanf("%d", &n);
	int maxDP[2][3];
	int minDP[2][3];
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (i == 0)
		{
			minDP[i][0] = a;
			minDP[i][1] = b;
			minDP[i][2] = c;

			maxDP[i][0] = a;
			maxDP[i][1] = b;
			maxDP[i][2] = c;
		}
		else
		{
			minDP[1][0] = min(minDP[0][0], minDP[0][1]) + a;
			minDP[1][1] = min(minDP[0][0], min(minDP[0][1], minDP[0][2])) + b;
			minDP[1][2] = min(minDP[0][1],minDP[0][2]) + c;
			maxDP[1][0] = max(maxDP[0][0], maxDP[0][1]) + a;
			maxDP[1][1] = max(maxDP[0][0], max(maxDP[0][1], maxDP[0][2])) + b;
			maxDP[1][2] = max(maxDP[0][1], maxDP[0][2]) + c;

			minDP[0][0] = minDP[1][0];
			minDP[0][1] = minDP[1][1];
			minDP[0][2] = minDP[1][2];
			maxDP[0][0] = maxDP[1][0];
			maxDP[0][1] = maxDP[1][1];
			maxDP[0][2] = maxDP[1][2];

		}
	}

	printf("%d %d\n", max(maxDP[0][0], max(maxDP[0][1], maxDP[0][2])), min(minDP[0][0], min(minDP[0][1], minDP[0][2])));
		

	return 0;
}