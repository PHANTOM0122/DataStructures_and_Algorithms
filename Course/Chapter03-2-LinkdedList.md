Sinlgy Linked List
=================
![image](https://user-images.githubusercontent.com/50229148/107219654-b7e57f00-6a54-11eb-9ad1-7a24ed98b3c7.png)
* 배열은 변화에 취약한 단점이 존재
* **linked list: 노드들이 선형적으로 순서화된 형태의 집합체이다**
* **다음 node를 가리키는 pointer와 node의 info를 가지고 있다**
* linkded list의 제일 마지막과 처음을 tail, head라 한다.
* **node를 추가하거나 삭제함으로써 resize가 가능하다**
## 3.2-1) 단일 링크드 리스트 구현
* tail의 가리키는 ptr은 nullptr이다.
#### Example code // 문자열 linkded list node
<pre><code>
class stringNode {
private:
	string elem;
	stringNode* next;
	friend class stringLinkedLIst; // stringLinkedList class가 stringnode를 사용 가능하게 한다!
};

class stringLinkedLIst {
public:
	stringLinkedLIst();
	~stringLinkedLIst();
	bool empty() const;
	const string& front() const;
	void addFront(const string& e);
	void removeFront();
private:
	stringNode* head;
};

stringLinkedLIst::stringLinkedLIst() { head = NULL; } // 생성자
stringLinkedLIst::~stringLinkedLIst() { while (!empty()) removeFront(); } // 소멸자
bool stringLinkedLIst::empty() const { return head == NULL; } // 빈 리스트?
const string& stringLinkedLIst::front() const { return head->elem; } // 이전 원소를 얻는다
</code></pre>
## 3.2-2) 단일 링크드 리스트 삽입
* **먼저 새로운 노드를 만들고, 원하는 문자열을 elem값으로 넣어주고
