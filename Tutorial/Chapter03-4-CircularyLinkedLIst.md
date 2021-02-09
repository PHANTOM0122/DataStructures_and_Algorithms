순환형 링크드 리스트와 리스트 반전
==================================
## 3.4-1) 순환형 링크드 리스트
![image](https://user-images.githubusercontent.com/50229148/107309071-1cdcbb80-6acd-11eb-9297-c786676b6edb.png)
* **단일 링크드 리스트와 마찬가지로 각 노드는 next poiner, Elem값을 가진다. 다만 리스트의 노드가 하나의 원형으로 연결되어 있다**
* **cursor(listData)라 불리는 특별한 Node가 필요한데, 리스트를 탐색시 시작할 지점을 정해준다**
![image](https://user-images.githubusercontent.com/50229148/107309526-ef444200-6acd-11eb-8d6e-dc2005da7cd6.png)
* **back(): cursor에 의해 참조되는 원소를 말한다. 리스트가 비어있다면 오류가 발생한다**
* **front(): cursor의 바로 다음 원소를 반환한다. 리스트가 비었다면 오류가 발생한다**
* **advance(): 리스트의 다음 노드로 커서를 이동시킨다.**
* **add(e): 커서의 바로 다음에 원소 e를 가지고 새로운 노드를 삽입한다. 만약 리스트가 비었다면, 이 노드는 커서가 되고 next는 자기 자신을 가리킨다.**
* **remove(): 유일한 node가 아니라면 커서 자체가 아닌 커서의 바로 다음 node를 삭제한다. 리스트가 비었다면, 커서는 null을 세팅한다.**
<pre><code>
typedef string Elem;
struct NodeType {
	Elem info;
	NodeType* next;
};

class CircleList {
	CircleList();
	~CircleList();
	bool empty() const;
	const Elem& front() const;
	const Elem& back() const;
	void advance();
	void add(const Elem& e);
	void remove();
private:
	NodeType* cursor;
};

CircleList::CircleList()
{
	cursor = nullptr;
}

CircleList::~CircleList()
{
	while (!empty()) {
		remove(); // 소멸자
	}
}

bool CircleList::empty() const
{
	return (cursor == NULL);
}

const Elem& CircleList::front() const
{
	return cursor->next->info;
}

const Elem& CircleList::back() const
{
	return cursor->info;
}

void CircleList::advance()
{
	cursor = cursor->next;
}

void CircleList::add(const Elem& e) // 커서의 다음에 추가
{
	NodeType* tempPtr = new NodeType;
	tempPtr->info = e;
	if (cursor == NULL) { // 빈 리스트일 경우
		tempPtr->next = tempPtr; // 자기 자신을 point
		cursor = tempPtr; // 커서는 tempPtr을 point
	}
	else { // 빈 리스트가 아닐 경우
		tempPtr->next = cursor->next; // tempPtr을 cursor 뒤의 원소와 연결
		cursor->next = tempPtr;
	}
}

void CircleList::remove() // cursor의 다음 node 삭제!
{
	NodeType* old = cursor->next; // cursor의 다음 원소 point
	if (old == cursor) { // 리스트의 원소가 자기 자신밖에 없을 경우
		cursor = nullptr; // 리스트를 가리키는 cursor는 없음
	}
	else {
		cursor->next = old->next; // cursor가 삭제될 원소 다음 원소를 point
	}
	delete old; // 원소 삭제
}</code></pre>
#### Circle link의 예시 - digital 오디오 플레이어의 재생 모
