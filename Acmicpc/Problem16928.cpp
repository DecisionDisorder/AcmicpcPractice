#include <iostream>
#include <queue>
#define SIZE 100

using namespace std;

class Board {
public:
	int position;
	int destination;
	int level;
	bool visited;

	Board() 
	{
		destination = 0;
		level = 0;
		visited = false;
	}

	void SetDestination(int d)
	{
		destination = d;
	}
};

void visit(Board* cBoard, Board* pBoard, queue<Board*>& que)
{
	if (cBoard->level > pBoard->level || !cBoard->visited)
	{
		cBoard->level = pBoard->level + 1;
		cBoard->visited = true;
		que.push(cBoard);
	}
}

int search(Board boards[SIZE], Board* endBoard)
{
	queue<Board*> que;
	Board* priorBoard = nullptr;
	que.push(&boards[0]);
	boards[0].visited = true;

	while (!que.empty())
	{
		Board* board = que.front();
		que.pop();
		board->visited = true;

		if (board == endBoard)
		{
			return board->level;
		}

		if (board->destination)
		{
			boards[board->destination].visited = true;
			boards[board->destination].level = board->level;
			
			que.push(boards + board->destination);
			board = boards + board->destination;
		}

		for (int i = 1; i <= 6; i++)
		{
			visit(board + i, board, que);
			if (board + i == endBoard)
			{
				return endBoard->level;
			}

		}

		
	}

	return 0;
}

int main()
{
	Board boards[SIZE];
	int n, m;

	cin >> n >> m;

	for(int i = 0; i < SIZE; i++)
		boards[i].position = i;

	for (int i = 0; i < n + m; i++)
	{
		int from, to;
		cin >> from >> to;
		boards[from - 1].destination = to - 1;
	}

	cout << search(boards, boards + (SIZE - 1)) << endl;

	return 0;
}