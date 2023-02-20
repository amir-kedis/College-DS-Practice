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

int main()
{

	return 0;
}