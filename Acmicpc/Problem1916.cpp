#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define INF 10000000000002
using namespace std;

vector<pair<int, int>> graph[100001];
int d[100001];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;

	pq.push({0, start});
	d[start] = 0;

	while (!pq.empty())
	{
		int distance = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if(d[now] < distance)
			continue;

		for (int i = 0; i < graph[now].size(); i++)
		{
			int cost = distance + graph[now][i].second;
			if (cost < d[graph[now][i].first])
			{
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, start, end;
	scanf("%d", &n);
	scanf("%d", &m);


	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		graph[from].push_back({to, cost});
	}

	scanf("%d %d", &start, &end);

	fill(d, d + 100001, INF);
	dijkstra(start);

	printf("%d\n", d[end]);
	
	return 0;
}