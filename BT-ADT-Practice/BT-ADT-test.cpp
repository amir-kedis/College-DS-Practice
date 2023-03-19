#include <iostream>
#include <string>
#include "BTInterface.h"
#include "BT.h"

void displayTree(BTInterface<std::string>* treePtr);
void treeTester(BTInterface<std::string>* treePtr);

int main()
{
	BTInterface<std::string>* testTree = new BT<std::string>;

	std::cout << "----------------------------------------\n";
	std::cout << "-------THIS PROGRAM TESTS BT ADT--------\n";
	std::cout << "----------------------------------------\n";

	treeTester(testTree);

	delete testTree;

	std::cout << "TEST Finished..........\n";

	std::cin.get();

	return 0;
}

void displayTree(BTInterface<std::string>* treePtr)
{

}

void treeTester(BTInterface<std::string>* treePtr)
{

}

