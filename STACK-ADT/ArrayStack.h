#pragma once
#include "StackInterface.h"
template <class ItemType, int MAX_SIZE>
class ArrayStack :
	public StackInterface<ItemType>
{
private:
	ItemType	items[MAX_SIZE];
	int			top;
public:
	ArrayStack();
	bool isEmpty() const;
	bool push(const ItemType& newEntry);
	bool pop();
	std::vector<ItemType> toVector() const;
	ItemType peek() const;
};

template<class ItemType, int MAX_SIZE>
inline ArrayStack<ItemType, MAX_SIZE>::ArrayStack()
{
}

template<class ItemType, int MAX_SIZE>
inline bool ArrayStack<ItemType, MAX_SIZE>::isEmpty() const
{
	return false;
}

template<class ItemType, int MAX_SIZE>
inline bool ArrayStack<ItemType, MAX_SIZE>::push(const ItemType& newEntry)
{
	return false;
}

template<class ItemType, int MAX_SIZE>
inline bool ArrayStack<ItemType, MAX_SIZE>::pop()
{
	return false;
}

template<class ItemType, int MAX_SIZE>
inline std::vector<ItemType> ArrayStack<ItemType, MAX_SIZE>::toVector() const
{
	return std::vector<ItemType>();
}

template<class ItemType, int MAX_SIZE>
inline ItemType ArrayStack<ItemType, MAX_SIZE>::peek() const
{
	return ItemType();
}
