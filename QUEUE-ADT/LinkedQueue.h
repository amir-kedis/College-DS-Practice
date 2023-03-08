#pragma once

#include "QueueInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedQueue : public QueueInterface<ItemType>
{
private:
	// The queue is implemented as a chain of linked nodes that has
	// two external pointers, a head pointer for the front of the
	// queue and a tail pointer for the back of the queue.
	Node<ItemType>* backPtr;
	Node<ItemType>* frontPtr;
public:
	LinkedQueue();
	LinkedQueue(const LinkedQueue& aQueue);
	virtual ~LinkedQueue();

	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const;
	std::vector<ItemType> toVector() const;
};

template<class ItemType>
inline LinkedQueue<ItemType>::LinkedQueue()
	: backPtr(nullptr), frontPtr(nullptr)
{
}

template<class ItemType>
inline LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue& aQueue)
{
	Node<ItemType>* originChainPtr = aQueue.frontPtr;

	if (originChainPtr == nullptr)
	{
		frontPtr = nullptr;
		backPtr = nullptr;
		return;
	}

	while (originChainPtr != nullptr)
	{
		enqueue(originChainPtr->getItem());
		originChainPtr = originChainPtr->getNext();
	}
}

template<class ItemType>
inline LinkedQueue<ItemType>::~LinkedQueue()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

template<class ItemType>
inline bool LinkedQueue<ItemType>::isEmpty() const
{
	return frontPtr == nullptr;
}

template<class ItemType>
inline bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

	if (isEmpty())
		frontPtr = newNodePtr;
	else
		backPtr->setNext(newNodePtr);
	backPtr = newNodePtr;
	return true;
}

template<class ItemType>
inline bool LinkedQueue<ItemType>::dequeue()
{
	bool result = false;

	if (!isEmpty())
	{
		// Queue is not empty: remove front
		Node<ItemType>* nodeToDeletePtr = frontPtr;
		
		if (frontPtr == backPtr) // Special case: one node in queue
		{
			frontPtr = nullptr;
			backPtr = nullptr;
		}
		else
			frontPtr = frontPtr->getNext();
		
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		result = true;
	}
	return result;
}

template<class ItemType>
inline ItemType LinkedQueue<ItemType>::peekFront() const
{
	return frontPtr->getItem();	// didn't check for empty because it's in the specification as a @pre
}

template<class ItemType>
inline std::vector<ItemType> LinkedQueue<ItemType>::toVector() const
{	
	std::vector<ItemType> queueContents;

	if (isEmpty())
		return queueContents;

	Node<ItemType>* curPtr = frontPtr;
	while (curPtr != nullptr)
	{
		queueContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
	}

	return queueContents;
}