Graph
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
