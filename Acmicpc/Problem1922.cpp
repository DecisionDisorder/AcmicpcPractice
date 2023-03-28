// Kruskal �˰��� ���

#include <iostream>
#include <queue>
#define VERTEX_MAX 1001

using namespace std;

int n, m;

/*
 * ����� �������� ������ ������ �����ϴ� �켱���� ť
 * first: -cost
 * second.first: vertex a, second.second: vertex b
 **/
priority_queue<pair<int, pair<int, int>>> edges;

// �θ� ������ ����Ű�� �迭
int parents[VERTEX_MAX];

// �θ� ���� ã��
int Find(int n)
{
	if (n == parents[n])
		return n;
	else
		return n = Find(parents[n]);
}

// �� ������ �ϳ��� ��ġ��
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	parents[a] = b;
}

int kruskal()
{
	int sum = 0;
	// �켱���� ť�� ��� Ž��
	while (!edges.empty())
	{
		int cost = -edges.top().first;		// ��� ��� (����� ���� �����̹Ƿ� ����� ��ȯ)
		int a = edges.top().second.first;	// ���� a
		int b = edges.top().second.second;  // ���� b
		edges.pop();

		// �� ������ ������ �ٸ��� Ȯ��
		if (Find(a) != Find(b))
		{
			// ����� ���ϰ�
			sum += cost;
			// �ϳ��� �������� ��ġ��
			Union(a, b);
		}
	}

	return sum;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	// �� ������ �θ� �ڱ� �ڽ����� ����
	for (int i = 1; i <= n; i++)
		parents[i] = i;

	// �Է¹ޱ�
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push({ -c, {a, b} });
	}


	cout << kruskal() << endl;

	return 0;
}