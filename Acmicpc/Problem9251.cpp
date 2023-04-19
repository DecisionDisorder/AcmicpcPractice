#include <iostream>
#include <string>
#include <algorithm>
#define MAX_STRING 1001

using namespace std;

int dp[MAX_STRING][MAX_STRING];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string a, b;

	cin >> a;
	cin >> b;
	
	for (int i = 1; i <= b.size(); i++)
	{
		for (int j = 1; j <= a.size(); j++)
		{
			if (b[i - 1] == a[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}


	cout << dp[b.size()][a.size()] << endl;

	return 0;
}