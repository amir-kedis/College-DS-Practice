#pragma once
#include "PriorityQueueInterface.h"
template <class ItemType>
class PriorityQueue :
	public PriorityQueueInterface<ItemType>
{

public:
	PriorityQueue();
	PriorityQueue(const PriorityQueue& pQueue);
	bool IsEmpty() const;
	int GetSize() const;
	bool Enqueue(const ItemType& anEntry);
	bool Dequeue();
	ItemType PeekFront() const;
	virtual ~PriorityQueue();
};

template<class ItemType>
inline PriorityQueue<ItemType>::PriorityQueue()
{
}

template<class ItemType>
inline PriorityQueue<ItemType>::PriorityQueue(const PriorityQueue& pQueue)
{
}

template<class ItemType>
inline bool PriorityQueue<ItemType>::IsEmpty() const
{
	return false;
}

template<class ItemType>
inline int PriorityQueue<ItemType>::GetSize() const
{
	return 0;
}

template<class ItemType>
inline bool PriorityQueue<ItemType>::Enqueue(const ItemType& anEntry)
{
	return false;
}

template<class ItemType>
inline bool PriorityQueue<ItemType>::Dequeue()
{
	return false;
}

template<class ItemType>
inline ItemType PriorityQueue<ItemType>::PeekFront() const
{
	return ItemType();
}

template<class ItemType>
inline PriorityQueue<ItemType>::~PriorityQueue()
{
}
