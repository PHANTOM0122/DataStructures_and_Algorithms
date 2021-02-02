Stack 
================
* ### 말 그대로 쌓아 놓는 것을 의미
* ### homogenous한 item들이 **한쪽으로만 넣고 빼고 하는 것(LIFO)**

> ### Stack operations
1) makeEmpty 2) IsEmpty 3) IsFull 4) Push(Itemtype newItem) 5) Pop 6) Itemtype Top()

  #####<Transformer>#####
  * push
  * pop
  #####<Observer>#####
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
