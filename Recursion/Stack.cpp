#include "Stack.h"

Stack::Stack() // Constructor
{
	head = nullptr;
}

Stack::~Stack() // Destructor
{
	while (!IsEmpty())
		Pop();
}


/*
Precondition – Takes an item as a parameter
Postcondition – Adds item to the front of the stack
*/
void Stack::Push(ItemType item_)
{
	if (!IsFull())
	{
		Node* temp = new Node;
		temp->next = head;
		temp->item = item_;
		head = temp;
	}
	else
		return;
}


/*
Precondition – if the list has atleast one item
Postcondition – Deletes the item from the top of the stack
*/
void Stack::Pop()
{
	if (!IsEmpty())
	{
		Node* temp = head;
		head = head->next;

		delete temp;
	}
	else
		return;
}


/*
Precondition – if the list has atleast one item
Postcondition – Returns a copy of the top item in the stack
*/
ItemType Stack::Top()
{
	Node* copy = head;
	if (!IsEmpty())
	{
		return copy->item;
	}
	else
		return copy->item;
	delete copy;
}


/*
Precondition – None
Postcondition – returns true if an item can not be added otherwise it return false
*/
bool Stack::IsFull()
{
	Node* temp;
	try
	{
		temp = new Node;
		delete temp;
		return false;
	}
	catch (std::bad_alloc& exception)
	{
		return true;
	}
}


/*
Precondition – None
Postcondition – returns true if the first item is null otherwise it returns false
*/
bool Stack::IsEmpty()
{
	if (head == nullptr)
		return true;

	else
		return false;
}


/*
Precondition – The stack has to have atleast two items to reverse the stack
Postcondition – Reverses the stack and return the reversed stack 
*/
Node* Stack::reverse(Node* head)
{
	if (IsEmpty() || head->next == NULL)
		return head;

	Node* rest = reverse(head->next);
	head->next->next = head;

	head->next = NULL;

	return rest;
}