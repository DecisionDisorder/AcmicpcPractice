#include <iostream>
#include <vector>
#include <queue>

#define MAX 101
#define INF 1000000001

using namespace std;

int n, m, r;
int item[MAX];
int d[MAX];
vector<pair<int, int>> graph[MAX];

int dijkstra(int start)
{
	int item_sum = 0;
	priority_queue<pair<int, int>> pq;

	fill(d + 1, d + n + 1, INF);
	d[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int now = pq.top().second;
		int cost_now = -pq.top().first;
		pq.pop();

		if (d[now] < cost_now)
			continue;

		for (int i = 0; i < graph[now].size(); i++)
		{
			int dest = graph[now][i].first;
			int cost2dest = graph[now][i].second + d[now];

			if (d[now] != INF && d[dest] > cost2dest && cost2dest <= m)
			{
				d[dest] = cost2dest;
				pq.push({ -cost2dest, dest });
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (d[i] != INF)
			item_sum += item[i];

	return item_sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int item_max = 0;

	cin >> n >> m >> r;

	for (int i = 0; i < n; i++)
		cin >> item[i + 1];

	for (int i = 0; i < r; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	for (int i = 1; i <= n; i++)
	{
		int res = dijkstra(i);
		if (res > item_max)
			item_max = res;
	}

	cout << item_max << endl;

	return 0;
}