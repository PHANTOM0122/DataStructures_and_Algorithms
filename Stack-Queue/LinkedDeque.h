#pragma once
#include "DoubleLinkedList.h"
#include <iostream>
using namespace std;

typedef string Elem;

class DequeEmpty : public exception {
public:
	DequeEmpty(string err) { errMsg = err; }
	void printError() { cout << what() << endl; cout << errMsg << endl;}
private:
	string errMsg;
};

class LinkedDeque {
public:
	LinkedDeque();
	int Size() const;
	bool empty() const;
	const Elem& front() const throw(DequeEmpty);
	const Elem& back() const throw(DequeEmpty);
	void insertFront(const Elem& e);
	void insertBack(const Elem& e);
	void removeFront() throw(DequeEmpty);
	void removeBack() throw(DequeEmpty);
private:
	DLinkedList D;
	int size;
};