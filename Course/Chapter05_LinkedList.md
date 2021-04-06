Linked List
==============
- **Dynamic allocation이 가능하다는 장점이 있다**

# NodeType
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
void LLStackType<ItemType>::Push(ItemType item) {
	NodeType* temp;
	temp = new NodeType<ItemType>;
	temp->info = item;
	temp->next = topPtr;
	topPtr = temp;
}

template <class ItemType>
void LLStackType<ItemType>::Pop() {
	if (IsEmpty())
		throw EmptyStack();

	NodeType<ItemType>* temp;
	temp = topPtr;
	topPtr = topPtr->next;
	delete temp;
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
  </code></pre>
