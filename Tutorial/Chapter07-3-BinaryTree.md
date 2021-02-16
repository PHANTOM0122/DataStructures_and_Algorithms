Binary Tree(이진트리)
======================
* **모든 노드가 최대로 두개의 자식 노드를 갖는 순서화된 트리**
> Binary Tree의 특성
  * **각 노드는 최대 2개의 자식을 갖는다**
  * **각 노드는 고유한 path(부모와의 관계)를 가지고 있다. -> path가 두개면 tree가 아니다**
  * **왼쪽 자식이 오른쪽 자식보다 먼저 오도록 순서화되었다(left subtree < parent < right subtree)**

## 7.3-1) Binary Tree ADT
* **p.left(): p의 왼쪽 자식을 반환한다. p가 leave이면 error**
* **p.right(): p의 오른쪽 자식을 반환한다. p가 leave이면 error**
* **p.parent(): p의 부모를 반환한다. p가 root면 error**
* **p.isRoot(): Root node?**
* **p.isExternal(): Leave node?**

## 7.3-2) Binary Tree interface 
> ### 강의 기준 
< 
