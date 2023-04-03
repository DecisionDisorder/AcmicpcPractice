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
		// 같은 column에 있는지     혹은 대각선에 있는지 (row의 차이와 col의 차이가 같으면 대각선)
		if (queens[i] == queens[row] || row - i == abs(queens[row] - queens[i]))
		{
			// pruning 필요
			return false;
		}
	}

	return true;
}

void nqueens(int row)
{
	// 맨 밑까지 내려왔으면 경우의 수 추가
	if (row == n)
	{
		amount++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		// queen 위치: 해당 row에서 column: i로 넣어봄
		queens[row] = i;
		// 유망하면 그 다음 row로
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