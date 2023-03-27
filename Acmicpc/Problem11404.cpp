#include <iostream>
#define INF 1000000001
using namespace std;

int graph[101][101];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		fill(graph[i] + 1, graph[i] + n + 1, INF);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(graph[a][b] > c)
			graph[a][b] = c;
	}


	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
				{
					graph[i][j] = 0;
					continue;
				}

				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] == INF)
				cout << "0 ";
			else
				cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	

	return 0;
}