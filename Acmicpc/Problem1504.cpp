#include <iostream>
#include <queue>
#include <vector>

#define MAX_VERTEX 801
#define INF 1000000001

using namespace std;

int v;
int e;
int d[MAX_VERTEX];
vector<pair<int, int>> graph[MAX_VERTEX];

int dijkstra(int start, int end)
{
	if (start == end)
		return 0;
	bool destinationArrived = false;
	fill(d, d + v + 1, INF);

	priority_queue<pair<int, int>> pq;
	d[start] = 0;
	pq.push({ 0, start });

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

			if (d[dest] > d[current] + cost)
			{
				d[dest] = d[current] + cost;
				pq.push({-d[dest], dest});
				if (end == dest)
					destinationArrived = true;
			}
		}

	}
	if (destinationArrived)
		return d[end];
	else
 		return -99999;
}

int main()
{
	int v1, v2;

	scanf("%d %d", &v, &e);

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	
	scanf("%d %d", &v1, &v2);

	int way1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, v);
	int way2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, v);

	if (way1 < 0 && way2 < 0)
		printf("-1\n");
	else if(way1 < 0)
		printf("%d\n", way2);
	else if(way2 < 0)
		printf("%d\n", way1);
	else
		printf("%d\n", way1 < way2 ? way1 : way2);

	return 0;
}