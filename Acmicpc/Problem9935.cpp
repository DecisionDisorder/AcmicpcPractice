#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string orignal_str, explosion_str, temp_str = "";
	int explosion_len;
	bool all_passed = false;

	cin >> orignal_str;
	cin >> explosion_str;
	explosion_len = explosion_str.size();

	for (int i = 0; i < orignal_str.size(); i++)
	{
		temp_str += orignal_str[i];
		int temp_size = temp_str.size();
		if (temp_size >= explosion_len)
		{
			string sub = temp_str.substr(temp_size - explosion_len, explosion_len);
			if (explosion_str.compare(sub) == 0)
			{
				string::iterator begin = temp_str.begin() + temp_size - explosion_len;
				temp_str.erase(begin, begin + explosion_len);
			}
		}
	}

	if (temp_str.size() > 0)
	{
		cout << temp_str << endl;
	}
	else
		cout << "FRULA" << endl;


	return 0;
}