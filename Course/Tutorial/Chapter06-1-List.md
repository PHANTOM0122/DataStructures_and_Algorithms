More about List using NodeType
=====================
## 6.2-1) 노드 기반 연산과 반복자
* **매개변수로 Node를 사용함으로써 함수가 저장된 곳의 위치를 직접적으로 접근 및 node 이웃들의 next,prev원소 삭제 가능**
* **Nodetype은 리스트 원소와 position을 나타내는 pointer를 가진다**
> **container & position**
  * 위치에 각 원소를 저장하고, 선형 순서로 이러한 위치들을 유지하는 컨테이너로 리스트를 간주
> **Iterator**
  * **container에서 다음 위치로 이동가능한 객체를 반복자라 한다**
  * 반복자는 위치의 확장이다. **노드의 원소에 접근 기능 + 컨테이너에서 앞뒤로 항해하는 기능 제공**
  * C++)의 경우 itertator p에 대해서 p.next()를 p++ / p.prev()를 p--로 이용하여 전후 container로 이동 가능하다
  * **begin: 반복자를 컨테이너 첫 번째 노드로 초기화 하는 기능 -> L.begin()은 시작하는 반복자 개체를 반환**
  * **end: 컨테이너의 마지막 노드를 넘어갔는지 판단하는 기능 -> L.end()는 끝내는 반복자 개체를 반환**

## 6.2-2) ADT of List
![image](https://user-images.githubusercontent.com/50229148/108017471-54f97680-7058-11eb-9188-1157a4e88bef.png)
* **begin(): L의 첫번째 원소를 참조하는 반복자를 반환한다. L가 비어있다면 end()와 같다**
* **end(): L의 마지막 원소를 바로 다음의 가상적인 원소를 참조하는 반복자를 반환한다**
* **insertFront(e): L의 첫번째 원소로 새 원소 e를 삽입한다**
* **insertBack(e): L의 마지막 원소로 새 원소 e를 삽입한다**
* **insert(p,e): L의 위치 p 앞에 새 원소 e를 삽입한다**
* **erase(p): 위치 p에 있는 원소를 L에서 삭제시킨다. p를 무효화한다**
##### Error case
* p가 초기화 되기 않았거나 다른 리스트의 위치로 설정
* p가 리스트로부터 이미 삭제된 것이다
* p가 불법적인 연산의 결과이다. if) p==L.end()에서 p++을 한 경우 등

## 6.2-3) Double linked list 구현
