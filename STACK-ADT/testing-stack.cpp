#include <iostream>
#include <string>

#include "StackInterface.h"
#include "ArrayStack.h"

using namespace std;

int main()
{
	StackInterface<string>* stackPtr;

	char userChoice;

	cout << "Which implementation would you like to test ('A' || 'L'): ";
	cin >> userChoice;

	if (userChoice == 'A')
	{
		// stackPtr = new ArrayStack<string>();
		cout << "Testing the Array-Based Stack:\n";

	}
	else {
		// stackPtr = new LinkedStack<string>();
		cout << "Testing the LinkedList-Based Stack:\n";
	}

	return 0;
}