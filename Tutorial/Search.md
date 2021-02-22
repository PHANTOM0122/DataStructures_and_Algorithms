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
