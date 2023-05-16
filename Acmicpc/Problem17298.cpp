#include <iostream>
#include <stack>

using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	stack<int> input_stack;
	stack<int> output_stack;
	stack<int> compare_stack;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		
		input_stack.push(input);
	}
	
	output_stack.push(-1);
	compare_stack.push(input_stack.top());
	input_stack.pop();
	while (!input_stack.empty())
	{
		int input = input_stack.top();
		input_stack.pop();
		
		while (!compare_stack.empty() && compare_stack.top() <= input)
		{
			compare_stack.pop();
		}

		if (compare_stack.empty())
			output_stack.push(-1);
		else
			output_stack.push(compare_stack.top());
		compare_stack.push(input);
	}

	while (!output_stack.empty())
	{
		cout << output_stack.top() << " ";
		output_stack.pop();
	}

	cout << "\n";

	return 0;
}