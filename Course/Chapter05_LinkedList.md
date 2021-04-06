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


