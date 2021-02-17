#include <fstream>
#include "Quetype.h"

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
};

template<class ItemType>
inline TreeType<ItemType>::TreeType()
{
	root = nullptr;
}

template<class ItemType>
void Destroy(TreeNode<ItemType>*& tree) {
	if (tree != NULL) {
		Destroy(tree->left);
		Destroy(tree->right);
		delete tree;
	}
}
template<class ItemType>
TreeType<ItemType>::~TreeType()
{
	Delete(root);
}

template<class ItemType>
TreeType<ItemType>::TreeType(const TreeType<ItemType>&)
{
}

template<class ItemType>
void TreeType<ItemType>::operator=(const TreeType<ItemType>&)
{
}

template<class ItemType>
void TreeType<ItemType>::makeEmpty()
{
}

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
}

template<class ItemType>
int TreeType<ItemType>::LengthIs() const
{
	if (root == NULL)
		return 0;
	else {
		return LengthIs(root->left) + LengthIs(root->right) + 1;
	}
}

template<class ItemType>
void TreeType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
	if (root == NULL) // base Case 2 - not found!
		found = false;
	else if (item < root->Info) // General case - 기준보다 작을때
		RetrieveItem(root->left, found); 
	else if (item > root->Info) // General case - 기준보다 클때
		RetrieveItem(root->right, found);
	else { // base case 1 - Found!
		item = root->Info;
		found = true;
	}
}

template<class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item) {
	if (tree == NULL) { // Insertion place not found!
		tree = new TreeNode<ItemType>;
		tree->right = NULL;
		tree->left = NULL;
	}
	else if (item < tree->Info)
		Insert(tree->left, item);
	else 
		Insert(tree->right, item);
}

template<class ItemType>
void TreeType<ItemType>::Insert(ItemType item)
{
	Insert(root, item);
}


template<class ItemType>
void TreeType<ItemType>::Delete(ItemType item)
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

template<class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree);

template<class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item);

template<class ItemType>
void TreeType<ItemType>::Delete(ItemType item)
// Calls recursive function Delete to delete item from tree.
{
	Delete(root, item);
}

template<class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item)
// Deletes item from tree.
// Post:  item is not in tree.
{
	if (item < tree->info)
		Delete(tree->left, item);   // Look in left subtree.
	else if (item > tree->info)
		Delete(tree->right, item);  // Look in right subtree.
	else
		DeleteNode(tree);           // Node found; call DeleteNode.
}
.
+
void GetPredecessor(TreeNode * tree, ItemType & data);

template<class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree)

{
	ItemType data;
	TreeNode* tempPtr;

	tempPtr = tree;
	if (tree->left == NULL)
	{
		tree = tree->right;
		delete tempPtr;
	}
	else if (tree->right == NULL)
	{
		tree = tree->left;
		delete tempPtr;
	}
	else
	{
		GetPredecessor(tree->left, data);
		tree->info = data;
		Delete(tree->left, data);  // Delete predecessor node.
	}
}
template<class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data)
// Sets data to the info member of the right-most node in tree.
{
	while (tree->right != NULL)
		tree = tree->right;
	data = tree->info;
}


template<class ItemType>
void TreeType<ItemType>::ResetTree(OrderType)
{
}

template<class ItemType>
void TreeType<ItemType>::GetNextItem(ItemType&, OrderType, bool&)
{
}

template<class ItemType>
void TreeType<ItemType>::PrintTree(std::ofstream& out) const
{
	if (tree != NULL) {
		PrintTree(root->left, out);
		out << root->Info;
		PrintTree(root->right, out);
	}
}
