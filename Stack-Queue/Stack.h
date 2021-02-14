#pragma once
#define MAX_SIZE 1000;
using namespace std;

template <typename T>
class Stack {
private:
	int* p_list;
	int size;
	int Max_size;
public:
	Stack();
	~Stack();

	// Transformer
	void push(T item);
	T pop();
	bool IsEmpty();
	T top();
	int get_size();
};