#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size;

	cin >> size;

	int **table = new int*[size];

	for (int i = 0; i < size; i++)
	{
		table[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			cin >> table[i][j];
		}
	}

	for (int k = 0; k < size; k++)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if(table[i][k] && table[k][j])
					table[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << table[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}