#include <iostream>

using namespace std;

int main()
{
	int n, m;
	int* arr;
	int* sumArr;

	scanf("%d %d", &n, &m);

	arr = new int[n];
	sumArr = new int[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
		if(i == 0)
			sumArr[i] = arr[i];
		else
			sumArr[i] = arr[i] + sumArr[i - 1];
	}
		
	
	for (int i = 0; i < m; i++)
	{
		int from, to, sum;
		scanf("%d %d", &from, &to);
		
		if(from == 1)
			sum = sumArr[to - 1];
		else
			sum = sumArr[to - 1] - sumArr[from - 2];

		printf("%d\n", sum);
	}

	return 0;
}