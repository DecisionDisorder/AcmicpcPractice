#include <iostream>
#include <string>

using namespace std;

int checkCrotiaAlphabet(string);

int main() 
{
	string input;
	cin >> input;

	cout << checkCrotiaAlphabet(input) << endl;

	return 0;
}

string eraseSpace(string str) 
{
	while (1)
	{
		size_t nPos = str.find(" ");
		if (nPos != string::npos)
			str = str.replace(nPos, 1, "");
		else
			break;
	}

	return str;
}

int checkCrotiaAlphabet(string targetStr)
{
	int alphabetAmount = 8;
	string croatia[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	int count = 0;

	for (int i = 0; i < alphabetAmount; i++)
	{
		while (1) 
		{
			size_t nPos = targetStr.find(croatia[i]);
			if (nPos != string::npos) {
				targetStr = targetStr.replace(nPos, croatia[i].length(), " ");
				count++;
			}
			else
				break;
		}
	}

	targetStr = eraseSpace(targetStr);

	count += targetStr.length();

	return count;
}