#include "ItemType.h"

ItemType::ItemType()
{
	value = 0;
}


/*
Precondition – Takes a number as a parameter
Postcondition – Makes the number equal to value
*/
void ItemType::Initialize(int number)
{
	value = number;
}


/*
Precondition – Takes an outstream as a parameter
Postcondition – Prints the Value
*/
void ItemType::Print(ofstream& out)
{
	out << value;
}


/*
Precondition – Takes an item as a parameter
Postcondition – Determines the ordering of two ItemType objects based on their keys
*/
RelationType ItemType::ComparedTo(ItemType item)
{
	if (value < item.value)
		return LESS;
	else if (value > item.value)
		return GREATER;
	else
		return EQUAL;
}