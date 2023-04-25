// Prim's �˰��� ���
// Problem1197.cpp(�Ｎ���� § �ڵ�) ��� �ð� �Ҹ� 10% �������� ���� (528ms -> 56ms)

#include <iostream>
#include <vector>
#include <queue>

#define EDGE_MAX 100001

using namespace std;

int n, m;

/* a->b�� ��� c�� ���� vector
 * edges�� index:      a
 * edges[a][i].first:  b
 * edges[a][i].second: c
 * ����) 1�� �������� 2�� �������� ���� ����� 3�̴� = graph[1][#] = {2, 3}
 *      (#�� 1�� �������� �̾����� ���� ���� ���� ����Ʈ�� ���� �ε���)
 **/
vector<pair<int, int>> edges[EDGE_MAX];

// �� ������ �̹� �湮�ߴ����� ���� �迭 (Cycle ������ ����)
bool visited[EDGE_MAX];

int prim()
{
	// first: cost
	// second: to
	priority_queue<pair<int, int>> pq;
	int sum = 0;

	// ���� ���� �߰�
	pq.push({ 0, 1 });

	/* n�� �ݺ����� ���ѵ� */ 
	for (int i = 1; i <= n; i++)
	{
		// pq�� �ִ� �ּ� ��� ���� �߿� �̹� �湮�� �� �ִ� ������ ����
		/* ���ʿ��� Ž�� ������ �ð� ���� */
		while (!pq.empty() && visited[pq.top().second])
			pq.pop();

		// ���� ��� ���� ���� �湮�ϰ�, ��� �ջ�
		int next = pq.top().second;
		int minCost = -pq.top().first;
		pq.pop();
		visited[next] = true;
		sum += minCost;

		// ���� ������ �켱���� ť�� �߰�
		for (auto adjacent : edges[next])
			pq.push({ -adjacent.second, adjacent.first });
	}

	return sum;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	// ���� ������ �Է� �ޱ�
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