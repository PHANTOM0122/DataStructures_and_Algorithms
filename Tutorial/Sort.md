Sort (다양한 정렬 방법)
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
## 삽입정렬
* **삽입 정렬이란 각 숫자를 적절한 위치(inde)]에 삽입하는 정렬 기법이다.**
* 배열의 원소들을 어떤 index에 삽입되도록 만든다는지 하는 개념이다.
* **들어갈 위치를 선택하는데 N번, 선택하는 횟수로 N번이므로 O(N2)이다**
> EX)Insert sort:  2 4 3 1 9 -> 2 4 3 1 9 -> 2 3 4 1 9 -> 2 3 1 4 9 -> 2 1 3 4 9 -> 1 2 3 4 9  
<pre><code>
void InsertSort(vector<int>& v) {
	int n = v.size();
	for (int i = 0; i < n - 1; i++) {
		int j = i; // j is insert index
		while (j >= 0 && v[ j ] > v[ j + 1] ) {
			swap(v[ j ], v[ j + 1 ]); // v[ j ]와 v[ j+1 ]의 원소를 비교
			j--; // 원래 v[ j+1 ]과 v[ j-1 ]이 sort!
		}
	}
}

void insertionSort(char* A, int n) { // n개의 문자의 배열을 정렬
	for (int i = 1; i < n-1; i++) { // 삽입 루프
		char cur = A[ i ]; // 삽입하려는 현재의 문자
		int j = i - 1; // 바로 앞의 문자에서 시작
		while ((j >= 0) && (A[ j ] > cur)) { // A[ j ]가 순서에 어긋나 있는 동안
			A[ j + i ] = A[ j ]; // A[ i ]를 오른쪽으로 이동
			j--; // j를 감소
		}
		A[ j + i ] = cur; // 이곳이 cur에게 맞는 위치
	}
}</code></pre>
## 퀵 정렬
* **퀵 정렬이란 pivot을 기준으로 큰 값과 작은 값을 서로 교체하는 정렬 기법이다**
* **값을 서로 교체하는데 N번, 엇갈린 경우 원소가 반으로 나누어지므로 원소를 나누는 데에 평균적으로 logN번이 소요되므로 O(NlogN)이다.
* **left, right에서 시작하여 left경우   pivot보다 큰 원소를 right의 경우 pivot보다 작은 원소를 선택하여 left<right 경우 swap한다**
* **pivot에 의해 편향된(ex 왼쪽으로 치우처짐) 경우 연산의 양이 O(N2)이다. -> algorithm 라이브러리 sort의 경우 O(NlogN)을 보장한다**
<pre><code>
void QuickSort(int start, int end) {
	if (start > end) return; // 
	int pivot = start, i = start + 1, j = end, temp; // 가장 왼쪽을 pivot이라 가정

	while (i <= j) { // left <= right 일 경우에만 작동
		while (i <= end && v[i] <= v[pivot]) i++; // i는 left에서 시작하여 v[pivot] 보다 큰 값의 index
		while (j > start && v[j] >= v[pivot]) j--; // j는 right에서 시작하여 v[pivot] 보다 작은 값의 index
		if (i > j) swap(v[pivot], v[j]); // left > right인 경우 pivot값과 right값 swap (right이 pivot보다 작은 값이므로!)
		else swap(v[i], v[j]); // left<=right인 경우 left, right swap
	}
}
</code></pre>
![image](https://user-images.githubusercontent.com/50229148/108651526-4c47eb00-7505-11eb-8829-e0d6986a106d.png)
![image](https://user-images.githubusercontent.com/50229148/108651537-54078f80-7505-11eb-8ffa-355a9c238e7c.png)
![image](https://user-images.githubusercontent.com/50229148/108651564-6386d880-7505-11eb-9025-8c68d5ac00bd.png)

## 계수 정렬(Counting sort)
* **계수 정렬은 크기를 기준으로 데이터의 개수를 세는 정렬 알고리즘이다.**
* **각 데이터를 바로 크기를 기준으로 분류하므로 O(N)이다**
* **데이터의 크기가 한정적일 때 사용할 수 있다**
<pre><code>
int n, m;
int a[MAX_VALUE];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> m; a[m]++; }
	for (int i = 0; i < MAX_VALUE; i++) {
		while (a[i] != 0) {cout << i << ' '; a[i]--;}
	}
	return 0;
}</code></pre>
![image](https://user-images.githubusercontent.com/50229148/108653026-d5145600-7508-11eb-97ab-af582a963227.png)
![image](https://user-images.githubusercontent.com/50229148/108653051-e1001800-7508-11eb-81d7-984e2d50045e.png)

## 기수 정렬(Radix sort)
* **기수 정렬은 자릿수를 기준으로 차례대로 데이터를 정렬하는 알고리즘이다.**
* **각 데이터를 자릿수를 기준으로 분류하므로 가장 큰 자릿수를 D(ex 345의 경우 3자리수), O(DN)의 시간 복잡도를 가진다.
* 아래와 같이 **마지막 원소부터 정렬을 시작하여 누적배열의 누적 value를 (index+1)로 하여 해당 위치에 들어가고 누적배열 값은--**
* 기수 정렬은 계수 정렬보다 약간 더 느리지만, 숫자가 매우 큰 상황에서도 사용 가능하다.
![image](https://user-images.githubusercontent.com/50229148/108654394-ee6ad180-750b-11eb-8c3e-de1ea2faa9d7.png)
![image](https://user-images.githubusercontent.com/50229148/108654411-f7f43980-750b-11eb-85d5-d75483c3484c.png)
![image](https://user-images.githubusercontent.com/50229148/108654432-03476500-750c-11eb-8b73-a96c7114234a.png)
![image](https://user-images.githubusercontent.com/50229148/108654712-9aacb800-750c-11eb-847a-b7fada71dc28.png)
![image](https://user-images.githubusercontent.com/50229148/108654759-aef0b500-750c-11eb-8b83-1e5c0364e7b8.png)
![image](https://user-images.githubusercontent.com/50229148/108654768-b6b05980-750c-11eb-81e9-cb362d760879.png)
![image](https://user-images.githubusercontent.com/50229148/108654815-cdef4700-750c-11eb-9a4a-95c44a47c1f7.png)
![image](https://user-images.githubusercontent.com/50229148/108654836-da739f80-750c-11eb-8762-9d72f3f01cc3.png)
![image](https://user-images.githubusercontent.com/50229148/108654854-e1021700-750c-11eb-883e-a3e94a9de65f.png)
<pre><code>
void radixsort(int* a, int n) {
	int result[MAX], maxValue = 0;
	int exp = 1; // 자릿수 1의 자리부터
	for (int i = 0; i < n; i++) {
		if (a[i] > maxValue) maxValue = a[i]; // find Maxvalue
	}

	while (maxValue / exp > 0) { // 1의 자리부터 최고 자릿수까지 계산
		int bucket[10] = { 0 }; // 자릿수 배열
		for (int i = 0; i < n; i++) bucket[(a[i] / exp) % 10]++; // 자릿수 배열 처리
		for (int i = 1; i < 10; i++) bucket[i] += bucket[i - 1]; // 누적 계산 처리
		for (int i = n - 1; i >= 0; i--) { // 같은 자릿수 끼리는 순서를 유지. 뒤의 원소부터 시작
			result[--bucket[(a[i] / exp) % 10]] = a[i]; // result [ 누적배열의 값-1 ]에 value입력
		}
		for (int i = 0; i < n; i++) a[i] = result[i]; // 기본 배열을 result배열로 갱신
		exp *= 10; // 자릿수 증가
	}
}</code></pre>
