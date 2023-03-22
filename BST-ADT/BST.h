#pragma once
#include <vector>
#include "BSTInterface.h"
#include "BinaryNode.h"
template <class ItemType>
class BST :
	public BSTInterface<ItemType>
{
private:
	/// =======================================
	/// Private data members.
	/// =======================================
	BinaryNode<ItemType>* root;
protected:
	/// =======================================
	/// Utility and helper Functions.
	/// =======================================
	void PreOrderHelper(void Visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
	void InOrderHelper(void Visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
	void PostOrderHelper(void Visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
	BinaryNode<ItemType>* InsertHelper(BinaryNode<ItemType>* root, ItemType& data);
	bool ContainsHelper(BinaryNode<ItemType>* treePtr, const ItemType& data) const;
	int GetNumberOfNodesHelper(BinaryNode<ItemType>* treePtr) const;
	int GetMaxDepthHelper(BinaryNode<ItemType>* treePtr) const;
	BinaryNode<ItemType>* RemoveHelper(BinaryNode<ItemType>* treePtr, const ItemType& data);
	BinaryNode<ItemType>* GetMinNode(BinaryNode<ItemType>* treePtr);
	BinaryNode<ItemType>* CopyBST(BinaryNode<ItemType>* oldTreePtr);

public:
	/// =======================================
	/// Constructors and destructor.
	/// =======================================
	BST();
	BST(const BST<ItemType>& aBST);
	BST(const BinaryNode<ItemType>* aRoot);
	~BST() override;

	/// =======================================
	/// Public Modification Function.
	/// =======================================
	bool IsEmpty() const;
	int GetMaxDepth() const;
	int GetNumberOfNodes() const;
	ItemType GetRootData() const;
	void SetRootData(const ItemType& data);
	bool Insert(const ItemType& data);
	bool Remove(const ItemType& data);
	void Clear();
	bool Contains(const ItemType& data) const;

	/// =======================================
	/// Traversal Member Functions.
	/// =======================================
	void PreorderTraverse(void Visit(ItemType&)) const;
	void InorderTraverse(void Visit(ItemType&)) const;
	void PostorderTraverse(void Visit(ItemType&)) const;
};


/// =======================================
/// Traversal Member Functions .
/// =======================================
template<class ItemType>
inline void BST<ItemType>::PreorderTraverse(void Visit(ItemType&)) const
{
	PreOrderHelper(Visit, root);
}

template<class ItemType>
inline void BST<ItemType>::InorderTraverse(void Visit(ItemType&)) const
{
	InOrderHelper(Visit, root);
}

template<class ItemType>
inline void BST<ItemType>::PostorderTraverse(void Visit(ItemType&)) const
{
	PostOrderHelper(Visit, root);
}

/// =======================================
/// Utility and helper Functions.
/// =======================================
template<class ItemType>
inline void BST<ItemType>::PreOrderHelper(void Visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if (!treePtr)
	{
		return;
	}
	ItemType visitItem = treePtr->getItem();
	Visit(visitItem);
	PreOrderHelper(Visit, treePtr->getLeftChildPtr());
	PreOrderHelper(Visit, treePtr->getRightChildPtr());
}

template<class ItemType>
inline void BST<ItemType>::InOrderHelper(void Visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if (!treePtr)
	{
		return;
	}
	InOrderHelper(Visit, treePtr->getLeftChildPtr());
	ItemType visitItem = treePtr->getItem();
	Visit(visitItem);
	InOrderHelper(Visit, treePtr->getRightChildPtr());
}

template<class ItemType>
inline void BST<ItemType>::PostOrderHelper(void Visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{
	if (!treePtr)
	{
		return;
	}
	PreOrderHelper(Visit, treePtr->getLeftChildPtr());
	PreOrderHelper(Visit, treePtr->getRightChildPtr());
	ItemType visitItem = treePtr->getItem();
	Visit(visitItem);
}

template<class ItemType>
inline BinaryNode<ItemType>* BST<ItemType>::InsertHelper(BinaryNode<ItemType>* root, ItemType& data)
{
	if (!root)
	{
		BinaryNode<ItemType>* newItem = new BinaryNode<ItemType>(data);
		return newItem;
	}
	if (root->getItem() < data)
	{
		root->setRightChildPtr(InsertHelper(root->getRightChildPtr(), data));
	}
	else
	{
		root->setLeftChildPtr(InsertHelper(root->getLeftChildPtr(), data));
	}
	return root;
}

template<class ItemType>
inline bool BST<ItemType>::ContainsHelper(BinaryNode<ItemType>* treePtr, const ItemType& data) const
{
	if (!treePtr)
	{
		return false;
	}
	if (treePtr->getItem() == data)
	{
		return true;
	}
	if (treePtr->getItem() > data)
	{
		return ContainsHelper(treePtr->getLeftChildPtr(), data);
	}
	else {
		return ContainsHelper(treePtr->getRightChildPtr(), data);
	}
}

template<class ItemType>
inline int BST<ItemType>::GetNumberOfNodesHelper(BinaryNode<ItemType>* treePtr) const
{
	if (!treePtr)
	{
		return 0;
	}
	return 1 + GetNumberOfNodesHelper(treePtr->getLeftChildPtr()) + GetNumberOfNodesHelper(treePtr->getRightChildPtr());
}

template<class ItemType>
inline int BST<ItemType>::GetMaxDepthHelper(BinaryNode<ItemType>* treePtr) const
{
	if (!treePtr)
	{
		return 0;
	}
	return 1 + max(GetMaxDepthHelper(treePtr->getLeftChildPtr()), GetMaxDepthHelper(treePtr->getRightChildPtr()));
}

template<class ItemType>
inline BinaryNode<ItemType>* BST<ItemType>::RemoveHelper(BinaryNode<ItemType>* treePtr, const ItemType& data)
{
	if (!treePtr)
	{
		return treePtr;
	}
	else if (data < treePtr->getItem())
	{
		treePtr->setLeftChildPtr(RemoveHelper(treePtr->getLeftChildPtr(), data));
	}
	else if (data > treePtr->getItem())
	{
		treePtr->setRightChildPtr(RemoveHelper(treePtr->getRightChildPtr(), data));
	}

	else { // I found you
		// CASE1: Leaf
		if (!treePtr->getLeftChildPtr() && !treePtr->getRightChildPtr())
		{
			delete treePtr;
			treePtr = NULL;
		}
		// CASE2: 1 Child
		else if (!treePtr->getLeftChildPtr())
		{
			BinaryNode<ItemType>* NodeToBeDelted = treePtr;
			treePtr = treePtr->getRightChildPtr();
			delete NodeToBeDelted;
		}
		else if (!treePtr->getRightChildPtr())
		{
			BinaryNode<ItemType>* NodeToBeDelted = treePtr;
			treePtr = treePtr->getLeftChildPtr();
			delete NodeToBeDelted;
		}
		// CASE3: 2 Children (General Case)
		else {
			BinaryNode<ItemType>* NextSuccusor = GetMinNode(treePtr->getRightChildPtr());
			treePtr->setItem(NextSuccusor->getItem());
			treePtr->setRightChildPtr(RemoveHelper(treePtr->getRightChildPtr(), NextSuccusor->getItem()));
		}
	}
	return treePtr;
}

template <class ItemType>
BinaryNode<ItemType>* BST<ItemType>::GetMinNode(BinaryNode<ItemType>* treePtr)
{
	if (!treePtr)
	{
		return treePtr;
	}
	if (!treePtr->getLeftChildPtr())
	{
		return treePtr;
	}
	treePtr = treePtr->getLeftChildPtr();
}

template<class ItemType>
inline BinaryNode<ItemType>* BST<ItemType>::CopyBST(BinaryNode<ItemType>* oldTreePtr)
{
	BinaryNode<ItemType>* newTreePtr = nullptr;

	if (oldTreePtr)
	{
		newTreePtr = new BinaryNode<ItemType>(oldTreePtr->getItem());
		newTreePtr->setLeftChildPtr(CopyBST(oldTreePtr->getLeftChildPtr()));
		newTreePtr->setRightChildPtr(CopyBST(oldTreePtr->getRightChildPtr()));
	}

	return newTreePtr;
}

/// =======================================
/// Constructors and destructor
/// =======================================
template<class ItemType>
inline BST<ItemType>::BST()
	:root(nullptr)
{
}

template<class ItemType>
inline BST<ItemType>::BST(const BST<ItemType>& aBST)
{
	root = CopyBST(aBST.root);
}

template<class ItemType>
inline BST<ItemType>::BST(const BinaryNode<ItemType>* aRoot)
	:root(aRoot)
{

}

template<class ItemType>
inline BST<ItemType>::~BST()
{
	Clear();
}

/// =======================================
/// Public Modification Function
/// =======================================
template<class ItemType>
inline bool BST<ItemType>::IsEmpty() const
{
	return !root;
}

template<class ItemType>
inline int BST<ItemType>::GetMaxDepth() const
{
	if (!root)
	{
		return 0;
	}

	return GetMaxDepthHelper(root);
}

template<class ItemType>
inline int BST<ItemType>::GetNumberOfNodes() const
{
	if (!root)
	{
		return 0;
	}

	return GetNumberOfNodesHelper(root);
}

template<class ItemType>
inline ItemType BST<ItemType>::GetRootData() const
{
	if (root)
	{
		return root->getItem();
	}
	return ItemType();
}

template<class ItemType>
inline void BST<ItemType>::SetRootData(const ItemType& data)
{
	if (root)
	{
		root->setItem(data);
	}
}

template<class ItemType>
inline bool BST<ItemType>::Insert(const ItemType& data)
{
	/// THIS BST implementation doesn't allow duplicates
	if (Contains(data))
	{
		return false;
	}
	ItemType dataCopy = data;
	root = InsertHelper(root, dataCopy);
	return true;
}

template<class ItemType>
inline bool BST<ItemType>::Remove(const ItemType& data)
{
	// CASE0: If empty tree return 0
	if (!root)
	{
		return false;
	}

	// CASE1: Value is not in tree
	if (!Contains(data))
	{
		return false;
	}

	root = RemoveHelper(root, data);
	return true;
}

template<class ItemType>
inline void BST<ItemType>::Clear()
{
	while (root)
	{
		Remove(root->getItem());
	}
}

template<class ItemType>
inline bool BST<ItemType>::Contains(const ItemType& data) const
{
	if (!root)
	{
		return false;
	}
	if (root->getItem() == data)
	{
		return true;
	}
	if (root->getItem() >= data)
	{
		return ContainsHelper(root->getLeftChildPtr(), data);
	}
	else
	{
		return ContainsHelper(root->getRightChildPtr(), data);
	}
}
