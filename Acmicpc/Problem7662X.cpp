#include <iostream>
#include <queue>

using namespace std;

class PriorityQueue
{
public:
	queue<int> pque;
	int max;

	void Insert(int num)
	{
		pque.push(num);
	}

	void Delete(int type)
	{
		if (type == 1)
		{
			
		}
		else
		{

		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;
	
	for (int test = 0; test < n; test++)
	{
		int k;
		cin >> k;


		for (int i = 0; i < k; i++)
		{
			char cmd;
			int input;
			cin >> cmd >> input;
		}
	}

	return 0;
}