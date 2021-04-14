Doubly Linked List
==================
- 기본적인 원리는 LinkedList와 유사하다
# SortedList using Doubly Linked List!
### Declare!
<pre><code>
struct NodeType {
	ItemType info;
	NodeType* next;
	NodeType* back;
};

class DLSortedList {
public:
	DLSortedList();
	~DLSortedList(); // = void MakeEmpty();
	void FindItem(NodeType*, ItemType, NodeType* &, bool&);
	void DeleteItem(ItemType);
	void InsertItem(ItemType);
	void GetNextItem(ItemType&);
	void Print();
private:
	NodeType* listData;
	NodeType* CurrentPos;
	int length;
};
</code></pre>
### Constructor & Destructor
<pre><code>
DLSortedList::DLSortedList() {
	listData = nullptr;
	CurrentPos = nullptr;
	length = 0;
}

DLSortedList::~DLSortedList() {
	NodeType* temp =  nullptr;
	while (listData != nullptr) {
		temp = listData;
		listData = listData->next;
		delete temp;
	}
}
</code></pre>
### FindItem (Retrieve Item)
<pre><code>
void DLSortedList::FindItem(NodeType* listData, ItemType target, NodeType* &location, bool& found) {
	bool moreToSearch = true;

	location = listData;
	found = false;

	while (moreToSearch && !found) {
		if (target < location->info) { // location cursor가 target의 최댓갑을 넘어가면 break!
			moreToSearch = false;
		}
		else if(target==location->info){ // target을 list에서 찾았을 때!
			found = true;
		}
		else { // location이 target이 있는 값보다 작을때 다음 노드로 넘어간다!
			if (location->next == nullptr) { // location이 끝 노드를 가리킬 때 : 예외처리!
				moreToSearch = false; // found는 default로 false
			}
			else // 다음 노드를 가리킨다
				location = location->next;
		}
	}
}
</code></pre>
### InsertItem
<pre><code>
// location을 통해 아이템이 삽일될 위치를 찾은 후, 그 곳에 새로운 노드를 삽입한다
// 항상 처음과 끝 노드는 예외처리를 해야하는지 살펴본다!
void DLSortedList::InsertItem(ItemType Item) {
	NodeType* location = nullptr;
	bool found;

	NodeType* newNode;
	newNode = new NodeType;
	newNode->info = Item;


	if (listData != nullptr) { // 빈 리스트가 아닐 때
		FindItem(listData, Item, location, found); // location이 insert할 위치 바로 다음 노드를 가리킨다! 

		if (location->info > Item) { // location이 가리키는 노드 전에다가 삽입
			newNode->back = location->back; // newNode과 newNode 이전의 노드를 연결
			newNode->next = location; // newNode와 newNode 이후의 노드를 연결!
			if (location != listData) // Not insert into beginning!
				location->back->next = newNode;
			else // special case : insert into beginning!
				listData = newNode; // location(첫번째 원소)의 back이 존재하지 않는다
			location->back = newNode; // newNode 이후의 back을 newNode로 지정한다
		}
		else { // list 맨 마지막에 원소를 삽입
			newNode->back = location;
			location->next = newNode;
			newNode->next = nullptr;
		}
	}

	else { // 빈 리스트에 원소 삽입
		listData = newNode;
		newNode->next = newNode->back = nullptr;
	}
}
</code></pre>
### DeleteItem
<pre><code>
void DLSortedList::DeleteItem(ItemType target) {
	NodeType* location = nullptr;
	NodeType* tempPtr = nullptr;
	bool found;
	// 삭제할 Item이 있는지 먼저 확인한다!
	FindItem(listData, target, location, found);
	
	// 중복 item들까지 삭제한다
	while (found) { 
		// location이 삭제할 Node를 가리키고 있다
		if (listData == location) { // location이 처음 원소를 가리킬 때 exception!
			tempPtr = location;
			location = location->next;
			location->back = nullptr; // 2번째 원소와 1번째 원소의 연결을 끊는다
			listData = location;
			delete tempPtr;
		}
		else
			location->back->next = location->next;
		
		if (location->next == nullptr) {// location이 마지막 원소를 가리킬 때 exception!
			tempPtr = location; // 마지막 노드 이전 노드의 back을 nullptr로 하면서 연결을 끊는다!
			location = location->back; // location을 이전 노드로 옮긴다!
			delete tempPtr;
		}
		else
			location->next->back = location->back; 
		
		// 더 삭제할 item이 있는지 확인한다!
		FindItem(listData, target, location, found);
	}
}
</code></pre>
### GetNextItem
<pre><code>
void DLSortedList::GetNextItem(ItemType& Item)
{
	NodeType* loc = listData;
	if (loc != nullptr){
		Item = loc->info;
		loc = loc->next;
	}
}
</code></pre>

<pre><code>
void DLSortedList::Print() {
	NodeType* loc = listData;
	while (loc != nullptr) {
		cout << loc->info << ' ';
		loc = loc->next;
	}
}
</code></pre>

<pre><code>
</code></pre>

# Linked List as an Array!
- **Linked List Node의 next에는 address가 아닌 index 값을 넣는다**
![image](https://user-images.githubusercontent.com/50229148/114683134-bbde9780-9d4a-11eb-8eea-f93c5d075420.png)
![image](https://user-images.githubusercontent.com/50229148/114683148-bed98800-9d4a-11eb-92b6-2e464f7d7d94.png)

# Deep Copy vs Shallow Copy!
- Deep Copy는 데이터를 새로 복사해서 만든다
- Shallow Copy는 데이터를 기존의 것과 같이 쓴다! -> shallow copy 한 후에 transform을 하면 기존의 것도 같이 바뀌므로 문제가 발생한다!
- **pass by value, =는 shallow copy를 만든다**
![image](https://user-images.githubusercontent.com/50229148/114684352-cc434200-9d4b-11eb-88f2-bfd90c350da7.png)
![image](https://user-images.githubusercontent.com/50229148/114684514-f09f1e80-9d4b-11eb-82e5-c2dff8328ecb.png)
![image](https://user-images.githubusercontent.com/50229148/114684592-03b1ee80-9d4c-11eb-88a5-2e03bf7e8c46.png)
### shallow copy이후 pop연산을 실행하면은 다음과 같다
![Uploading image.png…]()

# Deep copy를 위한 constructor & operator'='
<pre><code>
class StackType {
	// Copy constructor
	StackType(const StackType& anotherStack) { // 반드시 & 기호 붙어줘야한다
		NodeType* ptr1;
		NodeType* ptr2;
		if (anotherStack.topPtr == nullptr) {
			topPtr = nullptr; // anotherStack is empty -> this stack should be empty!
		}
		else {
			topPtr = new NodeType;
			topPtr->info = anotherStack.topPtr->info; // another스택의 topPtr값을 복사!
			ptr1 = anotherStack.topPtr->next;
			ptr2 = topPtr; 
			while (ptr1 != nullptr) { // Deep copy other nodes!
				ptr2->next = new NodeType; // topPtr -> newNode 이렇게 계속 연결해가며 데이터를 복사한다
				ptr2 = ptr2->next; 
				ptr2->info = ptr1->info; // anotherStack의 정보를 this에 copy
				ptr1 = ptr1->next; // anotherstack next element point!
			}
			ptr2->next = nullptr;
		}
	}
	// operator overloading!
	void operator= (StackType another) {
		// Same as original Stack!
	}
private:
	NodeType* topPtr;
};
</code></pre>

