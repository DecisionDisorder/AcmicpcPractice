// Kruskal 알고리즘 사용

#include <iostream>
#include <queue>
#define VERTEX_MAX 1001

using namespace std;

int n, m;

/*
 * 비용을 기준으로 간선의 정점을 정렬하는 우선순위 큐
 * first: -cost
 * second.first: vertex a, second.second: vertex b
 **/
priority_queue<pair<int, pair<int, int>>> edges;

// 부모 정점를 가리키는 배열
int parents[VERTEX_MAX];

// 부모 정점 찾기
int Find(int n)
{
	if (n == parents[n])
		return n;
	else
		return n = Find(parents[n]);
}

// 두 집합을 하나로 합치기
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	parents[a] = b;
}

int kruskal()
{
	int sum = 0;
	// 우선순위 큐를 모두 탐색
	while (!edges.empty())
	{
		int cost = -edges.top().first;		// 비용 얻기 (저장된 수는 음수이므로 양수로 전환)
		int a = edges.top().second.first;	// 정점 a
		int b = edges.top().second.second;  // 정점 b
		edges.pop();

		// 두 정점의 집합이 다른지 확인
		if (Find(a) != Find(b))
		{
			// 비용을 더하고
			sum += cost;
			// 하나의 집합으로 합치기
			Union(a, b);
		}
	}

	return sum;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	// 각 정점의 부모를 자기 자신으로 지정
	for (int i = 1; i <= n; i++)
		parents[i] = i;

	// 입력받기
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push({ -c, {a, b} });
	}


	cout << kruskal() << endl;

	return 0;
}