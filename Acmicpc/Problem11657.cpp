#include <iostream>
#include <vector>

#define MAX_VERTEX 501
#define INF (0x7FFFFFFFFFFFFFFF)
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	// a -> b�� ����� c�� ��, map[a][#].first = b, second = c.
	// #�� vector�� ���� �ε�����, a����� ���� ������ ������ ��� ���� vector.
	vector<pair<int, int>> map[MAX_VERTEX];
	// Ư�� �������� �ּҺ���� ������ �迭
	long long costs[MAX_VERTEX];

	cin >> v >> e;
	
	// �������� (1)�� ��� 0���� �ʱ�ȭ
	costs[1] = 0;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b, c });
	}
	// �ٸ� ����� ����� INF�� �ʱ�ȭ
	for (int i = 2; i <= v; i++)
		costs[i] = INF;

	// �ִ� �Ÿ��� ����� ������ŭ �ݺ��Ͽ� ���
	for (int i = 0; i < v; i++)
	{
		// ��� ���(vertex)�� ���� �ݺ�
		for (int j = 1; j <= v; j++)
		{
			// ������ ��忡 ���� �ݺ�
			for (int k = 0; k < map[j].size(); k++)
			{
				int to = map[j][k].first;	 // ������ ���
				int cost = map[j][k].second; // ���������� ���
				// j�� ������ �̾��� ���� �ִ��� & �� �ִ� �Ÿ����� Ȯ��
				if (costs[j] != INF && costs[j] + cost < costs[to])
				{
					// �ִ� �Ÿ��� ����
					costs[to] = costs[j] + cost;
					// ���� Cycle ���� Ȯ��.
					// i�� ���������� �ݺ��ص� ������ �ִܰŸ��� �ִٸ� ���� Cycle�̶�� �ǹ�.
					if (i == v - 1)
					{
						cout << "-1" << endl;
						return 0;
					}
				}
			}
		}
	}
	
	for (int i = 2; i <= v; i++)
	{
		if (costs[i] != INF)
			cout << costs[i] << endl;
		else
			cout << "-1" << endl;
	}



	return 0;
}