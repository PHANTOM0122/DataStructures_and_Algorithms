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
	friend class stringLinkedLIst; // friend 사용하기 싫으면 struct로 사용하면 된다!
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
	v->elem = e; // v = location
	v->next = head; // head = topPtr
	head = v;
}</code></pre>
## 3.2-3) 단일 링크드 리스트 delete
* **기존의 head가 가리키는 pointer를 먼저 저장하고, head pointer가 리스트의 다음 노드를 가리키도록 바꾸어준다. 그런 후 기존의 node를 지운다.**
![image](https://user-images.githubusercontent.com/50229148/107225482-30037300-6a5c-11eb-88b5-024e2d2b69bf.png)
<pre><code>
void stringLinkedLIst::removeFront() {
	stringNode* old = head; // 현재 head 저장
	head = old->next; // 이전 head 건너뛴다
	delete old; // 이전 head 삭제
}</code></pre>
## 3.2-4) 일반적인 단일 링크드 리스트 구현
<pre><code>

template<typename E>
struct SNode
{
	E elem; // 원소 값
	SNode* next; // 리스트 다음 항목 pointer
}; 

template<typename E>
class SLinkedList {
public:
	SLinkedList();
	~SLinkedList();
	bool empty() const;
	const E& front() const;
	void addFront(const E& e);
	void removeFront();
private:
	SNode<E>* head;
};

template<typename E>
SLinkedList<E>::SLinkedList()
{
	head = nullptr;
}

template<typename E>
SLinkedList<E>::~SLinkedList()
{
	while (!empty()) {
		removeFront();
	}
}

template<typename E>
bool SLinkedList<E>::empty() const
{
	return (head == nullptr);
}

template<typename E>
const E& SLinkedList<E>::front() const
{
	return head->elem;
}

template<typename E>
void SLinkedList<E>::addFront(const E& e)
{
	SNode<E>* location = new SNode<E>;
	location->elem = e;
	location->next = head;
	head = location;
}

template<typename E>
void SLinkedList<E>::removeFront()
{
	SNode<E>* old = head;
	head = old->next;
	delete old;
}</code></pre>
