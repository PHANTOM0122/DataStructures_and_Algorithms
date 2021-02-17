Heaps
===============
* **A binary tree that satisfies shape and order properties.
* **Shape property: Its shape must be a complete binary tree -> 마지막 level의 노드를 제외하고는 Full!**
* **ORDER property: (max heap 기준) parentNode value >= childNode value -> Root에서 가장 큰 값이 발견된다**
* **하나의 child만 가질 경우, 반드시 왼쪽 Node로만 가진다**
![image](https://user-images.githubusercontent.com/50229148/108164699-a0815280-7134-11eb-80c0-d0e4660080cc.png)

## Heap using Array representation
* **complete binary tree이기 때문에 waste가 발생하지 않아 array로 사용하기 용이하다**
![image](https://user-images.githubusercontent.com/50229148/108164915-066dda00-7135-11eb-8325-9f025db4d539.png)

## ADT of Heap 
<pre><code>
template <class ItemType>
struct HeapType {
	void ReheapDown(int root, int bottom);
	void REheapUp(int root, int bottom);

	ItemType* elements; // Array to be allocated dynamically
	int numElements; 
};</code></pre>
> **ReheapUp function**
  * **insertitem으로 인해 last level rightmost node에 힙 순서를 무시하는 노드를 attach한 경우**
  ![image](https://user-images.githubusercontent.com/50229148/108165474-f73b5c00-7135-11eb-9190-55a082df4805.png)
  <pre><code>
  template<class ItemType>
void HeapType<ItemType>::REheapUp(int root, int bottom)
{
	int parent; // 
	if (bottom > root) {// tree is not empty!
		
		parent = (bottom - 1) / 2; // find parent!
		if (elements[bottom] > elements[parent]) {
			swap(elements[parent], elements[bottom]);
			REheapUp(root, parent);
		}
	}
}</code></pre>
