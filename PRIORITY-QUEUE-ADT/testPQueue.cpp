#include <iostream>
#include "PriorityQueueInterface.h"
#include "PriorityQueue.h"

using namespace std;

void outL(string msg);
void displayPQueue(PriorityQueue<int>& pQueue);


int main()
{

	outL("------------------------------------");
	outL("This program test PRIORITY QUEUE ADT");
	outL("------------------------------------");

	outL("Starting the test....");



	return 0;
}

void outL(string msg)
{
	cout << msg << "\n";
}

void displayPQueue(const PriorityQueue<int>& pQueue)
{
	vector<int> qContents = pQueue.toVector();

	cout << "Queue contains [" << qContents.size() << "]: " << "\n";

	for (size_t i = 0; i < qContents.size(); i++)
	{
		cout << "[ " << qContents[i] << " ] => ";
	}
	outL("");
}

