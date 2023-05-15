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
	queue<Node*> graphQue;		// 탐색 대상 노드 대기열
	graphQue.push(graph);	// 시작 노드 Push 및 방문 처리
	graph->visited = true;

	// 모든 대기열을 탐색할 때 까지 반복
	while (!graphQue.empty())
	{
		// 대기열 맨 앞의 노드를 불러오고 Pop
		Node* node = graphQue.front();
		graphQue.pop();

		// 현재 노드와 인접한 모든 노드에 대해 탐색
		for (int i = 0; i < node->adjacent.size(); i++)
		{
			// 인접한 노드 중에 아직 방문하지 않은 노드는 방문 처리
 			if (!node->adjacent[i]->visited)
			{
				// 방문 체크 및 대기열에 push 후, 감염된 컴퓨터 수 증가 처리
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