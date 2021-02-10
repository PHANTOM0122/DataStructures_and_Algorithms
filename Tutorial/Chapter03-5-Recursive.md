Recursive
====================
* **loop를 제외한 반복을 얻는 또 다른 방법이다**
* **자신의 정의 내에서 자기 자신을 호출한다**
* Direct recursion: f(){f();}
* Indirect recursion: f()->g()->h()->f();
* **장점: 짧고, 간결하고, 이해하기 쉬운 코드가 만들어진다**
* **단범: 실행시간이 길다->비효율적**
> **Base case**
  * recursive call이 중단되는 case!
  * 모든 recursive algorithm은 base case를 적어도 1개 가져야 한다.
> **General case**
  * **작은 경우의 자기 자신을 다시 호출하는 case**
  * **결국 base case를 향해 간다.**
## 계승함수(factorial function)
> **factorial(n) = 1(if n==0) or n * factorial(n-1) (if n>=1)**
<pre><code>
int recursiveFactorial(int n){
  if(n==0) return 1;
  else return n * recursiveFactorial(n-1);} // 재귀적인 경우
</code></pre>
* recursive call이 먼저 일어나고 결과가 후에 계산된다!
![image](https://user-images.githubusercontent.com/50229148/107457281-1d408980-6b95-11eb-8341-782b884592e1.png)
## Combination
![image](https://user-images.githubusercontent.com/50229148/107457464-701a4100-6b95-11eb-842e-3e8ac3a229b3.png)
<pre><code>
int Combinations(int n, int k){
if(k==1) return n; // base case1
else if(k==n) return 1; // base case2
else 
 return(Combinations(n-1,k) + combinations(n-1,k-1));} 
</code></pre>
![image](https://user-images.githubusercontent.com/50229148/107457634-c25b6200-6b95-11eb-9bb3-119271836f4f.png)
## Verifying recursive functions (재귀 함수를 검증하는 3가지 질문) -> 수업의 핵심 주제
* Base-Case question: base case를 가지고 있나? // Ex) 0! = 1
* smaller_caller question: 재귀 call이 더 작은 case를 call 하는지? // Ex) f(n){ n * f(n-1);}
* General-Case question: recursive call이 정확하다고 할때, function이 올바르게 작동하는가?
# 3.5-1) 선형 재귀
* 재귀의 가장 간단한 형태이다.
* **선형 재귀는 호출이 발생할 때마다 최대로 하나의 재귀 호출이 이뤄지는 함수이다**
## Example1) Value in list?
<pre><code>
bool ValueInList(ListType list, int value, int startIndex)
{
  if (list.info[startIndex] == value)
    return true; // Base case 1 -> search 과정중에서 발견
  else if (startIndex == list.length-1)
    return false; // Base case 2 -> list의 마지막까지 search했지만 없는 경우
  else return ValueInList(list, value, startIndex + 1); // General case
}</code></pre>
## Example2) Print ReverseArray
<pre><code>
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
}</code></pre>
* 먼저 recursive call을 통해 마지막 원소까지 갔다가 print elem하는 것이다!
![image](https://user-images.githubusercontent.com/50229148/107460242-14eb4d00-6b9b-11eb-99f9-9916e7290066.png)


