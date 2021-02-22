선택 정렬과 삽입 정렬
============================
## 선택정렬
* **선택정렬이란 가장 작은 것을 선택해서 앞으로 보내는 정렬 기법이다**
* **가장 작은 것을 선택하는 데에 N번, 앞으로 보내는 데 N번 연산으로 O(N2)이다**
> EX)Selection sort:  5 2 3 1 4 -> 1 5 2 3 4 -> 1 2 5 3 4 -> 1 2 3 5 4 -> 1 2 3 4 5 
<pre><code>
void selectionSort(vector<int>& v) {
	int n = v.size(), min, index;
	for (int i = 0; i < n; i++) {
		min = INT_MAX; // 가장 큰 값을 대입 -> 배열의 가장 큰 원소까지 비교하기 위해서
		for (int j = i; j < n; j++) {
			if (min > v[j]) {
				min = v[j]; // i번째 원소 이후부터 계속 최소값이 저장된다.
				index = j; // 가장 작은 원소의 index
			}
		}
		swap(v[index], v[i]);
	}
}
</code></pre>
