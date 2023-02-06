#include <iostream>
#include <algorithm>

using namespace std;

int* sorted;

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

bool binarySearch(int *arr, int left, int right, int targetNum)
{
	int middle = (left + right) / 2;
	if (left <= right)
	{
		if (targetNum < arr[middle])
			return binarySearch(arr, left, middle - 1, targetNum);
		else if (targetNum > arr[middle])
			return binarySearch(arr, middle + 1, right, targetNum);
		else
			return true;
	}
	else
		return false;
}

int main()
{
	int N, M;
	scanf("%d", &N);
	int* A = new int[N];
	int* B;

	for (int i = 0; i < N; i++)
		scanf("%d", A + i);

	scanf("%d", &M);
	B = new int[M];
	for (int i = 0; i < M; i++)
		scanf("%d", B + i);

	sort(A, N);

	for (int i = 0; i < M; i++)
	{
		if (binarySearch(A, 0, N - 1, B[i]))
			printf("1\n");
		else
			printf("0\n");
	}


	return 0;
}