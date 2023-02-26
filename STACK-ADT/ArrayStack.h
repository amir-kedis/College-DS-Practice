#pragma once
#include "StackInterface.h"
template <class ItemType, int MAX_SIZE = 1000>
class ArrayStack :
	public StackInterface<ItemType>
{
private:
	ItemType	items[MAX_SIZE];
	int			top;

	bool isFull() const;
public:
	ArrayStack();
	bool isEmpty() const;
	bool push(const ItemType& newEntry);
	bool pop();
	ItemType peek() const;
	std::vector<ItemType> toVector() const;
};

template<class ItemType, int MAX_SIZE>
inline bool ArrayStack<ItemType, MAX_SIZE>::isFull() const
{
	return top == MAX_SIZE - 1;
}

template<class ItemType, int MAX_SIZE>
inline ArrayStack<ItemType, MAX_SIZE>::ArrayStack()
	:top(-1)
{
}

template<class ItemType, int MAX_SIZE>
inline bool ArrayStack<ItemType, MAX_SIZE>::isEmpty() const
{
	return (top < 0);
}

template<class ItemType, int MAX_SIZE>
inline bool ArrayStack<ItemType, MAX_SIZE>::push(const ItemType& newEntry)
{
	if (isFull())				// check if there is a place to add first
	{
		return false;
	}

	top++;						// increment top cause we started from -1
	items[top] = newEntry;		// add the element as the new top
	return true;
}

template<class ItemType, int MAX_SIZE>
inline bool ArrayStack<ItemType, MAX_SIZE>::pop()
{
	if (isEmpty())				// check if there are items to pop
	{
		return false;
	}

	top--;						// decrease the counter and any new item will override the value
	return true;
}

template<class ItemType, int MAX_SIZE>
inline ItemType ArrayStack<ItemType, MAX_SIZE>::peek() const
{
	return items[top]; // didn't check for empty because it's in the specification as a @pre
}

template<class ItemType, int MAX_SIZE>
inline std::vector<ItemType> ArrayStack<ItemType, MAX_SIZE>::toVector() const
{
	std::vector<ItemType> stackContents;

	if (isEmpty())
	{
		return stackContents;
	}

	for (int i = 0; i < top + 1; i++)
	{
		stackContents.push_back(items[i]);
	}

	return stackContents;
}
