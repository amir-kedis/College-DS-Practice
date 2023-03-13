#pragma once
#include "PriorityQueueInterface.h"
#include "Node.h"
#include <vector>
template <class ItemType>
class PriorityQueue :
	public PriorityQueueInterface<ItemType>
{
private:
	Node<ItemType>* head;
	int queueCount;

	ItemType getNodeBefore(const ItemType& anEntry) const;
	ItemType getNodeAt(int position) const;
	Node<ItemType>* CopyChain(Node<ItemType>* originChainPtr);
public:
	PriorityQueue();
	PriorityQueue(const PriorityQueue& pQueue);
	bool IsEmpty() const;
	int GetSize() const;
	bool Enqueue(const ItemType& anEntry);
	bool Dequeue();
	ItemType PeekFront() const;
	std::vector<ItemType> toVector() const;
	virtual ~PriorityQueue();
};

template<class ItemType>
inline ItemType PriorityQueue<ItemType>::getNodeBefore(const ItemType& anEntry) const
{
	return ItemType();
}

template<class ItemType>
inline ItemType PriorityQueue<ItemType>::getNodeAt(int position) const
{
	return ItemType();
}

template<class ItemType>
inline Node<ItemType>* PriorityQueue<ItemType>::CopyChain(Node<ItemType>* originChainPtr)
{
	return nullptr;
}

template<class ItemType>
inline PriorityQueue<ItemType>::PriorityQueue()
	:queueCount(0), head(nullptr)
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
inline std::vector<ItemType> PriorityQueue<ItemType>::toVector() const
{
	return std::vector<ItemType>();
}

template<class ItemType>
inline PriorityQueue<ItemType>::~PriorityQueue()
{
}
