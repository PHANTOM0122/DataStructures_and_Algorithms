Linked List
==============
- **Dynamic allocation이 가능하다는 장점이 있다**

# NodeType
![image](https://user-images.githubusercontent.com/50229148/113687876-bb6b4e80-9703-11eb-9461-6acef5f0d368.png)

<pre><code>
template < class ItemType > 
struct NodeType {
	ItemType info;
	NodeType* next;
};
</code></pre>

# Linked List를 이용한 StackType!

<pre><code>
template <class ItemType>
class LLStackType {
public:
	LLStackType();
	~LLStackType();
	bool IsFull();
	bool IsEmpty();
	void Push(ItemType);
	void Pop();
	ItemType Top();
private:
	NodeType<ItemType>* topPtr;
};


template <class ItemType>
LLStackType<ItemType>::LLStackType() {
	topPtr = nullptr;
}
</code></pre>
#### Destructor
- **topPtr이 nullptr이 될 때까지, tempPtr로 지울 Node를 가리키고 지우면서 topPtr = topPtr->next를 가리킨다. (끝까지 가면서 지운다)** 
<pre><code>	
template <class ItemType>
LLStackType<ItemType>::~LLStackType() {
	NodeType<ItemType> tempPtr;
	while (topPtr!=nullptr) {
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
}</code></pre>
#### IsFull
- **새로운 Node를 만드는 것을 try 해보고 exceptrion이 발생하면 FullStack인 것을 알 수 있다**
<pre><code>
template <class ItemType>
bool LLStackType<ItemType>::IsFull() {
	NodeType<ItemType>* location;
	try {
		location = new NodeType<ItemType>;
		delete location;
		return false;
	}
	catch (FullStack) {
		return true;
	}
}</code></pre>
#### IsEmpty
- **새로운 Node를 만드는 것을 try 해보고 exceptrion이 발생하면 FullStack인 것을 알 수 있다**
<pre><code>
template <class ItemType>
bool LLStackType<ItemType>::IsEmpty() {
	return	(topPtr == nullptr);
}</code></pre>
#### Top
- topPtr이 가리키는 node의 info를 return 한다
<code><pre>
template <class ItemType>
ItemType LLStackType<ItemType>::Top() {
	if (IsEmpty()) {
		throw EmptyStack();
	}
	else {
		return topPtr->info;
	}
}
</pre></code>
#### Push
- **tempPtr로 새로운 Node를 가리키고, 새 노드의 next를 topPtr->next(삽입 후 오른쪽 element)를 가리킨다**
- **이후, 기존의 topPtr로 새로운 노드를 가리킨다**
<code><pre>
template <class ItemType>
void LLStackType<ItemType>::Push(ItemType item) {
	NodeType* temp;
	temp = new NodeType<ItemType>;
	temp->info = item;
	temp->next = topPtr;
	topPtr = temp;
}</pre></code>
![image](https://user-images.githubusercontent.com/50229148/113688105-f4a3be80-9703-11eb-8833-197d99fd3def.png)
#### Pop
- **tempPtr로 topPtr이 가리키는 노드를 가리키고, topPtr = topPtr->next (다음 순서의 지울 원소를 가리킨다)**
- **이후, 기존의 노드였던 tempPtr를 delete**
<code><pre>
template <class ItemType>
void LLStackType<ItemType>::Pop() {
	if (IsEmpty())
		throw EmptyStack();

	NodeType<ItemType>* temp;
	temp = topPtr;
	topPtr = topPtr->next;
	delete temp;
}
 </code></pre>
 ![image](https://user-images.githubusercontent.com/50229148/113688539-5a904600-9704-11eb-8836-19decc31e93e.png)


# Linked List를 이용한 QueueType!
<pre><code>
template <class ItemType>
class LLQueueType {
public:
	LLQueueType();
	~LLQueueType();
	bool IsFull() const;
	bool IsEmpty() const;
	void Enqueue(ItemType);
	void Dequeue(ItemType& item);
	void makeEmpty();

private:
	NodeType<ItemType>* front;
	NodeType<ItemType>* rear;
};

// Constructor!
template< class ItemType >
LLQueueType<ItemType>::LLQueueType() {
	front = nullptr;
	rear = nullptr;
}</code></pre>

#### Destructor
- **front != rear일 때까지, tempPtr로 지울 Node(front가 가리킨 노드)를 point한다**
- **front = front -> next (다음 원소로 front이동)**
- **기존 노드(tempPtr) 삭제**
<pre><code>
template< class ItemType >
LLQueueType<ItemType>::~LLQueueType() {
	while (!IsEmpty()) {
		NodeType<ItemType>* tempPtr;
		tempPtr = front;
		front = front->next;
		delete tempPtr;
	}
}</code></pre>
#### IsFull, IsEmpty
- IsFull의 경우 stack과 동일
- **IsEmpty의 경우 front == rear이면 empty로 판단 가능하다**
<code><pre>
template< class ItemType >
bool LLQueueType<ItemType>::IsFull() const {
	try {
		NodeType<ItemType>* temp;
		temp = new NodeType<ItemType>;
		delete temp;
	}
	catch (FullQueue);
}
template< class ItemType >
bool LLQueueType<ItemType>::IsEmpty() const {
	return (front == rear);}
</code></pre>

#### Enqueue
1) **tempPtr로 새로운 노드(next는 nullptr)를 가리키고, 기존의 rear의 next에 새로운 노드를 연결시킨다**
2) **이후 rear = tempPtr(Newnode)을 통해 rear의 위치를 1증가시킨다!**
<pre><code>
template< class ItemType >
void LLQueueType<ItemType>::Enqueue(ItemType item){
	if (IsFull) { throw FullQueue(); }
	else {
		NodeType<ItemType> temp;
		temp = new NodeType<ItemType>;
		temp->info = item;
		temp->next = nullptr;
		if (rear == nullptr)
			front = temp; // front가 nullptr이다가 처음 Node를 가리키는 경우!
		else
			rear->next = temp; // (if rear-> next == nullptr인 경우, 위의 예외처리)
		rear = temp;
	}
}</code></pre>
![image](https://user-images.githubusercontent.com/50229148/113691803-d0e27780-9707-11eb-972c-c57e975b65a3.png)
![image](https://user-images.githubusercontent.com/50229148/113692431-831a3f00-9708-11eb-8415-839ec0e4c0f8.png)

#### Dequeue
1) **tempPtr로 지울 노드(front가 가리키는 노드)를 먼저 가리킨다**
2) **front = front->next를 통해 front의 위치를 1증가시킨다**
3) **기존의 노드(tempPtr)을 delete한다**
<pre><code>
template<class ItemType>
void LLQueueType<ItemType>::Dequeue(ItemType& item) {
	if (IsEmpty) { throw EmptyQueue(); }
	else {
		NodeType<ItemType>* temp;
		temp = front;
		front = front->next;
		item = temp->info;
		if (front == nullptr) // 위의 action이후 front가 nullptr, front->next가 오류가 발생하므로 rear역시 null로 만들어주어 Isempty()조건에 걸리게 한다
			rear = nullptr; 
		delete temp;
	}
}</code></pre>
![image](https://user-images.githubusercontent.com/50229148/113691795-cf18b400-9707-11eb-9039-7a941890d260.png)
![image](https://user-images.githubusercontent.com/50229148/113692395-78f84080-9708-11eb-937d-0305a2e60f23.png)

#### makeEmpty
- **Destructor처럼 front가 계속 rear쪽으로 이동하면서 기존 노드를 delete해야 한다**
- **마지막 노드를 지우는 경우 front와 rear를 nullptr로 지정해준다**
<pre><code>
template< class ItemType >
void LLQueueType<ItemType>::makeEmpty() {
	while (!IsEmpty()) {
		NodeType<ItemType>* tempPtr;
		tempPtr = front;
		front = front->next;
		delete tempPtr;
	}
	rear = nullptr;
}
</code></pre>
### circular queue design
- **rear->next가 nullptr이 아닌 front를 가리키면 된다**

# Linked List를 이용한 UnsortedType!
<pre><code>
template <class ItemType>
class UnsortedType {
public:
	UnsortedType();
	~UnsortedType();
	void makeEmpty();
	bool IsFull() const;
	int LengthIs() const;
	void RetrieveItem(ItemType& item, bool& found);
	void InsertItem(ItemType);
	void DeleteItem(ItemType& item);
	void ResetList();
	void GetNextItem(ItemType& item);
private:
	NodeType<ItemType>* listData;
	int length;
	NodeType<ItemType>* currentPos;
};

template <class ItemType>
UnsortedType<ItemType>::UnsortedType() {
	length = 0;
	listData = nullptr;
}

template <class ItemType>
int UnsortedType<ItemType>::LengthIs() const {
	return length;}
</code></pre>

#### RetrireveItem(item, bool& found) 
- **item이 list에 있으면 found가 true가 된다**
<pre><code>
template < class ItemType >
void UnsortedType<ItemType>::RetrieveItem(ItemType& item, bool& found) {
	bool moreToSearch;
	NodeType<ItemType>* location;
	location = listData; // listData의 첫번째 element를 가리킨다
	found = false;
	moreToSearch = (location != nullptr); // location이 끝까지 안갔을때까지 실행
	while (moreToSearch && !found) {
		if (item == location->info) {
			found = true;
			item = location->info;
		}
		else {
			location = location->next; // location ++
			moreToSearch = (location != nullptr);
		}
	}
}</code></pre>

#### InsertItem
<pre><code>
template < class ItemType >
void UnsortedType<ItemType>::InsertItem(ItemType item) {
	NodeType<ItemType>* location;
	location = new NodeType<ItemType>;
	location->info = item;
	location->next = listData;
	listData = location;
	length++;
}</code></pre>
![image](https://user-images.githubusercontent.com/50229148/113696658-3be27d00-970d-11eb-8c5a-1daa8df77c76.png)
#### DeleteItem
-**삭제할 node기준으로 좌우의 노드를 연결시켜줘야 한다->삭제할 노드를 가리키는 tempLoc, 삭제할 노드 이전을 가리키는 Loc을 알아야 한다**
-**Loc->next = tempLoc->next 한 이후에 노드를 삭제한다(순서 중요!)** 
<pre><code>
template < class ItemType >
void UnsortedType<ItemType>::DeleteItem(ItemType& item) {
	NodeType<ItemType>* location = listData;
	NodeType<ItemType>* tempLoc;
	bool found = false;
	if (item == listData->info) {
		tempLoc = location;
		listData = listData->next; // Delete first node
	}

	else {
		while (!(item == (location->next)->info))
			location = location->next;

		RetrieveItem(item, found); // item이 있는지 확인한다!
		if (found) {
			// delete node at location->next
			tempLoc = location->next;
			location->next = (location->next)->next; // 삭제될 원소의 오른쪽 원소를 point!
			delete tempLoc;
			length--;
		}
		else {
			// item is not in list!
		}
	}
}</code></pre>
![image](https://user-images.githubusercontent.com/50229148/113697003-a3003180-970d-11eb-9906-f2f555343e6c.png)
