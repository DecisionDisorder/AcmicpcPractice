#include <iostream>
#include <vector>

#define INF (0x7FFFFFFFFFFFFFFF)
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	vector<pair<int, int>>* map;

	cin >> v >> e;

	map = new vector<pair<int, int>>[v + 1];
	long long costs[501];
	costs[1] = 0;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b, c });
	}
	for (int i = 2; i <= v; i++)
		costs[i] = INF;

	for (int i = 1; i <= e; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			for (int k = 0; k < map[j].size(); k++)
			{
				int to = map[j][k].first;
				int cost = map[j][k].second;

				if (costs[j] != INF && costs[j] + cost < costs[to])
				{
					costs[to] = costs[j] + cost;
					if (i == v)
					{
						cout << "-1" << endl;
						return 0;
					}
				}
			}
		}
	}
	
	for (int i = 2; i <= v; i++)
	{
		if (costs[i] != INF)
			cout << costs[i] << endl;
		else
			cout << "-1" << endl;
	}



	return 0;
}