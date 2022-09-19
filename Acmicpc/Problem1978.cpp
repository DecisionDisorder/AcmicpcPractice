#include <iostream>

using namespace std;

bool checkPrimaryNumber(int);

int main()
{
	int n, count = 0;
	int* arr;
	cin >> n;

	arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		if (checkPrimaryNumber(arr[i]))
			count++;
	}
	
	cout << count << endl;

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