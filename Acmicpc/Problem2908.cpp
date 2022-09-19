#include <iostream>
#include <string>

using namespace std;

string reverse(string);

int main()
{
	string inputA, inputB;
	
	cin >> inputA >> inputB;
	
	int resultA = stoi(reverse(inputA));
	int resultB = stoi(reverse(inputB));

	if (resultA > resultB)
		cout << resultA << endl;
	else
		cout << resultB << endl;

	return 0;
}

string reverse(string str)
{
	int len = str.length();
	string result;

	result.resize(len);

	for (int i = 0; i < len; i++) 
	{
		result[i] = str[len - i - 1];
	}

	return result;
}