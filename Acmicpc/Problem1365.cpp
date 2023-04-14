#include <iostream>

using namespace std;

int n;		  // 기둥의 개수
int* arr;	  // (i-1)번 기둥에 연결되는 다른 기둥의 번호
int* lis;	  // (i)번 까지의 최장 증가 수열

int binary_search(int start, int end, int val)
{
	int mid = 0;
	while (start < end)
	{
		mid = (start + end) / 2;
		if (lis[mid] == val)
			return mid;
		else if (lis[mid] < val)
			start = mid + 1;
		else
			end = mid;
	}
	
	return end;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// LIS 길이
	int count = 1;
	cin >> n;

	arr = new int[n];
	lis = new int[n];

	fill(lis, lis + n, 0);

	// 이어지는 기둥 정보 받기
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		arr[i] = input;
	}

	lis[0] = arr[0];

	// 각 기둥에 대해서 검사
	for (int i = 1; i < n; i++)
	{
		int res = binary_search(0, count - 1, arr[i]);
		if (lis[res] < arr[i]) 
		{
			lis[res + 1] = arr[i];
			count++;
		}
		else
			lis[res] = arr[i];
	}

	cout << (n - count) << endl;
	 
	return 0;
}