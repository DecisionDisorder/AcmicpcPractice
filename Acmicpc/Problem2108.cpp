#include <iostream>
#include <cmath>

using namespace std;

int* sorted;

void sort(int*, int);
int counts[8001] = { 0, };

int main()
{
	int n, sum = 0;
	int* arr;

	cin >> n;
	arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		counts[i + 4000]++;
	}

	sort(arr, n);

	cout << round(sum / n) << endl;
	cout << arr[n / 2] << endl;
	cout << getMode() << endl;

	return 0;
}

int getMode()
{
	int maxCount = 0;
	for (int i = 0; i < 8001; i++)
	{
		if()
	}

	return 0;
}

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