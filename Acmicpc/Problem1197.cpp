#include <iostream>
#include <queue>
#include <vector>

#define VERTEX_MAX 10001

using namespace std;

int n, m;

vector<pair<int, int>> edges[VERTEX_MAX];
bool visited[VERTEX_MAX];

int prim()
{
	int weight = 0;
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, 1 });
	visited[1] = true;

	while (!pq.empty())
	{
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (!visited[now])
		{
			weight += cost;
			visited[now] = true;
		}

		for (int i = 0; i < edges[now].size(); i++)
		{
			int dest = edges[now][i].first;
			int cost = edges[now][i].second;

			if (!visited[dest])
				pq.push({ -cost, dest });
		}
	}

	return weight;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b, c });
		edges[b].push_back({ a, c });
	}

	cout << prim() << endl;

	return 0;
}