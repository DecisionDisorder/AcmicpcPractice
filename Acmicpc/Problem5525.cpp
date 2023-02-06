#include <iostream>
#include <string>
using namespace std;


int countIOI(char* str, int len, int n)
{
	int ioiLength = 2 * n  + 1;
	int count = 0;
	bool priorPassed = false;

	for (int i = 0; i < len; i++)
	{
		if(str[i] == 'O')
			continue;

		int k = 0;
		while (str[i + 1] == 'O' && str[i + 2] == 'I')
		{
			k++;
			i += 2;
			if (k == n)
			{
				k--;
				count++;
			}
		}
	}

	return count;
}

int main()
{
	int n, m;
	char *s;
	scanf("%d", &n);
	scanf("%d", &m);
	s = new char[m + 1];
	scanf("%s", s);

	printf("%d\n", countIOI(s, m, n));
	
	return 0;
}