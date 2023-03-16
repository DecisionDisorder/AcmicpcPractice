#include <iostream>

using namespace std;

int A2B(long long start, long long end, int level = 1)
{
	int a, b;
	if (start * 2 == end || start * 10 + 1 == end)
		return level + 1;

	if (start * 2 <= end)
		a = A2B(start * 2, end, level + 1);
	else
		a = -1;
	if (start * 10 + 1 <= end)
		b = A2B(start * 10 + 1, end, level + 1);
	else
		b = -1;

	if (a != -1)
		return a;
	else if (b != -1)
		return b;
	else
		return -1;
}

int main()
{
	long long start, end;
	cin >> start >> end;

	cout << A2B(start, end) << endl; 
	
	return 0;
}