#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int num;
	int cost;
	vector<Node*> children;

	int radius;
	int maximumCost;
	static int maximumRadius;

	void Init(int num, int cost)
	{
		this->num = num;
		this->cost = cost;
		maximumCost = 0;

		radius = 0;
	}

	void AddChild(Node* child)
	{
		children.push_back(child);
	}

	void SetMaximumRadius()
	{
		int a = 0, b = 0;
		int indexA = 0, indexB = 0;

		if (children.size() == 0)
			return;

		for (int i = 0; i < children.size(); i++)
		{
			children[i]->SetMaximumRadius();

			int childCost = children[i]->maximumCost + children[i]->cost;
			if (childCost > a)
			{
				b = a;
				indexB = indexA;

				a = childCost;
				indexA = i;
			}
  			else if (b <= childCost && childCost <= a)
			{
				b = childCost;
				indexB = i;
			}
		}
		radius = a + b;
		maximumCost = a > b ? a : b;

		if (maximumRadius < radius)
			maximumRadius = radius;
	}
};

int Node::maximumRadius = 0;

int main()
{
	int n;
	cin >> n;

	Node* tree = new Node[n + 1];
	tree[1].Init(1, 0);

	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		tree[b].Init(b, c);
		tree[a].AddChild(tree + b);
	}
	
	tree[1].SetMaximumRadius();

	cout << Node::maximumRadius << endl;

	return 0;
}