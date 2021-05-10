Binary Search Tree
=================================
- Tree에서 부모 노드는 1개만 존재한다

## Binary Tree가 되기 위한 조건
1. 각 노드는 자식 노드를 최대 2개까지 가질 수 있다
2. root로부터 각 노드까지 가는 길은 unique한 way 1개만 존재한다
- binary tree의 search time complexity -> O(N)

## Full Tree의 height을 이용하여 node의 갯수 구하기
**h = log2(N+1) -> O(logN)**

## Binary Search Tree
- Binary Tree보다 작은 개념이다
- 다음과 같은 조건을 만족해야한다
1) 왼쪽 subtree는 root보다 작다
2) 오른쪽 subtree는 root보다 크다
- Binary search Tree의 search time complexity -> O(log2N)

## NodeType for Tree Node
![image](https://user-images.githubusercontent.com/50229148/116846684-d1493200-ac23-11eb-9568-5822e6119eb8.png)
<pre><code>
template < class ItemType >
struct NodeType {
	ItemType info;
	NodeType<ItemType>* left;
	NodeType<ItemType>* right;
};</code></pre>

## TreeType class
<pre><code>
template < class ItemType >
class TreeType {
public:
	TreeType();
	~TreeType();
	TreeType(const TreeType< ItemType >&); // Deep copy constructor
	void operator=(const TreeType< ItemType >&);
	void MakeEmpty();
	bool IsEmpty() const;
	bool ISFull() const;
	int LengthIs() const;
	void RetrieveItem(ItemType&, bool&);
	void InsertItem(ItemType);
	void DeleteItem(ItemType);
	void ResetTree(OrderType);
	void GetNextItem(ItemType&, OrderType, bool&);
	void PrintTree(ofstream&) const;
private:
	TreeNode<ItemType>* root;
};
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
   if(tree == nullptr)
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

## Length함수
- **Recursion 방법을 이용하여 노드 수를 구한다**
<pre><code>
// Recursion을 이용하여 count Node!
template<class ItemType>
inline int TreeType<ItemType>::LengthIs() const
{
	return countNodes(root);
}

template<class ItemType>
inline int CountNodes(NodeType<ItemType>* root)
{
	if (root == nullptr) { return 0; }
	else {
		return CountNodes(root->left) + CountNodes(root->right) + 1;
	}
}</code></pre>

## RetrieveItem
- **이 역시 마찬가지로 recursion을 사용하여 판단한다**
- leaf까지 갔지만 없는 경우 base case!
<pre><code>
template<class ItemType>
inline void TreeType<ItemType>::RetrieveItem(ItemType& target, bool& found)
{
	RetrieveItem(root, target, found);
}

template<class ItemType>
void RetrieveItem(NodeType<ItemType>* root, ItemType& target, bool& found)
{
	if (tree == nullptr) { found = false; }
	else if (target < root->info)
		RetrieveItem(root->left, target, found);
	else if (target > root->info)
		RetrieveItem(root->right, target, found);
	else // base : found!
	{
		item == root->info;
		found = true;
	}
	}</code></pre>
![image](https://user-images.githubusercontent.com/50229148/116847489-9b0cb200-ac25-11eb-9d6f-1e9002c0b1e5.png)

## InsertItem
- **parameter를 무조건 reference type으로 넣어주어야 하는 것이 가장 중요하다!**
<pre><code>
template<class ItemType>
inline void TreeType<ItemType>::InsertItem(ItemType item)
{
	InsertItem(root, item);
}

template<class ItemType>
void InsertItem(NodeType<ItemType>*& root, ItemType item)
{
	if (root == nullptr) { // 처음으로 삽입 
		root = new NodeType;
		root->info = item;
		root->right = nullptr;
		root->left = nullptr;
	}
	else if (item < root->info) {
		InsertItem(root->left, item);
	}
	else {
		InsertItem(root->right, item);
	}
}</code></pre>
![image](https://user-images.githubusercontent.com/50229148/116847457-87614b80-ac25-11eb-95a7-8a6c94b14ea2.png)
	
## DeleteItem
**아래와 같은 3가지 경우를 고려해야 한다**
#### 1) Leaf node를 지우는 경우
![image](https://user-images.githubusercontent.com/50229148/117602701-4bca0280-b18c-11eb-91f5-71bc98068a4b.png)
- **간단히 delete leaf node만 하면 된다**

#### 2) one child를 가진 node를 지우는 경우
![image](https://user-images.githubusercontent.com/50229148/117602787-7f0c9180-b18c-11eb-8562-864a0e1e8b96.png)
- **parent에 자기 자식을 연결시키면 된다**

#### 3) two child를 가진 node를 지우는 경우
![image](https://user-images.githubusercontent.com/50229148/117602861-a3686e00-b18c-11eb-8f6e-aa8eb27e2bab.png)
- **Left substree의 max or Right subtree의 min을 Deleting node로 대체한다**

<pre><code>
// Function GetPredecessor : left subtree의 maxitem을 찾는 역학을 한다
template < class ItemType >
void GetPredecessor(NodeType< ItemType >* tree, ItemType& data) {
	while (tree->right != NULL)
		tree = tree->right; // move tree Ptr to most right element of Tree!
	data = tree->info;
}

// Function DeleteNode : Getpredecessor에서 찾은 위치의 노드를 제거하고 info를 treePtr에서의 info로 대체하는 역할을 한다.
template< class ItemType >
void DeleteNode(NodeType< ItemType >*& tree) {
	
	ItemType data;
	NodeType* tempPtr;
	tempPtr = tree;
	
	// 0 or 1 child
	if (tree->left == NULL) { 
		tree = tree->right; // move to right child
		delete tempPtr;
	}

	else if (tree->right == NULL) { 
		tree = tree->left; // move to left child
		delete tempPtr; 
	}

	// 2 children
	else {
		Getpredecessor(tree->left, data); // left subtree의 max item을 찾는다!
		tree->info = data;
		Delete(tree->left, data);
	}
}

// Function Delete : Recursive하게 
template < class ItemType >
void Delete (NodeType< ItemType >*& tree, ItemType item) {
	// Removes item from tree!!
	if (item < tree->info)
		Delete(tree->left, item);
	else if (item > tree->info)
		Delete(tree->right, item);
	else
		DeleteNode(tree); // Node found!
}

template<class ItemType>
inline void TreeType<ItemType>::DeleteItem(ItemType data)
{
	Delete(root, data);
}

</code></pre>

## printItem
- **Inorder(left child -> parent -> right child) 순서로 print 하는 것이 point!**
![image](https://user-images.githubusercontent.com/50229148/117609817-9f901800-b19b-11eb-9ed3-39f55cabb48b.png)
<pre><code>
template< class ItemType >
void PrintTree(NodeType< ItemType > tree, ofstream& out) {
	
	// Inorder traverse is important!
	if (tree != NULL) {
		PrintTree(tree->left.out); // left child
		out << tree->info; // tree itself
		PrintTree(tree->right.out); // right child
	}
}

template< class ItemType >
inline void TreeType< ItemType >::PrintTree(ofstream& out) const
{
	PrintTree(root, out);
}
</code></pre>

## Copy Constructor
- **모든 노드를 일일이 방문하면서 복사를 진행해야 한다**
<pre><code>
/// <Copy constructor>
template < class ItemType >
void CopyTree(NodeType < ItemType >*& copy, const NodeType < ItemType >* originalTree) {
	if (originalTree == NULL)
		copy = NULL;
	else {
		copy = new NodeType< ItemType >;
		copy->info = originalTree->info;
		CopyTree(copy->left, originalTree->left);
		CopyTree(copy->right, originalTree->right);
	}
}

template < class ItemType >
TreeType<ItemType>::TreeType(const TreeType< ItemType >& originalTree) {
	CopyTree(root, originalTree.root);
}</code></pre>

## Tree Traversal
- **tree의 모든 노드를 방문하는 순서이다**
#### 1) Inorder
- **left -> right -> parent** 순서이다
<pre><code>
template< class ItemType >
void Inorder(NodeType< ItemType >* tree, QueueType<ItemType>& InQueue) {
	if (tree != NULL) { // base Case : tree == nullptr!
		Inorder(tree->left, InQueue);
		InQueue.Enqueue(tree->info);
		Inorder(tree->right);
	}
}</code></pre>
![image](https://user-images.githubusercontent.com/50229148/117611366-51304880-b19e-11eb-81d2-2ba3e1d6cbde.png)

#### 2) Postorder
- **left child -> right child -> parent 순서이다**
- Useful with binary tree!
<pre><code>
template< class ItemType >
void Postorder(NodeType< ItemType >* tree, QueueType<ItemType>& postQueue) {
	if (tree != NULL) { // base Case : tree == nullptr!
		Postorder(tree->left, postQueue);
		Postorder(tree->right, postQueue);
		postQueue.Enqueue(tree->info);
	}
}</code></pre>
![image](https://user-images.githubusercontent.com/50229148/117611628-c8fe7300-b19e-11eb-81b6-18d530e15590.png)

#### 3) Preorder

