
template <class ItemType>
struct HeapType {
	void ReheapDown(int root, int bottom);
	void REheapUp(int root, int bottom);

	ItemType* elements; // Array to be allocated dynamically
	int numElements;
};

template<class ItemType>
void swap(ItemType& a, ItemType& b) {
	ItemType temp;
	temp = a;
	a = b;
	b = temp;
}

template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom) // bottom : rightmost int the last level -> array last elem
{
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;

	if (leftChild <= bottom) { // left child가 존재하는 경우
		if (leftChild == bottom) { // one child(==left child)
			maxChild = leftChild;
		}
		else { // Two children!
			if (elements[leftChild] < elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild; 
		}

		if (elements[root] < elements[maxChild]) {// case that violate heap priority
		
			swap(elements[root], elements[maxChild]);
			ReheapDown(maxChild, bottom); // Recursive
		}
	}
}

template<class ItemType>
void HeapType<ItemType>::REheapUp(int root, int bottom)
{
	int parent; // 
	if (bottom > root) {// tree is not empty!
		
		parent = (bottom - 1) / 2; // find parent!
		if (elements[bottom] > elements[parent]) {
			swap(elements[parent], elements[bottom]);
			REheapUp(root, parent); // Recursive 
		}
	}
}
