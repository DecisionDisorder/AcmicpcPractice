#include <iostream>
#include <vector>

#define INF 100000000001
#define MAX_VERTEX 501

using namespace std;

int n, m, w;

bool bellman_ford(vector<pair<int, int>> map[], long long costs[])
{
	costs[1] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < map[j].size(); k++)
			{
				int dest = map[j][k].first;
				// IntegerOverflow �߻����� long long���� ����
				long long cost = map[j][k].second + costs[j];

				// ������� 1�� ������ �ƴϱ� ������ �������� ������� �ʾҴ��� Ȯ���� �ʿ䰡 ����.
				if (costs[dest] > cost)
				{
					costs[dest] = cost;
					if (i == n - 1)
						return true;
				}
			}
		}
	}
	

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	cin >> testcase;

	for (int t = 0; t < testcase; t++)
	{
		vector<pair<int, int>> map[MAX_VERTEX];
		long long costs[MAX_VERTEX];

		cin >> n >> m >> w;

		fill(costs, costs + n + 1, INF);
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			map[a].push_back({b, c});
			map[b].push_back({a, c});

		}
		for (int i = 0; i < w; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			map[a].push_back({ b, -c });
		}


		cout << (bellman_ford(map, costs) ? "YES" : "NO") << endl;

	}
	return 0;
}