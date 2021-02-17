Priority Queue
==================
* **highest priority(우선순위에 따른) element의 접근이 언제든지 가능한 Queue**

## ADT of Priority Queue operations
> Transformer
* MakeEmpty
* Enqueue (일반적인 큐와 동일)
* **Dequeue (우선순위에 따라 highest value값이 나온다! - 일반적일 큐와 상이)**
> Observers
* IsEmpty
* IsFull

## Many ways to implement priority queue
- **Unsorted list: dequeuing시, 모든 list를 뒤져야한다**
- **Array-based sorted list: enqueuing할 시 모든 list를 뒤져야한다 -> O(N)**
- **Linked sorted list: enqueuing -> O(N)**
- **Binary search tree: enqueue, dequeue 모두 O(log2N)이 평균적으로 걸린다**
- **Heap: worst -> O(log2N)**

## class PQtype
#### Declaration
<pre><code>
class FullQueue{};
class EmptyQueue{};

template < class ItemType >
class PQtype {
	PQtype(int max);
	~PQtype();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType newitem);
	void Dequeue(ItemType& item);
private:
	int length;
	HeapType<ItemType> items;
	int maxItems;
};

template <class ItemType>
struct HeapType {
	void ReheapDown(int root, int bottom);
	void REheapUp(int root, int bottom);

	ItemType* elements; // Array to be allocated dynamically
	int numElements;
};</code></pre?
![image](https://user-images.githubusercontent.com/50229148/108170542-9fa0ee80-713d-11eb-832d-9f6fca615043.png)
#### Dequeue
* **step1) root에 반환 item 값 대입**
* **step2) root에 last leaf element assign**
* **step3) length--**
* **step4) reheapdown**
<pre><code>
void PQtype<ItemType>::Dequeue(ItemType& item)
{
	if (IsEmpty()) {
		throw EmptyQueue();
	}
	else {
		item = items.elements[0]; // item에 root assign
		items.elements[0] = items.elements[length - 1]; // items[0]에 [length-1] 대입
		length--;
		items.ReheapDown(0, length - 1); // Heap priority reset!
	}
}</code></pre>
#### Enqueue
* **step1) length++**
* **step2) reheapUp**
<pre><code>
void PQtype<ItemType>::Enqueue(ItemType newitem)
{
	if (IsFull()) {
		throw FullQueue();
	}
	else {
		length++;
		items.elements[length-1] = newitem;
		items.REheapUp(0, length-1);
	}
}</code></pre>

## Time comparision
![image](https://user-images.githubusercontent.com/50229148/108170958-29e95280-713e-11eb-992b-1e45443329db.png)
