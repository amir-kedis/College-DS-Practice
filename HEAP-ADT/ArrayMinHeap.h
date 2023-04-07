#pragma once
#include "HeapInterface.h"
template <class ItemType, int DEFAULT_CAPACITY = 20>
class ArrayMinHeap :
	public HeapInterface
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
	int getNumberOfNodes() const;
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

