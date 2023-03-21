#pragma once
#include "BinaryNode.h"
template <class ItemType>
class BSTInterface
{
public:
	virtual bool IsEmpty() const = 0;
	virtual int GetMaxDepth() const = 0;
	virtual int GetNumberOfNodes() const = 0;
	virtual ItemType GetRootData() const = 0;
	virtual void SetRootData(const ItemType& data) = 0;
	virtual bool Insert(const ItemType& data) = 0;
	virtual bool Remove(const ItemType& data) = 0;
	virtual void Clear() = 0;
	virtual bool Contains(const ItemType& data) const = 0;

	virtual void PreorderTraverse(void Visit(ItemType&)) const = 0;
	virtual void InorderTraverse(void Visit(ItemType&)) const = 0;
	virtual void PostorderTraverse(void Visit(ItemType&)) const = 0;

	virtual ~BSTInterface() {}
};

