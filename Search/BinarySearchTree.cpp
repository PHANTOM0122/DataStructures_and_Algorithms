#include <iostream>

using namespace std;

struct Node;
Node* insertNode(Node* root, int data);
Node* searchNode(Node* root, int data);
Node* findMinNode(Node* root);
Node* deleteNode(Node* root, int data);
void inorder(Node* root);


int main() {
	Node* root = nullptr;
	root = insertNode(root, 30);
	root = insertNode(root, 17);
	root = insertNode(root, 48);
	root = insertNode(root, 5);
	root = insertNode(root, 23);
	root = insertNode(root, 37);
	root = insertNode(root, 50);
	root = deleteNode(root, 23);
	inorder(root);
}


struct Node {
	int data;
	Node* leftchild;
	Node* rightchild;
};

Node* insertNode(Node* root, int data) {
	if (root == NULL) { // when root is emtpy!
		root = new Node;
		root->data = data;
		root->leftchild = root->rightchild = NULL;
		return root;
	}

	else {
		if (root->data > data) { // left child!
			root->leftchild = insertNode(root->leftchild, data);
		}
		else {
			root->rightchild = insertNode(root->rightchild, data);
		}
	}
	return root;
}

Node* searchNode(Node* root, int data)
{
	if (root == NULL) { return NULL; } // Not found!
	if (root->data == data) { return root; }
	else if (root->data > data) { return searchNode(root->leftchild, data); }
	else { return searchNode(root->rightchild, data); }
}

Node* findMinNode(Node* root)
{
	Node* node = root;
	while (node->leftchild != NULL) {
		node = node->leftchild; // find leftmost node of last level!
	}
	return node;
}

Node* deleteNode(Node* root, int data)
{
	Node* temp = NULL;
	if (root == NULL) return NULL; // empty!
	if (root->data > data) { // left child
		root->leftchild = deleteNode(root->leftchild, data);
	}
	else if (root->data < data) { // right child
		root->rightchild = deleteNode(root->rightchild, data);
	}
	else { // root->data = data
		if (root->leftchild != NULL && root->rightchild != NULL) { // have 2 child
			temp = findMinNode(root->rightchild); // root data 바로 다음 order data
			root->data = temp->data;
			root->rightchild = deleteNode(root->rightchild, temp->data); // temp를 삭제한 rightchild Node 갱신!
		}
		else { // have less than 1 child
			temp = (root->leftchild != NULL) ? root->leftchild : nullptr;
			delete root;
			return temp;
		}
	}

	return root;
}

void inorder(Node* root) {
	if (root == NULL) return;
	inorder(root->leftchild);
	cout << root->data << ' ';
	inorder(root->rightchild);
}

