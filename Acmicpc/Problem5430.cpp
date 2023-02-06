#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>

using namespace std;

class List {
public:
	int getLength() { return length; }

	List(vector<string> inputList, int len) 
	{
		length = len;

		for (int i = 0; i < len; i++)
		{
			list.push_back(stoi(inputList[i]));
		}
		start = 0;
		end = len - 1;
	}

	void Reverse()
	{
		reversed = !reversed;
	}

	bool Delete()
	{
		if (length > 0)
		{
			if(reversed)
				list.pop_back();
			else
				list.pop_front();
			length--;

			return true;
		}
		else 
			return false;
	}

	string* ToString()
	{
		string* res = new string("[");
		while (!list.empty())
		{
			if (!reversed) 
			{
				(*res) += to_string(list.front());
				list.pop_front();
			}	
			else 
			{
				(*res) += to_string(list.back());
				list.pop_back();
			}
			if(!list.empty())
				(*res) += ",";
		}
		(*res) += "]";
		return res;
	}

private:
	int length;
	deque<int> list;
	int start;
	int end;
	bool reversed = false;
};

vector<string> split(string str, char delimiter)
{
	vector<string> answer;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter))
	{
		answer.push_back(temp);
	}

	return answer;
}

int main()
{
	int testCase;
	scanf("%d", &testCase);

	for (int t = 0; t < testCase; t++)
	{
		bool result = true;
		string command;
		string listStr;
		int len;

		cin >> command;
		const char * cmd = command.c_str();

		scanf("%d", &len);
		cin.ignore();
		getline(cin, listStr);
		listStr = listStr.substr(1, listStr.length() - 2);
		vector<string> splitedList = split(listStr, ',');

		List *acList = new List(splitedList, len);

		for (int i = 0; i < command.length(); i++)
		{
			if (cmd[i] == 'R')
				acList->Reverse();
			else if (cmd[i] == 'D')
			{
				if (!acList->Delete())
				{
					result = false;
					break;
				}
			}
		}

		if(!result)
			cout << "error" << endl;
		else
			printf("%s\n", acList->ToString()->c_str());

		delete acList;
	}

}