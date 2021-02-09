#include "DoubleLinkedList.h"

DLinkedList::DLinkedList()
{
	header = new NodeType; // 헤더 앞에 새로운 노드 생성
	trailer = new NodeType; // 트레일 뒤에 새로운 노드 생성
	header->next = trailer; // 서로를 point!
	trailer->prev = header;
}

DLinkedList::~DLinkedList()
{
	while (!empty()) {removeFront();}
	delete header;
	delete trailer;
}

bool DLinkedList::empty() const
{
	return (header->next == trailer);
}

const Elem& DLinkedList::front() const
{
	return header->next->info;
}

const Elem& DLinkedList::back() const
{
	return trailer->prev->info;
}

void DLinkedList::addFront(const Elem& e)
{
	add(header->next, e); // list뒤에서 추가
}

void DLinkedList::addBack(const Elem& e)
{
	add(trailer, e); // list뒤에서 추가
}

void DLinkedList::removeFront()
{
	remove(header->next); // 앞에서 삭제
}

void DLinkedList::removeBack()
{
	remove(trailer->prev); // 뒤에서 삭제
}

void DLinkedList::add(NodeType* v, const Elem& e)
{
	NodeType* NewNode = new NodeType; // e를 위한 새로운 node 생성
	NewNode->info = e;
	NewNode->next = v;
	NewNode->prev = v->prev;
	v->prev->next = v->prev = NewNode;
}

void DLinkedList::remove(NodeType* v)
{
	NodeType* NewNode1 = v->prev; // 선행자
	NodeType* NewNode2 = v->next; // 후속자
	NewNode1->next = NewNode2;
	NewNode2->prev = NewNode1;
}

const Elem& DLinkedList::back() const
{
	// TODO: 여기에 return 문을 삽입합니다.
}
