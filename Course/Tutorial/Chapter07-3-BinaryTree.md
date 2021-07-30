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

# Binary Search Tree interface 
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
#### 1,2번 경우(Delete 0 or 1 child)
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
#### 3번 경우(Delete 2 child)
* **Find predecessor(left subtree에서 가장 오른쪽(rightmost) Node! -> leftsub에서 가장 큰 원소) or 반대로 오른쪽에서 가장 작은 node!**
* 지워질 data를 predecessor로 대체
* delete predecessor node!

![image](https://user-images.githubusercontent.com/50229148/108042360-0a412400-7083-11eb-8f9d-77bcc17cb04b.png)
<pre><code>
void DeleteNode(TreeNode *& tree){
Itemtype Data; 
TreeNode * tempPtr = tree;
else{ // 기존 tree의 값은 getpredecessor 함수를 통해 얻은 새 data값으로 대입!
  GetPredecessor(tree->left,data);
  tree->info = data;
  Delete(tree->left,data);}
}

void GetPredecessor(TreeNode * tree, ItemType& data){ // Get rightmost node of left subtree
while(tree->right != NULL){
  tree = tree->right; data = tree->info; 
}

template< class ItemType >
void TreeType<ItemType>::Delete(TreeNode * &tree, ItemType item) // item을 tree에서 삭제
{
	if (item < tree->info) {
		Delete(tree->left, item);
	}
	else if (item > tree->info) {
		Delete(tree->right, item);
	}
	else { // Node found!
		DeleteNode(tree);
	}
}
	
template< class ItemType >
void TreeType<ItemType>::Delete(ItemType item)
{
   Delete(root, item);
}
</code></pre>
> **Function Print**
* **print items in tree from smallest to largest**
* size: tree의 nodes수
* **Base case : If tree = NULL, do nothing!**
* **General case : left subtree -> 본인 -> rigth subtree 순서로 Traverse!**
![image](https://user-images.githubusercontent.com/50229148/108045987-758cf500-7087-11eb-8b25-35fa1a340869.png)
<pre><code>
template<class ItemType>
void TreeType<ItemType>::PrintTree(std::ofstream& out) const
{
	if (tree != NULL) {
		PrintTree(root->left, out);
		out << root->Info;
		PrintTree(root->right, out);
	}
}</code></pre>
> **Constructor & Destructor**
<pre><code>
template<class ItemType>
TreeType<ItemType>::TreeType()
{root = NULL;}

template<class ItemType>
void Destroy(TreeNode<ItemType>*& tree) {
if (tree != NULL) {
	Destroy(tree->left);
	Destroy(tree->right);
	delete tree;}
}
	
template<class ItemType>
TreeType<ItemType>::~TreeType()
 { Delete(root);}
}

TreeType::TreeType(const TreeType& originalTree)
{CopyTree(root, originalTree.root);}

void CopyTree(TreeNode*& copy,const TreeNode* originalTree){
 if (originalTree == NULL)
    copy = NULL;
 else{
 copy = new TreeNode;
 copy-->info = originalTree --> info;
 CopyTree(copy-->left, originalTree -->left);
 CopyTree(copy-->right, originalTree -->right);}
}</code></pre>

## Binary Tree traverse (이진 트리 순회)
### 1) Inorder Traverse
* **왼쪽 -> 본인 -> 오른쪽**
<pre><code>
void Inorder(TreeNode * tree, QueType& InQue){
  if(tree != NULL){
    Inorder(tree->left, InQue);
    InQue.Enqueue(tree->info);
    Inorder(tree->right, InQue);}
}</code></pre>
### 2) Postorder Traverse
* **왼쪽 -> 오른쪽 -> 본인**
* good for deletion
<pre><code>
void PostOrder(TreeNode* tree, QueType& PostQue){
 if(tree != NULL){
 PostOrder(tree->left, PostQue);
 PostOrder(tree->right, PostQue);
 PostQue.Enqueue(tree->info);}
}</code></pre>
### 3) Preorder Traverse
* **본인 -> 왼쪽 -> 오른쪽**
<pre><code>
void PreOrder(TreeNode* tree, QueType& preQue){
  if(tree != NULL){
  preQue.Enqueue(tree->info);
  preOrder(tree->left, preQue);
  preOrder(tree->right, preQue);}
}</code></pre>
#### Modification of Class TreeType
<pre><code>
enum OrderType{PRE_ORDER, IN_ORDER, POST_ORDER}
class TreeType{
  public:
  // Same as before
  private:
    TreeNode * root;
    QueType preQue;
    QueType inQue;
    QueType postQue;
};</code></pre>
> **Function ResetTree**
* calls function to create a queue of the tree elements in the desired order
<pre><code>
void TreeType::ResetTree(orderType order){
  switch(order){
    case PRE_ORDER : PreOrder(root,preQue); break;
    case IN_ORDER : InOrder(root, inQue); break;
    case POST_ORDER : PostOrder(root, postQue); break;
  }
}</code></pre>
> **Function GetNextItem**
<pre><code>
void TreeType::GetNextItem(ItemType& item, orderType order, bool& finished){
  finished = false;
  switch(order){
    case PRE_ORDER : PreQue,Dequeue(item);
    	  	     if(preQue.empty())
		       finished = true;
		     break;
    case IN_ORDER : InQue,Dequeue(item);
    	  	     if(inQue.empty())
		       finished = true;
		     break;
    case POST_ORDER : PostQue,Dequeue(item);
    	  	     if(postQue.empty())
		       finished = true;
		     break;
     }
} </code></pre>
# Iterative version
<pre><code>
void FindNode(TreeNode* tree, ItemType item, TreeNode* nodePtr, TreeNode* parentPtr) { 
	nodePtr = tree;
	parentPtr = nullptr; // tree -> root
	bool found = false;
	while (nodePtr != NULL && !found) {
		if (item < nodePtr->info) {
			parentPtr = nodePtr;
			nodePtr = nodePtr->left;
		}
		else if (item > nodePtr->info) {
			parentPtr = nodePtr;
			nodePtr = nodePtr->right;
		}
		else {
			found = true;
		}
	}
}

void TreeType::InsertItem(ItemType item) {
	TreeNode* newnode;
	TreeNode* nodeptr;
	TreeNode* parentptr;
	newnode = new TreeNode;
	newnode->info = item;
	newnode->left = NULL;
	newnode->right = NULL;
	FindNode(root, item, nodeptr, parentptr); 
	if (parentptr == NULL) // Empty!
		root = newnode;
	else if (item < parentptr->info) 
		parentptr->left = newnode; // 기준보다 작으면 왼쪽에 attach
	else
		parentptr->right = newnode; // 기준보다 크면 오른쪽에 attach
}

void TreeType::DeleteItem(ItemType item) {
	TreeNode* nodeptr;
	TreeNode* parentptr;
	FindNode(root, item, nodeptr, parentptr);
	if (nodeptr == root)
		DeleteNode(root);
	else {
		if (parentptr->left == nodeptr)
			DeleteNode(parentptr->left);
		else
			DeleteNode(parentptr->right);
	}
}</code></pre>
![image](https://user-images.githubusercontent.com/50229148/108075080-47baa700-70ad-11eb-8cfa-29f2b45cb17f.png)
![image](https://user-images.githubusercontent.com/50229148/108075514-cd3e5700-70ad-11eb-85f0-ddea2a6546c5.png)

## Array representation
* **Tree.nodes[index]**
* **left child : tree.node[ index * 2 + 1 ]**
* **right child : tree.node[ index * 2 + 2 ]**
* **its parent : tree.node[ (index-1) / 2]**
![image](https://user-images.githubusercontent.com/50229148/108075456-bb5cb400-70ad-11eb-87cc-3e718677af77.png)
