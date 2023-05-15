#include <iostream>
#include <vector>
#include <queue>
#define VERTEX_MAX 1001
#define INF 1000000001

using namespace std;

int n, m, dice_col;
vector<pair<int, int>> graph[VERTEX_MAX];

int dijkstra(int start, int end)
{
	priority_queue<pair<int, int>> pq;
	int distances[VERTEX_MAX];
	fill(distances + 1, distances + n + 1, INF);

	pq.push({ 0, start });

	while (!pq.empty())
	{
		int now = pq.top().second;
		int cost_now = -pq.top().first;
		pq.pop();

		if (distances[now] < cost_now)
			continue;

		for (int i = 0; i < graph[now].size(); i++)
		{
			int dest = graph[now][i].first;
			int cost = graph[now][i].second + cost_now;

			if (distances[dest] > cost)
			{
				distances[dest] = cost;
				pq.push({ -cost, dest });
			}
		}
	}

	return distances[end];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int max_distance = 0;

	cin >> n >> m >> dice_col;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	for (int i = 1; i <= n; i++)
	{
		if (i != dice_col)
		{
			int d = dijkstra(i, dice_col);
			d += dijkstra(dice_col, i);
			if (d > max_distance)
				max_distance = d;
		}
	}

	cout << max_distance << endl;

	return 0;
}