#include <iostream>
#include <algorithm>

using namespace std;

int compare(const void* a, const void* b)
{
	const int* x = (int*)a;
	const int* y = (int*)b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

int main()
{
	int n, cumWaitTime = 0, totalWaitTime = 0;
	int* p;

	cin >> n;

	p = new int[n];

	for (int i = 0; i < n; i++)
		cin >> p[i];

	qsort(p, n, sizeof(int), compare);

	for (int i = 0; i < n; i++)
	{
		cumWaitTime += p[i];
		totalWaitTime += cumWaitTime;
	}

	cout << totalWaitTime << endl;

	return 0;
}