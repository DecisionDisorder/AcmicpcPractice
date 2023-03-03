#include <iostream>
#include <queue>
using namespace std;

class Pixel {
public:
	int rgb;
	bool normalVisited;
	bool colorVisited;
	int row;
	int col;

	Pixel()
	{
		normalVisited = false;
		colorVisited = false;
	}
};

void visitNormal(queue<Pixel*>& que, Pixel* currentPixel, Pixel* priorPixel)
{
	if (!currentPixel->normalVisited && currentPixel->rgb == priorPixel->rgb)
	{
		currentPixel->normalVisited = true;
		que.push(currentPixel);
	}
}
void visitColor(queue<Pixel*>& que, Pixel* currentPixel, Pixel* priorPixel)
{
	if (!currentPixel->colorVisited)
	{
		if ((currentPixel->rgb < 2 && priorPixel->rgb < 2) || currentPixel->rgb == priorPixel->rgb)
		{
			currentPixel->colorVisited = true;
			que.push(currentPixel);
		}
	}
}

void searchNormal(Pixel** pixels, int row, int col, int size)
{
	queue<Pixel*> que;
	que.push(&pixels[row][col]);
	pixels[row][col].normalVisited = true;

	while (!que.empty())
	{
		Pixel* px = que.front();
		que.pop();
		
		if(px->row + 1 < size)
			visitNormal(que, &pixels[px->row + 1][px->col], px);
		if (px->row - 1 >= 0)
			visitNormal(que, &pixels[px->row - 1][px->col], px);
		if (px->col + 1 < size)
			visitNormal(que, &pixels[px->row][px->col + 1], px);
		if (px->col - 1 >= 0)
			visitNormal(que, &pixels[px->row][px->col - 1], px);

	}
}

void searchColor(Pixel** pixels, int row, int col, int size)
{
	queue<Pixel*> que;
	que.push(&pixels[row][col]);
	pixels[row][col].colorVisited = true;

	while (!que.empty())
	{
		Pixel* px = que.front();
		que.pop();

		if (px->row + 1 < size)
			visitColor(que, &pixels[px->row + 1][px->col], px);
		if (px->row - 1 >= 0)
			visitColor(que, &pixels[px->row - 1][px->col], px);
		if (px->col + 1 < size)
			visitColor(que, &pixels[px->row][px->col + 1], px);
		if (px->col - 1 >= 0)
			visitColor(que, &pixels[px->row][px->col - 1], px);

	}
}

void searchAll(Pixel** pixels, int size, int& normalCount, int&colorCount)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (!pixels[i][j].normalVisited)
			{
				searchNormal(pixels, i, j, size);
				normalCount++;
			}
			if (!pixels[i][j].colorVisited)
			{
				searchColor(pixels, i, j, size);
				colorCount++;
			}
		}
	}
}

int main()
{
	int size, normalCount = 0, colorCount = 0;
	cin >> size;

	Pixel **pixels = new Pixel*[size];

	for (int i = 0; i < size; i++)
	{
		pixels[i] = new Pixel[size];
		for (int j = 0; j < size; j++)
		{
			char input;
			cin >> input;

			switch (input)
			{
				case 'R':
					pixels[i][j].rgb = 0;
					break;
				case 'G':
					pixels[i][j].rgb = 1;
					break;
				case 'B':
					pixels[i][j].rgb = 2;
					break;
			}
			pixels[i][j].row = i;
			pixels[i][j].col = j;

		}
	}

	searchAll(pixels, size, normalCount, colorCount);

	cout << normalCount << " " << colorCount << endl;


	return 0;
}