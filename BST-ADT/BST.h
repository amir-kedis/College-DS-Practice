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
	void InOrderHelper(void Visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
	BinaryNode<ItemType>* InsertHelper(BinaryNode<ItemType>* root, ItemType& data);

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
	ItemType GetEntry(const ItemType& data) const;

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
}

template<class ItemType>
inline void BST<ItemType>::InorderTraverse(void Visit(ItemType&)) const
{
	InOrderHelper(Visit, root);
}

template<class ItemType>
inline void BST<ItemType>::PostorderTraverse(void Visit(ItemType&)) const
{
}

/// =======================================
/// Utility and helper Functions.
/// =======================================
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
}

template<class ItemType>
inline BST<ItemType>::BST(const BinaryNode<ItemType>* aRoot)
{
}

template<class ItemType>
inline BST<ItemType>::~BST()
{
}

/// =======================================
/// Public Modification Function
/// =======================================
template<class ItemType>
inline bool BST<ItemType>::IsEmpty() const
{
	return false;
}

template<class ItemType>
inline int BST<ItemType>::GetMaxDepth() const
{
	return 0;
}

template<class ItemType>
inline int BST<ItemType>::GetNumberOfNodes() const
{
	return 0;
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
	//if (Contains(data))
	//{
	//	return;
	//}
	ItemType dataCopy = data;
	root = InsertHelper(root, dataCopy);
	return true;
}

template<class ItemType>
inline bool BST<ItemType>::Remove(const ItemType& data)
{
	return false;
}

template<class ItemType>
inline void BST<ItemType>::Clear()
{
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
		//root->get
	}
}

template<class ItemType>
inline ItemType BST<ItemType>::GetEntry(const ItemType& data) const
{
	return ItemType();
}
