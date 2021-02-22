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
</code></pre>
![image](https://user-images.githubusercontent.com/50229148/108651526-4c47eb00-7505-11eb-8829-e0d6986a106d.png)
![image](https://user-images.githubusercontent.com/50229148/108651537-54078f80-7505-11eb-8ffa-355a9c238e7c.png)
![image](https://user-images.githubusercontent.com/50229148/108651564-6386d880-7505-11eb-9025-8c68d5ac00bd.png)
