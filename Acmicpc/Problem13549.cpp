#include <iostream>
#include <queue>
#include <vector>

#define MAX 100001
#define INF 1000000001

using namespace std;

vector<pair<int, int>> graph[MAX];
int d[MAX];


void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;

	pq.push({0, start});
	d[start] = 0;

	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist)
			continue;

		for (int i = 0; i < graph[now].size(); i++)
		{
			int cost = dist + graph[now][i].second;
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
	int start, end;
	cin >> start >> end;

	if (start <= end)
	{
		int limit = end * 2;
		if (limit >= MAX)
			limit = MAX - 1;

		for (int i = 0; i <= limit; i++)
		{
			if (i == 0)
			{
				graph[i].push_back({ i + 1, 1 });
				graph[i].push_back({ i * 2, 0 });
			}
			else if (i == limit)
			{
				graph[i].push_back({ i - 1, 1 });
			}
			else
			{
				if (i * 2 < MAX)
					graph[i].push_back({ i * 2, 0 });
				graph[i].push_back({ i - 1, 1 });
				graph[i].push_back({ i + 1, 1 });
			}
		}

		fill(d, d + MAX, INF);
		dijkstra(start);

		cout << d[end] << endl;
	}
	else
		cout << start - end << endl;

	return 0;
}