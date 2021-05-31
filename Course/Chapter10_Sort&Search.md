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
- **앞에서부터 차근차근 list정렬**
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

# 2) Bubble Sort
- **array의 마지막에서부터 sort하기 시작한다**
- **neighboring elements와 비교를 하며 list의 처음까지 올라간다**
- Time complexity = (N-1) + (N-2) + ... + 1 = O(N*N)
<pre><code>
// 2. Bubble sort

// 밑에서부터 sort 시작
template <class ItemType>
void BubbleUp(ItemType list[], int start, int end) {
	
	for (int index = end; index > start; index--)
		if (list[index] < list[index - 1])
			swap(list[index], list[index - 1]);
}

template <class ItemType>
void BubbleSort(ItemType list[], int numElements) {
	
	int current = 0;
	// Current를 증가시키면서 밑에서부터 current까지 bubbleUp이 된다
	while (current < numElements - 1) {
		BubbleUp(list, current, numElements - 1);
		current++;
	}
}</code></pre>
![image](https://user-images.githubusercontent.com/50229148/120187939-702b7300-c250-11eb-83de-d3e0d2912a55.png)

# 3) Insertion Sort
- **Array를 분할 후, 앞 부분을 배열해놓은 상태에서 new element를 알맞은 순서에 Insert하는 것이다**
- Time complexity = 1 + 2 + 3 + ... + N = O(N*N)
<pre><code>
// 3. Insertion sort

// list의 end index 원소를 정렬시킨다!
template <class ItemType>
void InsertItem(ItemType list[], int start, int end) {
	
	bool finished = false;
	int current = end;
	bool moreToSearch = (current != start);

	while (moreToSearch && !finished) {
		
		if (list[current] < list[current - 1]) {
			swap(list[current], list[current - 1]);
			current--;
			moreToSearch = (current != start);
		}
		else
			finished = false;
	}
}

template <class ItemType>
void InsertionSort(ItemType list[], int numElements)
{
	for (int count = 0; count < numElements; count++) {
		InsertItem(list, 0, count); // Count의 값이 자기의 자리를 찾아라!
	}
}
</code></pre>
![image](https://user-images.githubusercontent.com/50229148/120187961-76215400-c250-11eb-9eaf-85d40497f513.png)
