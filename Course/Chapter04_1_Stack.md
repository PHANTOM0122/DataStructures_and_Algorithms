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
* **&(referencing operator): variable의 address를 get!**
* ** * (dereferecing operator): 가리키는 address의 value를 get!**
* Null, nullptr : 아무것도 안 가리키는 pointer! -> if * ptr = nullptr, * ptr = 2 (Error!발생!) -> nullptr에 값을 정해줄 수 없다!

## Allocation of memory!
1) STATIC ALLOCATION 
* **compile time**동안 메모리가 할당된다. 
* **STATIC DATA: 프로그램 시작시 memory가 할당되어 생성되며, 프로그램 종료시 destroy된다. **
2) AUTOMATIC ALLOCATION 
* **AUTOMATIC DATA: 함수가 실행 시 생성되며, 함수 실행동안 살아있으며, return후 종료 시 소멸된다.**
3) DYANAIC ALLOCATION
* **DYNAMIC DATA: new라는 operator가 실행되면서 메모리가 할당된다. 이것은 프로그램이 끝나도 자동으로 destroy되지 않는다. 반드시 delete연산자가 실행되어야 destroy된다!**
* 만약 메모리가 부족하여 메모리 할당을 못 해주는 경우, null pointer가 할당된다!
* ** 배열을 delete 하는 경우, delete p가 아닌 delete p[]라고 나타낸다!**
#### Exmaple)
<pre><code>
void f(){
int x; // 함수가 실행 시 memory가 할당된다. 함수 종료시, 자동으로 destroy!
static int y; // 변수y의 주소가 고정된다. 프로그램이 끝나도, 함수가 종료되도 y의 주소는 변하지 않는다!
}

int * p = new int (100); // p는 배열의 첫 원소를 가리킨다. new int(100)의 경우는 이름이 없는 변수이다(anonymous variable)!
</code></pre>
 
