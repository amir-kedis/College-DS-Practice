#include <iostream>
#include <windows.h> 
#include "PriorityQueueInterface.h"
#include "PriorityQueue.h"
#include "MinHeapPQueue.h"
#include <vector>

using namespace std;

void outL(string msg);
void displayPQueue(PriorityQueueInterface<int>* pQueue);

void pQueueTester(PriorityQueueInterface<int>* pQ);


int main()
{

	outL(".----------------------------------------.");
	outL("|  This program test PRIORITY QUEUE ADT  |");
	outL("'----------------------------------------'");

	std::cout << "Choose which implementation do you want to test: \n";
	std::cout << "1. Sorted Linked List\n";
	std::cout << "2. Min Heap\n";

	int choice;
	std::cin >> choice;

	PriorityQueueInterface<int>* pQ;

	if (choice == 1)
	{
		pQ = new PriorityQueue<int>;
	}
	else if (choice == 2)
	{
		pQ = new MinHeapPriorityQueue<int>;
	}
	else
	{
		outL("Invalid choice");
		return 1;
	}

	outL("Starting the test....");
	pQueueTester(pQ);



	return 0;
}

void outL(string msg)
{
	cout << msg << "\n";
}

void displayPQueue(PriorityQueueInterface<int>* pQueue)
{
	vector<int> qContents = pQueue->toVector();

	cout << "Queue contains [" << qContents.size() << "] items: " << "\n";

	for (size_t i = 0; i < qContents.size(); i++)
	{
		cout << "[ " << qContents[i] << " ] => ";
	}
}

void pQueueTester(PriorityQueueInterface<int>* pQ)
{
	HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(col, 9); // sets color to Bright Blue
	/// START
	outL("At the start:...");
	displayPQueue(pQ);

	/// TEST IsEmpty()
	cout << "IsEmpty() returns " << pQ->IsEmpty() << " should return 1\n\n";

	SetConsoleTextAttribute(col, 2); // sets color
	/// TEST enqueue()
	cout << "Enqueue(4) returns " << pQ->Enqueue(4) << " should return 1\n";
	cout << "Enqueue(3) returns " << pQ->Enqueue(3) << " should return 1\n";
	cout << "Enqueue(1) returns " << pQ->Enqueue(9) << " should return 1\n";
	cout << "Enqueue(1) returns " << pQ->Enqueue(1) << " should return 1\n";
	cout << "Enqueue(5) returns " << pQ->Enqueue(5) << " should return 1\n";
	displayPQueue(pQ);
	outL("");

	SetConsoleTextAttribute(col, 6); // sets color
	/// TEST Dequeue()
	cout << "Dequeue() returns " << pQ->Dequeue() << " should return 1\n";
	cout << "Dequeue() returns " << pQ->Dequeue() << " should return 1\n";
	displayPQueue(pQ);
	outL("");

	SetConsoleTextAttribute(col, 5); // sets color
	/// TEST PeekFront()
	cout << "PeekFront() returns " << pQ->PeekFront() << " should return 4\n";
	cout << "Enqueue(1) returns " << pQ->Enqueue(1) << " should return 1\n";
	cout << "Enqueue(2) returns " << pQ->Enqueue(2) << " should return 1\n";
	cout << "Enqueue(22) returns " << pQ->Enqueue(22) << " should return 1\n";
	displayPQueue(pQ);

	SetConsoleTextAttribute(col, 8); // sets color back to gray
}
