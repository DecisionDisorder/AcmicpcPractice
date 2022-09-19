#include <iostream>
#include <cmath>

using namespace std;

int arr[10001] = {0,};

void setPrimaryNumbers(int);
int findLeftPrimary(int);
int findRightPrimary(int);

int main()
{
	int input, n;

	arr[0] = 1;
	arr[1] = 1;

	setPrimaryNumbers(10000);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		int half = input / 2;
		int left = findLeftPrimary(half);
		int right = findRightPrimary(half);
		while (left + right != input)
		{
			if (left + right < input)
				right = findRightPrimary(right + 1);
			else
				left = findLeftPrimary(left - 1);
		}

		cout << left << " " << right << endl;
	}

	return 0;
}

int findLeftPrimary(int num)
{
	int result = num;
	while (arr[result] == 1)
		result--;
	return result;
}

int findRightPrimary(int num)
{
	int result = num;
	while (arr[result] == 1)
		result++;
	return result;
}

void setPrimaryNumbers(int num)
{
	int limit = sqrt(num);
	for (int i = 2; i <= limit; i++)
	{
		if (arr[i] == 0)
		{
			for (int j = i * 2; j <= num; j += i)
			{
				arr[j] = 1;
			}
		}
	}
}