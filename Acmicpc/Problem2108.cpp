#include <iostream>
#include <cmath>

using namespace std;

int* sorted;
int frequency[8001] = {0};

void merge(int* arr, int left, int mid, int right)
{
	int s = left, i = left, j = mid + 1;
	while (i <= mid || j <= right)
	{
		if (i <= mid && j <= right)
		{
			if (arr[i] <= arr[j])
				sorted[s++] = arr[i++];
			else
				sorted[s++] = arr[j++];
		}
		else if (i <= mid)
			sorted[s++] = arr[i++];
		else if (j <= right)
			sorted[s++] = arr[j++];
	}

	for (int l = left; l <= right; l++)
		arr[l] = sorted[l];
}

void partition(int* arr, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		partition(arr, left, mid);
		partition(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void sort(int* arr, int n)
{
	sorted = new int[n];
	partition(arr, 0, n - 1);
}

int getMostFrequency(int* arr, int n)
{
	int max = 1, maxIndex = 0, maxCount = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] >= max)
		{
			max = arr[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == max)
		{
			maxCount++;
			maxIndex = i;
			if (maxCount == 2)
				break;
		}
	}

	return maxIndex - 4000;
}

int main()
{
	int n, sum = 0;
	scanf("%d", &n);

	int* numArray = new int[n];

	for (int i = 0; i < n; i++) 
	{
		scanf("%d", numArray + i);
		sum += numArray[i];
		frequency[numArray[i] + 4000]++;
	}

	sort(numArray, n);

	int avg = round((double)sum / n);
	printf("%d\n", avg);
	printf("%d\n", numArray[n / 2]);
	printf("%d\n", getMostFrequency(frequency, 8001));
	if (n > 1)
	{
		printf("%d", numArray[n - 1] - numArray[0]);
	}
	else
	{
		printf("0");
	}
	
	return 0;
}