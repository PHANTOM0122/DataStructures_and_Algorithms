#ifndef LINKEDSTACK
#define LINKEDSTACK

#include <iostream>

using namespace std;

typedef int ItemType;
struct NodeType;

class StackEmpty : public exception {
public:
	StackEmpty(const string& err) { 
		cout << "Empty Stack!!" << endl;
	}
};

class LinkedStack {
public:
	LinkedStack();
	~LinkedStack();
	bool empty() const;
	const ItemType& pop() const throw(StackEmpty);
	void push(const ItemType& item);
	void pop() throw(StackEmpty);
private:
	NodeType* topPtr;
};

struct NodeType {
	ItemType info;
	NodeType* next;
};

#endif LINKEDSTACK

