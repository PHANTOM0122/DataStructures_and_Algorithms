Stack
==============
## ADT of Stack Operations
* Transformers : Push, Pop
* Observers : IsEmpty, IsFull, LengthIs, Top
* Iterator : int top(Stack Pointer!)

## StackType class specification
<pre><code>
#include "ItemType.h"
#include <iostream>

class FullStack{
public:
	FullStack() {
		std::cout << "Full Stack! "<< "\n";
	}
};
class EmptyStack{
public:
	EmptyStack() {
		std::cout << "Full Stack! " << "\n";
	}
};

template <class ItemType>
class StackType {
public:
	// Constructor
	StackType();
	// Check whether stack is full!
	bool IsFull();
	bool IsEmpty();
	bool IsLength();
	void Push(const ItemType& item);
	void Pop();
	ItemType Top();
private:
	int top; // Stack Pointer. It contains index of top elements.
	ItemType items[MAX_ITEMS];
};

template <class ItemType>
StackType<ItemType>::StackType()
{
	top = -1;
}

template <class ItemType>
bool StackType<ItemType>::IsFull()
{
	return (top == MAX_ITEMS - 1);
}

template <class ItemType>
bool StackType<ItemType>::IsEmpty()
{
	return (top == -1);
}

template <class ItemType>
bool StackType<ItemType>::IsLength()
{
	return (top + 1);
}

template <class ItemType>
void StackType<ItemType>::Push(const ItemType& item)
{
	if (IsFull()) { throw FullStack(); }
	top++;
	items[top] = item;
}

template <class ItemType>
void StackType<ItemType>::Pop()
{
	if (IsEmpty()) {
		throw EmptyStack();
	}
	top--;
}

template <class ItemType>
ItemType StackType<ItemType>::Top()
{
	if (IsEmpty()) { throw EmptyStack(); }
	return items[top];
}
  </code></pre>
