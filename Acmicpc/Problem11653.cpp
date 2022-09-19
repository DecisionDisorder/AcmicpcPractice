#include <iostream>

using namespace std;

void printPrimeFactor(int);

int main()
{
	int input;

	cin >> input;

	printPrimeFactor(input);

	return 0;
}

void printPrimeFactor(int num) 
{
	for (int i = 2; num > 1;)
	{
		if (num % i == 0)
		{
			cout << i << endl;
			num /= i;
		}
		else
			i++;
	}
}