#pragma once

#include <fstream>

template <class ItemType>
struct TreeNode;

enum OrderType{PRE_ORDER, IN_ORDER, POST_ORDER};

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

template <class ItemType>
struct TreeNode {
	ItemType Info;
	TreeNode* left;
	TreeNode* right;
};