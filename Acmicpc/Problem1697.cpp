#include <iostream>
#include <queue>

using namespace std;

const int LIMIT = 100000;

class Apartment
{
public:
	bool visited = false;
	int level = 0;

	Apartment()
	{
		visited = false;
		level = 0;
	}
};

void visit(queue<int>& que, Apartment* posArr, int pos, int priorPos)
{
	if(0 <= pos && pos <= LIMIT)
	if (!posArr[pos].visited)
	{
		posArr[pos].visited = true;
		posArr[pos].level = posArr[priorPos].level + 1;
		que.push(pos);
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	queue<int> que;
	Apartment* posArr = new Apartment[100001];

	posArr[n].visited = true;
	que.push(n);

	while (!que.empty())
	{
		int pos = que.front();
		que.pop();

		visit(que, posArr, pos + 1, pos);
		visit(que, posArr, pos - 1, pos);
		visit(que, posArr, pos * 2, pos);

		if (pos == k)
			break;
	}

	cout << posArr[k].level << endl;

	return 0;
}