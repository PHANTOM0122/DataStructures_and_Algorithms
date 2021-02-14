#include <iostream>
using namespace std;

template <class ItemType>
struct NodeType {
	NodeType* next;
	ItemType Info;
};

template <class ItemType>
void Insert(NodeType<ItemType>* &location, ItemType item) {
	if (location == NULL || item < location->Info) { // base cases !
		// 빈 리스트, list끝에 삽입하거나 location 앞에 item 삽입
		NodeType<ItemType>* tempPtr = location;
		location = new NodeType<ItemType>;
		location->Info = item;
		location->next = tempPtr;
	}
	else {
		Insert(location->next, ItemType item); // general case!
	}
}

template <class ItemType>
class SortedType {
public:
	SortedType() {
		listData = new NodeType<ItemType>[length];
	}
	~SortedType() {
		delete[] listData;
	}
	void InsertItem(ItemType newItem);
private:
	ItemType* listData;
	int length;
};

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType newItem) {
	Insert(listData, newItem);
}


