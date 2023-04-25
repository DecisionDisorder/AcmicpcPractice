// Prim's 알고리즘 사용
// Problem1197.cpp(즉석으로 짠 코드) 대비 시간 소모 10% 수준으로 감축 (528ms -> 56ms)

#include <iostream>
#include <vector>
#include <queue>

#define EDGE_MAX 100001

using namespace std;

int n, m;

/* a->b의 비용 c에 대한 vector
 * edges의 index:      a
 * edges[a][i].first:  b
 * edges[a][i].second: c
 * 예시) 1번 정점에서 2번 정점으로 가는 비용은 3이다 = graph[1][#] = {2, 3}
 *      (#은 1번 정점에서 이어지는 여러 정점 정보 리스트에 대한 인덱스)
 **/
vector<pair<int, int>> edges[EDGE_MAX];

// 각 정점을 이미 방문했는지에 대한 배열 (Cycle 배제를 위함)
bool visited[EDGE_MAX];

int prim()
{
	// first: cost
	// second: to
	priority_queue<pair<int, int>> pq;
	int sum = 0;

	// 시작 지점 추가
	pq.push({ 0, 1 });

	/* n번 반복으로 제한됨 */ 
	for (int i = 1; i <= n; i++)
	{
		// pq에 있는 최소 비용 간선 중에 이미 방문한 적 있는 간선은 제거
		/* 불필요한 탐색 방지로 시간 절약 */
		while (!pq.empty() && visited[pq.top().second])
			pq.pop();

		// 가장 비용 낮은 간선 방문하고, 비용 합산
		int next = pq.top().second;
		int minCost = -pq.top().first;
		pq.pop();
		visited[next] = true;
		sum += minCost;

		// 인접 간선을 우선순위 큐에 추가
		for (auto adjacent : edges[next])
			pq.push({ -adjacent.second, adjacent.first });
	}

	return sum;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	// 간선 데이터 입력 받기
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