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
- 
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

template <class ItemType>
LLStackType<ItemType>::~LLStackType() {
	NodeType<ItemType> tempPtr;
	while (topPtr!=nullptr) {
		tempPtr = topPtr;
		topPtr = topPtr->next;
		delete tempPtr;
	}
}

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
}

template <class ItemType>
bool LLStackType<ItemType>::IsEmpty() {
	return	(topPtr == nullptr);
}

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
![image](https://user-images.githubusercontent.com/50229148/113688105-f4a3be80-9703-11eb-8833-197d99fd3def.png)

<code><pre>
template <class ItemType>
void LLStackType<ItemType>::Push(ItemType item) {
	NodeType* temp;
	temp = new NodeType<ItemType>;
	temp->info = item;
	temp->next = topPtr;
	topPtr = temp;
}</pre></code>

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


