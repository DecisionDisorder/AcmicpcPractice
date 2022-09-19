#include <iostream>

using namespace std;

char* Add(const char*, const char*);

int main() 
{
	char *A;
	char *B;

	A = new char[10000];
	B = new char[10000];

	cin >> A >> B;

	cout << Add(A, B) << endl;

	delete[] A;
	delete[] B;

	return 0;
}

int GetLength(const char* str) 
{
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}

char* Add(const char *A, const char* B)
{
	char* result;
	int lenA = GetLength(A);
	int lenB = GetLength(B);
	int mainLen = (lenA > lenB ? lenA : lenB) + 1;

	result = new char[mainLen + 1];

	result[0] = 9;
	for (int i = 1; i < mainLen; i++)
		result[i] = '0';
	result[mainLen] = '\0';

	for (int a = lenA - 1, b = lenB - 1, r = mainLen - 1; a >= 0 || b >= 0; r--)
	{
		char tempA = A[a] - '0';
		char tempB = B[b] - '0';
		char tempR = result[r] - '0';

		if (a < 0) tempA = 0;
		if (b < 0) tempB = 0;

		if (tempA + tempB + tempR < 10)
			result[r] += tempA + tempB;
		else
		{
			result[r] = (tempA + tempB + tempR) % 10 + '0';
			if (r == 1)
				result[0] = '0';
			result[r - 1]++;
		}

		if (a >= 0) a--;
		if (b >= 0) b--;


	}

	if (result[0] == 9)
		return &(result[1]);
	else
		return result;
}