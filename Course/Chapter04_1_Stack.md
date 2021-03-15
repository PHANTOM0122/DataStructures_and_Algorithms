Stack
==============
## ADT of Stack Operations
* Transformers : Push, Pop
* Observers : IsEmpty, IsFull, LengthIs, Top
* Iterator : int top(Stack Pointer!)

## StackType class specification
<pre><code>
#include "ItemType.h"
#include <iostream>

class FullStack{
public:
	FullStack() {
		std::cout << "Full Stack! "<< "\n";
	}
};
class EmptyStack{
public:
	EmptyStack() {
		std::cout << "Empty Stack! " << "\n";
	}
};

template <class ItemType>
class StackType {
public:
	// Constructor
	StackType();
	// Check whether stack is full!
	bool IsFull();
	bool IsEmpty();
	bool IsLength();
	void Push(const ItemType& item);
	void Pop();
	ItemType Top();
private:
	int top; // Stack Pointer. It contains index of top elements.
	ItemType items[MAX_ITEMS];
};

template <class ItemType>
StackType<ItemType>::StackType()
{
	top = -1;
}

template <class ItemType>
bool StackType<ItemType>::IsFull()
{
	return (top == MAX_ITEMS - 1);
}

template <class ItemType>
bool StackType<ItemType>::IsEmpty()
{
	return (top == -1);
}

template <class ItemType>
bool StackType<ItemType>::IsLength()
{
	return (top + 1);
}

template <class ItemType>
void StackType<ItemType>::Push(const ItemType& item)
{
	if (IsFull()) { throw FullStack(); }
	top++;
	items[top] = item;
}

template <class ItemType>
void StackType<ItemType>::Pop()
{
	if (IsEmpty()) {
		throw EmptyStack();
	}
	top--;
}

template <class ItemType>
ItemType StackType<ItemType>::Top()
{
	if (IsEmpty()) { throw EmptyStack(); }
	return items[top];
}
  </code></pre>

## class Template
* **다양한 Type에 대하여 한번에 처리해 주는 기능의 generic Type!**
> **Actual parameter & formal parameter**
  * formal parameter : Ex) int add(int x, int y) -> ( )안이 formal parameter!
  * Actual parameter : Ex) add(1,2) -> ( )안이 actual parameter!
> **When creating class template, .cpp파일이 실행되는 순서**
 1) '#'들을 코드에서 제거
 2) C++ 컴파일러가 실행
 3) ".obj" 파일이 생성 -> Library와의 Link를 통해 ".exe" 파일이 생성된다.
 #### Exmaple) class template의 작동 메커니즘
 <pre><code> 
 Before) template <class T> class M{T xx;}(class-form); -> compiler가 actual-instance generate! -> After) class M<int>{ int xx;}(actual-instance);
 </code></pre>
> **Seperated compliation**<br>
Ex) Myclass.h -> a.cpp(define Myclass), b.cpp(Using Myclass)에서 사용한다 가정<br>
-> **template 정의와 operation이 같이 있어야 actaul-instace로 바꾸기 용이하다!**
-> a.cpp -> a.obj -> a.exe (main함수 포함 X)<br> 
-> b.cpp -> b.obj -> a.exe (main함수 포함 O)<br>
-> **전체에서 같이 실행되는 파일 중에서 main함수는 1개만 있어야 한다!**

## Address in Memory!
* **address binding: variable name(문자)와 variable value가 저장된 메모리의 주소를 묶는 것을 의미한다**
* X는 2000번, number는 2002번, ch는 2006번과 같은 의미이다!
![image](https://user-images.githubusercontent.com/50229148/111113223-cb7c8c00-85a4-11eb-8f71-b20f4aef2f14.png)

