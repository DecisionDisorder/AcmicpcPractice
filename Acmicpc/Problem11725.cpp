#include <iostream>
#include <queue>
using namespace std;

int parents[100001];
queue<pair<int, int>> que[100001];

void SetParent(int child, int parent)
{
	parents[child] = parent;

	while (!que[child].empty())
	{
		int a = que[child].front().first;
		int b = que[child].front().second;
		que[child].pop();
		if (!((a == child && b == parent) || (a == parent && b == child)))
		{
			if (a == child)
			{
				SetParent(b, a);
			}
			else
			{
				SetParent(a, b);
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	parents[1] = 0;
	for (int i = 2; i <= n; i++)
		parents[i] = -1;
	
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		if (parents[a] != -1)
			SetParent(b, a);
		else if (parents[b] != -1)
			SetParent(a, b);
		else
		{
			que[a].push({ a, b });
			que[b].push({ a, b });
		}
			
	}

	for (int i = 2; i <= n; i++)
		printf("%d\n", parents[i]);

	return 0;
}