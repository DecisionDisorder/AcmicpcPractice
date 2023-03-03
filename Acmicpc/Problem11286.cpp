#include <iostream>
#include <cstdlib>

using namespace std;

class AbsHeap
{
private:
	int* heap;
	int size;
	int tail;

	void Swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	void GetChildIndex(int index, int& left, int& right)
	{
		left = index * 2 + 1;
		right = index * 2 + 2;
	}

	int GetParentIndex(int index)
	{
		return (index - 1) / 2;
	}

	int GetSelectedChildIndex(int value, int left, int right)
	{
		int absVal = abs(value);
		int absLeft = abs(heap[left]);
		int absRight = abs(heap[right]);
		if (left < tail && right < tail)
		{
			if (absLeft < absVal && absRight < absVal)
			{
				if (absLeft == absRight)
				{
					if(heap[left] < heap[right])
						return left;
					else
						return right;
				}
				else if (absLeft < absRight)
					return left;
				else
					return right;
			}
			else if (absLeft < absVal)
				return left;
			else if (absRight < absVal)
				return right;
			else if (absLeft == absVal)
				return heap[left] < value ? left : -1;
			else if (absRight == absVal)
				return heap[right] < value ? right : -1;
			else
				return -1;
		}
		else if (left < tail)
		{
			if(absVal == absLeft && value > heap[left])
				return left;
			if (absVal > absLeft)
				return left;
			else
				return -1;
		}
		else
		{
			return -1;
		}
	}

public:
	AbsHeap(int size)
	{
		this->size = size;
		heap = new int[size];
		tail = 0;
	}

	void Push(int num)
	{
		int currentIndex = tail;
		int parentIndex = GetParentIndex(currentIndex);
		heap[currentIndex] = num;
		tail++;

		while (true)
		{
			int absVal = abs(heap[currentIndex]);
			int absParent = abs(heap[parentIndex]);
			if(absVal > absParent)
				break;
			if(absVal == absParent && heap[currentIndex] >= heap[parentIndex])
				break;

			Swap(heap[currentIndex], heap[parentIndex]);
			currentIndex = parentIndex;
			parentIndex = GetParentIndex(currentIndex);
		}
	}

	int Pop()
	{
		if (tail > 0)
		{
			int currentIndex = 0;
			int returnValue = heap[currentIndex];
			heap[currentIndex] = heap[--tail];
			int left = 0, right = 0;
			GetChildIndex(currentIndex, left, right);
			int childIndex = GetSelectedChildIndex(heap[currentIndex], left, right);
			
			while (childIndex >= 0)
			{
				Swap(heap[currentIndex], heap[childIndex]);
				currentIndex = childIndex;
				GetChildIndex(currentIndex, left, right);
				childIndex = GetSelectedChildIndex(heap[currentIndex], left, right);
			}

			return returnValue;
		}
		else
			return 0;
	}

	void Print()
	{
		cout << "==========[Print]===========" << endl;
		cout << heap[0] << endl;
		for (int i = 1; i < tail; i+=2)
		{
			if(i + 1 < tail)
				cout << heap[i] << ", " << heap[i + 1] << "|";
			else
				cout << heap[i] << endl;
		}
		cout << endl << "=============================" << endl;
	}
};

int main()
{
	int n;

	scanf("%d", &n);
	
	AbsHeap heap(n);

	for (int i = 0; i < n; i++)
	{
		int input;
		scanf("%d", &input);

		if (input == 0)
		{
			printf("%d\n", heap.Pop());
		}
		else
		{
			heap.Push(input);
		}
	}
	
	return 0;
}