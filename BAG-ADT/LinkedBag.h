#pragma once
#include "BagInterface.h"
#include "Node.h"
template <class ItemType>
class LinkedBag :
	public BagInterface<ItemType>
{
private:
	Node<ItemType>* headPtr;
	int itemCount;

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
	Node<ItemType>* curPtr = headPtr;

	while (curPtr != nullptr)
	{
		if (curPtr->getItem() == target)
		{
			return curPtr;
		}
		curPtr = curPtr->getNext();
	}
	return nullptr; // fallBack if didn't find el
}

template<class ItemType>
inline LinkedBag<ItemType>::LinkedBag()
	:headPtr(nullptr), itemCount(0)
{
}

template<class ItemType>
inline LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
	Node<ItemType>* originChainPtr = aBag.headPtr;

	if (originChainPtr == nullptr)
	{
		headPtr = nullptr;
		return;
	}

	/* This implementation is not similar to the one in the Slides/Book*/
	while (originChainPtr != nullptr)
	{
		add(originChainPtr->getItem());
		originChainPtr = originChainPtr->getNext();
	}
}

template<class ItemType>
inline LinkedBag<ItemType>::~LinkedBag()
{
	clear();
}

template<class ItemType>
inline int LinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}

template<class ItemType>
inline int LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template<class ItemType>
inline bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
	// adds to the beginning of the list
	Node<ItemType>* newNodePointer = new Node<ItemType>;
	newNodePointer->setItem(newEntry);
	newNodePointer->setNext(headPtr);
	headPtr = newNodePointer;
	itemCount++;
	return true;
}

template<class ItemType>
inline bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
	// removes the first node (replaces data in node with first node then deletes first node)

	Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
	bool canRomveItem = !isEmpty() && (entryNodePtr != nullptr);

	if (canRomveItem)
	{
		entryNodePtr->setItem(headPtr->getItem());

		Node<ItemType>* nodeToBeDeletedPtr = headPtr; // store headPtr Pointer
		headPtr = headPtr->getNext();

		delete nodeToBeDeletedPtr;
		nodeToBeDeletedPtr = nullptr; // unnecessary but good practice
		itemCount--;
	}

	return canRomveItem;
}

template<class ItemType>
inline void LinkedBag<ItemType>::clear()
{
	while (headPtr != nullptr)
	{
		Node<ItemType>* nodeToBeDeltedPtr = headPtr;
		headPtr = headPtr->getNext();

		delete nodeToBeDeltedPtr;
	}
	itemCount = 0;
}

template<class ItemType>
inline bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getPointerTo(anEntry) != nullptr;
}

template<class ItemType>
inline int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;


	if (itemCount == 0) {
		return 0;

	}

	Node<ItemType>* curPtr = headPtr;
	while (curPtr != nullptr)
	{
		if (curPtr->getItem() == anEntry)
		{
			frequency++;
		}
		curPtr = curPtr->getNext();
	}

	return frequency;
}

template<class ItemType>
inline std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
	std::vector<ItemType> bagContents;

	Node<ItemType>* curPtr = headPtr;
	while (curPtr != nullptr)
	{
		bagContents.push_back(curPtr->getItem());
		curPtr = curPtr->getNext();
	}

	return bagContents;
}
