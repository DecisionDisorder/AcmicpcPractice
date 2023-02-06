#include <iostream>
#include <queue>
using namespace std;

class Position {
public:
	int floor;
	int row;
	int col;

	Position() {}

	Position(int floor, int row, int col)
	{
		setPosition(floor, row, col);
	}

	void setPosition(int floor, int row, int col)
	{
		this->floor = floor;
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

	void setInfo(int floor, int row, int col, int status)
	{
		pos.floor = floor;
		pos.row = row;
		pos.col = col;
		this->status = status;
		visited = false;
		level = 0;
	}
};

void visit(queue<Tomato*>& tomatoQue, Tomato* tomato, const Tomato* priorTomato)
{
	if (!tomato->visited && tomato->status == 0)
	{
		tomato->visited = true;
		tomato->level += priorTomato->level + 1;
		tomato->status = 1;
		tomatoQue.push(tomato);
	}	
}

void search(Tomato*** tomatoBox, queue<Tomato*>& tomatoQue, const Position& limitPos)
{
	while (!tomatoQue.empty())
	{
		Tomato* tomato = tomatoQue.front();
		tomatoQue.pop();

		int floor = tomato->pos.floor;
		int row = tomato->pos.row;
		int col = tomato->pos.col;

		if (col - 1 >= 0)
			visit(tomatoQue, &tomatoBox[floor][row][col - 1], tomato);
		if (col + 1 < limitPos.col)
			visit(tomatoQue, &tomatoBox[floor][row][col + 1], tomato);
		if (row - 1 >= 0)
			visit(tomatoQue, &tomatoBox[floor][row - 1][col], tomato);
		if (row + 1 < limitPos.row)
			visit(tomatoQue, &tomatoBox[floor][row + 1][col], tomato);
		if (floor - 1 >= 0)
			visit(tomatoQue, &tomatoBox[floor - 1][row][col], tomato);
		if (floor + 1 < limitPos.floor)
			visit(tomatoQue, &tomatoBox[floor + 1][row][col], tomato);
	}
}

void searchAll(Tomato*** tomatoBox, const Position& limitPos)
{
	queue<Tomato*> tomatoQue;

	for (int i = 0; i < limitPos.floor; i++)
	{
		for (int j = 0; j < limitPos.row; j++)
		{
			for (int k = 0; k < limitPos.col; k++)
			{
				Tomato* tomato = &tomatoBox[i][j][k];
				if (tomato->status == 1 && !tomato->visited)
				{
					tomato->visited = true;
					tomatoQue.push(tomato);
				}
			}
		}
	}

	search(tomatoBox, tomatoQue, limitPos);
}

int getTimeCost(Tomato*** tomatoBox, const Position& limitPos)
{
	int max = 0;
	for (int i = 0; i < limitPos.floor; i++)
	{
		for (int j = 0; j < limitPos.row; j++)
		{
			for (int k = 0; k < limitPos.col; k++)
			{
				Tomato* tomato = &tomatoBox[i][j][k];
				
				if (tomato->status == 0 && !tomato->visited)
					return -1;

				if (tomato->level > max)
				{
					max = tomato->level;
				}
			}
		}
	}

	return max;
}

int main()
{
	int M, N, H;

	scanf("%d %d %d", &M, &N, &H);
	
	Position limitPos(H, N, M);
	Tomato*** tomatoBox = new Tomato**[H];


	for (int i = 0; i < H; i++)
	{
		tomatoBox[i] = new Tomato * [N];
		for (int j = 0; j < N; j++)
		{
			tomatoBox[i][j] = new Tomato[M];
			for (int k = 0; k < M; k++)
			{
				int input;
				scanf("%d", &input);
				tomatoBox[i][j][k].setInfo(i, j, k, input);
			}
		}
	}

	searchAll(tomatoBox, limitPos);
	printf("%d\n", getTimeCost(tomatoBox, limitPos));

	return 0;
}