#include "CircularLinkedList.h"
#pragma once
CircleList::CircleList()
{
	cursor = nullptr;
}

CircleList::~CircleList()
{
	while (!empty()) {
		remove(); // 소멸자
	}
}

bool CircleList::empty() const
{
	return (cursor == NULL);
}

const Elem& CircleList::front() const
{
	return cursor->next->info;
}

const Elem& CircleList::back() const
{
	return cursor->info;
}

void CircleList::advance()
{
	cursor = cursor->next;
}

void CircleList::add(const Elem& e) // 커서의 다음에 추가
{
	NodeType* tempPtr = new NodeType;
	tempPtr->info = e;
	if (cursor == NULL) { // 빈 리스트일 경우
		tempPtr->next = tempPtr; // 자기 자신을 point
		cursor = tempPtr; // 커서는 tempPtr을 point
	}
	else { // 빈 리스트가 아닐 경우
		tempPtr->next = cursor->next; // tempPtr을 cursor 뒤의 원소와 연결
		cursor->next = tempPtr;
	}
}

void CircleList::remove() // cursor의 다음 node 삭제!
{
	NodeType* old = cursor->next; // cursor의 다음 원소 point
	if (old == cursor) { // 리스트의 원소가 자기 자신밖에 없을 경우
		cursor = nullptr; // 리스트를 가리키는 cursor는 없음
	}
	else {
		cursor->next = old->next; // cursor가 삭제될 원소 다음 원소를 point
	}
	delete old; // 원소 삭제
}
