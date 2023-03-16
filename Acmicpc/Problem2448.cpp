#include <iostream>

using namespace std;

void star(int num)
{
	if (num > 1)
		star(num - 1);

	for (int i = 1; i < num; i++)
		printf(" ");

}

int main()
{
	int n;
	scanf("%d", &n);

	star(n);

	return 0;
}