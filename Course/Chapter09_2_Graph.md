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

2) **Adjacency List(Linked-List) : 1D array -> to represent the vertices **
![image](https://user-images.githubusercontent.com/50229148/119369443-25a97400-bcef-11eb-8981-f969873f47ce.png)
- **구현 시험 문제에 출제 가능**





