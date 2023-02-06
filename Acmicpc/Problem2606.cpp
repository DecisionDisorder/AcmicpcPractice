#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
	vector<Node*> adjacent;
	bool visited = false;
};

void search(Node* graph, int& count)
{
	queue<Node*> graphQue;
	graphQue.push(graph);
	graph->visited = true;

	while (!graphQue.empty())
	{
		Node* node = graphQue.front();
		graphQue.pop();

		for (int i = 0; i < node->adjacent.size(); i++)
		{
 			if (!node->adjacent[i]->visited)
			{
				node->adjacent[i]->visited = true;
				graphQue.push(node->adjacent[i]);
				count++;
			}
		}
	}
}

int main()
{
	int n, m, count = 0;
	cin >> n;
	cin >> m;

	Node* graph = new Node[n];

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a - 1].adjacent.push_back(&graph[b - 1]);
		graph[b - 1].adjacent.push_back(&graph[a - 1]);
	}

	search(graph, count);

	cout << count << endl;

	return 0;
}