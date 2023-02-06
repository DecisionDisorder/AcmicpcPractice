#include <iostream>
#include <queue>

using namespace std;

int getNextNumber(queue<int>& que, int k)
{
	for (int i = 0; i < k; i++)
	{
		if (!que.empty())
		{
			int front = que.front();
			que.pop();
			if (i == k - 1)
				return front;
			else
				que.push(front);
		}
		else
			return 0;
	}
	return 0;
}

int main()
{
	queue<int> que;
	
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		que.push(i);
	}

	cout << "<";
	while (que.size() > 0)
	{
		cout << getNextNumber(que, k);
		if(que.size() > 0)
			cout << ", ";
	}
	cout << ">" << endl;


	return 0;
}