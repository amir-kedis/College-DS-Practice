#pragma once
#include "QueueInterface.h"
template <class ItemType>
class ArrayQueue :
	public QueueInterface<ItemType>
{
private:

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
{
}

template<class ItemType>
inline bool ArrayQueue<ItemType>::isEmpty() const
{
	return false;
}

template<class ItemType>
inline bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	return false;
}

template<class ItemType>
inline bool ArrayQueue<ItemType>::dequeue()
{
	return false;
}

template<class ItemType>
inline ItemType ArrayQueue<ItemType>::peekFront() const
{
	return ItemType();
}

template<class ItemType>
inline std::vector<ItemType> ArrayQueue<ItemType>::toVector() const
{
	return std::vector<ItemType>();
}
