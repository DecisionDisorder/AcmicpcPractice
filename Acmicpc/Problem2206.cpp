#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 필드 크기
int n, m;
// 길 상태를 가지고 있는 문자열 벡터
vector<string> graph;
// 0: 이미 벽을 부수고 이동하는 level
// 1: 벽을 부수기 전의 level
int level[1000][1000][2];
// 행렬로 움직이는 4방향에 대한 배열
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int bfs()
{
	// first.pair: row, col / second: block을 부수기 전인지 여부
	queue<pair<pair<int, int>, int>> que;
	// 시작 지점 설정
	que.push({ {0, 0}, 1 });
	level[0][0][1] = 1;

	while (!que.empty())
	{
		// 현재 노드의 위치와 벽을 부순적이 있는지 불러온다.
		int row = que.front().first.first;
		int col = que.front().first.second;
		int block = que.front().second;
		que.pop();

		// 마지막 노드이면 결과 리턴
		if (row == n - 1 && col == m - 1)
			return level[row][col][block];

		// 각 방향에 대해 반복
		for (int i = 0; i < 4; i++)
		{
			// 다음 움직일 위치
			int next_row = row + dir[i][0];
			int next_col = col + dir[i][1];

			// 다음 위치가 범위 내에 들어오는지
			if (0 <= next_row && next_row < n && 0 <= next_col && next_col < m)
			{
				// 다음 위치가 벽이고, 아직 벽을 부순적이 없으면
				if (graph[next_row][next_col] == '1' && block)
				{
					// 부순것으로 바꾸어 큐에 추가하고
					que.push({ {next_row, next_col}, 0 });
					// 벽을 부순 차원의 레벨을 1을 추가하여 갱신한다.
					level[next_row][next_col][0] = level[row][col][block] + 1;
				}
				// 다음 위치가 길이고, 해당 차원(벽을 부쉈건 안부쉈건)에서 방문한 적이 없으면
				else if (graph[next_row][next_col] == '0' && level[next_row][next_col][block] == 0)
				{
					// 다음 위치와 벽 상태 그대로 큐에 추가
					que.push({ {next_row, next_col}, block });
					// 그 차원의 레벨 +1 더하여 갱신
					level[next_row][next_col][block] = level[row][col][block] + 1;
				}
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		graph.push_back(input);
	}

	cout << bfs() << endl;

	return 0;
}