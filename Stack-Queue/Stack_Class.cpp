#include "Datastructure\Datastructure\Stack.h"
#include <iostream>

using namespace std;

class Stack {
	int* p_list;
	int size;
	int MAX_SIZE;

public:
	Stack(int _MAX_SIZE = 1000) {
		MAX_SIZE = _MAX_SIZE; size = 0;
		p_list = new int[MAX_SIZE];
	}
	
	~Stack() { delete[] p_list; }

	int find_index(int _item) {
		int index = -1;

		for (int i = 0; i < MAX_SIZE; i++) {
			if (p_list[i] == _item) {
				index = i;
			}
		}
		return index;
	}

	void push(int _item) {
		if (size > MAX_SIZE) {
			cout << "Error: No item exists in the list" << endl;
		}

		if (find_index(_item) == -1) {
			p_list[size] = _item;
			size++;
		}
`	}

	int pop() {
		if (size == 0) {
			cout << "Error: No item exists in the list" << endl;
		}
		else {
			size = size - 1;
			return p_list[size + 1];
		}
	}

	void print() const {
		cout << "Items in the list: ";
		for (int i = 0; i < size; i++) {
			cout << p_list[i] << ",";
		}
		cout << endl;
	}

	int get_size() {
		return size;
	}

	int get_item(int _index) {
		return p_list[_index];
	}
};

Stack operator += (Stack& s1, Stack& s2) {
	for (int i = 0; i < s2.get_size(); i++) {
		s1.push(s2.get_item(i));
	}
	for (int i = 0; i < s1.get_size(); i++) {
		return s1.get_item(i);
	}
}

bool operator == (Stack& s1, Stack& s2) {
	bool result = false;
	for (unsigned i = 0; i < s1.get_size(); i++) {
		if (s1.get_item(i) == s2.get_item(i) && s1.get_size() == s2.get_size()) { result = true; }
	}
	return result;
}



int main() {

	Stack s1, s2;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s2.push(1);
	s2.push(2);
	s2.push(5);



	s1.print();
	s2.print();
	s1 += s2;
	s1.print();
	s2.print();
	cout << "s1 == s2 ? " << (s1 == s2) << endl;
	s1.pop(); // 5 out
	s1.pop(); // 3 out
	s2.pop(); // 5 out
	cout << "s1 == s2 ? " << (s1 == s2) << endl;
	s2.pop();
	s2.pop();
	s2.pop();

	return 0;
}