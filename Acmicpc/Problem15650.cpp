#include <iostream>
#include <vector>

using namespace std;

void NMSequence(int n, int m, vector<int>& vec)
{
	if (vec.size() == m)
	{
		for (int i = 0; i < vec.size(); i++)
			cout << vec[i] << " ";
		cout << endl;
	}
	else if (vec.back() == n && vec.size() < m)
		return;
	else
	{
		for (int i = vec.back() + 1; i <= n; i++)
		{
			vec.push_back(i); 
			NMSequence(n, m, vec);
			vec.pop_back();
		}
	}
}

void NMSequence(int n, int m)
{
	for (int i = 1; i <= n; i++)
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

	NMSequence(n, m);

	return 0;
}