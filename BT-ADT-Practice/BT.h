#pragma once
#include "BTInterface.h"
#include "BinaryNode.h"
template <class ItemType>
class BT :
	public BTInterface<ItemType>
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
	BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* treePtr) const;
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
	BT();
	BT(const ItemType& rootItem);
	BT(const ItemType& rootItem,
		const BT<ItemType>* leftTreePtr,
		const BT<ItemType>* rightTreePtr);
	BT(const BT<ItemType>& tree);
	virtual ~BT();
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
	ItemType getEntry(const ItemType& anEntry) const;
	bool contains(const ItemType& anEntry) const;
	virtual std::vector<ItemType> toVector() const;
	//------------------------------------------------------------
	// Public Traversals Section.
	//------------------------------------------------------------
	void preorderTraverse(void visit(ItemType&)) const;
	void inorderTraverse(void visit(ItemType&)) const;
	void postorderTraverse(void visit(ItemType&)) const;
	//------------------------------------------------------------
	// Overloaded Operator Section.
	//------------------------------------------------------------
	BT& operator=(const BT& rightHandSide);
}; // end BinaryNodeTree

template <class ItemType>
std::vector<ItemType> BT<ItemType>::toVector() const
{
	return std::vector<ItemType>();
}

template <class ItemType>
BT<ItemType>& BT<ItemType>::operator=(const BT& rightHandSide)
{

}

template <class ItemType>
void BT<ItemType>::postorderTraverse(void visit(ItemType&)) const
{

}

template <class ItemType>
void BT<ItemType>::inorderTraverse(void visit(ItemType&)) const
{

}

template <class ItemType>
void BT<ItemType>::preorderTraverse(void visit(ItemType&)) const
{

}

template <class ItemType>
ItemType BT<ItemType>::getEntry(const ItemType& anEntry) const
{

}

template<class ItemType>
inline bool BT<ItemType>::contains(const ItemType& anEntry) const
{
	return false;
}

template <class ItemType>
void BT<ItemType>::clear()
{

}

template <class ItemType>
void BT<ItemType>::setRootData(const ItemType& newData)
{

}

template<class ItemType>
inline bool BT<ItemType>::add(const ItemType& newData)
{
	return false;
}

template<class ItemType>
inline bool BT<ItemType>::remove(const ItemType& data)
{
	return false;
}

template <class ItemType>
BT<ItemType>::~BT()
{

}

template<class ItemType>
inline bool BT<ItemType>::isEmpty() const
{
	return false;
}

template<class ItemType>
inline int BT<ItemType>::getHeight() const
{
	return 0;
}

template<class ItemType>
inline int BT<ItemType>::getNumberOfNodes() const
{
	return 0;
}

template<class ItemType>
inline ItemType BT<ItemType>::getRootData() const
{
	return ItemType();
}

template <class ItemType>
BT<ItemType>::BT(const BT<ItemType>& tree)
{

}

template <class ItemType>
BT<ItemType>::BT(const ItemType& rootItem, const BT<ItemType>* leftTreePtr, const BT<ItemType>* rightTreePtr)
{

}

template <class ItemType>
BT<ItemType>::BT(const ItemType& rootItem)
{

}

template <class ItemType>
BT<ItemType>::BT()
{

}

template <class ItemType>
void BT<ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{

}

template <class ItemType>
void BT<ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{

}

template <class ItemType>
void BT<ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const
{

}

template <class ItemType>
BinaryNode<ItemType>* BT<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const
{

}

template <class ItemType>
BinaryNode<ItemType>* BT<ItemType>::findNode(BinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const
{

}

template <class ItemType>
BinaryNode<ItemType>* BT<ItemType>::moveValuesUpTree(BinaryNode<ItemType>* subTreePtr)
{

}

template <class ItemType>
BinaryNode<ItemType>* BT<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success)
{

}

template <class ItemType>
BinaryNode<ItemType>* BT<ItemType>::balancedAdd(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr)
{

}

template <class ItemType>
void BT<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{

}

template <class ItemType>
int BT<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const
{

}

template <class ItemType>
int BT<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{

}
