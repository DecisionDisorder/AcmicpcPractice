#include <iostream>
#include <cmath>
using namespace std;

struct Point {
	long long x, y;
};

Point points[10000];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long area = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		points[i] = { x, y };
	}

	for (int i = 0; i < n; i++)
	{
		if (i < n - 1)
			area += points[i].x * points[i + 1].y - points[i].y * points[i + 1].x;
		else
			area += points[i].x * points[0].y - points[i].y * points[0].x;
	}

	area = abs(area);
	
	cout << area / 2 << "." << (area % 2 ? "5" : "0") << endl;

	return 0;
}