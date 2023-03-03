#include <iostream>
#include <queue>

using namespace std;

struct Position
{
	int row;
	int col;
};

class Fish
{
protected:
	Position pos;
	int size;
	int currentRound;
	int distance;

public:
	Fish() { currentRound = 0; distance = 0; }

	void Init(Position pos, int size)
	{
		this->pos = pos;
		this->size = size;
	}

	void Visit(int round, queue<Fish*>& que)
	{
		if (!IsVisited(round))
		{
			distance = que.front()->distance + 1;
			currentRound = round;
			que.push(this);
		}
	}

	bool IsVisited(int round)
	{
		return currentRound >= round ? true : false;
	}

	int GetSize()
	{
		return size;
	}

	Position GetPosition()
	{
		return pos;
	}

	void InitDistance()
	{
		distance = 0;
		currentRound++;
	}

	int GetDistance()
	{
		return distance;
	}

	void EatenUp()
	{
		size = 0;
	}
};

class Shark : public Fish
{
private:
	int fishCount;
	int timePassed;

public:
	Shark() {currentRound = 1; fishCount = 0; timePassed = 0;}

	void Init(Position pos, int size)
	{
		Fish::Init(pos, size);
	}

	void EatFish(Fish& fish)
	{
		if (Compare(fish) > 0)
		{
			timePassed += fish.GetDistance();
			fishCount++;
			fish.EatenUp();
			if (fishCount == size)
			{
				size++;
				fishCount = 0;
			}
		}
	}

	int Compare(Fish fish)
	{
		if (size == fish.GetSize() || fish.GetSize() == 0)
			return 0;
		else if (size > fish.GetSize())
			return 1;
		else
			return -1;
	}

	void AddRound()
	{
		currentRound++;
	}
	int GetRound()
	{
		return currentRound;
	}
	void SetPosition(Position newPos)
	{
		pos = newPos;
	}
	int GetTimePassed()
	{
		return timePassed;
	}
};

Fish* GetNearestFish(queue<Fish*> visitedQue, Shark& shark)
{
	int minDistance = 9999, minRow = 9999, minCol = 9999;
	Fish* nearestFish = nullptr;
	while(!visitedQue.empty())
	{
		Fish* fish = visitedQue.front();
		if (shark.Compare(*fish) > 0 && fish->GetDistance() < minDistance)
		{
			minDistance = fish->GetDistance();
			nearestFish = fish;
			minCol = fish->GetPosition().col;
			minRow = fish->GetPosition().row;
		}
		else if (shark.Compare(*fish) > 0 && fish->GetDistance() == minDistance)
		{
			if (fish->GetPosition().row == minRow)
			{
				if (fish->GetPosition().col < minCol)
				{
					minDistance = fish->GetDistance();
					nearestFish = fish;
					minCol = fish->GetPosition().col;
				}
			}
			else if (fish->GetPosition().row < minRow)
			{
				minDistance = fish->GetDistance();
				nearestFish = fish;
				minRow = fish->GetPosition().row;
			}
		}
		visitedQue.pop();
	}

	return nearestFish;
}

void Print(Fish** fishBoard, int size, Shark& shark)
{
	cout << endl;
	cout << "[time elapsed]" << shark.GetTimePassed() << endl;
	cout << "[size]" << shark.GetSize() << endl;
	cout << "[Shark Pos]" << shark.GetPosition().row << ", " << shark.GetPosition().col << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if(shark.GetPosition().row == i && shark.GetPosition().col == j)
				cout << "9 ";
			else
				cout << fishBoard[i][j].GetSize() << " ";

		}
		cout << endl;
	}
}

int Search(Fish** fishBoard, int size, Shark& shark)
{
	while (true)
	{
		Position sharkPos = shark.GetPosition();
		queue<Fish*> que;
		queue<Fish*> visitedQue;
		que.push(&fishBoard[sharkPos.row][sharkPos.col]);
		que.front()->InitDistance();

		while (!que.empty())
		{
			Fish* fish = que.front();
			visitedQue.push(que.front());
			Position fishPos = fish->GetPosition();

			if (fishPos.row - 1 >= 0)
				if (shark.Compare(fishBoard[fishPos.row - 1][fishPos.col]) >= 0)
					fishBoard[fishPos.row - 1][fishPos.col].Visit(shark.GetRound(), que);
			if (fishPos.col - 1 >= 0)
				if (shark.Compare(fishBoard[fishPos.row][fishPos.col - 1]) >= 0)
					fishBoard[fishPos.row][fishPos.col - 1].Visit(shark.GetRound(), que);
			if (fishPos.col + 1 < size)
				if (shark.Compare(fishBoard[fishPos.row][fishPos.col + 1]) >= 0)
					fishBoard[fishPos.row][fishPos.col + 1].Visit(shark.GetRound(), que);
			if (fishPos.row + 1 < size)
				if (shark.Compare(fishBoard[fishPos.row + 1][fishPos.col]) >= 0)
					fishBoard[fishPos.row + 1][fishPos.col].Visit(shark.GetRound(), que);

			que.pop();
		}

		shark.AddRound();

		Fish* nearestFish = GetNearestFish(visitedQue, shark);
		if (nearestFish != nullptr)
		{
			shark.EatFish(*nearestFish);
			shark.SetPosition(nearestFish->GetPosition());
		}
		else
			break;
	}
	
	return shark.GetTimePassed();
}

int main()
{
	int n;
	cin >> n;

	Fish** fishBoard = new Fish*[n];
	Shark shark;

	for (int i = 0; i < n; i++)
	{
		fishBoard[i] = new Fish[n];
		for (int j = 0; j < n; j++)
		{
			int size;
			cin >> size;
			if(size != 9)
				fishBoard[i][j].Init({i, j}, size);
			else
			{
				shark.Init({i, j}, 2);
				fishBoard[i][j].Init({i, j}, 0);
			}
				
		}
	}
	cout << Search(fishBoard, n, shark) << endl;

	return 0;
}