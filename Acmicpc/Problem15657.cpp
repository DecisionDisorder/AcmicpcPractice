#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inputList;

void NMSequence(int n, int m, vector<int>& vec)
{
	if (vec.size() == m)
	{
		for (int i = 0; i < vec.size(); i++)
			cout << inputList[vec[i]] << " ";
		cout << "\n";
	}
	else
	{
		for (int i = vec.back(); i < n; i++)
		{
			vec.push_back(i);
			NMSequence(n, m, vec);
			vec.pop_back();
		}
	}
}

void NMSequence(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		vector<int> nmVector;
		nmVector.push_back(i);
		NMSequence(n, m, nmVector);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	inputList.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> inputList[i];
	}
	sort(inputList.begin(), inputList.end());

	NMSequence(n, m);

	return 0;
}