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
	std::cout << "-------THIS PROGRAM TESTS BST ADT--------\n";
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
	std::cout << "[ " << " " << " ], ";
}

void displayTree(BSTInterface<std::string>* treePtr)
{
	treePtr->InorderTraverse(Log);
}


void treeTester(BSTInterface<std::string>* treePtr)
{
	methodTester<int>("test()", 1, 0, "this is not amazing");
	methodTester<int>("test3()", 1, 1, "this is not not not amazing");
	methodTester<int>("test33()", 2, 2, "this is amazing");
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
