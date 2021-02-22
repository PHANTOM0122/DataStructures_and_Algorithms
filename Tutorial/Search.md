Search(탐색)
==================
## 순차탐색(Sequential search)
* **특정한 원소를 찾기 위해 원소를 순차적으로 하나씩 탐색하는 방법**
* 원소를 하나씩 탐색해야 하므로 O(N)의 시간 복잡도를 가진다.
![image](https://user-images.githubusercontent.com/50229148/108697790-a4eba800-7546-11eb-8da2-fe92ef1768f2.png)
<pre><code>
void SequenceSearch(int* a, int length, int target) {
	for (int i = 0; i < length; i++) {
		if (target == a[i]) {
			cout << target << "is in " << i + 1 << "번째 원소이다." << endl;
			found = true;
		}
	}
	if (!found){cout << "Can't found!" << endl;}
}</code></pre>

## 이진탐색(Binary search)
* **이진 탐색은 배열 내부 데이터가 이미 정렬되어 있는 상황에서 사용 가능한 알고리즘이다.**
* **탐색 범위를 절반씩 좁혀가며 데이터를 탐색하는 특징이 있다 -> O(logN)**
![image](https://user-images.githubusercontent.com/50229148/108699639-d2395580-7548-11eb-8948-e5546a0b58b1.png)
<pre><code>
int Binarysearch(vector<int> a, int start, int end, int target) {
	if (start > end)return -1;
	int mid = (start + end) / 2;
	if (target > a[mid]) return Binarysearch(a, mid+1, end, target);
	else if (target < a[mid]) return Binarysearch(a, start, mid-1, target);
	else return mid;
}</code></pre>
