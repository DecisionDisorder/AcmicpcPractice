#include <iostream>
#include <string>

using namespace std;

int* sorted;

void sort(int*, int);

int main()
{
	int n, k;
	int* scores;

	cin >> n >> k;

	scores = new int[n];

	for (int i = 0; i < n; i++)
		cin >> scores[i];

	sort(scores, n);

	cout << sorted[n - k] << endl;

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