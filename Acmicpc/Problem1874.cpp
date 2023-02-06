#include <iostream>
#include <stack>
#include <list>

using namespace std;

int main()
{
	stack<int> stack;
	list<char> resultList;

	int n, i = 1, k = 0;
	scanf("%d", &n);

	int* sequence = new int[n];

	for (int j = 0; j < n; j++)
		scanf("%d", sequence + j);

	do
	{
		if (stack.empty())
		{
			stack.push(i);
			resultList.push_back('+');
			i++;
			continue;
		}

		if (stack.top() == sequence[k])
		{
			stack.pop();
			k++;
			resultList.push_back('-');
		}
		else if (stack.top() < sequence[k])
		{
			stack.push(i);
			resultList.push_back('+');
			i++;
		}
		else
		{
			printf("NO");
			return 0;
		}
	} while (!stack.empty() || i <= n);

	list<char>::iterator iter = resultList.begin();
 	for (iter = resultList.begin(); iter != resultList.end(); iter++)
	{
		printf("%c\n", *iter);
	}

	return 0;
}