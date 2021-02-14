#include <iostream>

using namespace std;

struct NodeType {
	int info;
	NodeType* next;
};

class SortedType {
public:
	SortedType();
	~SortedType();
	void RevPrint(NodeType* listPtr);
private:
	NodeType* listData;
};

SortedType::SortedType()
{
	listData = new NodeType[100]; // Default
}

SortedType::~SortedType()
{
	delete[] listData;
}

void SortedType::RevPrint(NodeType* listPtr)
{
	if (listPtr != NULL) { // general case!
		RevPrint(listPtr->next); // process the rest
		cout << listPtr->info << endl; // After recursive call, print elements backwards!
	}
	// Base case : when list is empty, do nothing!
}
