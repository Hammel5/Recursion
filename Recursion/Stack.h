#ifndef STACK_H
#define STACK_H

#include "ItemType.h"

struct Node
{
	ItemType item;
	Node* next;
};

class Stack
{
public:
	Node* head; // Postion of the top item in the stack
	Stack(); // default constructor
	~Stack(); // destructor

	void Push(ItemType item_); // Add a new item on the stack
	void Pop(); // Removes the top item from the stack
	ItemType Top(); // Returns a copy of the top item from the stack
	bool IsFull(); // Check to see if the stack is full
	bool IsEmpty(); // Check to see if the stack is empty
	Node* reverse(Node* node); // Reverses the order of the stack

private:

};

#endif // !STACK_H