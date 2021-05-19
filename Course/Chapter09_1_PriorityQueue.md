Heap & Priority Queue
===============================

## Heap 되기 위한 조건
1. Complete tree이어야 한다.
2. Parent Node의 값이 Children Node보다 값이 크거나 같다

# MAXHEAP (Textbook 기준 -> 시험에는 MINHEAP 가능성이 높다)
- **Root Node의 값이 tree내에서 가장 크다**

## HEAP implementation using array representation
![image](https://user-images.githubusercontent.com/50229148/118808703-be518580-b8e4-11eb-8665-9d475115d46e.png)
![image](https://user-images.githubusercontent.com/50229148/118808892-ee008d80-b8e4-11eb-9add-6490f24805f0.png)

## Struct HeapType
<pre><code>
template < class ItemType >
struct HeapType{
void ReheapDown( int root, int bottom);
void ReheapUp( int root, int bottom);

ItemType* elements; // Array to be allocated dynamically
int numElements;
}
</code></pre>

## ReheapDown
<pre><code>
// Root is the index of the node that may violate the heap order property
void HeapType < ItemType > :: ReheapDown( int root, int bottom ) // bottom : rightmost node in the last level
{ int maxChild;
  int rightChild;
  int leftChild;
  
  leftchild = root * 2 + 1;
  rightchild = root * 2 + 2;
  
  if(leftchild <= bottom){ // Is there leftchild? -> leftchild가 Array index 밖을 벗어나면 stop!
  else{
    // Find maxchild
    if (leftchild == bottom) // only one child
      maxchild = leftchild;
    else // two children
      maxchild = leftchild;
      }
  
  if (elements[ root ] < elements [ maxchild ])
      {
          Swap (elements[ root ] , elements [ maxchild ] );
          ReheapDown (maxChild, bottom); // Recursion -> Heap 순서를 재정렬!
       }
  }
}
</code></pre>
![image](https://user-images.githubusercontent.com/50229148/118811444-fd350a80-b8e7-11eb-8986-cf78664d557b.png)

## ReheapUp
<pre><code>
// bottom is the index of the node that may violate the heap order priority
void HeapType < ItemType > :: ReheapUp( int root, int bottom ) // bottom : rightmost node in the last level
{
    int parent;
    
    if (bottom > root) // tree isn't empty!
    {
    	parent = (bottom - 1) / 2;  
	if(elements[parent] < elements[bottom])
	{	
	    Swap( elements[parents], elements[bottom]);
	    ReheapUp(root, parent); // Recursion -> 계속해서 Heap 순서 재정렬!
 	}
    }
}
</code></pre>
![image](https://user-images.githubusercontent.com/50229148/118811456-00c89180-b8e8-11eb-9d3b-fb4c0f33a599.png)

## Removing largest element from the heap
1. Copy the bottom rightmost element to the root // Array의 마지막 index 원소를 root에 복사
2. Delete the bottom rightmost node
3. ReheapDown을 이용하여 힙 순서 재정렬!
![image](https://user-images.githubusercontent.com/50229148/118810999-73853d00-b8e7-11eb-80d1-e7ae7e12e5da.png)
![image](https://user-images.githubusercontent.com/50229148/118811008-754f0080-b8e7-11eb-917b-31cfef1aafca.png)
![image](https://user-images.githubusercontent.com/50229148/118811012-76802d80-b8e7-11eb-893c-d689b394f655.png)

## Insert new element into the heap
1. Insert the new element in th next bottom leftmost place // Array 끝(complete tree 가장 오른쪽)에 새로운 원소 삽입
2. ReheapUp을 이용하여 힙 순서 재정렬!
![image](https://user-images.githubusercontent.com/50229148/118811251-bfd07d00-b8e7-11eb-8dfc-f9a58541375c.png)
![image](https://user-images.githubusercontent.com/50229148/118811260-c19a4080-b8e7-11eb-8abe-83518dca7ce5.png)

## Priority Queue
- **우선순위 큐는 오직 highest-priority(ex. max or min) element만 언제나 접근 가능해야 한다**
<pre><code>
template < class ItemType >
TreeType<ItemType>::TreeType() {
	root = nullptr;
}</pre></code>

## Destructor
- **모든 노드를 방문하면서 delete를 해줘야 한다!**
- **PostOrder(left child -> right child -> parent) 순서로 방문하여 delete를 해야한다**
<pre><code>
template < class ItemType >
TreeType<ItemType>::~TreeType() {
	Destroy(root);
}

void Destroy(NodeType*& tree){
   if(tree != nullptr)
   // 왼족 -> 오른쪽 ->자기 자신 순서로 delete해야 한다!
   {	Destroy(tree->left);
   	Destory(tree->right);
	delete tree;
   }
}
</pre></code>

## bool IsEmpty, IsFull
<pre><code>
template<class ItemType>
inline bool TreeType<ItemType>::IsEmpty() const
{
	return (root == nullptr);
}

template<class ItemType>
inline bool TreeType<ItemType>::ISFull() const
{
	NodeType* location;
	try {
		location = new NodeType;
		delete location;
		return false;
	}
	catch (std::bad_alloc) { return true; }
}</code></pre>
