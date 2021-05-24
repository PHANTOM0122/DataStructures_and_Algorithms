Graph
=============
- **A data structure consists of nodes(vertices/vertex) and a set of edges that relate the nodes to each other**
- Set of edges describes relationship among vertices
- **Edge가 방향성이 있으면 directed, 없으면 undirected라 부른다**
- Tree is a special case of graph
- complete directed graph edge 수 : N(N-1) / Undirected graph : N(N-1)/2
- **Weighted Graph : a graph in which edge carries a value**

# Graph implementation
1) **Adjacency Matrix : 1D array -> to represent the vertices / 2D array -> to represent edges**
![image](https://user-images.githubusercontent.com/50229148/119369239-e8dd7d00-bcee-11eb-9620-3a92f0450ea4.png)

## Graph specification based on adjacency matrix representation
<pre><code>
template < class VertexType >
class GraphType {
public:
	GraphType(int maxVertex);
	~GraphType();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void AddVertex(VertexType);
	void AddEdge(VertexType startVertex, VertexType endVertex, int weight);
	int WeightIs(VertexType startVertex, VertexType endVertex);
	// Traverse!
	void GetToVertices(VertexType, QueueType<VertexType>&);
	void ClearMarks();
	void MarkVertex(VertexType);
	bool IsMarked(VertexType) const;
private:
	int numVertices;
	int maxVertices;
	VertexType* vertices;
	int** edges;
	bool* marks;
};

// Constructor
template < class VertexType >
GraphType< VertexType >::GraphType(int maxV) {
	numVertices = 0;
	maxVertices = maxV;
	vertices = new VertexType[maxV];
	edges = new int[maxV];
	for (int i = 0; i < maxV; i++)
		edges[i] = new int[maxV];
	marks = new bool[maxV];
}

// Destructor
template < class VertexType >
GraphType< VertexType >::~GraphType() {
	
	delete[] vertices;
	for (int i = 0; i < maxVertices; i++)
		delete[] edges[i];
	delete[] edges;
	delete[] marks;
}

template < class VertexType >
void GraphType< VertexType >::AddVertex(VertexType vertex) 
{
	vertices[numVertices] = vertex;

	for (int index = 0; index < numVertices; index++) {
		edges[numVertices][index] = NULL_EDGE;
		edges[index][numVertices] = NULL_EDGE;
	}
	numVertices++;
}

template < class VertexType >
void GraphType< VertexType >::AddEdge(VertexType fromVertex, VertexType toVertex, int weight) {
	
	int row;
	int column;

	row = IndexIs(vertices, fromVertex);
	col = IndexIs(vertices, toVertex);
	edges[row][col] = weight;
}

template < class VertexType >
int GraphType< VertexType >::WeightIs(VertexType fromVertex, VertexType toVertex) {
	int row;
	int col;

	row = IndexIs(vertices, fromVertex);
	col = IndexIs(vertices, toVertex);
	return edges[row][col];
}

template < class VertexType >
void GraphType < VertexType >::GetToVertices(VertexType vertex, QueueType<VertexType>& advertexQ) {

	int fromIndex;
	int toIndex;

	fromIndex = IndexIs(vertices, vertex); // 주어진 vertices의 index를 반환
	for (toIndex = 0; toIndex < numVertices; toIndex++)
		if (edges[fromIndex][toIndex] != NULL_EDGE)
			advertexQ.Enqueue(vertices[toIndex]);
}

template<class VertexType>
inline void GraphType<VertexType>::ClearMarks()
{
	for (int i = 0; i < numVertices; i++)
		vertices[i] = false;
}

template<class VertexType>
inline void GraphType<VertexType>::MarkVertex(VertexType item)
{
	marks[IndexIs(vertices, item)] == true;
}

template<class VertexType>
inline bool GraphType<VertexType>::IsMarked(VertexType target) const
{
	return marks[IndexIs(vertices, target)] == true;
}
</code></pre>

2) **Adjacency List(Linked-List) : 1D array -> to represent the vertices**
![image](https://user-images.githubusercontent.com/50229148/119369443-25a97400-bcef-11eb-8981-f969873f47ce.png)
- **구현 시험 문제에 출제 가능**

# Graph Searching
## 1) Depth-First-Search(DFS)
- Visit all nodes in branch to its deepest point before moving up(Travel as far as you can down a path)
- 자식부터 먼저 봐야기 때문에 **Stack**을 사용한다
#### Implementation
<pre><code>
template < class VertexType >
void DepthFirstSearch(GraphType< VertexType > graph, VertexType startVertex, VertexType endVertex) {

	StackType< VertexType > stack;
	QueueType< VertexType > vertexQ;

	bool found = false;
	VertexType vertex;
	VertexType item;

	graph.ClearMarks();
	stack.Push(startVertex);
	do {
		stack.Pop(vertex);
		
		if (vertex == endVertex)
			found = true; // end까지 도달하는 경우
		
		else {	
			if (!graph.IsMarked(vertex)) { // 방문한 적이 없는 경우
				graph.MarkVertex(vertex); // 방문 기록 남기기
				graph.GetToVertices(vertex, vertexQ); // Queue에 먼저 자식들을 넣는다
			}

			// Queue의 원소들을 stack에 push!
			while(!vertexQ.IsEmpty()){
				vertexQ.Dequeue(item);
				if (!graph.IsMarked(item)) // 방문 기록 확인!
					stack.Push(item);
			}
		}
	} while (!stack.IsEmpty() && !found);

	if (!found)
		cout << "Path not found!" << endl;
}
</code></pre>
![image](https://user-images.githubusercontent.com/50229148/119370225-019a6280-bcf0-11eb-981d-8d4241d694a7.png)
![image](https://user-images.githubusercontent.com/50229148/119370237-04955300-bcf0-11eb-836c-fd8f5c4edc71.png)
![image](https://user-images.githubusercontent.com/50229148/119370249-065f1680-bcf0-11eb-8680-cc1b66ab3490.png)

## 2) Breadth-First-Search(BFS)
- Visit all the nodes on one level before going to next level
- **내려가기 전 옆부터 보고 가야한다는 얘기**
- **Queue를 사용하여 FIFO**

#### Implementation
<pre><code>
// BFS
template < class VertexType >
void BreadthFirstSearch(GraphType< VertexType > graph, VertexType startVertex, VertexType endVertex) {
	QueueType< VertexType > queue;
	QueueType< VertexType > vertexQ;

	bool found = false;
	VertexType vertex;
	VertexType item;

	graph.ClearMarks();
	queue.Enqueue(startVertex);
	do {
		queue.Dequeue(vertex);
		if (vertex == endVertex) // Base case : found하는 경우!
			found = true;
		else {
			if (!graph.IsMarked(vertex)) {
				graph.MarkVertex(vertex);
				graph.GetToVertices(vertex, vertexQ); // 임시 큐에 먼저 vertex를 넣는다

				while (!vertexQ.IsEmpty()) {
					vertexQ.Dequeue(item); // vertexQ dequeue
					if (!graph.IsMarked(item))
						queue.Enqueue(item); // dequeue한 item을 큐에 넣는다
				}
			}
		}
	} while (!queue.IsEmpty() && !found);
	
	if (!found)
		cout << "Path not found" << endl;

}
</code></pre>
![image](https://user-images.githubusercontent.com/50229148/119370957-dfedab00-bcf0-11eb-9fe1-a26647e16971.png)
![image](https://user-images.githubusercontent.com/50229148/119370970-e3813200-bcf0-11eb-80cd-67eef02731a4.png)
![image](https://user-images.githubusercontent.com/50229148/119370980-e5e38c00-bcf0-11eb-8672-5b37797b05e5.png)

# ADT Set Definitions
- Sets cannot contain dulplicates(집합의 원소는 중복이 없다)
- If item does not in a set, then item from the set doesn't change the set
- set는 정렬되어있지 않다.
- Bit연산과 Array-index를 활용하여 집합을 나타낼 수 있다. 
![image](https://user-images.githubusercontent.com/50229148/119371826-b3865e80-bcf1-11eb-93b2-fb81a945aaf1.png)
