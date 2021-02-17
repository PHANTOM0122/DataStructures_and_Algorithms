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
> **ReheapDown function**
  * **Deleteitem으로 인해 root에 가장 biggest value가 없는 경우**
  * **parent와 child(left,right 중 큰 것)과 swap!!**
  ![image](https://user-images.githubusercontent.com/50229148/108165948-c90a4c00-7136-11eb-9270-ea4be4712739.png)
<pre><code>
template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom) // bottom : rightmost int the last level -> array last elem
{
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;

	if (leftChild <= bottom) { // left child가 존재하는 경우
		if (leftChild == bottom) { // one child(==left child)
			maxChild = leftChild;
		}
		else { // Two children!
			if (elements[leftChild] < elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild; 
		}

		if (elements[root] < elements[maxChild]) {// case that violate heap priority
			swap(elements[root], elements[maxChild]);
			ReheapDown(maxChild, bottom); // Recursive
		}
	}
}</code></pre>
