Binary Search Tree
=================================
- Tree에서 부모 노드는 1개만 존재한다

## Binary Tree가 되기 위한 조건
1. 각 노드는 자식 노드를 최대 2개까지 가질 수 있다
2. root로부터 각 노드까지 가는 길은 unique한 way 1개만 존재한다
- binary tree의 search time complexity -> O(N)

## Full Tree의 height을 이용하여 node의 갯수 구하기
**h = log2(N+1) -> O(logN)**

## Binary Search Tree
- Binary Tree보다 작은 개념이다
- 다음과 같은 조건을 만족해야한다
1) 왼쪽 subtree는 root보다 작다
2) 오른쪽 subtree는 root보다 크다
- Binary search Tree의 search time complexity -> O(log2N)

## NodeType for Tree Node
![image](https://user-images.githubusercontent.com/50229148/116846684-d1493200-ac23-11eb-9568-5822e6119eb8.png)
<pre><code>
template < class ItemType >
struct NodeType {
	ItemType info;
	NodeType<ItemType>* left;
	NodeType<ItemType>* right;
};</code></pre>
