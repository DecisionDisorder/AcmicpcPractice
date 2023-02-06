#include <iostream>
#include <vector>

using namespace std;

class Node {

public:
	bool visited = false;
	vector<Node*> adjacent;
};

void dfs(Node* node)
{
	if (!node->adjacent.empty())
	{
		node->visited = true;
		for (int i = 0; i < node->adjacent.size(); i++)
		{
			if(!node->adjacent[i]->visited)
				dfs(node->adjacent[i]);
		}
			
	}
}

void search(Node* nodes, int len, int& count)
{
	for (int i = 0; i < len; i++)
	{
		if (!nodes[i].visited)
		{
			dfs(nodes + i);
			count++;
		}
	}
}

int main()
{
	int N, M, count = 0;
	Node* nodes;
	scanf("%d %d", &N, &M);

	nodes = new Node[N];

	for (int i = 0; i < M; i++)
	{
		int inputA, inputB;
		scanf("%d %d", &inputA, &inputB);
		--inputA; --inputB;
		nodes[inputA].adjacent.push_back(&nodes[inputB]);
		nodes[inputB].adjacent.push_back(&nodes[inputA]);
	}

	search(nodes, N, count);

	printf("%d\n", count);

	return 0;
}