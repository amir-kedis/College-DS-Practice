#pragma once
#include <vector>
#include "BSTInterface.h"
#include "BinaryNode.h"
template <class TypeName>
class BST :
	public BSTInterface<TypeName>
{
private:
	/// =======================================
	/// Private data members.
	/// =======================================
	BinaryNode<TypeName>* root;
protected:
	/// =======================================
	/// Utility and helper Functions.
	/// =======================================
	void InOrderHelper(void Visit(TypeName&), BinaryNode<TypeName>* treePtr) const;

public:
	/// =======================================
	/// Constructors and destructor
	/// =======================================
	BST();
	BST(const BST<TypeName>& aBST);
	BST(const BinaryNode<TypeName>* aRoot);
	~BST() override;

	/// =======================================
	/// Public Modification Function
	/// =======================================
	bool IsEmpty() const;
	int GetMaxDepth() const;
	int GetNumberOfNodes() const;
	TypeName GetRootData() const;
	void SetRootData(const TypeName& data);
	void Insert(const TypeName& data);
	bool Remove(const TypeName& data);
	void Clear();
	bool Contains(const TypeName& data) const;
	TypeName GetEntry(const TypeName& data) const;

	/// =======================================
	/// Traversal Member Functions .
	/// =======================================
	void PreorderTraverse(void Visit(TypeName&)) const;
	void InorderTraverse(void Visit(TypeName&)) const;
	void PostorderTraverse(void Visit(TypeName&)) const;
};

/// =======================================
/// Traversal Member Functions .
/// =======================================
template<class TypeName>
inline void BST<TypeName>::PreorderTraverse(void Visit(TypeName&)) const
{
}

template<class TypeName>
inline void BST<TypeName>::InorderTraverse(void Visit(TypeName&)) const
{
	InOrderHelper(Visit, root);
}

template<class TypeName>
inline void BST<TypeName>::PostorderTraverse(void Visit(TypeName&)) const
{
}

/// =======================================
/// Utility and helper Functions.
/// =======================================
template<class TypeName>
inline void BST<TypeName>::InOrderHelper(void Visit(TypeName&), BinaryNode<TypeName>* treePtr) const
{
	if (!root)
	{
		return;
	}
	InOrderHelper(Visit, root->getLeftChildPtr());
	TypeName visitItem = root->getItem();
	Visit(visitItem);
	InOrderHelper(Visit, root->getRightChildPtr());
}

/// =======================================
/// Constructors and destructor
/// =======================================
template<class TypeName>
inline BST<TypeName>::BST()
	:root(nullptr)
{
}

template<class TypeName>
inline BST<TypeName>::BST(const BST<TypeName>& aBST)
{
}

template<class TypeName>
inline BST<TypeName>::BST(const BinaryNode<TypeName>* aRoot)
{
}

template<class TypeName>
inline BST<TypeName>::~BST()
{
}

/// =======================================
/// Public Modification Function
/// =======================================
template<class TypeName>
inline bool BST<TypeName>::IsEmpty() const
{
	return false;
}

template<class TypeName>
inline int BST<TypeName>::GetMaxDepth() const
{
	return 0;
}

template<class TypeName>
inline int BST<TypeName>::GetNumberOfNodes() const
{
	return 0;
}

template<class TypeName>
inline TypeName BST<TypeName>::GetRootData() const
{
	if (root)
	{
		return root->getItem();
	}
	return TypeName();
}

template<class TypeName>
inline void BST<TypeName>::SetRootData(const TypeName& data)
{
}

template<class TypeName>
inline void BST<TypeName>::Insert(const TypeName& data)
{
}

template<class TypeName>
inline bool BST<TypeName>::Remove(const TypeName& data)
{
	return false;
}

template<class TypeName>
inline void BST<TypeName>::Clear()
{
}

template<class TypeName>
inline bool BST<TypeName>::Contains(const TypeName& data) const
{
	return false;
}

template<class TypeName>
inline TypeName BST<TypeName>::GetEntry(const TypeName& data) const
{
	return TypeName();
}
