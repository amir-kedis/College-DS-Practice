#pragma once
template <class ItemType>
class HeapInterface
{
public:
	/** Sees whether this heap is empty.
@return True if the heap is empty, or false if not. */
	virtual bool IsEmpty() const = 0;
	/** Gets the number of nodes in this heap.
	@return The number of nodes in the heap. */
	virtual int GetNumberOfNodes() const = 0;
	/** Gets the height of this heap.
	@return The height of the heap. */
	virtual int GetHeight() const = 0;
	/** Gets the data that is in the root (top) of this heap.
	For a max-heap, the data is the largest value in the heap;
	for a min-heap, the data is the smallest value in the heap.
	@pre The heap is not empty.
	@post The root’s data has been returned, and the heap is unchanged.
	@return The data in the root of the heap. */
	virtual ItemType PeekTop() const = 0;
	/** Adds a new node containing the given data to this heap.
	@param newData The data for the new node.
	@post The heap contains a new node.
	@return True if the addition is successful, or false if not. */
	virtual bool Add(const ItemType& newData) = 0;
	/** Removes the root node from this heap.
	@return True if the removal is successful, or false if not. */
	virtual bool Remove() = 0;
	/** Removes all nodes from this heap. */
	virtual void Clear() = 0;

	virtual ~HeapInterface() = 0;
};

