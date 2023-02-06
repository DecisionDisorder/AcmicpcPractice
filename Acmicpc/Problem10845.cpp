#include <iostream>
#include <queue> 
#include <string>

using namespace std;

string commands[] { "push", "pop", "size", "empty", "front", "back" };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> que;
	int n;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		string command;
		int input;
		cin >> command;
		if(command == commands[0])
			cin >> input;
		
		if (command == commands[0])
			que.push(input);
		else if (command == commands[1])
		{
			if (que.empty())
			{
				cout << -1 << endl;
				continue;
			}
			int res = que.front();
			que.pop();
			cout << res << endl;
		}
		else if (command == commands[2])
			cout << que.size() << endl;
		else if (command == commands[3])
			cout << que.empty() << endl;
		else if (command == commands[4])
		{
			if (que.empty() == 0)
				cout << que.front() << endl;
			else
				cout << -1 << endl;
		}
			
		else
		{
			if (que.empty() == 0)
				cout << que.back() << endl;
			else
				cout << -1 << endl;
		}			
	}
		

	return 0;
}