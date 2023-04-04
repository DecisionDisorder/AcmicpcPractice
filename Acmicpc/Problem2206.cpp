#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// �ʵ� ũ��
int n, m;
// �� ���¸� ������ �ִ� ���ڿ� ����
vector<string> graph;
// 0: �̹� ���� �μ��� �̵��ϴ� level
// 1: ���� �μ��� ���� level
int level[1000][1000][2];
// ��ķ� �����̴� 4���⿡ ���� �迭
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int bfs()
{
	// first.pair: row, col / second: block�� �μ��� ������ ����
	queue<pair<pair<int, int>, int>> que;
	// ���� ���� ����
	que.push({ {0, 0}, 1 });
	level[0][0][1] = 1;

	while (!que.empty())
	{
		// ���� ����� ��ġ�� ���� �μ����� �ִ��� �ҷ��´�.
		int row = que.front().first.first;
		int col = que.front().first.second;
		int block = que.front().second;
		que.pop();

		// ������ ����̸� ��� ����
		if (row == n - 1 && col == m - 1)
			return level[row][col][block];

		// �� ���⿡ ���� �ݺ�
		for (int i = 0; i < 4; i++)
		{
			// ���� ������ ��ġ
			int next_row = row + dir[i][0];
			int next_col = col + dir[i][1];

			// ���� ��ġ�� ���� ���� ��������
			if (0 <= next_row && next_row < n && 0 <= next_col && next_col < m)
			{
				// ���� ��ġ�� ���̰�, ���� ���� �μ����� ������
				if (graph[next_row][next_col] == '1' && block)
				{
					// �μ������� �ٲپ� ť�� �߰��ϰ�
					que.push({ {next_row, next_col}, 0 });
					// ���� �μ� ������ ������ 1�� �߰��Ͽ� �����Ѵ�.
					level[next_row][next_col][0] = level[row][col][block] + 1;
				}
				// ���� ��ġ�� ���̰�, �ش� ����(���� �ν��� �Ⱥν���)���� �湮�� ���� ������
				else if (graph[next_row][next_col] == '0' && level[next_row][next_col][block] == 0)
				{
					// ���� ��ġ�� �� ���� �״�� ť�� �߰�
					que.push({ {next_row, next_col}, block });
					// �� ������ ���� +1 ���Ͽ� ����
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