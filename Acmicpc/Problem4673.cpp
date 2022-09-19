#include <iostream>

using namespace std;

int selfNum(int);

int main()
{
	for(int i )
	cout << selfNum(33);

	return 0;
}

int selfNum(int num)
{
	int result = num, div = 10;
	result += num % 10;

	while (num > 0) 
	{
		result += (num / div) % (div * 10);
		div *= 10;
		num /= div;
	}

	return result;
}