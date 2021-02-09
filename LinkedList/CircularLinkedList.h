#ifndef CIRCULARLINKEDLIST
#define CIRCULARLINKEDLIST

#include <iostream>

using namespace std;

typedef string Elem;
struct NodeType {
	Elem info;
	NodeType* next;
};

class CircleList {
public:
	CircleList();
	~CircleList();
	bool empty() const;
	const Elem& front() const;
	const Elem& back() const;
	void advance();
	void add(const Elem& e);
	void remove();
private:
	NodeType* cursor;
};
#endif CIRCULARLINKEDLIST
