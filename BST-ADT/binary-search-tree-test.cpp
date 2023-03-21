#include <iostream>
#include <string>
#include <windows.h>
#include "BSTInterface.h"
#include "BST.h"

void displayTree(BSTInterface<std::string>* treePtr);
template <class T>
void methodTester(std::string methodName, T testReturnValue, T actualValue, std::string msg = "");
void treeTester(BSTInterface<std::string>* treePtr);

int main()
{
	BSTInterface<std::string>* testTree = new BST<std::string>;

	std::cout << "----------------------------------------\n";
	std::cout << "-------THIS PROGRAM TESTS BST ADT-------\n";
	std::cout << "----------------------------------------\n";

	treeTester(testTree);

	delete testTree;

	std::cout << "TEST Finished..........\n";

	std::cin.get();

	return 0;
}

#if 0
void displayTree(BSTInterface<std::string>* treePtr)
{
	std::vector<std::string> treeItems = treePtr->toVector();
	int numberOfEntries = (int)treeItems.size();

	std::cout << "The Tree Contains " << numberOfEntries << " items:\n";

	for (size_t i = 0; i < numberOfEntries; i++)
	{
		std::cout << "\"" << treeItems[i] << "\" ";
	}

	std::cout << "\n";
}
#endif

void Log(std::string& msg)
{
	std::cout << "[ " << msg << " ], ";
}

void displayTree(BSTInterface<std::string>* treePtr)
{
	std::cout << "The tree contains " << treePtr->GetNumberOfNodes() << " node: ";
	treePtr->InorderTraverse(Log);
	std::cout << "\n\n";
}


void treeTester(BSTInterface<std::string>* treePtr)
{
	// TESTING INSERT
	std::cout << "TESTING Insert():\n";
	std::cout << "=================\n";
	methodTester("Insert(\"Bob\")", treePtr->Insert("Bob"), true);
	methodTester("Insert(\"Amir\")", treePtr->Insert("Amir"), true);
	methodTester("Insert(\"Zeron\")", treePtr->Insert("Zeron"), true);
	methodTester("Insert(\"Emy\")", treePtr->Insert("Emy"), true);
	methodTester("Insert(\"Carl\"))", treePtr->Insert("Carl"), true);
	methodTester("Insert(\"Carl\"))", treePtr->Insert("Carl"), false, "No Duplicates");
	displayTree(treePtr);

	// TESTING GetRootData and SetRootData
	std::cout << "TESTING GetRootData() & SetRootData():\n";
	std::cout << "======================================\n";
	methodTester<std::string>("GetRootData()", treePtr->GetRootData(), "Bob");
	treePtr->SetRootData("BobReplaced");
	methodTester<std::string>("SetRootData(\"BobReplaced\") & GetRootData()", treePtr->GetRootData(), "BobReplaced", "this function shouldn't be used because it can mess the order");
	displayTree(treePtr);

	// TESTING Contains()
	std::cout << "TESTING Contains():\n";
	std::cout << "===================\n";
	methodTester("Contains(\"Amir\")", treePtr->Contains("Amir"), true, "left branch");
	methodTester("Contains(\"BobReplaced\")", treePtr->Contains("BobReplaced"), true, "root item");
	methodTester("Contains(\"Zeron\")", treePtr->Contains("Zeron"), true, "right branch");
	methodTester("Contains(\"Adam\")", treePtr->Contains("Adam"), false);
	displayTree(treePtr);

	// TESTING GetNumberOfNodes() & GetMaxDepth()
	std::cout << "TESTING GetNumberOfNodes() & GetMaxDepth():\n";
	std::cout << "===========================================\n";
	methodTester("GetNumberOfNodes()", treePtr->GetNumberOfNodes(), 5);
	methodTester("GetMaxDepth()", treePtr->GetMaxDepth(), 4);
	methodTester("Insert(\"Arnold\")", treePtr->Insert("Arnold"), true);
	methodTester("GetNumberOfNodes()", treePtr->GetNumberOfNodes(), 6);
	methodTester("GetMaxDepth()", treePtr->GetMaxDepth(), 4);
	displayTree(treePtr);


}

template<class T>
void methodTester(std::string methodName, T testReturnValue, T actualValue, std::string msg)
{
#define GREEN			2
#define LIGHTGRAY		7
#define LIGHTGREEN		10
#define LIGHTRED		12
	bool pass = testReturnValue == actualValue;

	HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);

	std::string mark;

	if (pass)
	{
		SetConsoleTextAttribute(col, LIGHTGREEN);
		mark = "pass";
	}
	else
	{
		SetConsoleTextAttribute(col, LIGHTRED);
		mark = 'X';
	}

	std::cout << methodName << " returns "
		<< testReturnValue << " should return " << actualValue
		<< "... " << mark;

	if (!msg.empty())
	{
		std::cout << " ===> " << msg;
	}


	std::cout << "\n";
	SetConsoleTextAttribute(col, LIGHTGRAY);
}
