#ifndef STRINGLINKEDLIST_H
#define STRINGLINKEDLIST_H

#include <string>

using namespace std;

// string linked list node
class stringNode {
private:
	string elem;
	stringNode* next;
	friend class stringLinkedLIst;
};

class stringLinkedLIst {
public:
	stringLinkedLIst();
	~stringLinkedLIst();
	bool empty() const;
	const string& front() const;
	void addFront(const string& e);
	void removeFront();
private:
	stringNode* head;
};
#endif STRINGLINKEDLIST_H#pragma once
