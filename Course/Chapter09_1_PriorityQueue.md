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

## ReheapUp
<pre><code>
</code></pre>

## 
<pre><code>
</code></pre>

## 
<pre><code>
</code></pre>

## constructor
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
