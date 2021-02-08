단일 링크드 리스트
===========================
![image](https://user-images.githubusercontent.com/50229148/107219654-b7e57f00-6a54-11eb-9ad1-7a24ed98b3c7.png)
* 배열은 변화에 취약하다는 단점이 있다
* **linkedlist는 node들이 선형적으로 순서화된 형태의 집합체이다**
* **다음의 node를 가리키는 pointer, node의 info를 가지고 있다**
* 리스트의 처음과 마지막 노드를 각각 head, tail이라 한다.
## 3.2-1) 단일 링크드 리스트 구현
<pre><code>
// string linked list node
class stringNode {
private:
	string elem;
	stringNode* next;
	friend class stringLinkedLIst;
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
## 3.2-2) 단일 링크드 리스트 insert
* **먼저 새로운 node를 만들고 원하는 info를 넣어주고 마지막으로 next연결을 list의 현재 head를 가리키도록 만들면 된다**
![image](https://user-images.githubusercontent.com/50229148/107224921-760c0700-6a5b-11eb-9b3c-7541f7ad15df.png)
<pre><code>
void stringLinkedLIst::addFront(const string& e) {
	stringNode* v = new stringNode;
	v->elem = e;
	v->next = head;
	head = v;
}</code></pre>

