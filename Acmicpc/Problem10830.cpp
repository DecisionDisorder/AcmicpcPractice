#include <iostream>
#define MAX 5

using namespace std;

long long** multiply_matrix(long long** matrixA, long long** matrixB, int n)
{
	long long **matrix_result;
	matrix_result = new long long* [n];
	for (int i = 0; i < n; i++)
	{
		matrix_result[i] = new long long[n];
		fill(matrix_result[i], matrix_result[i] + n, 0);
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				matrix_result[i][j] += matrixA[i][k] * matrixB[k][j];
				matrix_result[i][j] %= 1000;
			}
				
		}
	}
	return matrix_result;
}

long long** squaring(long long **matrix, int n, long long b)
{
	if (b > 1)
	{
		long long** matrix_result = multiply_matrix(matrix, matrix, n);
		if (b % 2 == 0)
		{
			return squaring(matrix_result, n, b / 2);
		}
		else
		{
			return multiply_matrix(squaring(matrix_result, n, b / 2), matrix, n);
		}
	}
	else
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				matrix[i][j] %= 1000;

	return matrix;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	long long b;
	long long** matrix;

	cin >> n >> b;

	matrix = new long long* [n];
		
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new long long[n];
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
	}

	long long** result = squaring(matrix, n, b);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << result[i][j] << " ";
		cout << "\n";
	}

	return 0;
}