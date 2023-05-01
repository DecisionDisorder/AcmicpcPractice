#include <iostream>
#include <queue>
#define MAX_VERTEX 100001

using namespace std;

int n, m;
int parents[MAX_VERTEX];
priority_queue<pair<int, pair<int, int>>> edges;

int Find(int n)
{
	if (parents[n] == 0)
		return parents[n] = n;
	else if (parents[n] == n)
		return n;
	else
		return parents[n] = Find(parents[n]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	parents[a] = b;
}

int Kruskal()
{
	int sum = 0, maxCost = 0;

	while (!edges.empty())
	{
		int cityA = edges.top().second.first;
		int cityB = edges.top().second.second;
		int cost = -edges.top().first;
		edges.pop();
		if (Find(cityA) != Find(cityB))
		{
			Union(cityA, cityB);
			sum += cost;
			maxCost = max(cost, maxCost);
		}
	}

	return sum - maxCost;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push({ -c, {a, b} });
	}

	cout << Kruskal() << endl;

	return 0;
}