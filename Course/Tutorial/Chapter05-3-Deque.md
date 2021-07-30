Deque(양방향 큐)
============================
* **front와 rear 양쪽에서 삽입과 삭제 연산을 지원하는 큐와 유사한 데이터 구조**

## 5.3-1) ADT of Deque
* **insertfront(e): 첫 번째에 새로운 원소 e를 삽입한다**
* **insertBack(e): 마지막에 새로운 원소 e를 삽입한다**
* **eraseFront(e): 첫 번째 원소를 삭제한다. 공백상태이면 error 발생시킨다!**
* **eraseBack(e): 마지막 원소를 삭제한다. 공백상태이면 error 발생시킨다!**
* **front(e): 첫 번째 원소를 반환시킨다.**
* **back(e): 마지막 원소를 반환시킨다**
* **size: 원소의 갯수를 return**
* **empty(): return true if deque is empty!**

## 5.3-2) STL of Deque
<pre><code>
#include < deque >
using namespace std;
deque<string> myDeque;
</code></pre>
> member function
* size() / empty() / push_front() / push_back() / pop_front() / pop_back() / front() / back()

## 5.3-3) 이중 링크드 리스트를 이용한 데크의 구현 
<pre><code>
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

LinkedDeque::LinkedDeque()
{
	DLinkedList();
}

int LinkedDeque::Size() const
{
	return size;
}

bool LinkedDeque::empty() const
{
	return (size == 0);
}

const Elem& LinkedDeque::front() const throw(DequeEmpty)
{
	if (empty()) {
		throw DequeEmpty("removeFront of empty deque");
	}
	else {
		return D.front();
	}
}

const Elem& LinkedDeque::back() const throw(DequeEmpty)
{
	if (empty()) {
		throw DequeEmpty("removeFront of empty deque");
	}
	else {
		return D.back();
	}
}

void LinkedDeque::insertFront(const Elem& e)
{
	D.addFront(e);
	size++;
}

void LinkedDeque::insertBack(const Elem& e)
{
	D.addBack(e);
	size++;
}

void LinkedDeque::removeFront() throw(DequeEmpty)
{
	if (empty()) {
		throw DequeEmpty("removeFront of empty deque");
	}
	else {
		return D.removeFront();
		size--;
	}

}

void LinkedDeque::removeBack() throw(DequeEmpty)
{
	if (empty()) {
		throw DequeEmpty("removeFront of empty deque");
	}
	else {
		return D.removeBack();
		size--;
	}
}
</code></pre>
## 5.3-4) Deque를 이용한 stack 의 구현
<pre><code>
class DequeStack {
public:
	DequeStack();
	int size() const;
	bool empty() const;
	const Elem& top() const throw(StackEmpty);
	void push(const Elem& e);
	void pop() throw(StackEmpty);
private:
	LinkedDeque D;
};
DequeStack::DequeStack()
{
	DLinkedList();
}

int DequeStack::size() const
{
	return D.Size();
}

bool DequeStack::empty() const
{
	return D.empty();
}

const Elem& DequeStack::top() const throw(StackEmpty)
{
	if (D.empty()) {
		throw StackEmpty("Empty stack!");
	}
	else {
		return D.front();
	}
}

void DequeStack::push(const Elem& e)
{
	D.insertFront(e);
}

void DequeStack::pop() throw(StackEmpty)
{
	if (D.empty()) {
		throw StackEmpty("Empty stack!");
	}
	D.removeFront();
}</code></pre>
