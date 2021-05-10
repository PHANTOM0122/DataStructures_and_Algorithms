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

## constructor & destructor
<pre><code>
template < class ItemType >
TreeType<ItemType>::TreeType() {
	root = nullptr;
}

template < class ItemType >
TreeType<ItemType>::~TreeType() {
	MakeEmpty();
}</pre></code>

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

3) two child를 가진 node를 지우는 경우

<pre><code>

</code></pre>

## InsertItem
- **parameter를 무조건 reference type으로 넣어주어야 하는 것이 가장 중요하다!**
<pre><code>

</code></pre>
