#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Apartment
{
public:
	int row;
	int col;
	int house;
	bool visited;

	Apartment()
	{
		visited = false;
	}
};

bool visit(Apartment** apt, int row, int col, int size, queue<Apartment*>& que)
{
	if (0 <= row && row < size && 0 <= col && col < size)
	{
		if (apt[row][col].house && !apt[row][col].visited)
		{
			apt[row][col].visited = true;
			que.push(&apt[row][col]);
			return true;
		}
	}
	return false;
}

void search(Apartment** apt, int row, int col, int size, int& aptCount)
{
	queue<Apartment*> que;
	que.push(&apt[row][col]);
	aptCount++;
	apt[row][col].visited = true;

	while (!que.empty())
	{
		Apartment* apart = que.front();
		que.pop();
		int row = apart->row, col = apart->col;

		visit(apt, row + 1, col, size, que) ? aptCount++ : 0;
		visit(apt, row - 1, col, size, que) ? aptCount++ : 0;
		visit(apt, row, col + 1, size, que) ? aptCount++ : 0;
		visit(apt, row, col - 1, size, que) ? aptCount++ : 0;
	}
}

void aptNumbering(Apartment** apt, int size, vector<int>& aptCountList)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (apt[i][j].house && !apt[i][j].visited)
			{
				int count = 0;
				search(apt, i, j, size, count);
				aptCountList.push_back(count);
			}
		}
	}
	sort(aptCountList.begin(), aptCountList.end());
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	scanf("%d", &n);
	Apartment **apt = new Apartment *[n];
	vector<int> aptCountList;

	for (int i = 0; i < n; i++)
	{
		apt[i] = new Apartment[n];
		for (int j = 0; j < n; j++)
		{
			int input;
			scanf("%1d", &input);
			apt[i][j].house = input;
			apt[i][j].row = i;
			apt[i][j].col = j;
		}
	}

	aptNumbering(apt, n, aptCountList);

	printf("%d\n", aptCountList.size());
	for (int i = 0; i < aptCountList.size(); i++)
	{
		printf("%d\n", aptCountList[i]);
	}

	return 0;
}