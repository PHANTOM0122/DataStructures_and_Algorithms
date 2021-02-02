Stack 
================
* ### 말 그대로 쌓아 놓는 것을 의미
* ### homogenous한 item들이 **한쪽으로만 넣고 빼고 하는 것(LIFO)**

> ### Stack operations
1) makeEmpty 2) IsEmpty 3) IsFull 4) Push(Itemtype newItem) 5) Pop 6) Itemtype Top()

  <Transformer>
  * push
  * pop
  <Observer>
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
