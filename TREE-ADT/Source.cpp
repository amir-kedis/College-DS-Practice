#include <iostream>
#include "BinaryNodeTree.h"

using namespace std;

template<class ItemType>
void getMax(ItemType& k)
{
	static int max = -1;
	if (k > max)
		max = k;
	cout << max << " ";
}

int main()
{
	BinaryNodeTree<int>* b = new BinaryNodeTree<int>(1);
	b->add(2);
	b->add(3);
	b->add(4);
	cout << b->getNumberOfNodes() << endl;
	b->clear();
	cout << b->getNumberOfNodes();
}