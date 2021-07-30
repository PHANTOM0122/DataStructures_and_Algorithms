Graph, DFS, BFS
================
* **그래프란 사물을 정점(vertex)와 간선(Edge)로 나타내기 위한 도구이다**
* **그래프는 2가지 방식으로 구현할 수 있다**
## 1. 인접행렬(Adjacency Matrix)
* **2차원 배열을 사용하는 방식**
* **모든 정점들의 연결 여부를 저장하여 O(N2)의 공간을 요구. 주 정점이 서로 연결되있는지 확인하기 위해서는 O(1).**
![image](https://user-images.githubusercontent.com/50229148/108811059-de2c2280-75ef-11eb-83fe-869752c05edb.png)
* **Undirected Graph: 모든 edge가 방향성을 가지지 않는 그래프**
* **Unweighted Graph: 모든 edge에 가중치가 없는 그래프**
#### Exmaple) Undirected & Unweighted Graph
<pre><code>
int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}</code></pre>

## 2. 인접리스트(Adjacency list)
* **연결된 edge정보만을 저장하여 O(E)의 공간을 요구하므로 공간 효율성이 우수하지만 두 정젖ㅁ이 서로 연결되있는지 확인하기 위해 O(N).**
* **Directed Graph : 모든 간선이 방향을 가지는 그래프**
* **Weighted Graph : 모든 간선에 가중치가 있는 그래프**
#### Exmaple) Directed & Weighted Graph
<pre><code>
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
}</code></pre>
![image](https://user-images.githubusercontent.com/50229148/108811047-d79dab00-75ef-11eb-8fd7-950e9370d6de.png)
## DFS
* **탐색을 함에 있어서 보다 깊은 것을 우선적으로 탐색하는 알고리즘이다.**
* 전체 노드를 맹목적으로 탐색하고자 할 때 사용
* **Stack에 기반하여 구할 수 있다**
* **stack을 사용하지 않고도 재귀함수를 이용하여 구할 수 있으며, O(N)의 시간이 소요된다**
> **DFS steps**
1) **탐색 시작 노드를 stack에 삽입하고 방문처리**
2) **스택의 최상단 노드에 방문하지 않은 인접 노드가 있으면 그 노드를 스택에 넣고 방문처리. 방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 꺼낸다**
3) 2번의 과정을 더 이상 수행할 수 없을 때까지 반복한다(재귀)
![image](https://user-images.githubusercontent.com/50229148/108818549-e63e8f00-75fc-11eb-9ea7-d235132f18fb.png)
<pre><code>
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
} </code></pre>
![image](https://user-images.githubusercontent.com/50229148/108818158-56004a00-75fc-11eb-9d0b-4c1ab77aabff.png)

![image](https://user-images.githubusercontent.com/50229148/108818018-20f3f780-75fc-11eb-84d1-893db093e0c8.png)

## BFS
* **탐색을 함에 있어서 보다 너비를 우선적으로 탐색하는 알고리즘이다.**
* 전체 노드를 맹목적으로 탐색하고자 할 때 사용
* **Queue에 기반하여 구할 수 있다**
* **고급 그래프 탐색 알고리즘에 자주 활용된다!**
* **O(N)의 시간 복잡도를 가진다**
> **BFS steps**
1) **탐색 시작 노드를 큐에 삽입하고 방문 처리를 한다**
2) **큐에서 노드를 꺼내 해당 노드의 인접 노드 중에서 방문하지 않은 노드들을 모두 큐에 삽입하고, 방문 처리를 한다**
3) 2번의 과정을 더 이상 수행할 수 없을 때까지 반복한다(재귀)

![image](https://user-images.githubusercontent.com/50229148/108820486-97462900-75ff-11eb-947e-8980080d6b99.png)

<pre><code>
struct Queue {
	Node* front;
	Node* rear;
	int count; // 원소의 갯수
};

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
}</code></pre>
![image](https://user-images.githubusercontent.com/50229148/108822594-a4184c00-7602-11eb-8479-2b4404468f16.png)
