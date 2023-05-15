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
	// 인접한 노드가 있는지 확인
	if (!node->adjacent.empty())
	{
		// 현재 노드 방문 처리
		node->visited = true;
		// 모든 인접한 노드에 대해서 반복
		for (int i = 0; i < node->adjacent.size(); i++)
		{
			// 인접 노드 중에 아직 방문하지 않은 노드를 매개변수러 담아서 재귀적 호출
			if(!node->adjacent[i]->visited)
				dfs(node->adjacent[i]);
		}
			
	}
}

void search(Node* nodes, int len, int& count)
{
	// 모든 노드에 대해서 반복
	for (int i = 0; i < len; i++)
	{
		// 방문하지 않은 노드에 대해서
		if (!nodes[i].visited)
		{
			// dfs 탐색하며 연결된 노드들의 방문처리
			dfs(nodes + i);
			// count 개수 증가 처리
			count++;
		}
	}
}

int main()
{
	int N, M, count = 0;
	Node* nodes;
	cin >> N >> M;

	nodes = new Node[N];

	for (int i = 0; i < M; i++)
	{
		int inputA, inputB;
		cin >> inputA >> inputB;

		// 1번부터 시작하는 번호를 0번부터 시작으로 변환
		--inputA; --inputB; 
		// 양방향으로 인접 노드 추가
		nodes[inputA].adjacent.push_back(&nodes[inputB]);
		nodes[inputB].adjacent.push_back(&nodes[inputA]);
	}

	// 탐색 후 출력
	search(nodes, N, count);

	cout << count << endl;

	return 0;
}