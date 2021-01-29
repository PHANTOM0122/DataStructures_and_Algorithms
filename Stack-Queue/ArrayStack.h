#pragma once
#include <string>
#include <iostream>
using namespace std;

class StackOutOfRange :public exception {
public:
	StackOutOfRange(const string& err) :errorMSg(err) {
		cout << what() << endl;
		exit(1);
	}
private:
	string errorMSg;
};

template<typename T>
class ArrayStack {
public:
	ArrayStack(int Default = 100) {
		capacity = Default;
		p_list = new T[capacity];
		top_index = -1;
	}
	~ArrayStack() { delete[] p_list; }
	bool empty() const { return (top_index < 0); }
	int size() const { return (top_index + 1); }
	T top() const {
		return p_list[top_index];
	}
	void push(T item) {
		++top_index;
		p_list[top_index] = item;
	}
	void pop() {
		--top_index;
	}
private:
	T* p_list;
	int capacity;
	int top_index;
};


