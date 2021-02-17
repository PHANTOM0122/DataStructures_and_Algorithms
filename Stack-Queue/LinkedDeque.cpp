#include "LinkedDeque.h"

LinkedDeque::LinkedDeque()
{
	DLinkedList();
}

int LinkedDeque::Size() const
{
	return size;
}

bool LinkedDeque::empty() const
{
	return (size == 0);
}

const Elem& LinkedDeque::front() const throw(DequeEmpty)
{
	if (empty()) {
		throw DequeEmpty("removeFront of empty deque");
	}
	else {
		return D.front();
	}
}

const Elem& LinkedDeque::back() const throw(DequeEmpty)
{
	if (empty()) {
		throw DequeEmpty("removeFront of empty deque");
	}
	else {
		return D.back();
	}
}

void LinkedDeque::insertFront(const Elem& e)
{
	D.addFront(e);
	size++;
}

void LinkedDeque::insertBack(const Elem& e)
{
	D.addBack(e);
	size++;
}

void LinkedDeque::removeFront() throw(DequeEmpty)
{
	if (empty()) {
		throw DequeEmpty("removeFront of empty deque");
	}
	else {
		return D.removeFront();
		size--;
	}

}

void LinkedDeque::removeBack() throw(DequeEmpty)
{
	if (empty()) {
		throw DequeEmpty("removeFront of empty deque");
	}
	else {
		return D.removeBack();
		size--;
	}
}


