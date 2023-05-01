#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inputList;
bool selected[8];

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
		for (int i = 0; i < n; i++)
		{
			if (selected[i])
				continue;

			selected[i] = true;
			vec.push_back(i);
			NMSequence(n, m, vec);
			vec.pop_back();
			selected[i] = false;

		}
	}
}

void NMSequence(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		vector<int> nmVector;
		nmVector.push_back(i);
		selected[i] = true;
		NMSequence(n, m, nmVector);
		selected[i] = false;
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