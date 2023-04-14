#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string formula;
	cin >> formula;

	stack<char> stack;

	for (int i = 0; i < formula.size(); i++)
	{
		if ('A' <= formula[i] && formula[i] <= 'Z')
			cout << formula[i];
		else if (formula[i] == '(')
			stack.push(formula[i]);
		else if (formula[i] == ')')
		{
			while (!stack.empty() && stack.top() != '(')
			{
				cout << stack.top();
				stack.pop();
			}
			stack.pop();
		}
		else if (formula[i] == '*' || formula[i] == '/')
		{
			while (!stack.empty() && (stack.top() == '*' || stack.top() == '/'))
			{
				cout << stack.top();
				stack.pop();
			}
			stack.push(formula[i]);
		}
		else if(formula[i] == '+' || formula[i] == '-')
		{
			while (!stack.empty() && (stack.top() != '('))
			{
				cout << stack.top();
				stack.pop();
			}
			stack.push(formula[i]);
		}
	}

	while (!stack.empty())
	{
		cout << stack.top();
		stack.pop();
	}
	return 0;
}