#include <iostream>
#include <cmath>

using namespace std;

void getSequence(int row, int col, int size, int& result)
{
	if(size == 0)
		return;

	int half = size / 2;
	int m = 2 * ((int)log2(size) - 1);
	if (row < half)
	{
		if (col < half)
		{
			getSequence(row, col, half, result);
		}
		else
		{
			result += pow(2, m);
			getSequence(row, col - half, half, result);
		}
	}
	else
	{
		if (col < half)
		{
			result += 2 * pow(2, m);
			getSequence(row - half, col, half, result);
		}
		else
		{
			result += 3 * pow(2, m);
			getSequence(row - half, col - half, half, result);
		}
	}
}

int main()
{
	int n, r, c, size, result = 0;
	cin >> n >> r >> c;

	size = pow(2, n);

	getSequence(r, c, size, result);

	cout << result << endl;
	
	return 0;
}