#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MAX 100000

using namespace std;

class Point {
public:
	int row;
	int col;

	int GetDistance(Point point)
	{
		return abs(point.row - row) + abs(point.col - col);
	}
};

int n, m;
vector<Point> chickens;
vector<Point> homes;
int distances[100];

int GetMinimumDistance(int selectedChicken, int chickenIndex)
{
	int sum = 0;
	int minimum = MAX;
	int tempDistances[100];

	for (int i = 0; i < homes.size(); i++)
	{
		int dist = chickens[chickenIndex].GetDistance(homes[i]);
		tempDistances[i] = distances[i];
		distances[i] = min(dist, distances[i]);
		sum += distances[i];
	}

	if (selectedChicken + 1 < m)
	{
		for (int i = chickenIndex + 1; i < chickens.size(); i++)
		{
			int res = GetMinimumDistance(selectedChicken + 1, i);
			if (minimum > res)
				minimum = res;
		}
		
		for (int i = 0; i < homes.size(); i++)
			distances[i] = tempDistances[i];
		return minimum;
	}
	else
	{
		for (int i = 0; i < homes.size(); i++)
			distances[i] = tempDistances[i];
 		return sum;
	}
}

int GetMinimumDistance()
{
	int minimum = MAX;

	for (int i = 0; i < chickens.size(); i++)
	{
		int res = GetMinimumDistance(0, i);
		if (minimum > res)
			minimum = res;
	}

 	return minimum;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int input;
			cin >> input;
			if (input == 1)
				homes.push_back({ i, j });
			else if (input == 2)
				chickens.push_back({ i, j });
		}
	}

	fill(distances, distances + homes.size(), MAX);

	cout << GetMinimumDistance() << endl;

	return 0;
}