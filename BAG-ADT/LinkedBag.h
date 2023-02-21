#pragma once
#include "BagInterface.h"
#include "Node.h"
template <class ItemType>
class LinkedBag :
	public BagInterface<ItemType>
{
private:
	Node<ItemType>* headPtr;
	int itmCount;

	Node<ItemType>* getPointerTo(const ItemType& target) const;
public:
	LinkedBag();
	LinkedBag(const LinkedBag<ItemType>& aBag); // copy Constructor
	virtual ~LinkedBag();						// destructor should be virtual
	int getCurrentSize() const;
	int isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	std::vector<ItemType> toVector() const;
};

template<class ItemType>
inline Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& target) const
{
	return nullptr;
}

template<class ItemType>
inline LinkedBag<ItemType>::LinkedBag()
	:Node(NULL), headPtr(nullptr), itmCount(0)
{
}

template<class ItemType>
inline LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
}

template<class ItemType>
inline LinkedBag<ItemType>::~LinkedBag()
{
}

template<class ItemType>
inline int LinkedBag<ItemType>::getCurrentSize() const
{
	return 0;
}

template<class ItemType>
inline int LinkedBag<ItemType>::isEmpty() const
{
	return 0;
}

template<class ItemType>
inline bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
	return false;
}

template<class ItemType>
inline bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
	return false;
}

template<class ItemType>
inline void LinkedBag<ItemType>::clear()
{
}

template<class ItemType>
inline bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return false;
}

template<class ItemType>
inline int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	return 0;
}

template<class ItemType>
inline std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
	return std::vector<ItemType>();
}
