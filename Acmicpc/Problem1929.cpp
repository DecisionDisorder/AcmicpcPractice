#include <iostream>
#include <cmath>

using namespace std;

int arr[1000001] = { 0, };

int main()
{
	int min, max;
	cin >> min >> max;

	arr[0] = 1;
	arr[1] = 1;

	int limit = sqrt(max);
	for (int i = 2; i <= limit; i++) 
	{
		if (arr[i] == 0)
		{
			for (int k = 2 * i; k <= max; k += i)
				arr[k] = 1;
		}
	}

	for (int i = min; i <= max; i++)
		if (arr[i] == 0)
			cout << i << "\n";
	
	return 0;
}