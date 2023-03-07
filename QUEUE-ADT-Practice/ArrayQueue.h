#pragma once
#include "QueueInterface.h"

const int QUEUE_SIZE = 50;

template <class ItemType>
class ArrayQueue :
	public QueueInterface<ItemType>
{
	/// QUEUE Implementation using circular array
	/// I recommend you try to make it before 
private:
	ItemType items[QUEUE_SIZE];
	int front;
	int rear;
	int count;
public:
	ArrayQueue();
	virtual bool isEmpty() const;
	virtual bool enqueue(const ItemType& newEntry);
	virtual bool dequeue();
	virtual ItemType peekFront() const;
	virtual std::vector<ItemType> toVector() const;
};

template<class ItemType>
inline ArrayQueue<ItemType>::ArrayQueue()
	:front(-1), rear(-1), count(0)
{
}

template<class ItemType>
inline bool ArrayQueue<ItemType>::isEmpty() const
{
	return count == 0;
}

template<class ItemType>
inline bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	if (count >= QUEUE_SIZE)
	{
		return false;
	}

	if (count == 0)
	{
		front = (front + 1) % QUEUE_SIZE;
	}

	rear = (rear + 1) % QUEUE_SIZE; // move the back index clockwise 
	items[rear] = newEntry;			// put item in new position
	count++;						// increase the count

	return true;
}

template<class ItemType>
inline bool ArrayQueue<ItemType>::dequeue()
{
	if (isEmpty())
	{
		return false;
	}

	front = (front + 1) % QUEUE_SIZE; // move the front index clockwise (freeing its place)
	count--;

	return true;
}

template<class ItemType>
inline ItemType ArrayQueue<ItemType>::peekFront() const
{
	return items[front];
}

template<class ItemType>
inline std::vector<ItemType> ArrayQueue<ItemType>::toVector() const
{
	std::vector<ItemType> queueItems;
	int index;
	for (int i = 0; i < count; i++)
	{
		index = (front + i) % QUEUE_SIZE;
		queueItems.push_back(items[index]);
	}

	return queueItems;
}
