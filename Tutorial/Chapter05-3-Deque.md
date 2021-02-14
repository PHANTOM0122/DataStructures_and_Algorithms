Deque(양방향 큐)
============================
* **front와 rear 양쪽에서 삽입과 삭제 연산을 지원하는 큐와 유사한 데이터 구조**

## 5.3-1) ADT of Deque
* **insertfront(e): 첫 번째에 새로운 원소 e를 삽입한다**
* **insertBack(e): 마지막에 새로운 원소 e를 삽입한다**
* **eraseFront(e): 첫 번째 원소를 삭제한다. 공백상태이면 error 발생시킨다!**
* **eraseBack(e): 마지막 원소를 삭제한다. 공백상태이면 error 발생시킨다!**
* **front(e): 첫 번째 원소를 반환시킨다.**
* **back(e): 마지막 원소를 반환시킨다**
* **size: 원소의 갯수를 return**
* **empty(): return true if deque is empty!**

## 5.3-2) STL of Deque
<pre><code>
#include < deque >
using namespace std;
deque<string> myDeque;
</code></pre>
> member function
* size() / empty() / push_front() / push_back() / pop_front() / pop_back() / front() / back()

## 5.3-2) STL of Deque
