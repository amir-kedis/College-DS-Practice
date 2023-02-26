#pragma once

#include <vector>

template <class ItemType>
class StackInterface
{
	/// =======================================
	/// STACK ADT Axioms (Rules)
	/// (new Stack()).isEmpty() = true
	/// (new Stack()).pop() = false
	/// (new Stack()).peek() = error
	/// (aStack.push(item)).isEmpty() = false
	/// (aStack.push(item)).peek() = item
	/// (aStack.push(item)).pop() = true
	/// =======================================

public:
	/** Sees whether this stack is empty.
	@return True if the stack is empty, or false if not. */
	virtual bool isEmpty() const = 0;

	/** Adds a new entry to the top of this stack.
	@post If the operation was successful, newEntry is at the top of the stack.
	@param newEntry The object to be added as a new entry.
	@return True if the addition is successful or false if not. */
	virtual bool push(const ItemType& newEntry) = 0;

	/** Removes the top of this stack.
	@post If the operation was successful, the top of the stack
	has been removed.
	@return True if the removal is successful or false if not. */
	virtual bool pop() = 0;

	/** Returns the top of this stack.
	@pre The stack is not empty.
	@post The top of the stack has been returned, and
	the stack is unchanged.
	@return The top of the stack. */
	virtual ItemType peek() const = 0;

	/** Empties and then fills a given vector with all entries that
	are in this bag.
	@return A vector containing all the entries in the bag. */
	virtual std::vector<ItemType> toVector() const = 0;
};

