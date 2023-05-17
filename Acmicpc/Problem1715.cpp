#include <iostream>
#include <queue>

using namespace std;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	int sum = 0;
	priority_queue<int, vector<int>, greater<int>> cards;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		cards.push(c);
	}

	if (n > 1)
	{
		while (!cards.empty())
		{
			int cardAmount1 = cards.top();
			cards.pop();

			int cardAmount2 = cards.top();
			cards.pop();

			sum += cardAmount1 + cardAmount2;

			if (!cards.empty())
				cards.push(cardAmount1 + cardAmount2);
		}
	}

	cout << sum << endl;

	return 0;
}