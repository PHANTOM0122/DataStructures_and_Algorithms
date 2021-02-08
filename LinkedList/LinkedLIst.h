#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename E>
struct SNode
{
	E elem; // 원소 값
	SNode* next; // 리스트 다음 항목 pointer
}; 

template<typename E>
class SLinkedList {
public:
	SLinkedList();
	~SLinkedList();
	bool empty() const;
	const E& front() const;
	void addFront(const E& e);
	void removeFront();
private:
	SNode<E>* head;
};

template<typename E>
SLinkedList<E>::SLinkedList()
{
	head = nullptr;
}

template<typename E>
SLinkedList<E>::~SLinkedList()
{
	while (!empty()) {
		removeFront();
	}
}

template<typename E>
bool SLinkedList<E>::empty() const
{
	return (head == nullptr);
}

template<typename E>
const E& SLinkedList<E>::front() const
{
	return head->elem;
}

template<typename E>
void SLinkedList<E>::addFront(const E& e)
{
	SNode<E>* location = new SNode<E>;
	location->elem = e;
	location->next = head;
	head = location;
}

template<typename E>
void SLinkedList<E>::removeFront()
{
	SNode<E>* old = head;
	head = old->next;
	delete old;
}
#endif LINKEDLIST_H