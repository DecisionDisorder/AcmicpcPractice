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
	// a -> b의 비용이 c일 때, map[a][#].first = b, second = c.
	// #은 vector에 대한 인덱스로, a노드의 여러 인접한 노드들을 담기 위한 vector.
	vector<pair<int, int>> map[MAX_VERTEX];
	// 특정 노드까지의 최소비용을 정리한 배열
	long long costs[MAX_VERTEX];

	cin >> v >> e;
	
	// 시작지점 (1)의 비용 0으로 초기화
	costs[1] = 0;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b, c });
	}
	// 다른 노드의 비용은 INF로 초기화
	for (int i = 2; i <= v; i++)
		costs[i] = INF;

	// 최단 거리를 노드의 개수만큼 반복하여 계산
	for (int i = 0; i < v; i++)
	{
		// 모든 노드(vertex)에 대해 반복
		for (int j = 1; j <= v; j++)
		{
			// 인접한 노드에 대해 반복
			for (int k = 0; k < map[j].size(); k++)
			{
				int to = map[j][k].first;	 // 목적지 노드
				int cost = map[j][k].second; // 목적지까지 비용
				// j번 노드까지 이어진 길이 있는지 & 더 최단 거리인지 확인
				if (costs[j] != INF && costs[j] + cost < costs[to])
				{
					// 최단 거리로 갱신
					costs[to] = costs[j] + cost;
					// 음의 Cycle 인지 확인.
					// i를 마지막까지 반복해도 갱신할 최단거리가 있다면 음의 Cycle이라는 의미.
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