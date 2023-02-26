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
	ItemType peek() const;
};

