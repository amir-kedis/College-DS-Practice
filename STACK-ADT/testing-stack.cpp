#include <iostream>
#include <string>

#include "StackInterface.h"
#include "ArrayStack.h"
#include "LinkedStack.h"

using namespace std;

void displayStack(StackInterface<string>* stackPtr)
{


	vector<string> stackItems = stackPtr->toVector();
	int numberOfEntries = (int)stackItems.size();

	cout << "The Stack Contains " << numberOfEntries << " items:\n";

	for (size_t i = 0; i < numberOfEntries; i++)
	{
		cout << stackItems[i] << " ";
	}

	cout << "\n\n";
}

void stackTester(StackInterface<string>* stackPtr)
{
	/// TEST isEmpty()
	cout << "isEmpty: returns " << stackPtr->isEmpty() << "; should be 1 (true)\n\n";

	/// TEST push()
	string items[] = { "one", "two", "three", "four", "five", "six" };
	cout << "Add 6 items to the stack: \n";
	for (size_t i = 0; i < 6; i++)
	{
		stackPtr->push(items[i]);
	}
	displayStack(stackPtr);
	cout << "isEmpty: returns " << stackPtr->isEmpty() << "; should be 0 (false)\n\n";

	/// TEST peek() & pop()
	cout << "peek: returns " << stackPtr->peek() << "; should be six\n";
	cout << "pop: returns " << stackPtr->pop() << "; should be true\n";
	cout << "peek: returns " << stackPtr->peek() << "; should be five\n\n";

	/// clear stack
	cout << "Clearing Stack...\n\n";
	stackPtr->pop();
	stackPtr->pop();
	stackPtr->pop();
	stackPtr->pop();
	stackPtr->pop();
	cout << "isEmpty: returns " << stackPtr->isEmpty() << "; should be 1 (true)\n\n";
}

int main()
{
	StackInterface<string>* stackPtr;

	char userChoice;

	cout << "Which implementation would you like to test ('A' || 'L'): ";
	cin >> userChoice;

	if (userChoice == 'A')
	{
		stackPtr = new ArrayStack<string>();
		cout << "Testing the Array-Based Stack:\n";
	}
	else {
		stackPtr = new LinkedStack<string>();
		cout << "Testing the LinkedList-Based Stack:\n";
	}

	cout << "The initial stack is empty.\n\n";

	// starts the tests
	stackTester(stackPtr);

	delete stackPtr;
	stackPtr = nullptr;
	cout << "All done!\n";

	return 0;
}