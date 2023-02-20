#include <iostream>

#include "ArrayBag.h"

using namespace std;

void displayBag(ArrayBag<string>& bag)
{
	cout << "The bag contains " << bag.getCurrentSize()
		<< " items: " << "\n";

	vector<string> bagItems = bag.toVector();

	int numberOfEntries = (int)bagItems.size();
	for (size_t i = 0; i < numberOfEntries; i++)
	{
		cout << bagItems[i] << " ";
	}
	cout << "\n\n";
}

void bagTester(ArrayBag<string>& bag)
{
	cout << "isEmpty: returns " << bag.isEmpty() << "; should be 1 (true)\n";
	displayBag(bag);

	string items[] = { "one", "two", "three", "four", "five", "one" };
	cout << "Add 6 items to the bag: \n";
	for (size_t i = 0; i < 6; i++)
	{
		bag.add(items[i]);
	}
	displayBag(bag);

	cout << "isEmpty: returns " << bag.isEmpty() << "; should be 0 (false)\n";
	cout << "getCurrnetSize: returns " << bag.getCurrentSize() << "; should be 6\n";
	cout << "Try to add another entry: add(\"extra\") returns " << bag.add("extra") << "\n";
	cout << "getFrequencyOf(\"one\") returns " << bag.getFrequencyOf("one")
		<< " should return 2\n";
	cout << "contains(\"two\") returns " << bag.contains("two") << " should return 1(true)\n";
	cout << "contains(\"extra\") returns " << bag.contains("extra") << " should return 0(false)\n";
	cout << "remove(\"one\") returns " << bag.remove("one") << " should return 1(true)\n";
	cout << "getFrequencyOf(\"one\") returns " << bag.getFrequencyOf("one") << " should return 1\n";

	displayBag(bag);
	cout << "After clearing the bag, ";
	bag.clear();
	cout << "isEmpty: returns " << bag.isEmpty()
		<< "; should be 1 (true)\n";

}

int main()
{
	ArrayBag<string> bag;
	cout << "Testing the Array-Based Bag:\n";
	cout << "The intial bag is empty.\n";
	bagTester(bag);
	cout << "All done!\n";
	return 0;
}