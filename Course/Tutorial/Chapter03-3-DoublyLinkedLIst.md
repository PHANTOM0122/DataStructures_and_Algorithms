이중 링크드 리스트
============================
![image](https://user-images.githubusercontent.com/50229148/107237657-4e706b00-6a6a-11eb-82ca-f9ce6f4f3896.png)
* **리스트의 양방향을 탐색하는 방법**
* **원소 멤버 이외에, 리스트의 다음 노드와 이전 노드를 각각 가리키는 next링크와 prev링크를 가진다**
* **header 노드와 trailer 노드: head앞, trailer뒤에 어떠한 원소를 저장하지 않는 node를 추가시켜서, header->next = head / trailer->prev = trail을 만든다**(강의 교재에서는 header Node만 사용한다)
## 3.3-1) 이중 링크드 리스트에 삽입하기
* **새로운 Node를 만들고 pre, next pointer를 전후의 원소들과 연결시키면 된다!**
![image](https://user-images.githubusercontent.com/50229148/107240529-5c73bb00-6a6d-11eb-920e-b04c2859f8f3.png)
<pre><code>
typedef std::string Elem;
struct NodeType{
	Elem info;
	NodeType* prev;
	NodeType* next;
};

class DLinkedList {
public:
	DLinkedList();
	~DLinkedList();
	bool empty()const;
	const Elem& front() const;
	const Elem& back() const;
	void addFront(const Elem& e);
	void addBack(const Elem& e);
	void removeFront();
	void removeBack();
private:
	NodeType* header;
	NodeType* trailer;
protected:
	void add(NodeType* v, const Elem& e); // v전에 새로운 node삽입
	void remove(NodeType* v); // v노드 제거
};

DLinkedList::DLinkedList()
{
	header = new NodeType; // 헤더 앞에 새로운 노드 생성
	trailer = new NodeType; // 트레일 뒤에 새로운 노드 생성
	header->next = trailer; // 서로를 point!
	trailer->prev = header;
}

DLinkedList::~DLinkedList()
{
	while (!empty()) {removeFront();}
	delete header;
	delete trailer;
}

bool DLinkedList::empty() const
{
	return (header->next == trailer);
}

const Elem& DLinkedList::front() const
{
	return header->next->info;
}

const Elem& DLinkedList::back() const
{
	return trailer->prev->info;
}

void DLinkedList::addFront(const Elem& e)
{
	add(header->next, e); // list뒤에서 추가
}

void DLinkedList::addBack(const Elem& e)
{
	add(trailer, e); // list뒤에서 추가
}

void DLinkedList::removeFront()
{
	remove(header->next); // 앞에서 삭제
}

void DLinkedList::removeBack()
{
	remove(trailer->prev); // 뒤에서 삭제
}

void DLinkedList::add(NodeType* v, const Elem& e)
{
	NodeType* NewNode = new NodeType; // e를 위한 새로운 node 생성
	NewNode->info = e;
	NewNode->next = v;
	NewNode->prev = v->prev;
	v->prev->next = v->prev = NewNode;
}

void DLinkedList::remove(NodeType* v)
{
	NodeType* NewNode1 = v->prev; // 선행자
	NodeType* NewNode2 = v->next; // 후속자
	NewNode1->next = NewNode2;
	NewNode2->prev = NewNode1;
}

const Elem& DLinkedList::back() const
{
	// TODO: 여기에 return 문을 삽입합니다.
}</code></pre>

