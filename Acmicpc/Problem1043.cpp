#include <iostream>
#include <vector>
using namespace std;

int n, m, knownLength;
vector<int> know;
vector<int>* partyList;
int parents[51];

// Find와 Union의 개념이 중요한 문제였음
int Find(int x)
{
	if (parents[x] == x)
		return x;
	return x = Find(parents[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	parents[x] = y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	cin >> knownLength;
	partyList = new vector<int>[m];
	int count = m;

	for (int i = 0; i < knownLength; i++)
	{
		int input;
		cin >> input;
		know.push_back(input);
	}

	for (int i = 1; i <= n; i++) parents[i] = i;

	for (int i = 0; i < m; i++)
	{
		int size, prev, input;
		cin >> size;
		for (int j = 0; j < size; j++)
		{
			if (j >= 1)
			{
				prev = input;
				cin >> input;
				Union(prev, input);
			}
			else
			{
				cin >> input;
			}
			partyList[i].push_back(input);
		}
	}

	for (int i = 0; i < m; i++)
	{
		bool sayTruth = false;
		for (int j = 0; j < partyList[i].size(); j++)
		{
			for (int k = 0; k < know.size(); k++)
			{
				if (Find(partyList[i][j]) == Find(know[k]))
				{
					sayTruth = true;
					break;
				}
			}
			if (sayTruth)
				break;
		}
		if (sayTruth)
			count--;
	}
		
	cout << count << endl;

	return 0;
}