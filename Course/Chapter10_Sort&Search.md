Sort & Search
====================

# simple sort
1) straight selection sort
2) Bubble sort
3) Insertion sort

# Complex sort
1) Quick sort
2) Merge sort
3) Heap sort


# 1) Selection Sort
- **Array에서 가장 min element를 찾은 후에(O(N)), array의 가장 앞으로 swap한다. 이 과정을 numElement(O(N))만큼 반복한다**
- Time complexity : (N-1) + (N-2) + ... + 2 + 1 = O(N*N)
<pre><code>
// 1. Selection sort

// list에서 가장 작은 element의 index를 반환한다
template <class ItemType>
int MinIndex(ItemType list[], int start, int end) {
	
	// Default minIndex
	int indexOfMin = start;

	for (int index = start + 1; index <= end; index++) {
		if (list[index] < list[indexOfMin])
			indexOfMin = index;
	}

	return indexOfMin;
}

template <class ItemType>
void SelectionSort(ItemType list[], int numElements) {

	int endIndex = numElements - 1;
	
	// list [0]번부터 [n-1]까지 순서대로 sort!
	for (int current = 0; current < endIndex; current++) {
		swap(list[current], list[MinIndex(list, cuurent, endIndex)]);
	}
}</code></pre>
