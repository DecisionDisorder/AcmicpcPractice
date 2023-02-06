#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

bool checkDigit(string str)
{
	for (int i = 0; i < str.size(); i++)
		if (!isdigit(str[i]))
			return false;
	return true;
}

void split(string sourceStr, vector<int>& destNumbers, vector<char>& destMark)
{
	istringstream iss(sourceStr);
	string buffer;

	char delimiterPos = '+';

	while (getline(iss, buffer, delimiterPos))
	{
		if (checkDigit(buffer))
		{
			destNumbers.push_back(stoi(buffer));
		}
		else
		{
			istringstream issNeg(buffer);
			string bufferNeg;
			char delimiterNeg = '-';
			while (getline(issNeg, bufferNeg, delimiterNeg))
			{
				destNumbers.push_back(stoi(bufferNeg));
			}
		}
	}

	string marks = regex_replace(sourceStr, regex("[0-9]+"), "");
	copy(marks.begin(), marks.end(), back_inserter(destMark));
}

int main()
{
	string input;
	vector<int> numbers;
	vector<char> marks;
	int sumPos, sumNeg = 0;
	bool markedNegative = false;

	cin >> input;

	split(input, numbers, marks);

	sumPos = numbers[0];
	for (int i = 1, m = 0; i < numbers.size(); i++, m++)
	{
		if (marks[m] == '+')
		{
			if (!markedNegative)
				sumPos += numbers[i];
			else
				sumNeg += numbers[i];
		}
		else
		{
			markedNegative = true;
			sumNeg += numbers[i];
		}
	}

	cout << sumPos - sumNeg << endl;

	return 0;
}