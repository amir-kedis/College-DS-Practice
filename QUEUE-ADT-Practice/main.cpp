#include <iostream>
#include "QueueInterface.h"
#include "ArrayQueue.h"
#include "LinkedQueue.h"

using namespace std;

void displayQueue(QueueInterface<string>* queuePtr);
void queueTester(QueueInterface<string>* queuePtr);

int main()
{
	QueueInterface<string>* queuePtr;
	char userChoice;

	cout << "Which implementation would you like to test ('A' || 'L'): ";
	cin >> userChoice;

	if (userChoice == 'A')
	{
		queuePtr = new ArrayQueue<string>();
		cout << "Testing the Array-Based Queue:\n";
	}
	else {
		queuePtr = new LinkedQueue<string>();
		cout << "Testing the LinkedList-Based Queue:\n";
	}

	cout << "The initial Queue is empty.\n\n";

	// starts the tests
	queueTester(queuePtr);

	delete queuePtr;
	cout << "All done!\n";
}

void displayQueue(QueueInterface<string>* queuePtr)
{
	vector<string> queueItems = queuePtr->toVector();
	int numberOfEntries = (int)queueItems.size();

	cout << "The Queue Contains " << numberOfEntries << " items:\n";

	for (size_t i = 0; i < numberOfEntries; i++)
	{
		cout << queueItems[i] << " ";
	}

	cout << "\n\n";
}

void queueTester(QueueInterface<string>* queuePtr)
{
	/// TESTING toVector
	displayQueue(queuePtr);

	/// TESTING isEmpty
	cout << "isEmpty returns: " << queuePtr->isEmpty() << " should return 1 (true)\n";
}
