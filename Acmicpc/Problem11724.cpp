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
	// ������ ��尡 �ִ��� Ȯ��
	if (!node->adjacent.empty())
	{
		// ���� ��� �湮 ó��
		node->visited = true;
		// ��� ������ ��忡 ���ؼ� �ݺ�
		for (int i = 0; i < node->adjacent.size(); i++)
		{
			// ���� ��� �߿� ���� �湮���� ���� ��带 �Ű������� ��Ƽ� ����� ȣ��
			if(!node->adjacent[i]->visited)
				dfs(node->adjacent[i]);
		}
			
	}
}

void search(Node* nodes, int len, int& count)
{
	// ��� ��忡 ���ؼ� �ݺ�
	for (int i = 0; i < len; i++)
	{
		// �湮���� ���� ��忡 ���ؼ�
		if (!nodes[i].visited)
		{
			// dfs Ž���ϸ� ����� ������ �湮ó��
			dfs(nodes + i);
			// count ���� ���� ó��
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

		// 1������ �����ϴ� ��ȣ�� 0������ �������� ��ȯ
		--inputA; --inputB; 
		// ��������� ���� ��� �߰�
		nodes[inputA].adjacent.push_back(&nodes[inputB]);
		nodes[inputB].adjacent.push_back(&nodes[inputA]);
	}

	// Ž�� �� ���
	search(nodes, N, count);

	cout << count << endl;

	return 0;
}