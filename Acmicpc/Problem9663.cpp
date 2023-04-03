#include <iostream>
#include <cmath>

using namespace std;

int queens[15];
int n;
int amount = 0;


bool promising(int row)
{
	for (int i = 0; i < row; i++)
	{
		// ���� column�� �ִ���     Ȥ�� �밢���� �ִ��� (row�� ���̿� col�� ���̰� ������ �밢��)
		if (queens[i] == queens[row] || row - i == abs(queens[row] - queens[i]))
		{
			// pruning �ʿ�
			return false;
		}
	}

	return true;
}

void nqueens(int row)
{
	// �� �ر��� ���������� ����� �� �߰�
	if (row == n)
	{
		amount++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		// queen ��ġ: �ش� row���� column: i�� �־
		queens[row] = i;
		// �����ϸ� �� ���� row��
		if (promising(row))
		{
			nqueens(row + 1);
		}
	}
}

int main()
{
	cin >> n;

 	nqueens(0);

	cout << amount << endl;

	return 0;
}