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

	Node<ItemType>* getNodeBefore(const ItemType& anEntry) const;
	Node<ItemType>* getNodeAt(int position) const;
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
inline Node<ItemType>* PriorityQueue<ItemType>::getNodeBefore(const ItemType& anEntry) const
{
	Node<ItemType>* curPtr = head;
	Node<ItemType>* prevPtr = nullptr;

	while (curPtr && (anEntry > curPtr->getItem()))
	{
		prevPtr = curPtr;
		curPtr = curPtr->getNext();
	}
	return prevPtr;
}

template<class ItemType>
inline Node<ItemType>* PriorityQueue<ItemType>::getNodeAt(int position) const
{
	Node<ItemType>* curPtr = head;

	for (int skip = 1; skip < position; skip++)
		curPtr = curPtr->GetNext();

	return curPtr;
}

template<class ItemType>
inline Node<ItemType>* PriorityQueue<ItemType>::CopyChain(Node<ItemType>* originChainPtr)
{
	Node<ItemType>* copiedChainPtr;
	if (originChainPtr)
	{
		copiedChainPtr = new Node<ItemType>(originChainPtr->getItem());
		copiedChainPtr->setNext(CopyChain(originChainPtr->setNext()));
	}
	return copiedChainPtr;
}

template<class ItemType>
inline PriorityQueue<ItemType>::PriorityQueue()
	:queueCount(0), head(nullptr)
{
}

template<class ItemType>
inline PriorityQueue<ItemType>::PriorityQueue(const PriorityQueue& pQueue)
{
	head = CopyChain(pQueue);
	queueCount = pQueue.queueCount;
}

template<class ItemType>
inline bool PriorityQueue<ItemType>::IsEmpty() const
{
	return queueCount == 0;
}

template<class ItemType>
inline int PriorityQueue<ItemType>::GetSize() const
{
	return queueCount;
}

template<class ItemType>
inline bool PriorityQueue<ItemType>::Enqueue(const ItemType& anEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(anEntry);
	Node<ItemType>* prevPtr = getNodeBefore(anEntry);

	if (IsEmpty() || prevPtr == nullptr)
	{
		newNodePtr->setNext(head);
		head = newNodePtr;
	}
	else {
		Node<ItemType>* afterPtr = prevPtr->getNext();
		newNodePtr->setNext(afterPtr);
		prevPtr->setNext(newNodePtr);
	}

	queueCount++;
	return true;
}

template<class ItemType>
inline bool PriorityQueue<ItemType>::Dequeue()
{
	if (IsEmpty())
	{
		return false;
	}

	Node<ItemType>* temp = head;
	head = head->getNext();
	delete temp;

	queueCount--;
	return true;
}

template<class ItemType>
inline ItemType PriorityQueue<ItemType>::PeekFront() const
{
	return head->getItem();
}

template<class ItemType>
inline std::vector<ItemType> PriorityQueue<ItemType>::toVector() const
{
	std::vector<ItemType> queueContents;

	if (IsEmpty())
		return queueContents;

	Node<ItemType>* curPtr = head;
	while (curPtr != nullptr)
	{
		queueContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
	}

	return queueContents;
}

template<class ItemType>
inline PriorityQueue<ItemType>::~PriorityQueue()
{
}
