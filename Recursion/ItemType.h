#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <fstream>
using namespace std;

const int MAX_ITEMS = 100; // A constant specifying the maximum number of items to be on the list

enum RelationType // An enumeration type that consists of LESS, GREATER, EQUAL
{
	LESS, GREATER, EQUAL
};

class ItemType // A class encapsulating the type of the items in the list.
{
public:
	ItemType();

	void Initialize(int number);
	void Print(ofstream& out);
	RelationType ComparedTo(ItemType item);

	int value;

};

#endif // !ITEMTYPE_H