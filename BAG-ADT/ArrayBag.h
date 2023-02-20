#pragma once
#include "BagInterface.h"
template <class ItemType>
class ArrayBag :
	public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 6;
	ItemType items[DEFAULT_CAPACITY];
	int itemCount;
	int maxItems;
	int getIndexOf(const ItemType& target) const;
public:
	ArrayBag();
	int getCurrentSize() const;
	int isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	int getFrequencyOf(const ItemType& anEntry) const;
	bool contains(const ItemType& anEntry) const;
	std::vector<ItemType> toVector() const;
};

template<class ItemType>
inline ArrayBag<ItemType>::ArrayBag()
	:itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}


template<class ItemType>
inline int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	for (size_t i = 0; i < itemCount; i++)
	{
		if (items[i] == target)
		{
			return i;
		}
	}
	return -1;
}

template<class ItemType>
inline int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}

template<class ItemType>
inline int ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template<class ItemType>
inline bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = itemCount < maxItems;

	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}

	return hasRoomToAdd;
}

template<class ItemType>
inline bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
	int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = locatedIndex > -1;
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount]; // put last element data in to-be-deleted cell
	}
	return canRemoveItem;
}

template<class ItemType>
inline void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}

template<class ItemType>
inline int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	unsigned int frequency = 0;

	for (size_t curIndex = 0; curIndex < itemCount; curIndex++)
	{
		if (items[curIndex] == anEntry)
		{
			frequency++;
		}
	}

	return frequency;
}

template<class ItemType>
inline bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) != -1;
}

template<class ItemType>
inline std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	std::vector<ItemType> bagContents;

	for (size_t i = 0; i < itemCount; i++)
	{
		bagContents.push_back(items[i]);
	}

	return bagContents;
}
