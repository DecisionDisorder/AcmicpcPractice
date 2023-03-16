#include <iostream>
#include <queue>
#define MAX 200001

using namespace std;

class Node 
{
public:
	int num;
	int level;
	int wayAmount;

	Node()
	{
		level = 9999999;
		wayAmount = 0;
	}
};

int startPoint;
int endPoint;
Node* nodes;

void visit(int index, int priorIndex, queue<Node*>& que)
{
	if (nodes[index].level >= nodes[priorIndex].level + 1)
	{
		nodes[index].level = nodes[priorIndex].level + 1;
		nodes[index].wayAmount++;
		que.push(nodes + index);
	}
}

void search()
{
	queue<Node*> que;
	que.push(nodes + startPoint);

	while (!que.empty())
	{
		Node* node = que.front();
		que.pop();
		
		if (node->num - 1 >= 0)
			visit(node->num - 1, node->num, que);
		if (node->num + 1 < MAX)
			visit(node->num + 1, node->num, que);
		if (node->num * 2 < MAX)
			visit(node->num * 2, node->num, que);
	}
}

int main()
{
	cin >> startPoint >> endPoint;

	if (startPoint == endPoint)
	{
		cout << 0 << endl << 1 << endl;
		return 0;
	}
	else if (startPoint > endPoint)
	{
		cout << startPoint - endPoint << endl << 1 << endl;
		return 0;
	}
	nodes = new Node[MAX];
	nodes[startPoint].level = 0;

	for (int i = 0; i < MAX; i++)
	{
		nodes[i].num = i;
	}

	search();

	cout << nodes[endPoint].level << endl;
	cout << nodes[endPoint].wayAmount << endl;

	return 0;
}