#include <iostream>
#include <queue>

using namespace std;

class Document {
public:
	int priority;
	int index;

	Document(int priority, int index)
	{
		this->priority = priority;
		this->index = index;
	}
};

int getMaxPriority(queue<Document*> docueue)
{
	int max = 0;
	for (int i = 0; i < docueue.size(); i++) {
		Document* document = docueue.front();
		if (max < document->priority)
			max = document->priority;

		docueue.pop();
		docueue.push(document);
	}

	return max;
}

bool repeatCheck(queue<Document*> docueue, int M, int maxPriority)
{
	Document* document = docueue.front();
	return document->index == M && maxPriority == document->priority;
}

int getSequence(queue<Document*> docueue, int M)
{
	int sequence = 0, maxPriority = getMaxPriority(docueue);
	while (!repeatCheck(docueue, M, maxPriority))
	{
		Document* temp = docueue.front();
		docueue.pop();
		if (maxPriority > temp->priority)
			docueue.push(temp);
		else {
			maxPriority = getMaxPriority(docueue);
			sequence++;
		}
	}
	return sequence + 1;
}

int main()
{
	queue<Document*> docueue;
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int N, M;
		cin >> N >> M;

		for (int j = 0; j < N; j++) {
			int priority;
			cin >> priority;

			docueue.push(new Document(priority, j));
		}

		cout << getSequence(docueue, M) << endl;
		docueue = queue<Document*>();
	}

	return 0;
}