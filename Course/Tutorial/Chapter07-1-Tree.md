Tree
==========
## 7.1-1) 트리의 정의와 특성
* **비선형적인 자료구조**
* 선형 구조를 사용할 때보다 빠른 알고리즘의 구현 가능, 상하위의 객체들의 관계는 계층적이다
* **각각의 원소는 하나의 parent 원소와 0 또는 여러개의 children 원소를 가진다**
* 최상위 원소를 **root**라 하며, 자식을 갖지 않는 노드들을 **leave(external)**라 한다.
* 동일한 부모를 가진 자식 노드들을 sibling(형제)라 한다.
* **subtree: tree의 일부분. 이 역시 tree구조가 된다**
## 7.1-2) ADT of tree
* 트리의 각 노드는 위치와 연관되어 있어 이것을 통해 노드에 접근가능하다
* **트리 노드의 위치 모음을 저장하는 것을 위치 리스트(position list)라 한다**
* p.parent(): p의 부모를 반환한다. p가 root이면 error
* p.children(): p의 자식들을 포함하는 위치 리스트를 반환한다
* p.isRoot(): p가 루트이면 참, 아니면 거짓을 반환한다.
* p.isExternal(): p가 외부노드이면 참 아니면 거짓을 반환한다.
* size(): tree내의 노드수를 반환한다
* empty(): tree가 비었으면 참 아니면 거짓을 반환
* root(): 트리의 루트에 대한 위치를 반환. 비었으면 error
* positions(): tree의 모든 노드의 위치 리스트를 반환

## 7.1-3) C++ Tree interface
<pre><code>
template <typename E>
class Position<E> {
public:
  E& operator*(); // 원소를 구하라
  Position parent() const; // 부모를 구해라
  PositionList children() const; // 노드의 자식리스트를 구하라
  bool isRoot() const; // root node?
  bool isExternal() const; // external(leave) node?
};

template <typename E>
class Tree<E> {
public:
  class Position; // 노드 위치
  class PositionList // 노드 위치 리스트
public:
  int size() const; // 노드의 갯수
  bool empty() const; // 트리가 empty?
  Position root() const; // 루트를 구하라
  PositionList positions() const; // 모든 노드의 위치를 구하라
};
  </code></pre>
## 7.1-4) 일반적인 트리를 위한 링크드 구조
![image](https://user-images.githubusercontent.com/50229148/108031686-9e57bf00-7074-11eb-822a-621baa77f9c2.png)
* root Node의 경우 부모는 NULL이고, leave Node의 경우 자식은 NULL

  
  
