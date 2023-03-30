#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int* line = new int[n];
	long long start = 1, end = 0, mid = 0;
	int res = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> line[i];
		if (end < line[i])
			end = line[i];
	}

	while (start <= end)
	{
		mid = (start + end) / 2;

		int amount = 0;
		for (int i = 0; i < n; i++)
		{
			amount += line[i] / mid;
		}

		if (amount < m)
			end = mid - 1;
		else
		{
			res = mid;
			start = mid + 1;
		}

	}

	cout << res << endl;

	return 0;
}