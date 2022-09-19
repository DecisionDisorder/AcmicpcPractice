#include <iostream>
#include <cmath>

using namespace std;

int arr[1000001] = { 0, };

void setPrimaryNumbers(int);

int main()
{
	arr[0] = 1;
	arr[1] = 1;

	while (true)
	{
		int input, count = 0;
		cin >> input;

		if (input == 0)
			break;

		setPrimaryNumbers(input * 2);
		
		for (int i = input + 1; i <= input * 2; i++)
			if(arr[i] == 0)
				count++;
		
		cout << count << endl;
	}
}

void setPrimaryNumbers(int num)
{
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (arr[i] == 1)
			continue;

		for (int k = 2 * i; k <= num; k += i)
			arr[k] = 1;
	}
}