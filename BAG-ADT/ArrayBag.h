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
inline int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	// SPUD
	return 0;
}

template<class ItemType>
inline ArrayBag<ItemType>::ArrayBag()
	:itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}

template<class ItemType>
inline int ArrayBag<ItemType>::getCurrentSize() const
{
	return 0;
}

template<class ItemType>
inline int ArrayBag<ItemType>::isEmpty() const
{
	return 0;
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
	return false;
}

template<class ItemType>
inline void ArrayBag<ItemType>::clear()
{
}

template<class ItemType>
inline int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	return 0;
}

template<class ItemType>
inline bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return false;
}

template<class ItemType>
inline std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
	return std::vector<ItemType>();
}
