#include <iostream>
#include <queue>

using namespace std;

struct Point;

bool board[100][100];
int boardSize;
queue<pair<int, char>> actingQueue;

struct Point {
	int row;
	int col;
};

Point directions[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

class Snake {
private:
	int direction;
	Point head;
	deque<Point> headPathDeque;

	bool CheckGameOver()
	{
		if (0 <= head.row && head.row < boardSize && 0 <= head.col && head.col < boardSize)
		{
			if (!headPathDeque.empty())
			{
				for (int i = 0; i < headPathDeque.size() - 1; i++)
				{
					int row = headPathDeque[i].row;
					int col = headPathDeque[i].col;
					if (row == head.row && col == head.col)
						return true;
				}
			}

			return false;
		}
		else
			return true;
	}

public:

	Snake()
	{
		head = { 0, 0 };
		direction = 0;
		headPathDeque.push_back(head);
	}

	void TurnLeft()
	{
		direction--;
		if (direction < 0)
			direction = 3;
	}

	void TurnRight()
	{
		direction++;
		direction %= 4;
	}

	bool Move()
	{
		head.row += directions[direction].row;
		head.col += directions[direction].col;

		headPathDeque.push_back(head);

		bool res = CheckGameOver();

		if (!board[head.row][head.col])
		{
			if (!headPathDeque.empty())
			{
				headPathDeque.pop_front();
			}
		}
		else
		{
			board[head.row][head.col] = false;
		}

		return !res;
	}

	void ChangeDirection(char dir)
	{
		if (dir == 'L')
			TurnLeft();
		else
			TurnRight();
	}
};


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int k, l, time = 0;
	Snake snake;

	cin >> boardSize;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;
		board[r - 1][c - 1] = true;
	}

	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int time;
		char dir;
		cin >> time >> dir;
		actingQueue.push({ time, dir });
	}
	

	while (true)
	{
		time++;

		if (!snake.Move())
		{
			break;
		}

		if (!actingQueue.empty())
		{
			if (actingQueue.front().first == time)
			{
				snake.ChangeDirection(actingQueue.front().second);
				actingQueue.pop();
			}
		}
 		
	}

	cout << time << endl;
	return 0;
}