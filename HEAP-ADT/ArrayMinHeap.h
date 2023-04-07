#pragma once
#include "HeapInterface.h"
template <class ItemType, int DEFAULT_CAPACITY = 20>
class ArrayMinHeap :
	public HeapInterface<ItemType>
{
public:
	////////////////////////////////
	/// Constructors and Destructor
	////////////////////////////////
	ArrayMinHeap();
	ArrayMinHeap(const ItemType arr[], const int& size);
	virtual ~ArrayMinHeap();


	///////////////////////
	/// Main Heap Functions 
	///////////////////////
	bool IsEmpty() const;
	int GetNumberOfNodes() const;
	int GetHeight() const;
	ItemType PeekTop() const;
	bool Add(const ItemType& data);
	bool Remove();
	void Clear();

private:

	///////////////////////
	/// Heap Data 
	///////////////////////
	ItemType* heapArr;
	int itemCount;
	const int ROOT_INDEX = 0;

private:

	////////////////////////////////////////
	/// Private Helper and Utility Functions 
	////////////////////////////////////////
	int GetLeftChildIndex(const int& nodeIndex) const;
	int GetRightChildIndex(const int& nodeIndex) const;
	int GetParentIndex(const int& nodeIndex) const;
	bool IsLeaf(const int& nodeIndex) const;
	void HeapRebuild(const int& nodeIndex);
	void HeapCreate();
};

template<class ItemType, int DEFAULT_CAPACITY>
inline ArrayMinHeap<ItemType, DEFAULT_CAPACITY>::ArrayMinHeap()
{
}

template<class ItemType, int DEFAULT_CAPACITY>
inline ArrayMinHeap<ItemType, DEFAULT_CAPACITY>::ArrayMinHeap(const ItemType arr[], const int& size)
{
}

template<class ItemType, int DEFAULT_CAPACITY>
inline ArrayMinHeap<ItemType, DEFAULT_CAPACITY>::~ArrayMinHeap()
{
}

template<class ItemType, int DEFAULT_CAPACITY>
inline bool ArrayMinHeap<ItemType, DEFAULT_CAPACITY>::IsEmpty() const
{
	return false;
}

template<class ItemType, int DEFAULT_CAPACITY>
inline int ArrayMinHeap<ItemType, DEFAULT_CAPACITY>::GetNumberOfNodes() const
{
	return 0;
}

template<class ItemType, int DEFAULT_CAPACITY>
inline int ArrayMinHeap<ItemType, DEFAULT_CAPACITY>::GetHeight() const
{
	return 0;
}

template<class ItemType, int DEFAULT_CAPACITY>
inline ItemType ArrayMinHeap<ItemType, DEFAULT_CAPACITY>::PeekTop() const
{
	return ItemType();
}

template<class ItemType, int DEFAULT_CAPACITY>
inline bool ArrayMinHeap<ItemType, DEFAULT_CAPACITY>::Add(const ItemType& data)
{
	return false;
}

template<class ItemType, int DEFAULT_CAPACITY>
inline bool ArrayMinHeap<ItemType, DEFAULT_CAPACITY>::Remove()
{
	return false;
}

template<class ItemType, int DEFAULT_CAPACITY>
inline void ArrayMinHeap<ItemType, DEFAULT_CAPACITY>::Clear()
{
}
