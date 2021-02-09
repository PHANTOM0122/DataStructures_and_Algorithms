#include "LinkedStack.h"

LinkedStack::LinkedStack()
{
	topPtr = nullptr;
}

LinkedStack::~LinkedStack() // All items deallocate!
{
	NodeType* tempPtr;
	while (tempPtr!=NULL) {
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
}

bool LinkedStack::IsFull() const // 동적 할당이 되면 ok, 안되면 full
{
	NodeType* location;
	try
	{
		location = new NodeType;
		delete location;
		return false;
	}
	catch (std::bad_alloc)
	{
		return true;
	}
}

bool LinkedStack::empty() const
{
	return (topPtr == NULL);
}

const ItemType& LinkedStack::top() const throw(StackEmpty)
{
	if (empty()) {
		throw StackEmpty("Empty stack!");
	}
	else {
		return topPtr->info;
	}
}

void LinkedStack::push(const ItemType& item)
{
	NodeType* tempPtr = new NodeType;
	tempPtr->info = item;
	tempPtr->next = topPtr;
	topPtr = tempPtr;
}

void LinkedStack::pop() throw(StackEmpty)
{
	if (empty()) {
		throw StackEmpty("Empty stack!");
	}
	else {
		NodeType* tempPtr;
		tempPtr = topPtr;
		topPtr = tempPtr->next;
		delete tempPtr;
	}
}
