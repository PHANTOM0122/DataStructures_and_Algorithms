Queue
========
# What is Queue?
- 한쪽 방향으로만 insert, remove 되는 자료구조
- **Added at rear, removed at front (First In, First Out)**

# ADT of Queue
Transformers : Enqueue, Dequeue, MakeEmpty
Observers : IsEmpty, IsFull, LengthIs
Iterator : front, rear

# Implementation Issue 
1. 한쪽 방향으로 rear, front가 이동하니 array 한계에 도달할 수 있다. 
2. remove이후 array의 원소를 1칸씩 앞으로 이동시킨다 -> 시간이 많이 든다!
3. 1&2를 해결하기 위해서는 **circular structure**를 사용하자
![image](https://user-images.githubusercontent.com/50229148/113130136-acddec80-9256-11eb-814b-5c7cf0ec94b1.png)
![image](https://user-images.githubusercontent.com/50229148/113130452-0fcf8380-9257-11eb-8cc4-da0d2dbb798f.png)
![image](https://user-images.githubusercontent.com/50229148/113130484-1827be80-9257-11eb-9da0-ec425485f207.png)


# class QueueType
<pre><code>
#include "itemType.h"
template < class Itemtype >
class QueueType{
public:
  QueType(); // default Constructor -> static allocation
  QueType(int max); // Parameterized Constructor -> Dynamic allocation
  ~QueType();
  bool IsFull() const;
  bool IsEmpty() const;
  void Enqueue(ItemType item);
  void Dequeue(ItemType& item);
private:
  int front;
  int rear;
  int maxQue;
  ItemType* items; 
}

template < class Itemtype >
QueType< ItemType > :: QueType () {
  maxQue = 100 // Default size of array!
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType(maxQue); // Static allocation!
}

template < class Itemtype >
QueType< ItemType > :: QueType (int max) {
  maxQue = max + 1 // get size of array!
  front = maxQue - 1;
  rear = maxQue - 1;
  items = new ItemType(maxQue); // Dynamic allocation!
}

template < class Itemtype >
QueType< ItemType > :: ~QueType () {
  delete[] items;
}

template < class Itemtype >
bool QueType< ItemType > :: IsEmpty () {
  return ( rear == front );  
}

template < class Itemtype >
bool QueType< ItemType > :: IsFull () {
  return ( (rear+1) % maxQue == front );  
}

template < class Itemtype >
void QueType< ItemType > :: Enqueue(ItemType item) {
  rear = (rear+1) % maxQue; // Circular
  items[ rear ] = item;
}

template < class Itemtype >
void QueType< ItemType > :: Dequeue(ItemType& item) {
  front = (front+1) % maxQue; // Circular 
  item = items[ front ];
}
</code></pre>


![image](https://user-images.githubusercontent.com/50229148/113130533-24138080-9257-11eb-8933-dd8b61805315.png)
![image](https://user-images.githubusercontent.com/50229148/113130547-283f9e00-9257-11eb-9902-91d2d679e476.png)


# class CountedQueueType
<pre><code>
class CountedQueueType : public QueueType <ItemType>{
public:
  CountedQueueType();
  void Enqueue( ItemType newitem );
  void Dequeue( ItemType& item);
  int LengthIs() const;
private:
  int length; // number of items on the counted queue
}

template < class Itemtype >
CountedType<ItemType>::CountedQueueType(){
  length = 0;
}
  
template < class Itemtype >
int CountedType<ItemType>::LengthIs() const{
  return length;
}
  
template < class Itemtype >
void CountedType<ItemType>::Enqueue(ItemType newItem){
  length++;
  QueType< ItemType >::Enqueue( newItem );
}
  
template < class Itemtype >
void CountedType<ItemType>::Dequeue(ItemType item){
  length--;
  QueType< ItemType >::Dequeue( item );
}</code></pre>

# palindrome!
<pre><code>
#include <iostream>
#include <string>
#include <stack>
#include <queue>

int main(){
  string Input;
  getline(cin, Input); // Get string from user!
  bool IsPalindrome = true;
  
  stack<char> s;
  queue<char> q;
  
  for(char ch : Input){
    if(ch == ' ') {continue;}
    ch = toupper(ch);
    s.push(ch);
    q.push(ch);
  }
  
  char stack_char, queue_char;
  while (!s.empty() && !q.empty()) { // stack과 queue의 크기는 모두 같아야 하고, 비어있지 않아야 한다.
		stack_char = s.top();
		queue_char = q.front();
		
		if (stack_char != queue_char) {
			Palindrome = false;
			break;
		}

		s.pop();
		q.pop();
	}

	if (Palindrome) { cout << input << " is a Palindrome!" << endl; }
	else { cout << input << " isn't a Palindrome!" << endl; }
}
</code></pre>
