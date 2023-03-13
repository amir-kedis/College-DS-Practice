#pragma once

template<class ItemType>
class BinaryNode
{
private:
	ItemType item; // Data portion
	BinaryNode<ItemType>* leftChildPtr; // Pointer to left child
	BinaryNode<ItemType>* rightChildPtr; // Pointer to right child
public:
	BinaryNode();
	BinaryNode(const ItemType& anItem,
			BinaryNode<ItemType>* leftPtr = nullptr,
			BinaryNode<ItemType>* rightPtr = nullptr);
	void setItem(const ItemType& anItem);
	ItemType getItem() const;
	bool isLeaf() const;
	BinaryNode<ItemType>* getLeftChildPtr() const;
	BinaryNode<ItemType>* getRightChildPtr() const;
	void setLeftChildPtr(BinaryNode<ItemType>* leftPtr);
	void setRightChildPtr(BinaryNode<ItemType>* rightPtr);
};

template<class ItemType>
inline BinaryNode<ItemType>::BinaryNode()
	: leftChildPtr(nullptr), rightChildPtr(nullptr)
{
}

template<class ItemType>
inline BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,
	BinaryNode<ItemType>* leftPtr,
	BinaryNode<ItemType>* rightPtr)
	: item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr)
{
}

template<class ItemType>
inline void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}


template<class ItemType>
inline ItemType BinaryNode<ItemType>::getItem() const
{
	return item;
}


template<class ItemType>
inline bool BinaryNode<ItemType>::isLeaf() const 
{
	return (leftChildPtr == nullptr && rightChildPtr == nullptr);
}


template<class ItemType>
inline BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const
{
	return leftChildPtr;
}

template<class ItemType>
inline BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const
{
	return rightChildPtr;
}

template<class ItemType>
inline void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr)
{
	leftChildPtr = leftPtr;
}

template<class ItemType>
inline void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr)
{
	rightChildPtr = rightPtr;
}