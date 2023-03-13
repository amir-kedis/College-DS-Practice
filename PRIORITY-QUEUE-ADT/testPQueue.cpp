#include <iostream>
#include <windows.h> 
#include "PriorityQueueInterface.h"
#include "PriorityQueue.h"

using namespace std;

void outL(string msg);
void displayPQueue(PriorityQueue<int>& pQueue);

void pQueueTester(PriorityQueue<int>& pQ);


int main()
{

	outL("------------------------------------");
	outL("This program test PRIORITY QUEUE ADT");
	outL("------------------------------------");

	outL("Starting the test....");

	PriorityQueue<int> pQ;
	pQueueTester(pQ);

	return 0;
}

void outL(string msg)
{
	cout << msg << "\n";
}

void displayPQueue(PriorityQueue<int>& pQueue)
{
	vector<int> qContents = pQueue.toVector();

	cout << "Queue contains [" << qContents.size() << "] items: " << "\n";

	for (size_t i = 0; i < qContents.size(); i++)
	{
		cout << "[ " << qContents[i] << " ] => ";
	}
	if (qContents.size() != 0)
	{
		outL("should be sorted");
	}

}

void pQueueTester(PriorityQueue<int>& pQ)
{
	HANDLE col = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(col, 9); // sets color to Bright Blue
	/// START
	outL("At the start:...");
	displayPQueue(pQ);

	/// TEST IsEmpty()
	cout << "IsEmpty() returns " << pQ.IsEmpty() << " should return 1\n\n";

	SetConsoleTextAttribute(col, 2); // sets color
	/// TEST enqueue()
	cout << "Enqueue(4) returns " << pQ.Enqueue(4) << " should return 1\n";
	cout << "Enqueue(3) returns " << pQ.Enqueue(3) << " should return 1\n";
	cout << "Enqueue(1) returns " << pQ.Enqueue(9) << " should return 1\n";
	cout << "Enqueue(1) returns " << pQ.Enqueue(1) << " should return 1\n";
	cout << "Enqueue(5) returns " << pQ.Enqueue(5) << " should return 1\n";
	displayPQueue(pQ);


	SetConsoleTextAttribute(col, 8); // sets color back to gray
}

