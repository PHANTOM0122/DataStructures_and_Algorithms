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
