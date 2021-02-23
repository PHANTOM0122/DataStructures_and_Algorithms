#include <iostream>

using namespace std;\

struct Node {
	int index;
	int disance;
	Node* next;
};

// 연결리스트 삽입 함수
void addFront(Node* root, int index, int distance) { 
	Node* node = new Node;
	node->index = index;
	node->disance = distance;
	node->next = root->next;
	root->next = node;
}

// 연결리스트 출력 함수
void showAll(Node* root) {
	Node* cur = root->next;
	while (cur != NULL) {
		cout << cur->index << "(거리: " << cur->disance << ")";
		cur = cur->next;
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	Node** a = new Node* [n];

	for (int i = 1; i <= n; i++) {
		a[i] = new Node;
		a[i]->next = NULL;
	}

	for (int i = 0; i < m; i++) {
		int x, y, distance;
		cin >> x >> y >> distance;
		addFront(a[x], y, distance);
	}

	for (int i = 1; i <= n; i++) {
		cout << "원소 [" << i << "]";
		showAll(a[i]);
		cout << endl;
	}

	return 0;
}