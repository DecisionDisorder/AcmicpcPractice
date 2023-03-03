#include <iostream>

using namespace std;

class Node
{
public:
	char name;
	Node* left;
	Node* right;
	Node* parent;

	Node(char name)
	{
		this->name = name;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
};

void SetChildren(Node* parent, char left, char right)
{
	if (left != '.')
	{
		Node* leftNode = new Node(left);
		parent->left = leftNode;
	}
	if (right != '.')
	{
		Node* rightNode = new Node(right);
		parent->right = rightNode;
	}
}

Node* GetParentByName(Node* root, char name)
{
	Node* node = root;
	if (node != nullptr)
	{
		if (node->name == name)
			return node;
		else
		{
			Node* left, * right;

			if (node->left != nullptr)
			{
				left = GetParentByName(node->left, name);
				if (left != nullptr)
					return left;
			}

			if (node->right != nullptr)
			{
				right = GetParentByName(node->right, name);
				if (right != nullptr)
					return right;
			}

			return nullptr;
		}
	}
	else
		return nullptr;
}

void Preorder(Node* node)
{
	if (node != nullptr)
	{
		cout << node->name;
		Preorder(node->left);
		Preorder(node->right);
	}
}
void Inorder(Node* node)
{
	if (node != nullptr)
	{
		Inorder(node->left);
		cout << node->name;
		Inorder(node->right);
	}
}
void Postorder(Node* node)
{
	if (node != nullptr)
	{
		Postorder(node->left);
		Postorder(node->right);
		cout << node->name;
	}
}

int main()
{
	int n;
	char parentName, left, right;
	cin >> n;

	Node* root;

	cin >> parentName >> left >> right;
	root = new Node(parentName);
	SetChildren(root, left, right);

	for (int i = 1; i < n; i++)
	{
		cin >> parentName >> left >> right;
		SetChildren(GetParentByName(root, parentName), left, right);
	}

	Preorder(root);
	cout << endl;
	Inorder(root);
	cout << endl;
	Postorder(root);
	
	return 0;
}