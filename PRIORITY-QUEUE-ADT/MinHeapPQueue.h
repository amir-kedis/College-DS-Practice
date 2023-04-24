#pragma once
#include <type_traits>
#include <iostream>

template<class ItemType>
class MinHeapPriorityQueue : public PriorityQueueInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 100;
	ItemType* items;
	int itemCount;
	int maxItems;
	int left(const int nodeIndex) const;
	int right(int nodeIndex) const;
	int parent(int nodeIndex) const;
	bool isLower(const ItemType& a, const ItemType& b) const;
	void minHeapify(int nodeIndex);
	void buildHeap();
public:
	MinHeapPriorityQueue();
	MinHeapPriorityQueue(const ItemType someArray[], const int arraySize);
	MinHeapPriorityQueue(const MinHeapPriorityQueue& H);
	bool IsEmpty() const;
	ItemType PeekFront() const;
	bool Enqueue(const ItemType& newData);
	bool Dequeue();
	bool Dequeue(ItemType& min);
	int GetSize() const;
	void clear();
	std::string ToString(); // for UI and debugging
	std::vector<ItemType> toVector() const;
	virtual ~MinHeapPriorityQueue();
};

template<class ItemType>
MinHeapPriorityQueue<ItemType>::MinHeapPriorityQueue() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
	items = new ItemType[DEFAULT_CAPACITY];
}

template<class ItemType>
MinHeapPriorityQueue<ItemType>::MinHeapPriorityQueue(const ItemType someArray[], const int arraySize)
{
	itemCount = arraySize;
	maxItems = max(arraySize, DEFAULT_CAPACITY);
	items = new ItemType[arraySize];

	for (int i = 0; i < arraySize; i++)
		items[i] = someArray[i];

	buildHeap();
}

template<class ItemType>
MinHeapPriorityQueue<ItemType>::MinHeapPriorityQueue(const MinHeapPriorityQueue& H)
{
	itemCount = H.itemCount;
	maxItems = H.maxItems;
	items = new ItemType[itemCount];

	for (int i = 0; i < itemCount; i++)
		items[i] = H.items[i];
}

template<class ItemType>
MinHeapPriorityQueue<ItemType>::~MinHeapPriorityQueue()
{
	itemCount = 0;
	maxItems = DEFAULT_CAPACITY;
	delete[] items;
}

template<class ItemType>
int MinHeapPriorityQueue<ItemType>::left(const int nodeIndex) const
{
	return (2 * nodeIndex) + 1;
}

template<class ItemType>
int MinHeapPriorityQueue<ItemType>::right(int nodeIndex) const
{
	return 2 * (nodeIndex + 1);
}

template<class ItemType>
int MinHeapPriorityQueue<ItemType>::parent(int nodeIndex) const
{
	return (nodeIndex - 1) / 2;
}

template<class ItemType>
bool MinHeapPriorityQueue<ItemType>::isLower(const ItemType& a, const ItemType& b) const
{
	return (a < b);
}

template<class ItemType>
void MinHeapPriorityQueue<ItemType>::minHeapify(int nodeIndex)
{
	int l = left(nodeIndex);
	int r = right(nodeIndex);
	int smallest = nodeIndex;

	if (l < itemCount && isLower(items[l], items[smallest]))
		smallest = l;
	if (r < itemCount && isLower(items[r], items[smallest]))
		smallest = r;
	if (smallest != nodeIndex)
	{
		std::swap(items[smallest], items[nodeIndex]);
		minHeapify(smallest);
	}
}

template<class ItemType>
void MinHeapPriorityQueue<ItemType>::buildHeap()
{
	for (int i = itemCount / 2; i >= 0; i--)
		minHeapify(i);
}

template<class ItemType>
bool MinHeapPriorityQueue<ItemType>::IsEmpty() const
{
	return (itemCount == 0);
}

template<class ItemType>
ItemType MinHeapPriorityQueue<ItemType>::PeekFront() const
{
	return items[0];
}

template<class ItemType>
bool MinHeapPriorityQueue<ItemType>::Enqueue(const ItemType& newData)
{
	if (itemCount == maxItems)
	{
		ItemType* temp = new ItemType[2 * maxItems];
		if (temp == nullptr)
			return false;

		for (int i = 0; i < itemCount; i++) {
			temp[i] = items[i];
		}

		delete[] items;
		maxItems *= 2;
		items = temp;
	}

	int i = itemCount;
	items[itemCount++] = newData;
	while (i > 0)
	{
		int p = parent(i);
		if (!isLower(items[i], items[p]))
			break;

		std::swap(items[i], items[p]);
		i = parent(i);
	}
	return true;
}

template<class ItemType>
bool MinHeapPriorityQueue<ItemType>::Dequeue()
{
	if (IsEmpty())
		return false;

	items[0] = items[--itemCount];
	minHeapify(0);
	return true;
}

template<class ItemType>
bool MinHeapPriorityQueue<ItemType>::Dequeue(ItemType& min)
{
	if (IsEmpty())
		return false;

	min = items[0];
	items[0] = items[--itemCount];
	minHeapify(0);
	return true;
}

template<class ItemType>
inline int MinHeapPriorityQueue<ItemType>::GetSize() const
{
	return itemCount;
}

template<class ItemType>
void MinHeapPriorityQueue<ItemType>::clear()
{
	itemCount = 0;
	maxItems = DEFAULT_CAPACITY;
	delete[] items;
	items = new ItemType[DEFAULT_CAPACITY];
}

template<class ItemType>
inline std::string MinHeapPriorityQueue<ItemType>::ToString()
{
	std::string str = "";
	for (int i = 0; i < itemCount; i++)
	{
		str += items[i]->ToString();
		if (i != itemCount - 1)
		{
			str += ", ";
		}
	}

	if (itemCount == 0)
	{
		str += "Empty List";
	}
	return str;
}

template<class ItemType>
inline std::vector<ItemType> MinHeapPriorityQueue<ItemType>::toVector() const
{
	std::vector<ItemType> vec;

	for (int i = 0; i < itemCount; i++)
	{
		vec.push_back(items[i]);
	}

	return vec;
}
