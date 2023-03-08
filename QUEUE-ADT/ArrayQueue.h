/** ADT queue: Circular array-based implementation. */

#pragma once
#include "QueueInterface.h"

const int MAX_QUEUE = 50;

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType>
{
private:
	ItemType items[MAX_QUEUE];    // Array of queue items
	int front;                    // Index to front of queue
	int back;					  // Index to back of queue
	int count;					  // Number of items currently in the queue
public:
	ArrayQueue();
	// Copy constructor and destructor supplied by compiler
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const;
	std::vector<ItemType> toVector() const;
};

template<class ItemType>
inline ArrayQueue<ItemType>::ArrayQueue()
	: front(0), back(MAX_QUEUE - 1), count(0)
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
	bool result = false;

	if (count < MAX_QUEUE)
	{	
		// if back exceeds max size and the array is not full,
		// it will return to the beginning of the array to insert (circular array implementation)
		back = (back + 1) % MAX_QUEUE;      
		items[back] = newEntry;
		count++;
		result = true;
	}

	return result;
}

template<class ItemType>
inline bool ArrayQueue<ItemType>::dequeue()
{
	bool result = false;

	if (!isEmpty())
	{
		// the same as with back when enqueuing (circular array implementation)
		front = (front + 1) % MAX_QUEUE;
		count--;
		result = true;
	}

	return result;
}

template<class ItemType>
inline ItemType ArrayQueue<ItemType>::peekFront() const
{
	return items[front];	// didn't check for empty because it's in the specification as a @pre
}

template<class ItemType>
inline std::vector<ItemType> ArrayQueue<ItemType>::toVector() const
{
	std::vector<ItemType> queueContents;

	if (isEmpty())
		return queueContents;

	int curIndex = front;
	while (curIndex != back + 1)
	{
		queueContents.push_back(items[curIndex]);
		curIndex = (curIndex + 1) % MAX_QUEUE;
	}

	return queueContents;
}