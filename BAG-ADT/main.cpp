#include <iostream>

#include "BagInterface.h"
#include "ArrayBag.h"
#include "LinkedBag.h"

using namespace std;

void displayBag(BagInterface<string>* bagPtr)
{
	cout << "The bag contains " << bagPtr->getCurrentSize()
		<< " items: " << "\n";

	vector<string> bagItems = bagPtr->toVector();

	int numberOfEntries = (int)bagItems.size();
	for (size_t i = 0; i < numberOfEntries; i++)
	{
		cout << bagItems[i] << " ";
	}
	cout << "\n\n";
}

void bagTester(BagInterface<string>* bagPtr)
{
	cout << "isEmpty: returns " << bagPtr->isEmpty() << "; should be 1 (true)\n";
	displayBag(bagPtr);

	string items[] = { "one", "two", "three", "four", "five", "one" };
	cout << "Add 6 items to the bag: \n";
	for (size_t i = 0; i < 6; i++)
	{
		bagPtr->add(items[i]);
	}
	displayBag(bagPtr);

	cout << "isEmpty: returns " << bagPtr->isEmpty() << "; should be 0 (false)\n";
	cout << "getCurrnetSize: returns " << bagPtr->getCurrentSize() << "; should be 6\n";
	cout << "Try to add another entry: add(\"extra\") returns " << bagPtr->add("extra") << "\n";
	cout << "getFrequencyOf(\"one\") returns " << bagPtr->getFrequencyOf("one")
		<< " should return 2\n";
	cout << "contains(\"two\") returns " << bagPtr->contains("two") << " should return 1(true)\n";
	cout << "contains(\"extra\") returns " << bagPtr->contains("extra") << "\n";
	cout << "contains(\"ten\") returns " << bagPtr->contains("ten") << " should return 0(false)\n";
	cout << "remove(\"one\") returns " << bagPtr->remove("one") << " should return 1(true)\n";
	cout << "getFrequencyOf(\"one\") returns " << bagPtr->getFrequencyOf("one") << " should return 1\n";

	displayBag(bagPtr);
	cout << "After clearing the bag, ";
	bagPtr->clear();
	cout << "isEmpty: returns " << bagPtr->isEmpty()
		<< "; should be 1 (true)\n";

}

int main()
{
	BagInterface<string>* bagPtr;

	char userChoice;

	cout << "Which implementation would you like to test ('A' || 'L'): ";
	cin >> userChoice;

	if (userChoice == 'A')
	{
		bagPtr = new ArrayBag<string>();
		cout << "Testing the Array-Based Bag:\n";

	}
	else {
		bagPtr = new LinkedBag<string>();
		cout << "Testing the Array-Based Bag:\n";
	}


	cout << "The initial bag is empty.\n";
	bagTester(bagPtr);
	delete bagPtr;
	bagPtr = nullptr;
	cout << "All done!\n";
	return 0;
}