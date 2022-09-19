#include <iostream>

using namespace std;

bool checkPrimaryNumber(int);

int main()
{
	int min, max;
	cin >> min >> max;

	int primaryNumMin = 0, sum = 0;

	for (int i = min; i <= max; i++)
	{
		if (checkPrimaryNumber(i))
		{
			if (primaryNumMin == 0)
				primaryNumMin = i;
			sum += i;
		}
	}

	if (sum > 0)
	{
		cout << sum << endl;
		cout << primaryNumMin << endl;
	}
	else
		cout << -1 << endl;

	return 0;
}

bool checkPrimaryNumber(int num)
{
	if (num == 1)
		return false;

	for (int i = 2; i < num; i++)
		if (num % i == 0)
			return false;
	return true;
}