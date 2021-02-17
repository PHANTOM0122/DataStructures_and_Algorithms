#include "PQtype.h"

template<class ItemType>
PQtype<ItemType>::PQtype(int max)
{
	maxItems = max;
	length = 0;
	items.elements = new ItemType[max];
}

template<class ItemType>
PQtype<ItemType>::~PQtype()
{
	delete[] items.elements;
}

template<class ItemType>
void PQtype<ItemType>::MakeEmpty()
{
	length = 0;
}

template<class ItemType>
bool PQtype<ItemType>::IsEmpty() const
{
	return (length == 0);
}

template<class ItemType>
bool PQtype<ItemType>::IsFull() const
{
	return(length == maxItems);
}

template<class ItemType>
void PQtype<ItemType>::Enqueue(ItemType newitem)
{
	if (IsFull()) {
		throw FullQueue();
	}
	else {
		length++;
		items.elements[length-1] = newitem;
		items.REheapUp(0, length-1);
	}
}

template<class ItemType>
void PQtype<ItemType>::Dequeue(ItemType& item)
{
	if (IsEmpty()) {
		throw EmptyQueue();
	}
	else {
		item = items.elements[0]; // item에 root assign
		items.elements[0] = items.elements[length - 1]; // items[0]에 [length-1] 대입
		length--;
		items.ReheapDown(0, length - 1); // Heap priority reset!
	}
}
