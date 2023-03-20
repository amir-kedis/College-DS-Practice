#pragma once
template <class TypeName>
class BSTInterface
{
public:
	virtual bool IsEmpty() const = 0;
	virtual int GetMaxDepth() const = 0;
	//virtual int GetMaxDepthIter() const = 0;
	virtual int GetNumberOfNodes() const = 0;
	virtual TypeName GetRootData() const = 0;
	virtual void SetRootData(const TypeName& data) = 0;
	virtual void Insert(const TypeName& data) = 0;
	virtual bool Remove(const TypeName& data) = 0;
	virtual void Clear() = 0;
	virtual bool Contains(const TypeName& data) const = 0;
	//virtual bool IterContains(const TypeName& data) const = 0;
	virtual TypeName GetEntry(const TypeName& data) const = 0;

	virtual void PreorderTraverse(void Visit(TypeName&)) const = 0;
	virtual void InorderTraverse(void Visit(TypeName&)) const = 0;
	virtual void PostorderTraverse(void Visit(TypeName&)) const = 0;

	virtual ~BSTInterface() {}
};

