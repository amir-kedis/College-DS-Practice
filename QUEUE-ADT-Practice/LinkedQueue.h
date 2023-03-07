#pragma once
#include "QueueInterface.h"
template <class ItemType>
class LinkedQueue :
	public QueueInterface<ItemType>
{
private:

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
{
}

template<class ItemType>
inline LinkedQueue<ItemType>::~LinkedQueue()
{
}

template<class ItemType>
inline bool LinkedQueue<ItemType>::isEmpty() const
{
	return false;
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
	return std::vector<ItemType>();
}
