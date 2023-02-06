#include <iostream>

using namespace std;

class Point {
private:
	int x;
	int y;

public:
	Point() {}

	Point(int x, int y) 
	{
		this->x = x;
		this->y = y;
	}

	int getX() 
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	void setPosition(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int compare(Point otherPoint) {
		if (x > otherPoint.x)
			return 1;
		else if (x < otherPoint.x)
			return -1;
		else
		{
			if (y > otherPoint.y)
				return 1;
			else if (y < otherPoint.y)
				return -1;
			else
				return 0;
		}
	}
};

Point* sorted;

void swap(Point* left, Point* right) {
	Point temp = *left;
	*left = *right;
	*right = temp;
}


void merge(Point* arr, int left, int mid, int right)
{
	int s = left, i = left, j = mid + 1;
	while (i <= mid || j <= right)
	{
		if (i <= mid && j <= right)
		{
			if (arr[i].compare(arr[j]) < 0)
				sorted[s++] = arr[i++];
			else
				sorted[s++] = arr[j++];
		}
		else if (i <= mid)
			sorted[s++] = arr[i++];
		else if (j <= right)
			sorted[s++] = arr[j++];
	}

	for (int l = left; l <= right; l++)
		arr[l] = sorted[l];
}

void partition(Point* arr, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		partition(arr, left, mid);
		partition(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}

}

void sort(Point* arr, int n)
{
	sorted = new Point[n];
	partition(arr, 0, n - 1);
}

int main() 
{
	int n, priorX = -1, xLeft = -1, xRight = -1;
	scanf("%d", &n);

	Point *pointArr = new Point[n];

	for(int i = 0; i < n; i++)  
	{
		int x, y;
		scanf("%d %d", &x, &y);

		pointArr[i].setPosition(x, y);
	}

	sort(pointArr, n);
	

	for (int i = 0; i < n; i++)
		printf("%d %d\n", pointArr[i].getX(), pointArr[i].getY());

	return 0;
}