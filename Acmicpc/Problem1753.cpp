#include <iostream>
#include <queue>
#include <vector>
#define MAX_VERTEX 20000
#define INF 1000000001

using namespace std;

vector<pair<int, int>> graph[MAX_VERTEX];
int d[MAX_VERTEX];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({0, start});
	d[start] = 0;

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (d[current] < cost)
			continue;

		for (int i = 0; i < graph[current].size(); i++)
		{
			int cost = graph[current][i].second;
			int dest = graph[current][i].first;
			if (d[current] + cost < d[dest])
			{
				d[dest] = d[current] + cost;
				pq.push(make_pair(-d[dest], dest));
			}
		}
	}
}

int main()
{
	int v, e, start;
	scanf("%d %d", &v, &e);
	scanf("%d", &start);

	for (int i = 0; i < e; i++)
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		graph[from - 1].push_back({to - 1, cost});
	}

	fill(d, d + MAX_VERTEX, INF);

	dijkstra(start - 1);

	for (int i = 0; i < v; i++)
	{
		if (d[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", d[i]);
			
	}

	return 0;
}