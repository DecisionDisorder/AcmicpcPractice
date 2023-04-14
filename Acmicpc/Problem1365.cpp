#include <iostream>

using namespace std;

int n;		  // ����� ����
int* arr;	  // (i-1)�� ��տ� ����Ǵ� �ٸ� ����� ��ȣ
int* lis;	  // (i)�� ������ ���� ���� ����

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

	// LIS ����
	int count = 1;
	cin >> n;

	arr = new int[n];
	lis = new int[n];

	fill(lis, lis + n, 0);

	// �̾����� ��� ���� �ޱ�
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		arr[i] = input;
	}

	lis[0] = arr[0];

	// �� ��տ� ���ؼ� �˻�
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