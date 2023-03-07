#pragma once
#include "QueueInterface.h"
#include "Node.h"
template <class ItemType>
class LinkedQueue :
	public QueueInterface<ItemType>
{
private:
	Node<ItemType>* front;
	Node<ItemType>* rear;
public:
	LinkedQueue();
	virtual ~LinkedQueue();
	virtual bool isEmpty() const;
	virtual bool enqueue(const ItemType& newEntry);
	virtual bool dequeue();
	virtual ItemType peekFront() const;
	virtual std::vector<ItemType> toVector() const;
};

template<class ItemType>
inline LinkedQueue<ItemType>::LinkedQueue()
	:front(nullptr), rear(nullptr)
{
}

template<class ItemType>
inline LinkedQueue<ItemType>::~LinkedQueue()
{
}

template<class ItemType>
inline bool LinkedQueue<ItemType>::isEmpty() const
{
	return (front == nullptr);
}

template<class ItemType>
inline bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	return false;
}

template<class ItemType>
inline bool LinkedQueue<ItemType>::dequeue()
{
	return false;
}

template<class ItemType>
inline ItemType LinkedQueue<ItemType>::peekFront() const
{
	return ItemType();
}

template<class ItemType>
inline std::vector<ItemType> LinkedQueue<ItemType>::toVector() const
{
	std::vector<ItemType> queueContents;

	if (isEmpty())
	{
		return queueContents;
	}

	Node<ItemType>* curPtr = front;
	while (curPtr)
	{
		queueContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
	}

	return queueContents;
}
