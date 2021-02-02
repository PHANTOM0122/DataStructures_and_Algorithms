Stack 
================
* ### 말 그대로 쌓아 놓는 것을 의미
* ### homogenous한 item들이 **한쪽으로만 넣고 빼고 하는 것(LIFO)**

> ### Stack operations
1) makeEmpty 2) IsEmpty 3) IsFull 4) Push(Itemtype newItem) 5) Pop 6) Itemtype Top() </br>

  Transformer
  * push
  * pop </br>
  
  Observer
  * IsEmpty
  * IsFull

> ### Stack class sample codes // StackType.h
<pre>
<code>
#include "ItemType.h"
/* ItemType.h StackDriver
const int MAX_ITEMS = 5;
typedef int ItemType;*/

class FullStack {}; // Exception class thrown by Push when stack is full.
class EmptyStack {}; // Exception class thrown by Pop and Top when stack is emtpy.

class StackType {
public:
    StackType();   // Class constructor.
    bool IsFull() const;  // Function: Determines whether the stack is full.
    bool IsEmpty() const;   // Function: Determines whether the stack is empty.
    void Push(ItemType item);  // Function: Adds newItem to the top of the stack.
    void Pop();  // Function: Removes top item from the stack.
    ItemType Top();  // Function: Returns a copy of top item on the stack.
private:
    int top;
    Itemtype items[MAX_ITEMS];
};

StackType::StackType(){
 top = -1; 
}

bool StackType::IsEmpty() const
{
  return (top == -1);
}

bool StackType::IsFull() const
{
  return (top ==  MAX_ITEMS-1);
}

void StackType::Push(ItemType newItem)
{
  if( IsFull() )
    throw FullStack();
  top++;
  items[top] = newItem;
}

void StackType::Pop()
{
  if( IsEmpty() )
    throw EmptyStack();
  top--;
}

ItemType StackType::Top()
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];
}   
</code>
</pre>
### Example
![image](https://user-images.githubusercontent.com/50229148/106563240-d6d4a480-656e-11eb-8a96-2e1cca7b9bc2.png)
### Stack class sample codes // Using template class
<pre>
<code>
template<class ItemType>
bool StackType<ItemType>::IsFull() const
{
  return (top == MAX_ITEMS-1);
}
template<class ItemType>
void StackType<ItemType>::Push(ItemType newItem) 
{
  if (IsFull())
       throw FullStack()
  top++;
  items[top] = newItem;
}
template<class ItemType>
void StackType<ItemType>::Pop()
{
  if( IsEmpty() )
    throw EmptyStack();
  top--;
}
template<class ItemType>
ItemType StackType<ItemType>::Top()
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];
} 
</code>
</pre>
* **template class에 대한 parameter는 any data type이나 상관없다!**
* **When creating class template(선언과 정의시), .h와 .cpp를 같은 파일에 넣거나 .h에 .cpp를 include 시켜야 Link오류가 나지 않는다!**
### Test Driver 중 Exception Handling 
<pre>
<code>
    catch (FullStack)
    {
      outFile << "FullStack exception thrown." << endl;
    }
    catch (EmptyStack)
    {
      outFile << "EmtpyStack exception thrown." << endl;
    }    
</code>
</pre>
> ### Recall Pointer (수업시간 내용)
![image](https://user-images.githubusercontent.com/50229148/106565164-b65a1980-6571-11eb-9fb3-cd79d8289d58.png)
* '\0' : 문자열이 끝났음을 알려주는 개행문자!
* int * x, y == int* x, int y // (Not int* x, int* y !!) -> **Tricky!**

> ### STATIC Allocation vs DYNAMIC Allocation
* **STATIC Allocation**: compile 시간 동안 메모리 공간이 할당
* **DYNAMIC Allocation**: **new**연산자를 이용하여 **run-time**에만 메모리 공간이 할당

##### 3가지 종류의 program Data
* STATIC DATA : 함수의 사용 여부와 상관없이 **프로그램이 시작될 때 만들어진다. 함수가 종료후에도 메모리 공간이 남아있다.(살아있다)** 프로그램이 종료되어야 메모리가 반납된다.
Ex) static int y; // y의 구조는 프로그램 종료시까지 바뀌지 않는다.
* AUTOMATIC DATA : **함수가 실행시에 메모리를 할당 받고, 함수가 종료시에 메모리가 사라진다.**
* **DYNAMIC DATA** : **new, delete** 연산자 사용 시까지 메모리가 할당된다. **다이내믹 데이터는 변수 이름을 가지지 않는다!** 

# 수업시간 외 plus alpha!!
> ### STL Stack
* 원소가 삽입되면 동적으로 자신의 크기를 변경한다
* STL구현에는 빈 스택에 대한 top, pop연산이 정의 되어 있지 않다. 
  -> **오류가 발생하지 않는다.**
* STL vector를 기반으로 하고 있다.
  
> ### ArrayStack class sample codes // ArrayStack.h
* 문제점 : **메모리 낭비 및 초과 되기가 싶다!!**
<pre>
<code>
class RuntimeException{
  private: 
    string errorMsg;
  public:
     RuntimeException(const string& err) : errorMsg(err) {}
     string getMessage() const {return errorMsg;}
};

class StackEmpty : public RuntimeException{ // 빈 스택에 대해서 top 또는 pop을 시키면 발생하는 에러. StackFull도 이와 동일!
public:
  StackEmpty(const string& err) : RumtimeException(err){}
};

template <typename E>
class ArrayStack {
    enum { DEF_CAPACITY = 100 };
public:
    ArrayStack(int cap = DEF_CAPACITY);
    int size() const;
    bool empty() const;
    const E& top() const throw(StackEmpty);
    void push(const E& e) throw(StackFull);
    void pop() throw(StackEmpty);
private:
    E* S; // 스택 원소들의 배열
    int capacity; // 스택 용량
    int t; // 스택 최상위 원소의 인덱스
};
template<typename E>
ArrayStack<E>::ArrayStack(int cap) : S(new E[cap]), capacity(cap), t(-1) {} // 스택 생성 및 디폴트 값 입력

template<typename E>
int ArrayStack<E>::size() {
    return (t + 1); // 스택에 저장된 아이템 갯수
}

template<typename E>
bool ArrayStack<E>::empty() const {
    return (t < 0); // t가 -1이면 비어있는 상태!
}

template<typename E>
const E& ArrayStack<E>::top() const throw(StackEmpty) {
    if (empty())
        throw stackEmpty("Top of empty stack");
    return S[t];
}

template<typename E>
void ArrayStack<E>::push(const E& e) throw(StackFull) {
    if (size() >= capacity)
        throw StackFull("Push to full stack");
    t++;
    S[t] = e;
}
template<typename E>
void ArrayStack<E>::pop() throw(StackEmpty) {
    if (empty())
        throw StackEmpty("Pop from empty stack!");
    t--;
} 
  
int main() { // Test Driver 
    try {
        // Do something!
    }
    catch (StackEmpty& e) {
        cout << e.getMessage() << endl;
    }
    catch (StackFull& e) {
        cout << e.getMessage() << endl;
    }
}
</code>
</pre>
> ### Linked list를 이용한 Stack의 구현
<pre>
<code>
typedef string Elem;
class LinkedStack{
public:
  // 위와 동일 (push만 제외 throw 없는거 제외, 소멸자는 SlinkedList의 소멸자 이용!)
  void push(const Elem& e);
private:
  SLinkedList<Elem> S; // 원소의 링크드 리스트
  int n; // 원소의 갯수
};

LinkedStack::LinkedStack() : S(nullptr), n(0) {} // Default
int LinkedStack::size() const { return n; } // 스택 내의 아이템 갯수 반환
bool LinkdedStack empty() const { return n==0; } 
const Elem& LinkdedStack::top() const throw(StackEmpty){
 if(empty())
    throw StackEmpty("Pop from empty stack!");
 return S.front(); // Slinkedlist는 head에서만 상수 시간에 원소를 삽입 삭제가 가능하기 때문에, head를 당연히 선택해야 한다.
 }
void Linked::push(const E& e){
  ++n; 
  S.addFront(e); // 스택의 최상위에 원소 삽입
}
void Linked::pop() throw(Stackempty){
  if(empty()) 
    throw StackEmpty("Pop from empty stack!");
  n--;
  S.removeFront(e); // 스택의 최상위에 원소 삽입
}

> ### 스택을 이용한 벡터의 역순화
'''
template<typename E>
void reverse(vector<E>& V){
  ArrayStack<E> S(V.size()); // 생성
  for(int i=0; i<V.size();i++)
      S.push(V[i]); // 원소들을 stack에 push
  for(int i=0; i<V.size();i++_
      v[i] = S.top(); S.pop(); // 원소들을 역순으로 재지정 및 pop!
  }
'''
>### 응용 문제 괄호와 HTML 태그 맞추기
  ### 괄호 맞추기를 위한 기본 알고리즘
  '''
  Algorithm ParenMatch(X,n);
    입력: n개의 토큰으로 이루어진 배열 X.(수학 연산자, 이름, 심볼, 숫자 등)
    출력: true(만약 X의 모든 분류 심볼이 맞을 경우)
    Let S be empty stack!
    for i=0, n-1; do
        if X[i]가 여는 괄호 -> S.push(X[i]);
        else if X[i]가 닫는 괄호 
        -> if s.empty() : return false;
           else if X[i]와 type이 다르다 : return false;
           else S.pop(X[i]); 
    if S.empty() // 모든 심볼이 맞아서 비어있는 경우
      return true;
    else
      return false; // 맞춰지지 않는 심볼이 남아있다.
  '''
  
