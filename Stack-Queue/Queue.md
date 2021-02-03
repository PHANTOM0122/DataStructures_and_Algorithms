Queue
================
* ### Rear방향으로 원소가 추가되고, front방향으로 원소가 제거되는 구조.
* ### homogenous한 item들이 **한방향으로만 넣고 빼고 하는 것(FIFO)**

> ### Queue operations
1) makeEmpty 2) IsEmpty 3) IsFull 4) Enqueue(newitem) 5) Dequeue(&item)  </br>

  Transformer
  * MakeEmpty
  * Enqueue
  * Dequeue </br>
  
  Observer
  * IsEmpty
  * IsFull
  
> ### Basic Enqueue & Dequeue  
![image](https://user-images.githubusercontent.com/50229148/106693218-5c149380-6619-11eb-8d0c-40c75c7f5e8b.png)
* rear -> -1, front -> 0 으로 위치 초기화
* Enqueue시 rear 위치를 +1하고, 원소를 삽입한다
* Dequeue시 front 위치를 +1하고, 원소를 제거한다.
* 원형 구조를 생각하여서(ring Queue) 끝나면 앞으로 돌아가는 구조! -> **rear = (rear+1) % maxQue**

> ### Full Queue & Empty Queue
  * Full 과 Empty 모두 **rear + 1 == front**가 되어서 구분이 불가하다는 문제점!
![image](https://user-images.githubusercontent.com/50229148/106693714-62573f80-661a-11eb-8902-ed3552e8a990.png)
  * **reserved front**를 이용하여 해결! 대신 1메모리가 낭비된다!
  > Full : **rear + 1 = front** -> **(rear + 1) % maxQue = front (generalize)**
  > Empty : **rear = front** -> **rear % maxQue = front (generalize)**
![image](https://user-images.githubusercontent.com/50229148/106694027-0f31bc80-661b-11eb-93af-f2abdd016202.png)
![image](https://user-images.githubusercontent.com/50229148/106694331-aa2a9680-661b-11eb-8b9b-0af38b607cfb.png)
![image](https://user-images.githubusercontent.com/50229148/106694356-b7e01c00-661b-11eb-9ec9-97aa0768e4c2.png)

> ### Queue class sample codes // QueueType.h
<pre>
<code>
#include "ItemType.h"
/* ItemType.h StackDriver
const int MAX_ITEMS = 5;
typedef char ItemType;*/

class FullQueue {}; // Exception class thrown by Push when stack is full.
class EmptyQueue {}; // Exception class thrown by Pop and Top when stack is emtpy.

class QueueType {
public:
    QueueType();   // Class constructor.
    QueueType(int max);
    ~QueueType();
    void makeEmpty(); // Function: Initializes the queue to an empty state.
    bool IsFull() const;  // Function: Determines whether the queue is full.
    bool IsEmpty() const;   // Function: Determines whether the queue is empty.
    void Enqueue(ItemType item);  // Function: Adds newItem to the rear of the queue.
    void DEqueue(ItemType& item);  // Function: Removes top item from the stack.
    ItemType Top();  // Function: Removes front item from the queue and returns it in item.
private:
    int front;
    int rear;
    ItemType* items;
    int maxQue;
};

QueType::QueType() {
    maxQue = (defualtvalue + 1); // reserved로 인한 default + 1!
    front = maxQue - 1;
    rear = maxQue - 1;
    items = new Itemtype [maxQue];
}

QueType::QueType(int max) {
    maxQue = max + 1 // reserved로 인한 max + 1!
    front = maxQue - 1; 
    rear = maxQue - 1;
    items = new Itemtype [maxQue];
}

QueType::~QueType()         
{
  delete [] items;
}

void QueType::MakeEmpty(){
  front = maxQue - 1; 
  rear = maxQue - 1;
}

bool QueType::IsEmpty() const{
  return (front==rear);
}

bool QueType::IsFull() const{
  return ((rear+1) % maxQue == front);
}

void QueType::Enqueue(ItemType newItem) throw(FullQueue) {
  if(Isfull())
    throw FullQueue("Full Queue");
  else{
    rear = (rear + 1) % maxQue;
    items[rear] = newItem;
    }
}

void QueType::Dequeue(ItemType& item) throw(EmptyQueue) {
  if(IsEmpty())
    throw EmptyQueue("Empty Queue");
  else{
    front = (front + 1) % maxQue;
    item = items[front]}
}
</code> </pre>
    
> ### Example
