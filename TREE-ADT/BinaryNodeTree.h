#pragma once

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"


template<class ItemType>
class BinaryNodeTree : public BinaryTreeInterface<ItemType>
{
private:
	BinaryNode<ItemType>* rootPtr;
protected:
	//------------------------------------------------------------
	// Protected Utility Methods Section:
	// Recursive helper methods for the public methods.
	//------------------------------------------------------------
	int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;
	int getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const;

	// Recursively deletes all nodes from the tree.
	void destroyTree(BinaryNode<ItemType>* subTreePtr);

	// Recursively adds a new node to the tree in a left/right fashion to
	// keep the tree balanced.
	BinaryNode<ItemType>* balancedAdd(BinaryNode<ItemType>* subTreePtr,
		BinaryNode<ItemType>* newNodePtr);

	// Removes the target value from the tree by calling moveValuesUpTree
	// to overwrite value with value from child.
	BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr,
		const ItemType target, bool& success);

	// Copies values up the tree to overwrite value in current node until
	// a leaf is reached; the leaf is then removed, since its value is
	// stored in the parent.
	BinaryNode<ItemType>* moveValuesUpTree(BinaryNode<ItemType>* subTreePtr);
	
	// Recursively searches for target value in the tree by using a
	// preorder traversal.
	BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr,
		const ItemType& target,
		bool& success) const;
	
	// Copies the tree rooted at treePtr and returns a pointer to
	// the copy.
	BinaryNode<ItemType>*
		copyTree(const BinaryNode<ItemType>* treePtr) const;
	
	// Recursive traversal helper methods:
	void preorder(void visit(ItemType&),
		BinaryNode<ItemType>* treePtr) const;
	void inorder(void visit(ItemType&),
		BinaryNode<ItemType>* treePtr) const;
	void postorder(void visit(ItemType&),
		BinaryNode<ItemType>* treePtr) const;
public:
	//------------------------------------------------------------
	// Constructor and Destructor Section.
	//------------------------------------------------------------
	BinaryNodeTree();
	BinaryNodeTree(const ItemType& rootItem);
	BinaryNodeTree(const ItemType& rootItem,
		const BinaryNodeTree<ItemType>* leftTreePtr,
		const BinaryNodeTree<ItemType>* rightTreePtr);
	BinaryNodeTree(const BinaryNodeTree<ItemType>& tree);    //Copy Constructor
	virtual ~BinaryNodeTree();
	
	//------------------------------------------------------------
	// Public BinaryTreeInterface Methods Section.
	//------------------------------------------------------------
	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	ItemType getRootData() const;
	void setRootData(const ItemType& newData);
	bool add(const ItemType& newData); // Adds a node
	bool remove(const ItemType& data); // Removes a node
	void clear();

	bool contains(const ItemType& anEntry) const;

	//------------------------------------------------------------
	// Public Traversals Section.
	//------------------------------------------------------------
	void preorderTraverse(void visit(ItemType&)) const;
	void inorderTraverse(void visit(ItemType&)) const;
	void postorderTraverse(void visit(ItemType&)) const;

};

template<class ItemType>
inline BinaryNodeTree<ItemType>::BinaryNodeTree()
	: rootPtr(nullptr)
{
}

template<class ItemType>
inline BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
{
	rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}

template<class ItemType>
inline BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
								 const BinaryNodeTree<ItemType>* leftTreePtr,
								 const BinaryNodeTree<ItemType>* rightTreePtr)
{
	rootPtr = new BinaryNode<ItemType>(rootItem, 
									   copyTree(leftTreePtr->rootPtr),
									   copyTree(rightTreePtr->rootPtr));
}

template<class ItemType>
inline BinaryNodeTree<ItemType>::
						  BinaryNodeTree(const BinaryNodeTree<ItemType>& treePtr)
{
	rootPtr = copyTree(treePtr.rootPtr);
}

template<class ItemType>
inline BinaryNodeTree<ItemType>::~BinaryNodeTree()
{
	destroyTree(rootPtr);
}

template<class ItemType>
inline BinaryNode<ItemType>* BinaryNodeTree<ItemType>::
							 copyTree(const BinaryNode<ItemType>* treePtr) const
{
	BinaryNode<ItemType>* newTreePtr = nullptr;

	// Copy tree nodes during a preorder traversa
	if (treePtr != nullptr)
	{
		// Copy node
		newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(),
											  nullptr, nullptr);
		newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
		newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
	}

	return newTreePtr;
}

template<class ItemType>
inline void BinaryNodeTree<ItemType>::
						   destroyTree(BinaryNode<ItemType>* subTreePtr)
{
	if (subTreePtr != nullptr)
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		delete subTreePtr;
	}
	rootPtr = nullptr;
}

template<class ItemType>
inline int BinaryNodeTree<ItemType>::
						  getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{
	if (subTreePtr == nullptr)
	{
		return 0;
	}

	return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),
				   getHeightHelper(subTreePtr->getRightChildPtr()));
}

template<class ItemType>
inline int BinaryNodeTree<ItemType>::
						  getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const
{
	if (subTreePtr == nullptr)
	{
		return 0;
	}

	return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr())
			 + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
}

template<class ItemType>
inline BinaryNode<ItemType>* BinaryNodeTree<ItemType>::
							 balancedAdd(BinaryNode<ItemType>* subTreePtr,
								         BinaryNode<ItemType>* newNodePtr)
{
	if (subTreePtr == nullptr)
		return newNodePtr;
	else
	{
		BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
		BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();
		
		if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
		{
			rightPtr = balancedAdd(rightPtr, newNodePtr);
			subTreePtr->setRightChildPtr(rightPtr);
		}
		else
		{
			leftPtr = balancedAdd(leftPtr, newNodePtr);
			subTreePtr->setLeftChildPtr(leftPtr);
		}
	}

	return subTreePtr;
}

template<class ItemType>
inline BinaryNode<ItemType>* BinaryNodeTree<ItemType>::
							 removeValue(BinaryNode<ItemType>* subTreePtr,
										 const ItemType target, bool& success)
{
	return nullptr;
}

template<class ItemType>
inline BinaryNode<ItemType>* BinaryNodeTree<ItemType>::
							 moveValuesUpTree(BinaryNode<ItemType>* subTreePtr)
{
	if (subTreePtr == nullptr)
	{
		return nullptr;
	}

	BinaryNode<ItemType>* leftPtr = subTreePtr->getLeftChildPtr();
	BinaryNode<ItemType>* rightPtr = subTreePtr->getRightChildPtr();

	if (leftPtr != nullptr)
	{
		ItemType theItem = leftPtr->getItem();
		subTreePtr->setItem(theItem);
		BinaryNode<ItemType>* temp = moveValuesUpTree(leftPtr);
		if (temp == nullptr)
			subTreePtr->setLeftChildPtr(nullptr);
		return subTreePtr;
	}
	else if (rightPtr != nullptr)
	{
		ItemType theItem = rightPtr->getItem();
		subTreePtr->setItem(theItem);
		BinaryNode<ItemType>* temp = moveValuesUpTree(rightPtr);
		if (temp == nullptr)
			subTreePtr->setRightChildPtr(nullptr);
		return subTreePtr;
	}
	else
	{
		delete subTreePtr;
		subTreePtr = nullptr;
		return subTreePtr;
	}
}

template<class ItemType>
inline BinaryNode<ItemType>* BinaryNodeTree<ItemType>::
							 findNode(BinaryNode<ItemType>* treePtr,
						              const ItemType& target,
							          bool& success) const
{
	BinaryNode<ItemType>* newPtr = nullptr;

	if (treePtr != nullptr)
	{
		if (treePtr->getItem() == target)
		{
			success = true;
			return treePtr;
		}
		newPtr = findNode(treePtr->getLeftChildPtr(), target, success);
		if (newPtr != nullptr)
		{
			success = true;
			return newPtr;
		}

		newPtr = findNode(treePtr->getRightChildPtr(), target, success);
	}

	if (newPtr == nullptr)
		success = false;
	else
		success = true;

	return newPtr;
}

template<class ItemType>
inline void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&),
									  BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		preorder(visit, treePtr->getLeftChildPtr());
		preorder(visit, treePtr->getRightChildPtr());
	}
}

template<class ItemType>
inline void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&),
									  BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
		inorder(visit, treePtr->getLeftChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
		inorder(visit, treePtr->getRightChildPtr());
	}
}

template<class ItemType>
inline void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&),
	BinaryNode<ItemType>* treePtr) const
{
	if (treePtr != nullptr)
	{
		postorder(visit, treePtr->getLeftChildPtr());
		postorder(visit, treePtr->getRightChildPtr());
		ItemType theItem = treePtr->getItem();
		visit(theItem);
	}
}


template<class ItemType>
inline bool BinaryNodeTree<ItemType>::isEmpty() const
{
	return rootPtr == nullptr;
}

template<class ItemType>
inline int BinaryNodeTree<ItemType>::getHeight() const
{
	return getHeightHelper(rootPtr);
}


template<class ItemType>
inline int BinaryNodeTree<ItemType>::getNumberOfNodes() const
{
	return getNumberOfNodesHelper(rootPtr);
}


template<class ItemType>
inline ItemType BinaryNodeTree<ItemType>::getRootData() const
{
	// We must check first if Tree isEmpty before calling this function
	return rootPtr->getItem();
}


template<class ItemType>
inline void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData)
{
	if (rootPtr == nullptr)
	{
		rootPtr = new BinaryNode<ItemType>(newData, nullptr, nullptr);
		return;
	}

	rootPtr->setItem(newData);
}


template<class ItemType>
inline bool BinaryNodeTree<ItemType>::add(const ItemType& newData)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
	rootPtr = balancedAdd(rootPtr, newNodePtr);

	return true;
}


template<class ItemType>
inline bool BinaryNodeTree<ItemType>::remove(const ItemType& data)
{
	bool success = false;
	removeValue(rootPtr, data, success);
	return success;
}

template<class ItemType>
inline void BinaryNodeTree<ItemType>::clear()
{
	destroyTree(rootPtr);
}


template<class ItemType>
inline bool BinaryNodeTree<ItemType>::
						   contains(const ItemType& anEntry) const
{
	bool isFound = false;
	findNode(rootPtr, anEntry, isFound);
	return isFound;
}


template<class ItemType>
inline void BinaryNodeTree<ItemType>::
						   preorderTraverse(void visit(ItemType&)) const
{
	preorder(visit, rootPtr);
}


template<class ItemType>
inline void BinaryNodeTree<ItemType>::
					       inorderTraverse(void visit(ItemType&)) const
{
	inorder(visit, rootPtr);
}

template<class ItemType>
inline void BinaryNodeTree<ItemType>::
						   postorderTraverse(void visit(ItemType&)) const
{
	postorder(visit, rootPtr);
}