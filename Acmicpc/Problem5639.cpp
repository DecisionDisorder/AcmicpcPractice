#include <iostream>

using namespace std;

class Node
{
public:
	int num;
	Node* left;
	Node* right;

	Node(int num)
	{
		this->num = num;
		left = nullptr;
		right = nullptr;
	}
};

class Tree
{
public:
	Node* head;

	void insert(Node* newNode)
	{
		Node* node = head;
		while (true)
		{
			if (node->num < newNode->num)
			{
				if (node->right)
					node = node->right;
				else
				{
					node->right = newNode;
					break;
				}
			}
			else
			{
				if (node->left)
					node = node->left;
				else
				{
					node->left = newNode;
					break;
				}
			}
		}
	}

	void postorder(Node* node = nullptr)
	{
		if (!node)
			node = head;

		if (node->left)
			postorder(node->left);
		if (node->right)
			postorder(node->right);
		printf("%d\n", node->num);
	}
};

int main()
{
	Tree tree;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num;
	int inputIdx = 0;
	while (cin >> num) {
		if (inputIdx == 0)
			tree.head = new Node(num);
		else
			tree.insert(new Node(num));
		inputIdx++;
	}

	tree.postorder();

	return 0;
}