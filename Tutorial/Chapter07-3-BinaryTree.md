Binary Tree(이진트리)
======================
* **모든 노드가 최대로 두개의 자식 노드를 갖는 순서화된 트리**
> Binary Tree의 특성
  * **각 노드는 최대 2개의 자식을 갖는다**
  * **각 노드는 고유한 path(부모와의 관계)를 가지고 있다. -> path가 두개면 tree가 아니다**
  * **왼쪽 자식이 오른쪽 자식보다 먼저 오도록 순서화되었다(left subtree < parent < right subtree)**

## 7.3-1) Binary Tree ADT
* **p.left(): p의 왼쪽 자식을 반환한다. p가 leave이면 error**
* **p.right(): p의 오른쪽 자식을 반환한다. p가 leave이면 error**
* **p.parent(): p의 부모를 반환한다. p가 root면 error**
* **p.isRoot(): Root node?**
* **p.isExternal(): Leave node?**

## 7.3-2) Binary Tree interface 
> ### 강의 기준 
<pre><code>
template <class ItemType>
struct NodeType {
	ItemType Info;
	NodeType* next;
};

template <class ItemType>
struct TreeNode {
	ItemType Info;
	TreeNode* left;
	TreeNode* right;
};

enum OrderType { PRE_ORDER, IN_ORDER, POST_ORDER };

template <class ItemType>
class TreeType {
public:
	TreeType();
	~TreeType();
	TreeType(const TreeType<ItemType>&); // Deep copy를 위한 생성자
	void operator=(const TreeType<ItemType>&); // copy를 위한 연산자
	void makeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	int LengthIs() const;
	void RetrieveItem(ItemType&, bool& found);
	void Insert(ItemType);
	void Delete(ItemType);
	void ResetTree(OrderType);
	void GetNextItem(ItemType&, OrderType, bool&);
	void PrintTree(std::ofstream&) const;
private:
	TreeNode<ItemType>* root;
 };</code></pre>
> **IsFull() & IsEmpty()**
 <pre><code>
 template<class ItemType>
bool TreeType<ItemType>::IsEmpty() const
{
	return (root == nullptr);
}

template<class ItemType>
bool TreeType<ItemType>::IsFull() const
{
	// 새로운 Node가 만들어지면 not Full
	NodeType* tempPtr;
	try {
		tempPtr = new NodeType;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception) {
		return true;
	}
 }</pre></code>
> **Function countNodes**
* Recursive fucntion
* Base: **tree is empty**
* General: **CountNodes(left) + CountNodes(right) + 1**
<pre><code>
template<class ItemType>
int TreeType<ItemType>::LengthIs() const
{if (root == NULL)
		return 0;
	else {
		return LengthIs(root->left) + LengthIs(root->right) + 1;}
}</code></pre>
![image](https://user-images.githubusercontent.com/50229148/108039702-cac50880-707f-11eb-81e9-743d7328a313.png)
> **Function RetrieveItem**
* Recursive fucntion
* Base: **1)item found! 2)Tree is empty(item not found!)**
* General: **search left or right subtrees**
<pre><code>
template<class ItemType>
void TreeType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{	if (root == NULL) // base Case 2 - not found!
		found = false;
	else if (item < root->Info) // General case - 기준보다 작을때
		RetrieveItem(root->left, found); 
	else if (item > root->Info) // General case - 기준보다 클때
		RetrieveItem(root->right, found);
	else { // base case 1 - Found!
		item = root->Info;
		found = true;}
}</code></pre>
![image](https://user-images.githubusercontent.com/50229148/108040099-3c04bb80-7080-11eb-8773-dda4b9e69a2b.png)
> **Function InsertItem**
* **Refrence type으로 TreeNode 받는 것!**
<pre><code>
template<class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item) {
	if (tree == NULL) { // Insertion place not found!
		tree = new TreeNode<ItemType>;
		tree->right = NULL;
		tree->left = NULL;}
	else if (item < tree->Info)
		Insert(tree->left, item);
	else 
		Insert(tree->right, item);}
template<class ItemType>
void TreeType<ItemType>::Insert(ItemType item)
{Insert(root, item);}
</code></pre>
![image](https://user-images.githubusercontent.com/50229148/108040625-e250c100-7080-11eb-80e9-fc178243e2fe.png)
> **Function DeleteItem**
* 다음과 같은 3가지 상황을 고려
1) Deleting a leaf
![image](https://user-images.githubusercontent.com/50229148/108040847-28a62000-7081-11eb-8f0c-f76e63405a0a.png)
2) Deleting a node with only one child
![image](https://user-images.githubusercontent.com/50229148/108040922-3f4c7700-7081-11eb-9c13-7fc69f916654.png)
3) Deleting a node with two children
![image](https://user-images.githubusercontent.com/50229148/108040948-48d5df00-7081-11eb-989f-e5b4415eeb20.png)
* **1,2번 경우(Delete 0 or 1 child)**
![image](https://user-images.githubusercontent.com/50229148/108041852-72dbd100-7082-11eb-9d99-336ad444fcd2.png)
<pre><code>
void DeleteNode(TreeNode *& tree){
Itemtype Data;
TreeNode * tempPtr;
tempPtr = tree;
if(tree->left == NULL){ 
 tree = tree->right; delete tempPtr;}
 else if(tree->right == NULL){
 tree = tree->left; delete tempPtr;}
}}</code></pre>
* **3번 경우(Delete 2 child)**
