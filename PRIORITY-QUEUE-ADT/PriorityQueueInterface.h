#pragma once
template <class ItemType>
class PriorityQueueInterface
{
public:
	virtual bool IsEmpty() const = 0;
	virtual int GetSize() const = 0;
	virtual bool Enqueue(const ItemType& anEntry) = 0;
	virtual bool Dequeue() = 0;
	virtual ItemType PeekFront() const = 0;
	virtual ~PriorityQueueInterface() {}
};

