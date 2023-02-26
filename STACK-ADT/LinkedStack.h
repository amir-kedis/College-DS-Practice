#pragma once
#include "StackInterface.h"
#include "Node.h"
template <class ItemType>
class LinkedStack :
	public StackInterface<ItemType>
{
private:
	Node<ItemType>* topPtr;

public:
	LinkedStack();										// Default constructor
	LinkedStack(const LinkedStack<ItemType>& aStack);	// Copy constructor
	virtual ~LinkedStack();								// Destructor


	bool isEmpty() const;
	bool push(const ItemType& newItem);
	bool pop();
	ItemType peek() const;
	std::vector<ItemType> toVector() const;
};

template<class ItemType>
inline LinkedStack<ItemType>::LinkedStack()
	:topPtr(nullptr)
{
}

template<class ItemType>
inline LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack)
{
	Node<ItemType>* originChainPtr = aStack.topPtr;

	if (originChainPtr == nullptr)
	{
		topPtr = nullptr;
		return;
	}

	/* This implementation is not similar to the one in the Slides/Book*/
	while (originChainPtr != nullptr)
	{
		push(originChainPtr->getItem());
		originChainPtr = originChainPtr->getNext();
	}
}

template<class ItemType>
inline LinkedStack<ItemType>::~LinkedStack()
{
	while (!isEmpty())
	{
		pop();
	}
}

template<class ItemType>
inline bool LinkedStack<ItemType>::isEmpty() const
{
	return (topPtr == nullptr);
}

template<class ItemType>
inline bool LinkedStack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr); // make new node point to old top
	topPtr = newNodePtr; // update top
	return true; // No Size Limitation => always returns true
}

template<class ItemType>
inline bool LinkedStack<ItemType>::pop()
{
	if (isEmpty()) // return if no item to pop
	{
		return false;
	}

	Node<ItemType>* nodeToDeletePtr = topPtr;	// store current PTR for deallocation
	topPtr = topPtr->getNext();					// update PTR
	delete nodeToDeletePtr;						// free memory
	return true;
}

template<class ItemType>
inline ItemType LinkedStack<ItemType>::peek() const
{
	return topPtr->getItem();  // didn't check for empty because it's in the specification as a @pre
}

template<class ItemType>
inline std::vector<ItemType> LinkedStack<ItemType>::toVector() const
{
	std::vector<ItemType> stackContents;

	if (isEmpty())
	{
		return stackContents;
	}

	Node<ItemType>* curPtr = topPtr;
	while (curPtr)
	{
		stackContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
	}

	return stackContents;
}
