#include <iostream>
#include <vector>
#include "BinaryNodeTree.h"
#include "BinaryNode.h"
#include "BinaryTreeInterface.h"
using namespace std;

void displayTree(BinaryTreeInterface<string>* treePtr);
void treeTester(BinaryTreeInterface<string>* treePtr);


int main()
{
	BinaryTreeInterface<string>* treePtr;
	
	treePtr = new BinaryNodeTree<string>();

	cout << "The initial Tree is empty.\n\n";

	// starts the tests
	treeTester(treePtr);

	delete treePtr;
	cout << "All done!\n";

}

void displayTree(BinaryTreeInterface<string>* treePtr)
{
	vector<string> treeItems = treePtr->toVector();
	int numberOfEntries = (int)treeItems.size();

	cout << "The Tree Contains " << numberOfEntries << " items:\n";

	for (size_t i = 0; i < numberOfEntries; i++)
	{
		cout << "\"" << treeItems[i] << "\" ";
	}

	cout << "\n";
}

void treeTester(BinaryTreeInterface<string>* treePtr)
{
	displayTree(treePtr);

	/// TESTING isEmpty()
	cout << "isEmpty returns: " << treePtr->isEmpty() << " should return 1 (true)\n\n";

	/// TESTING add()
	vector<string> items = {
		"ITEM 1",
		"ITEM 2",
		"ITEM 3",
		"ITEM 4",
		"ITEM 5",
		"ITEM 6",
	};

	for (int i = 0; i < items.size(); i++)
	{
		treePtr->add(items[i]);
	}

	displayTree(treePtr);
	cout << "Tree should contain [ITEM 1 ITEM 2 ITEM 3 ITEM 4 ITEM 5 ITEM 6] (not necessary with the same order)\n\n";
	
	treePtr->remove("ITEM 3");
	displayTree(treePtr);
	cout << "ITEM 3 should be deleted \n\n";

	cout << "The height of the tree is " << treePtr->getHeight() << "\n\n";

	cout << "Checking if ITEM 6 is in the tree" << endl;
	cout << "contains return: " << treePtr->contains("ITEM 6") << " should return 1 (true)\n\n";

	cout << "Calling clear() to remove all the nodes of the tree" << endl;
	treePtr->clear();
	displayTree(treePtr);
}

