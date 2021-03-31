Queue
========
# What is Queue?
- 한쪽 방향으로만 insert, remove 되는 자료구조
- **Added at rear, removed at front (First In, First Out)**

# ADT of Queue
Transformers : Enqueue, Dequeue, MakeEmpty
Observers : IsEmpty, IsFull, LengthIs
Iterator : front, rear

> Implementation Issue 
  1. 한쪽 방향으로 rear, front가 이동하니 array 한계에 도달할 수 있다. 
  2. remove이후 array의 원소를 1칸씩 앞으로 이동시킨다 -> 시간이 많이 든다!
  3. 1&2를 해결하기 위해서는 **circular structure**를 사용하자

# class QueueType
<pre><code>
#include "itemType.h"
template < class Itemtype>
class QueueType{
public:
  QueType(); // default Constructor -> static allocation
  QueType(int max); // Parameterized Constructor -> Dynamic allocation
  ~QueType();
  bool IsFull() const;
  void Enqueue(ItemType item);
  void Dequeue(ItemType& item);
private:
  int front;
  int rear;
  int maxQue;
  ItemType* items; 
}
</code></pre>
