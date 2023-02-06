#include <iostream>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

class Node {
public:
	int val;
	list<Node*> adjacentNodes;
	bool visitedDFS = false;
	bool visitedBFS = false;
};

list<int> searchBFS(Node* root, int start)
{
	list<int> result;

	queue<Node*> nodeQueue;
	root = root + (start - 1);
	root->visitedBFS = true;
	nodeQueue.push(root);

	while (!nodeQueue.empty())
	{
		Node* r = nodeQueue.front();
		nodeQueue.pop();
		result.push_back(r->val);

		list<Node*>::iterator iter;
		for (iter = r->adjacentNodes.begin(); iter != r->adjacentNodes.end(); iter++)
		{
			if (!(*iter)->visitedBFS)
			{
				(*iter)->visitedBFS = true;
				nodeQueue.push(*iter);
			}
		}
	}
	return result;
}

void dfs(Node* node, list<int> &result)
{
	list<Node*>::iterator iter = node->adjacentNodes.begin();
	result.push_back(node->val); 
	for (; iter != node->adjacentNodes.end(); iter++)
	{
 		if (!(*iter)->visitedDFS)
		{
			(*iter)->visitedDFS = true;
			dfs(*iter, result);
		}
	}
	
}

list<int> searchDFS(Node* root, int start)
{
	list<int> result;
	root = root + (start - 1);
	root->visitedDFS = true;

	dfs(root, result);

	return result;
}

int main()
{
	int n, m, start;
	list<int> resultBFS, resultDFS;
	Node* nodes;

	cin >> n >> m >> start;
	nodes = new Node[n];
	for (int i = 0; i < n; i++)
		nodes[i].val = i + 1;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		nodes[a - 1].adjacentNodes.push_back(nodes + b - 1);
		nodes[b - 1].adjacentNodes.push_back(nodes + a - 1);
	}

	for (int i = 0; i < n; i++)
		nodes[i].adjacentNodes.sort();

	resultDFS = searchDFS(nodes, start);
	resultBFS = searchBFS(nodes, start);

	list<int>::iterator iter;
	for (iter = resultDFS.begin(); iter != resultDFS.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	for (iter = resultBFS.begin(); iter != resultBFS.end(); iter++) 
		cout << *iter << " ";
		

	return 0;
}