#pragma once
#include <iostream>
using namespace std;

class QueueEmpty : public exception {
public:
	QueueEmpty(const string& err){
		errorMsg = err;
		cout << errorMsg << endl;
		cout << what() << endl;
	}
private:
	string errorMsg;
};

template<typename T>
class Queue {
private:
	int front;
	int rear;
	int maxQue;
	T* items;

public:
	Queue();
	Queue(int max);
	~Queue();
	void Enqueue(T _item);
	T Dequeue() ;
	bool empty() const;
	bool IsFull() const;
};

template<typename T>
Queue<T>::Queue() {
	maxQue = 100;
	front = maxQue - 1;
	rear = maxQue - 1;
	items = new T[maxQue];
}

template<typename T>
Queue<T>::Queue(int max) {
	maxQue = max + 1;
	front = maxQue - 1;
	rear = maxQue - 1;
	items = new T[maxQue];
}

template<typename T>
Queue<T>::~Queue() {
	delete[] items;
}

template<typename T>
bool Queue<T>::empty() const {
	return (rear == front);
}

template<typename T>
bool Queue<T>::IsFull() const {
	return ((rear + 1) % maxQue == front);
}

template<typename T>
void Queue<T>::Enqueue(T item) {
	rear = (rear + 1) % maxQue; // 순환형 구조
	items[rear] = item;
}

template<typename T>
T Queue<T>::Dequeue() {
	front = (front + 1) % maxQue;
	T item = items[front];
	return item;
}


