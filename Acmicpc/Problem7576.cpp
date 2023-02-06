#include <iostream>
#include <queue>

using namespace std;


class Position {
public:
	int row;
	int col;

	Position() {}

	Position(int row, int col)
	{
		setPosition(row, col);
	}

	void setPosition(int row, int col)
	{
		this->row = row;
		this->col = col;
	}
};

class Tomato {
public:
	Position pos;
	int status;
	bool visited;
	int level;

	Tomato() {}

	void setInfo(int row, int col, int status)
	{
		pos.row = row;
		pos.col = col;
		this->status = status;
		visited = false;
		level = 0;
	}
};

void visit(Tomato* tomato, queue<Tomato*>& que, const Tomato* priorTomato)
{
	if (tomato->status == 0 && !tomato->visited)
	{
		que.push(tomato);
		tomato->visited = true;
		tomato->status = 1;
		tomato->level += priorTomato->level + 1;
	}
}

void search(Tomato** tomatoBox, queue<Tomato*> que, const Position& limitPos)
{
	while (!que.empty())
	{
		Tomato* tomato = que.front();
		que.pop();

		int row = tomato->pos.row;
		int col = tomato->pos.col;

		if(row - 1 >= 0)
			visit(&tomatoBox[row - 1][col], que, tomato);
		if(row + 1 < limitPos.row)
			visit(&tomatoBox[row + 1][col], que, tomato);
		if(col - 1 >= 0)
			visit(&tomatoBox[row][col - 1], que, tomato);
		if (col + 1 < limitPos.col)
			visit(&tomatoBox[row][col + 1], que, tomato);
	}
}

void searchAll(Tomato** tomatoBox, const Position& limitPos)
{
	queue<Tomato*> que;

	for (int i = 0; i < limitPos.row; i++)
	{
		for (int j = 0; j < limitPos.col; j++)
		{
			if (tomatoBox[i][j].status == 1)
			{
				que.push(&tomatoBox[i][j]);
				tomatoBox[i][j].visited = true;
			}
		}
	}

	search(tomatoBox, que, limitPos);
}

int getTimeCost(Tomato** tomatoBox, const Position& limitPos)
{
	int max = 0;
	for (int j = 0; j < limitPos.row; j++)
	{
		for (int k = 0; k < limitPos.col; k++)
		{
			Tomato* tomato = &tomatoBox[j][k];

			if (tomato->status == 0 && !tomato->visited)
				return -1;

			if (tomato->level > max)
			{
				max = tomato->level;
			}
		}
	}

	return max;
}

int main()
{
	int M, N;

	scanf("%d %d", &M, &N);

	Position limitPos(N, M);
	Tomato** tomatoBox = new Tomato *[N];


	for (int j = 0; j < N; j++)
	{
		tomatoBox[j] = new Tomato[M];
		for (int k = 0; k < M; k++)
		{
			int input;
			scanf("%d", &input);
			tomatoBox[j][k].setInfo(j, k, input);
		}
	}

	searchAll(tomatoBox, limitPos);
	printf("%d\n", getTimeCost(tomatoBox, limitPos));

	return 0;
}