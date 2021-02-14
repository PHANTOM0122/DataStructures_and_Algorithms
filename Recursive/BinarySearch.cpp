#include <iostream>

using namespace std;

// Recursive
template<class ItemType>
bool BInarSearch(ItemType list[], ItemType item, int left, int right) {
	int mid;
	if (left > right) { return false; } // Base case 1 : not found!
	else {
		mid = (left + right) / 2;
		if (list[mid] == item) // Base case 2 : found at mid
			return true;
		else if (item < list[mid]) // Search lower half
			return BInarSearch(list, ItemType item, left, mid - 1);
		else // Search upper half
			return BInarSearch(list, ItemType item, mid+1, right);
	}
}

/*
* Non-recursive
* 
template<class ItemType>
class SortedType {
public:
	SortedType() { info = new ItemType[length]; }
	void Retrieveitem(ItemType& item, bool& found);
private:
	ItemType* info;
	int length;
};

template<class ItemType>
void SortedType<ItemType>::Retrieveitem(ItemType& item, bool& found) {
	int midPoint;
	int first = 0;
	int last = length - 1;

	found = false;
	while ((first < last) && !found) {
		midPoint = (first + last) / 2;
		if (item < info[midPoint])
			last = midPoint - 1; // 왼쪽 part -> last 감소
		else if (item > info[midPoint])
			first = midPoint + 1; // 오른쪽 part -> first 증가
		else { // item == midPoint
			found = true;
			item = info[midPoint];
		}
	}
}*/ 
