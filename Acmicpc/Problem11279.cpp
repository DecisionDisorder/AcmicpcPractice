#include <iostream>

using namespace std;

class MaxHeap {
private:
	int* heap;
	int size;
	int bottom;

private:
	int GetParentIndex(int index)
	{
		return (index - 1) / 2;
	}
	int GetLeftChildIndex(int index)
	{
		return index * 2 + 1;
	}
	int GetRightChildIndex(int index)
	{
		return index * 2 + 2;
	}

	void Swap(int* a, int* b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}

	int GetTargetChildIndex(int left, int right, int val)
	{
		if (left < bottom && right < bottom)
		{
			if (heap[left] > val && heap[right] > val)
			{
				return heap[left] > heap[right] ? left : right;
			}
			else if (heap[left] > val)
			{
				return left;
			}
			else if (heap[right] > val)
			{
				return right;
			}
			else
			{
				return -1;
			}
		}
		else if (left < bottom)
		{
			if(heap[left] > val)
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
	MaxHeap(int size)
	{
		heap = new int[size];
		this->size = size;

		bottom = 0;
	}

	void Push(int val)
	{
		heap[bottom] = val;
		int parentIndex = GetParentIndex(bottom);
		int index = bottom;
		while (heap[parentIndex] < val)
		{
			Swap(heap + parentIndex, heap + index);
			index = parentIndex;
			parentIndex = GetParentIndex(parentIndex);
		}
		bottom++;
	}

	int Pop()
	{
		if (bottom > 0)
		{
			int index = 0;
			int returnValue = heap[index];
			heap[index] = heap[--bottom];
			int left = GetLeftChildIndex(0);
			int right = GetRightChildIndex(0);
			int targetChild = GetTargetChildIndex(left, right, heap[index]);

			while (targetChild >= 0)
			{
				Swap(heap + index, heap + targetChild);
				index = targetChild;
				left = GetLeftChildIndex(index);
				right = GetRightChildIndex(index);
				targetChild = GetTargetChildIndex(left, right, heap[index]);
			}

			return returnValue;
		}
		else
			return 0;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	scanf("%d", &n);

	MaxHeap heap(n);
	
	for (int i = 0; i < n; i++)
	{
		int input;
		scanf("%d", &input);
		if (input > 0)
		{
			heap.Push(input);
		}
		else
		{
			printf("%d\n", heap.Pop());
		}
		
	}

	return 0;
}