#include <iostream>
#define MAX 1001
using namespace std;

struct Node {
	int index;
	Node* next;
};

struct Queue {
	Node* front;
	Node* rear;
	int count; // 원소의 갯수
};

Node** a;
int vertex, edge, visited[MAX];

void addFront(Node* root, int index) {
	Node* temp = new Node;
	temp->index = index;
	temp->next = root->next;
	root->next = temp;
}

void queuePush(Queue* queue, int index) {
	Node* temp = new Node;
	temp->index = index;
	temp->next = NULL;
	if (queue->count == 0) { // queue is empty!
		queue->front = temp; // 비어있으면 front에 삽입
	}
	else {
		queue->rear->next = temp; // rear에 삽입
	}

	queue->rear = temp; // front에 삽입한 경우 때문
	queue->count++; // 갯수 증가
}

int queuePop(Queue* queue) {
	if(queue->count==0) // empty
	{
		cout << "EmptyQueue!";
	}

	Node* temp = queue->front;
	int index = temp->index;
	queue->front = temp->next; // front한칸 뒤로 이동!
	delete temp;
	queue->count--;
	return index;
}

void BFS(int start) {
	Queue q;
	q.front = q.rear = NULL;
	q.count = 0;
	queuePush(&q, start); // start index Queue 삽입
	visited[start] = 1; // 방문기록남김
	while (q.count != 0) {
		int x = queuePop(&q); // print current index 
		cout << x << " is visited!" << endl;
		
		Node* cur = a[x]->next; // next element
		while (cur != NULL) {
			int next = cur->index;
			if (!visited[next]) { // 다음번 원소를 처음 방문시
				queuePush(&q, next); // index를 queue에 삽입
				visited[next] = 1;
			}
			cur = cur->next;
		}
	}
}
int main() {
	cin >> vertex >> edge;
	a = new Node * [MAX];
	for (int i = 1; i <= vertex; i++) {
		a[i] = new Node;
		a[i]->next = NULL;
	}

	for (int i = 0; i < edge; i++) {
		int x, y; // x is from y is to index!
		cin >> x >> y;
		addFront(a[x], y);
		addFront(a[y], x);

	}
	BFS(1);
}