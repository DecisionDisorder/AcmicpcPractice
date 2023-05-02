#include <iostream>
#define MAX 100001

using namespace std;

int seq[MAX];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, s;
	int start = 0, end = 0;
	int sum = 0, min_count = MAX;

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> seq[i];

	sum = seq[0];

	while (true)
	{
		if (sum < s)
		{
			if (end < n)
			{
				end++;
				sum += seq[end];
			}
			else
				break;
		}
		else
		{
			int count = end - start + 1;
			if (min_count > count)
				min_count = count;

			start++;
			sum -= seq[start - 1];

			if (start == n)
				break;
			else if (end < start)
				end = start;
		}
	}

	min_count = min_count == MAX ? 0 : min_count;

	cout << min_count << endl;

	return 0;
}