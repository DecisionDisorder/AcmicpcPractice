#include <iostream>
#include <algorithm>

using namespace std;

int n, c;
int homes[200001];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> c;

	for (int i = 0; i < n; i++)
	{
		cin >> homes[i];
	}

	sort(homes, homes + n);

	int start = 1;
	int end = homes[n - 1] - homes[0];
	int max_distance = 0;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		int count = 1, recent = 0;
		for (int i = 1; i < n; i++)
		{
			if (homes[i] - homes[recent] >= mid)
			{
				count++;
				recent = i;
			}
		}

		if (count < c)
		{
			end = mid - 1;
		}
		else
		{
			max_distance = max(max_distance, mid);
			start = mid + 1;
		}
	}

	cout << max_distance << endl;

	return 0;
}