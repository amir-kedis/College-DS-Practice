#pragma once

#include <vector>

template<class ItemType>
class QueueInterface
{
public:
	/** Sees whether this queue is empty.
	@return True if the queue is empty, or false if not. */
	virtual bool isEmpty() const = 0;

	/** Adds a new entry to the back of this queue.
	@post If the operation was successful, newEntry is at the back of the queue.
	@param newEntry The object to be added as a new entry.
	@return True if the addition is successful or false if not. */
	virtual bool enqueue(const ItemType& newEntry) = 0;

	/** Removes the front of this queue.
	@post If the operation was successful, the front of the queue
	has been removed.
	@return True if the removal is successful or false if not. */
	virtual bool dequeue() = 0;

	/** Returns the front of this queue.
	@pre The queue is not empty.
	@post The front of the queue has been returned, and
	the queue is unchanged.
	@return The front of the queue. */
	virtual ItemType peekFront() const = 0;

	/** Empties and then fills a given vector with all entries that
	are in this queue.
	@return A vector containing all the entries in the queue. */
	virtual std::vector<ItemType> toVector() const = 0;
};

