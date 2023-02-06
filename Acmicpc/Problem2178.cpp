#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Node {
public:
	bool available;
	bool visited;
	int level = 1;
	int row;
	int col;
};

void visit(Node** root, queue<Node*>& que, int row, int col, int level, int rowSize, int colSize)
{
	if (row >= 0 && col >= 0 && row < rowSize && col < colSize) 
	{
		Node* node = &root[row][col];
		if (node->available && !node->visited)
		{
			node->visited = true;
			node->level = level + 1;
			que.push(node);
		}
	}
}

int search(Node** root, int rowSize, int colSize)
{
	list<Node*> pathList;
	queue<Node*> nodeQueue;
	(*root)->visited = true;
	nodeQueue.push(*root);

	while (!nodeQueue.empty())
	{
		Node* currentNode = nodeQueue.front();
		nodeQueue.pop();
		pathList.push_back(currentNode);

		visit(root, nodeQueue, currentNode->row - 1, currentNode->col, currentNode->level, rowSize, colSize);
		visit(root, nodeQueue, currentNode->row, currentNode->col - 1, currentNode->level, rowSize, colSize);
		visit(root, nodeQueue, currentNode->row + 1, currentNode->col, currentNode->level, rowSize, colSize);
		visit(root, nodeQueue, currentNode->row, currentNode->col + 1, currentNode->level, rowSize, colSize);
	}
	
	return root[rowSize - 1][colSize - 1].level;
}

int main()
{
	int rowSize, colSize, result;
	Node** maze;
	cin >> rowSize >> colSize;
	maze = new Node*[rowSize];

	for (int i = 0; i < rowSize; i++)
	{
		maze[i] = new Node[colSize];
		char* cols = new char[colSize];

		cin >> cols;
		for (int j = 0; j < colSize; j++)
		{
			maze[i][j].row = i;
			maze[i][j].col = j;
			maze[i][j].available = cols[j] == '1' ? true : false;
			maze[i][j].visited = false;
		}
	}

	result = search(maze, rowSize, colSize);
	cout << result << endl;

	return 0;
}