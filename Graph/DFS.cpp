#include <iostream>
#include <stack>
#define MAX_SIZE 1001

using namespace std;

struct Node {
	int index;
	Node* next;

};

Node** a;
int vertex, edge, visited[MAX_SIZE];

void addFront(Node* root, int index) {
	Node* node = new Node;
	node->index = index;
	node->next = root->next;
	root->next = node;
}

void DFS(int index) { 
	if (visited[index]) return;
	else {
		visited[index] = 1; // 방문 O
		cout << index << " is visited!" << endl;
		Node* cur = a[index]->next; 
		while (cur != NULL) {
			int nextindex = cur->index; // 다음 item의 index
			DFS(nextindex);
			cur = cur->next; // Recursion
		}
	}
}

int main() {
	cin >> vertex >> edge;
	a = new Node* [MAX_SIZE];
	for (int i = 1; i <= vertex; i++) {
		a[i] = new Node;
		a[i]->next = NULL;
	}

	for (int i = 0; i < edge; i++) {
		int x, y; // x is itself index, y is connected Node's index
		cin >> x >> y;
		addFront(a[x], y); // x, y is connected
		addFront(a[y], x); // Since it's directed Graph!
	}
	DFS(1); // Start with element's index is 1
}