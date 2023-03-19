#include <iostream>
#include <string>
#include <windows.h> 
#include "BTInterface.h"
#include "BT.h"

void displayTree(BTInterface<std::string>* treePtr);
template <class T>
void methodTester(std::string methodName, T testReturnValue, T actualValue, std::string msg = "");
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
	methodTester<int>("test()", 1, 0, "this is amazing");
	methodTester<int>("test1()", 1, 1);
	methodTester<int>("test2()", 1, 0);
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
