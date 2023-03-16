#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	int num;
	int parent;
};

int main()
{
	int n;
	scanf("%d", &n);

	Node* tree = new Node[n];
	tree[0].num = 1;
	tree[0].parent = 1;
	for (int i = 1; i < n; i++)
		tree[i].parent = 0;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		if (tree[a - 1] == 0)
		{
			tree[a - 1] = b;
		}
		else
		{
			tree[b - 1] = a;
		}
	}

	for (int i = 1; i < n; i++)
	{
		printf("%d\n", tree[i]);
	}
	
	return 0;
}