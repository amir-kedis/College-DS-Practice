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
}

template<class ItemType>
inline LinkedStack<ItemType>::~LinkedStack()
{
}

template<class ItemType>
inline bool LinkedStack<ItemType>::isEmpty() const
{
	return (topPtr == nullptr);
}

template<class ItemType>
inline bool LinkedStack<ItemType>::push(const ItemType& newItem)
{
	return false;
}

template<class ItemType>
inline bool LinkedStack<ItemType>::pop()
{
	return false;
}

template<class ItemType>
inline ItemType LinkedStack<ItemType>::peek() const
{
	return topPtr->getItem();  // didn't check for empty because it's in the specification as a @pre
}

template<class ItemType>
inline std::vector<ItemType> LinkedStack<ItemType>::toVector() const
{
	return std::vector<ItemType>();
}
