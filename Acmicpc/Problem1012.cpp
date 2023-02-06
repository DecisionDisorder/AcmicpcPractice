#include <iostream>

using namespace std;

class Cabbage
{
public:
	bool planted = false;
	bool visited = false;
};

void visitNeighborhood(Cabbage** cabbages, int x, int y, int width, int height)
{
	if (0 <= x && x < width && 0 <= y && y < height)
	{
		if (cabbages[y][x].planted && !cabbages[y][x].visited)
		{
			cabbages[y][x].visited = true;
			visitNeighborhood(cabbages, x - 1, y, width, height);
			visitNeighborhood(cabbages, x + 1, y, width, height);
			visitNeighborhood(cabbages, x, y - 1, width, height);
			visitNeighborhood(cabbages, x, y + 1, width, height);
		}
	}
}

int getAmountOfWorm(Cabbage** cabbages, int width, int height)
{
	int count = 0;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			Cabbage* currentCab = &cabbages[y][x];
			if (currentCab->planted && !currentCab->visited)
			{
				visitNeighborhood(cabbages, x, y, width, height);
				count++;
			}
			else
				continue;
		}
	}

	return count;
}

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int width, height, num, count = 0;
		cin >> width >> height >> num;

		Cabbage** cabbages = new Cabbage*[height];
		for (int j = 0; j < height; j++)
			cabbages[j] = new Cabbage[width];

		for (int j = 0; j < num; j++)
		{
			int x, y;
			cin >> x >> y;
			cabbages[y][x].planted = true;
		}

		cout << getAmountOfWorm(cabbages, width, height) << endl;
	}

	return 0;
}