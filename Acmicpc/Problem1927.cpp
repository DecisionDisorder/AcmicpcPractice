#include <iostream>
#include <queue>
using namespace std;

int main()
{
	priority_queue<int> pq;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int input;
		scanf("%d", &input);

		if (input == 0)
		{
			if (!pq.empty())
			{
				printf("%d\n", -pq.top());
				pq.pop();
			}
			else
				printf("0\n");
		}
		else
		{
			pq.push(-input);
		}
	}
	
	return 0;
}